namespace c_sharp;

public class Stacks
{
    public static void Run()
    {
        var result = CheckParenthesis("()])()[[]");
        Console.WriteLine(result);
    }

    public static bool CheckParenthesis(string s)
    {
        var stack = new Stack<char>();

        var dictionary = new Dictionary<char, char>
        {
            {
                '(', ')'
            },
            {
                '{', '}'
            },
            {
                '[', ']'
            }
        };

        var rights = dictionary.Values.ToList();

        char left;

        foreach (var character in s)
        {
            if (rights.Contains(character))
            {
                left = dictionary.FirstOrDefault(x => x.Value == character).Key;
                if (stack.Peek() == left)
                {
                    stack.Push(character);
                    stack.Pop();
                    stack.Pop();
                }

                continue;
            }

            stack.Push(character);
        }

        if (stack.Count == 0) return true;

        return false;
    }
}