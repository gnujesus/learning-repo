# PeopleSoft Simulation API

A NestJS-based REST API that simulates a PeopleSoft classroom schedule system. This API provides classroom schedule data with JWT authentication.

## Project Setup

```bash
npm install
```

## Running the Server

```bash
# Development
npm run start

# Watch mode
npm run start:dev

# Production
npm run start:prod
```

The server runs on port `4000` by default (or the port specified in the `PORT` environment variable).

## API Documentation

### Base URL

```
http://localhost:4000
```

### Authentication

This API uses JWT (JSON Web Token) authentication. You must obtain a token before accessing protected endpoints.

#### Login

**Endpoint:** `POST /auth/login`

**Request:**
```bash
curl -X POST http://localhost:4000/auth/login \
  -H "Content-Type: application/json" \
  -d '{"username": "admin", "password": "1234567"}'
```

**Response:**
```json
{
  "access_token": "eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9..."
}
```

The token expires in **1 hour**.

---

### Protected Endpoints

All protected endpoints require the JWT token in the `Authorization` header:

```
Authorization: Bearer <your_access_token>
```

#### Get Classroom Schedule

**Endpoint:** `GET /api/classroom-schedule`

**Request:**
```bash
curl -X GET http://localhost:4000/api/classroom-schedule \
  -H "Authorization: Bearer <your_access_token>"
```

**Response:**
```json
[
  {
    "classroom": "AH302",
    "serverDateTime": "2025-12-10T08:00:00-04:00",
    "currentYear": 2025,
    "currentTerm": "2025-10",
    "classes": [
      {
        "courseCode": "MED-101",
        "courseTitle": "ANATOMÍA HUMANA I",
        "section": "01",
        "instructor": "Dr. María Rodríguez",
        "startTime": "08:00",
        "endTime": "10:00"
      }
    ]
  }
]
```

**Error Response (401 Unauthorized):**
```json
{
  "statusCode": 401,
  "message": "Unauthorized"
}
```

---

## Frontend Integration

### JavaScript/TypeScript Example

```javascript
const API_BASE_URL = 'http://localhost:4000';

// Step 1: Login and get token
async function login(username, password) {
  const response = await fetch(`${API_BASE_URL}/auth/login`, {
    method: 'POST',
    headers: {
      'Content-Type': 'application/json',
    },
    body: JSON.stringify({ username, password }),
  });

  const data = await response.json();
  return data.access_token;
}

// Step 2: Fetch protected data
async function getClassroomSchedule(token) {
  const response = await fetch(`${API_BASE_URL}/api/classroom-schedule`, {
    method: 'GET',
    headers: {
      'Authorization': `Bearer ${token}`,
    },
  });

  if (!response.ok) {
    throw new Error('Unauthorized');
  }

  return response.json();
}

// Usage
async function main() {
  try {
    const token = await login('admin', '1234567');
    const schedule = await getClassroomSchedule(token);
    console.log(schedule);
  } catch (error) {
    console.error('Error:', error.message);
  }
}
```

### React Example

```jsx
import { useState, useEffect } from 'react';

const API_BASE_URL = 'http://localhost:4000';

function useAuth() {
  const [token, setToken] = useState(localStorage.getItem('token'));

  const login = async (username, password) => {
    const response = await fetch(`${API_BASE_URL}/auth/login`, {
      method: 'POST',
      headers: { 'Content-Type': 'application/json' },
      body: JSON.stringify({ username, password }),
    });
    const data = await response.json();
    localStorage.setItem('token', data.access_token);
    setToken(data.access_token);
    return data.access_token;
  };

  const logout = () => {
    localStorage.removeItem('token');
    setToken(null);
  };

  return { token, login, logout };
}

function ClassroomSchedule() {
  const { token, login } = useAuth();
  const [schedule, setSchedule] = useState([]);
  const [loading, setLoading] = useState(true);

  useEffect(() => {
    async function fetchSchedule() {
      if (!token) {
        await login('admin', '1234567');
      }

      const response = await fetch(`${API_BASE_URL}/api/classroom-schedule`, {
        headers: { 'Authorization': `Bearer ${token}` },
      });

      const data = await response.json();
      setSchedule(data);
      setLoading(false);
    }

    fetchSchedule();
  }, [token]);

  if (loading) return <div>Loading...</div>;

  return (
    <div>
      {schedule.map((room) => (
        <div key={room.classroom}>
          <h2>{room.classroom}</h2>
          <ul>
            {room.classes.map((cls) => (
              <li key={cls.courseCode}>
                {cls.courseCode} - {cls.courseTitle} ({cls.startTime}-{cls.endTime})
              </li>
            ))}
          </ul>
        </div>
      ))}
    </div>
  );
}
```

---

## WebSocket Client Integration

If you have a WebSocket server that needs to fetch data from this API, here's how to integrate:

### Node.js WebSocket Server Example

```javascript
const WebSocket = require('ws');

const API_BASE_URL = 'http://localhost:4000';
let cachedToken = null;
let tokenExpiry = null;

// Get or refresh token
async function getToken() {
  const now = Date.now();

  // Return cached token if still valid (with 5 min buffer)
  if (cachedToken && tokenExpiry && now < tokenExpiry - 300000) {
    return cachedToken;
  }

  const response = await fetch(`${API_BASE_URL}/auth/login`, {
    method: 'POST',
    headers: { 'Content-Type': 'application/json' },
    body: JSON.stringify({ username: 'admin', password: '1234567' }),
  });

  const data = await response.json();
  cachedToken = data.access_token;
  tokenExpiry = now + 3600000; // 1 hour from now

  return cachedToken;
}

// Fetch schedule data
async function fetchSchedule() {
  const token = await getToken();

  const response = await fetch(`${API_BASE_URL}/api/classroom-schedule`, {
    headers: { 'Authorization': `Bearer ${token}` },
  });

  return response.json();
}

// WebSocket server that broadcasts schedule data
const wss = new WebSocket.Server({ port: 8080 });

wss.on('connection', (ws) => {
  console.log('Client connected');

  ws.on('message', async (message) => {
    const request = JSON.parse(message);

    if (request.type === 'getSchedule') {
      try {
        const schedule = await fetchSchedule();
        ws.send(JSON.stringify({ type: 'schedule', data: schedule }));
      } catch (error) {
        ws.send(JSON.stringify({ type: 'error', message: error.message }));
      }
    }
  });
});

// Optional: Broadcast updates periodically
setInterval(async () => {
  try {
    const schedule = await fetchSchedule();
    wss.clients.forEach((client) => {
      if (client.readyState === WebSocket.OPEN) {
        client.send(JSON.stringify({ type: 'scheduleUpdate', data: schedule }));
      }
    });
  } catch (error) {
    console.error('Failed to fetch schedule:', error);
  }
}, 60000); // Every minute
```

### WebSocket Client Example

```javascript
const ws = new WebSocket('ws://localhost:8080');

ws.onopen = () => {
  console.log('Connected to WebSocket server');
  // Request schedule data
  ws.send(JSON.stringify({ type: 'getSchedule' }));
};

ws.onmessage = (event) => {
  const message = JSON.parse(event.data);

  if (message.type === 'schedule' || message.type === 'scheduleUpdate') {
    console.log('Received schedule:', message.data);
  }
};

ws.onerror = (error) => {
  console.error('WebSocket error:', error);
};
```

---

## Response Data Structure

### Classroom Schedule Object

| Field | Type | Description |
|-------|------|-------------|
| `classroom` | string | Classroom identifier (e.g., "AH302") |
| `serverDateTime` | string | ISO 8601 datetime with timezone |
| `currentYear` | number | Academic year |
| `currentTerm` | string | Term identifier |
| `classes` | array | List of classes scheduled |

### Class Object

| Field | Type | Description |
|-------|------|-------------|
| `courseCode` | string | Course code (e.g., "MED-101") |
| `courseTitle` | string | Course name |
| `section` | string | Section number |
| `instructor` | string | Instructor name |
| `startTime` | string | Start time (HH:mm) |
| `endTime` | string | End time (HH:mm) |

---

## Error Handling

| Status Code | Description |
|-------------|-------------|
| 200 | Success |
| 401 | Unauthorized - Invalid or missing token |
| 403 | Forbidden - Token valid but access denied |

---

## Running Tests

```bash
# Unit tests
npm run test

# E2E tests
npm run test:e2e

# Test coverage
npm run test:cov
```

## License

This project is [MIT licensed](https://github.com/nestjs/nest/blob/master/LICENSE).
