namespace c_sharp;

public class Stacks
{
    public static void Run()
    {
        var result = CheckParenthesis("(()[])()[[]]");
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
                if (stack.Count != 0 && stack.Peek() == left)
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

    // ChatGPT Solution
    public static bool CheckParenthesisChatGptSolution(string s)
    {
        var stack = new Stack<char>();

        // Map closing bracket to corresponding opening bracket
        var pairs = new Dictionary<char, char>
        {
            { ')', '(' },
            { '}', '{' },
            { ']', '[' }
        };

        foreach (var ch in s)
            if (pairs.ContainsKey(ch))
            {
                // ch is a closing bracket
                if (stack.Count == 0 || stack.Pop() != pairs[ch]) return false;
            }
            else
            {
                // ch is an opening bracket
                stack.Push(ch);
            }

        return stack.Count == 0;
    }
}