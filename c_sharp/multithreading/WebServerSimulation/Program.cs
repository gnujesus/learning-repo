Console.WriteLine("Server is running. Type 'exit' to exit.");

// Q
var requestQ = new Queue<Task>();

while (true)
{
    // Each input introduced is a request
    string? input = Console.ReadLine();
    
    if (input?.ToLower() == "exit")
    {
        break;
    }
    
    RequestHandler(input, requestQ);
    RequestMonitor(requestQ);
}

static void RequestHandler(string? input, Queue<Task> q)
{
    q.Enqueue(Task.Run(() =>  ProcessInput(input) ));
}

static void RequestMonitor(Queue<Task> q)
{
    Console.WriteLine($"Queue Size: {q.Count}\nProcessing: {1}");

    Task.Run(() => Console.WriteLine("Hello World"));
}

// Request Processor
static void ProcessInput(string? input)
{
    // Simulate heavy task, long processing time
    Thread.Sleep(5000);
    Console.WriteLine($"Processed input: {input}");
}