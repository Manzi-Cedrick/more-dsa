#include <iostream>
#include <stack>
using namespace std;

int main()
{
    stack<int> s;
    stack<string> names;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    names.push("Iris");
    names.push("Manzi");
    names.push("Derrick");
    cout << s.top() << endl;
    cout << names.top() << endl;
    return 0;
}