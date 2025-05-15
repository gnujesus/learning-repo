namespace c_sharp;

public class Queues
{
    public static void Run()
    {
        var q = new Queue<int>();
        StackFromQueues.Push(q, 2);

        foreach (var val in q) Console.WriteLine(val);
    }
}

public class StackFromQueues
{
    public static void Push(Queue<int> q, int item)
    {
        if (q.Count != 0)
        {
            q.Enqueue(item);

            for (var i = 0; i < q.Count; i++)
                q.Enqueue(q.Last());
        }
    }

    public static void Pop()
    {
    }

    public static void Top()
    {
    }

    public static void Empty()
    {
    }
}