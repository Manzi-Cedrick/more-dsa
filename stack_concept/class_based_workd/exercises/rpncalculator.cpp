#include <iostream>
#include <stack>
#include <string>
using namespace std;


int evaluateReversePN(string *tokens, int size) {
    stack<int> s;
    for (int i = 0; i < size; i++) {
        string token = tokens[i];
        if (token == "+") {
            int y = s.top(); s.pop();
            int x = s.top(); s.pop();
            s.push(x + y);
        } else if (token == "*") {
            int y = s.top(); s.pop();
            int x = s.top(); s.pop();
            s.push(x * y);
        } else if (token == "-") {
            int y = s.top(); s.pop();
            int x = s.top(); s.pop();
            s.push(x - y);
        } else if (token == "/") {
            int y = s.top(); s.pop();
            int x = s.top(); s.pop();
            s.push(x / y);
        } else {
            s.push(stoi(token));
        }
    }
    return s.top();
}

int main() {
    string tokens1[] = {"2","1","+","3","*"};
    string tokens2[] = {"4","13","5","/","+"};
    int size1 = sizeof(tokens1)/sizeof(tokens1[0]);
    cout << evaluateReversePN(tokens1, size1) << endl;
    return 0;
}
