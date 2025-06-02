using System.Diagnostics;

int[] numbersArray = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

var stopWatch = Stopwatch.StartNew();

int numberOfSegments = 4; 
int segmentLength = numbersArray.Length / numberOfSegments; // 2.5, truncated to 2

// --

int SumSegment(int start, int end)
{
    int segmentSum = 0;
    for (int i = start; i < end; i++)
    {
        Thread.Sleep(100);
        segmentSum += numbersArray[i];
    }

    return segmentSum;
}

var tasks = new Task<int>[]
{
    Task.Run(() => SumSegment(0, segmentLength)),
    Task.Run(() => SumSegment(segmentLength, 2 * segmentLength)),
    Task.Run(() => SumSegment(2 * segmentLength,  3 * segmentLength)),
    Task.Run(() => SumSegment(3 * segmentLength,  numbersArray.Length)) // Handle remaining operations (MORE EXPENSIVE)
};

var results = await Task.WhenAll(tasks);
var total = results.Sum();

// --

stopWatch.Stop();

Console.WriteLine($"Elapsed: {stopWatch.Elapsed}");

Console.WriteLine($"Sum: {total}");