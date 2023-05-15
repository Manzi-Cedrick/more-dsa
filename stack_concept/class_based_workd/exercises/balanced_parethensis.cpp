#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

bool validInput(string s)
{
    stack<char> stack_string;
    char opening_brackets_values[] = {'(','{','['};
    for (char c : s)
    {
        if (find(begin(opening_brackets_values),end(opening_brackets_values),c) != end(opening_brackets_values))
        {
            stack_string.push(c);
        }
        else
        {
            if (stack_string.empty())
            {
                return false;
            }
            char top = stack_string.top();
            if ((c == ')' && top != '(') || (c == '}' && top != '{') || (c == ']' && top != '['))
            {
                return false;
            }
            stack_string.pop();
        }
    }
    return stack_string.empty();
}
int main()
{
    string s1 = "()[]{}";
    string s2 = "()";
    string s3 = "(]";
    string s4 = "([)]";
    string s5 = "{[]}()";

    cout << boolalpha;
    cout << validInput(s1) << endl;
    cout << validInput(s2) << endl;
    cout << validInput(s3) << endl;
    cout << validInput(s4) << endl;
    cout << validInput(s5) << endl;
}