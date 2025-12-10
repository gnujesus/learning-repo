START_OF_FILE
# Classroom Display System - Task Checklist

---

## ✅ Phase 1: Foundation Setup (COMPLETED)

### Task 1.1: Project Setup ✅
- [x] Create new NestJS project: `nest new classroom-display-system`
- [x] Install WebSocket dependencies: `npm install @nestjs/websockets @nestjs/platform-socket.io socket.io`
- [x] Install HTTP module: `npm install @nestjs/axios axios`
- [x] Verify server starts: `npm run start:dev`

### Task 1.2: Create Folder Structure ✅
- [x] Create `src/screen/` folder
- [x] Create `src/schedule/` folder
- [x] Create `src/mock-data/` folder
- [x] Create `src/types/` folder
- [x] Create `src/helper/` folder

### Task 1.3: Create Mock Schedule Data ✅
- [x] Create file: `src/mock-data/schedules.json`
- [x] Add mock data for 3 classrooms: `EL304`, `AH301`, `BT205`
- [x] Update `tsconfig.json`: Add `"resolveJsonModule": true`

---

## ✅ Phase 2: WebSocket Gateway (IN PROGRESS)

### Task 2.1: Generate Screen Module & Gateway ✅
- [x] Run: `nest g module screen`

- [x] Run: `nest g gateway screen/screen`
- [x] Verify files created in `src/screen/`


### Task 2.2: Configure Dynamic Namespace ✅
- [x] Add `@WebSocketGateway()` decorator
- [x] Configure `cors: { origin: '*' }`
- [x] Configure `namespace: /^\/screens\/[A-Z0-9]+$/`
- [x] Add `@WebSocketServer() server: Server`
- [x] Add Logger: `private readonly logger = new Logger(ScreenGateway.name)`

### Task 2.3: Implement Connection Lifecycle ✅
- [x] Add `OnGatewayConnection`, `OnGatewayDisconnect` interfaces
- [x] Implement `handleConnection(client: Socket)` method
- [x] Implement `handleDisconnect(client: Socket)` method
- [x] Both methods use `HelperService`
- [x] Both methods parse classroom code
- [x] Logging is consistent

### Task 2.4: Create Helper Service ✅
- [x] Create `src/types/classroom.types.ts` with `Classroom` interface
- [x] Create `src/helper/helper.service.ts`
- [x] Create `extractCodeFromNamespace(namespace: string)` method
- [x] Create `parseClassroomCode(code: string): Classroom` method
- [x] Create `src/helper/helper.module.ts` with `@Global()` decorator
- [x] Export `HelperService` from module
- [x] Import `HelperModule` in `AppModule`

### Task 2.5: Implement Send Methods ⬅️ NEXT

- [x] Add sendToClassroom method
- [x] Add broadcastToAll method
- [ ] Test both methods compile without errors


### Task 2.6: Implement Stats Methods

- [ ] Add getConnectedClassrooms method
- [ ] Add getClassroomStats method
- [ ] Add getAllStats method
- [ ] Verify all methods compile

### Task 2.7: Export Gateway
- [ ] Open `src/screen/screen.module.ts`

- [ ] Verify `ScreenGateway` in `providers` array
- [ ] Verify `ScreenGateway` in `exports` array
- [ ] Code compiles without errors

---

## Phase 3: Test WebSocket Connection

### Task 3.1: Create Test HTML Client
- [ ] Create `test-client.html` in project root

- [ ] Add Socket.IO client from CDN
- [ ] Add input field for classroom code
- [ ] Add Connect and Disconnect buttons
- [ ] Add logging display area
- [ ] Add listener for updateSchedule event

### Task 3.2: Test Basic Connection
- [ ] Start server

- [ ] Open test-client.html in browser
- [ ] Enter classroom EL304
- [ ] Click Connect
- [ ] Verify browser shows CONNECTED
- [ ] Verify server logs show connection with correct classroom
- [ ] Verify server logs show building EL and room 304
- [ ] Click Disconnect
- [ ] Verify browser shows DISCONNECTED
- [ ] Verify server logs show disconnection

### Task 3.3: Test Multiple Connections
- [ ] Open test client in Browser Tab 1
- [ ] Connect to EL304
- [ ] Open test client in Browser Tab 2
- [ ] Connect to EL304 (same classroom)
- [ ] Open test client in Browser Tab 3
- [ ] Connect to AH301 (different classroom)
- [ ] Verify server logs show all 3 connections
- [ ] Verify server logs show 2 connections to EL304
- [ ] Verify server logs show 1 connection to AH301
- [ ] Close Tab 2
- [ ] Verify server logs show only Tab 2 disconnected
- [ ] Verify Tabs 1 and 3 still connected

---

## Phase 4: Schedule Module

### Task 4.1: Generate Schedule Module
- [ ] Run nest g module schedule
- [ ] Run nest g service schedule

- [ ] Run nest g controller schedule

- [ ] Verify files created in src/schedule/

### Task 4.2: Import Required Modules
- [ ] Open src/schedule/schedule.module.ts

- [ ] Import HttpModule from @nestjs/axios
- [ ] Import ScreenModule from ../screen/screen.module
- [ ] Add both to imports array

- [ ] Verify code compiles

### Task 4.3: Implement Schedule Service
- [ ] Open src/schedule/schedule.service.ts
- [ ] Import HttpService from @nestjs/axios
- [ ] Import mock schedules JSON
- [ ] Inject HttpService in constructor
- [ ] Add property useMockData = true
- [ ] Add Logger
- [ ] Create fetchSchedule method

- [ ] Method returns mock data when useMockData is true
- [ ] Verify code compiles

### Task 4.4: Create Mock Data Method
- [ ] In ScheduleService create getMockSchedule method
- [ ] Return schedule from mock data for requested classroom
- [ ] Return null or default if classroom not found
- [ ] Handle errors gracefully
- [ ] Verify method works correctly

### Task 4.5: Implement Schedule Controller
- [ ] Open src/schedule/schedule.controller.ts
- [ ] Inject ScheduleService in constructor
- [ ] Inject ScreenGateway in constructor

- [ ] Set route prefix @Controller('schedule')
- [ ] Add Logger
- [ ] Verify code compiles

### Task 4.6: Create Update Endpoint
- [ ] Add endpoint POST /schedule/update/:classroom
- [ ] Extract classroom param

- [ ] Call scheduleService.fetchSchedule
- [ ] Call screenGateway.sendToClassroom
- [ ] Return success response with schedule data
- [ ] Add logging
- [ ] Verify endpoint compiles


### Task 4.7: Create Update All Endpoint
- [ ] Add endpoint POST /schedule/update-all
- [ ] Call screenGateway.getConnectedClassrooms
- [ ] Loop through each classroom with Promise.all

- [ ] Fetch schedule for each classroom
- [ ] Send to each classroom via WebSocket
- [ ] Return summary with total updated and results array

- [ ] Add error handling for failed updates
- [ ] Verify endpoint compiles

### Task 4.8: Create Stats Endpoints
- [ ] Add endpoint GET /schedule/stats

- [ ] Call screenGateway.getAllStats
- [ ] Return connection statistics
- [ ] Add endpoint GET /schedule/stats/:classroom
- [ ] Call screenGateway.getClassroomStats
- [ ] Return stats for specific classroom

- [ ] Verify both endpoints compile

---


## Phase 5: Integration & Testing

### Task 5.1: Update Test Client to Listen for Updates
- [ ] Open test-client.html
- [ ] Add listener for updateSchedule event
- [ ] Display schedule data in UI
- [ ] Show classroom, course codes, course titles, instructors, times
- [ ] Format display nicely
- [ ] Test in browser

### Task 5.2: End-to-End Test with HTTP + WebSocket
- [ ] Keep server running

- [ ] Open 2 test clients connected to EL304
- [ ] Open 1 test client connected to AH301
- [ ] Use Postman/cURL POST /schedule/update/EL304
- [ ] Verify both EL304 clients receive updateSchedule event
- [ ] Verify AH301 client does NOT receive update

- [ ] Use Postman/cURL POST /schedule/update-all
- [ ] Verify all 3 clients receive updates
- [ ] Check server logs for broadcast confirmations

### Task 5.3: Test Stats Endpoints
- [ ] Keep multiple screens connected
- [ ] Use Postman/cURL GET /schedule/stats
- [ ] Verify response shows all connected classrooms
- [ ] Verify counts are correct
- [ ] Use Postman/cURL GET /schedule/stats/EL304
- [ ] Verify response shows 2 connected screens
- [ ] Verify socket IDs are present

### Task 5.4: Error Handling Test
- [ ] Test invalid classroom code
- [ ] Verify appropriate error response
- [ ] Test update with no screens connected
- [ ] Verify endpoint still works
- [ ] Test stats with non-existent classroom
- [ ] Verify returns 0 connected screens
- [ ] Check server logs for error handling

---

## Final Checklist


- [ ] All phases completed
- [ ] Server starts without errors
- [ ] Screens can connect to dynamic namespaces
- [ ] HTTP endpoints trigger WebSocket broadcasts
- [ ] Multiple screens in same classroom receive same data
- [ ] Different classrooms receive different data
- [ ] Stats endpoints show correct information
- [ ] All logs are clear and helpful
- [ ] Code is clean and well-documented
- [ ] Ready for production deployment

---

## Progress Summary


Phase 1: Foundation Setup - 100% (3/3 tasks)
Phase 2: WebSocket Gateway - 60% (4/7 tasks)

Phase 3: Test WebSocket - 0% (0/3 tasks)
Phase 4: Schedule Module - 0% (0/8 tasks)
Phase 5: Integration & Testing - 0% (0/4 tasks)


Overall Progress: 28% (7/25 tasks)

---

## Next Steps

1. Complete Task 2.5: Add send methods to gateway
2. Complete Task 2.6: Add stats methods to gateway
3. Complete Task 2.7: Export gateway properly
4. Move to Phase 3: Create and test HTML client

5. Move to Phase 4: Build schedule module with HTTP endpoints

6. Move to Phase 5: Integration testing

---

## Notes


- Keep server running during testing
- Use browser DevTools console to debug client-side issues
- Check server terminal for backend logs
- Each screen device will eventually use config stored in localStorage
- Mock data is in src/mock-data/schedules.json
- Helper service is globally available via @Global() decorator

---

Current Status: Task 2.5 - Implement Send Methods
END_OF_FILE
