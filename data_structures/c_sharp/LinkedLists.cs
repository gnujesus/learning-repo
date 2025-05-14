namespace c_sharp;

public class LinkedLists
{
    public static void Run()
    {
        var linkedList = new LinkedList<int>();

        for (var i = 0; i < 5; i++) linkedList.AddLast(i);

        TraverseLinkedList(linkedList.First);
        linkedList = ReverseLinkedList(linkedList);

        Console.WriteLine("\n\n--- Reversed List ---");
        TraverseLinkedList(linkedList?.First);
    }

    private static void TraverseLinkedList(LinkedListNode<int>? head)
    {
        if (head == null)
        {
            Console.WriteLine("No head given");
            return;
        }

        var temp = head;

        while (temp.Next != null)
        {
            var val = temp.Next == null ? "null" : temp.Next.Value.ToString();
            Console.WriteLine($"Curr val: {temp.Value} -> {val}");
            temp = temp.Next;
        }
    }

    private static LinkedList<int>? ReverseLinkedList(LinkedList<int>? linkedList)
    {
        if (linkedList == null)
        {
            Console.WriteLine("No list given");
            return null;
        }

        var reversedList = new LinkedList<int>();

        foreach (var val in linkedList) reversedList.AddFirst(val);

        return reversedList;
    }
}