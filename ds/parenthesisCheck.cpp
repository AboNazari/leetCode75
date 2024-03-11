#include <iostream>
#include <stack>
#include <string>

using namespace std;


bool parenthesisCheck(string str) {
    stack<char> s;

    for (char ch : str) {
        switch (ch) {
            case '(':
            case '{':
            case '[':
                s.push(ch); // Push opening parentheses onto the stack
                break;
            case ')':
                if (s.empty() || s.top() != '(') return false; // Mismatched or extra closing parenthesis
                s.pop(); // Pop the matching opening parenthesis
                break;
            case '}':
                if (s.empty() || s.top() != '{') return false;
                s.pop();
                break;
            case ']':
                if (s.empty() || s.top() != '[') return false;
                s.pop();
                break;
            default:
                // Ignore non-parentheses characters
                break;
        }
    }

    return s.empty();
}


int main() {
    string s = "(asdfasdf){(asdfasdfASDFASD)}";

    bool res = parenthesisCheck(s);


    cout << res << endl;

    return 0;
}