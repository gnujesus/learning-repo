
using System.Text.Encodings.Web;

void WriteThreadId()
{
    for (int i = 0; i < 100; i++)
    {
        Console.WriteLine(Thread.CurrentThread.ManagedThreadId);
        Thread.Sleep(50);
    }
}

Thread thread1 = new Thread(WriteThreadId);
thread1.Start();

Thread thread2 = new Thread(WriteThreadId);
thread2.Start();

WriteThreadId();


