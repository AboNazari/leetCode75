#include <iostream>
#include <stack>
#include <string>
#include <cmath> // For pow function

using namespace std;


//Initialize a stack for operators and an empty string for the postfix expression.
//Iterate through each character of the infix expression.
//Add operands directly to the postfix string.
//Push opening parentheses onto the stack.
//For closing parentheses, pop from the stack to the postfix string until an opening parenthesis is encountered. Exclude the parentheses themselves from the postfix string.
//For operators, pop from the stack to the postfix string any operators of greater or equal precedence, then push the current operator onto the stack.
//After processing the input, pop any remaining operators from the stack to the postfix string.
//Return the postfix string.




using namespace std;

// Function to return precedence of operators
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^') return 3; // Exponentiation has the highest precedence
    return 0;
}

// Function to check if the character is an operator
bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

// Function to convert infix expression to postfix
string infixToPostfix(string infix) {
    stack<char> st; // stack for operators.
    string postfix = ""; // Initialize postfix as empty string.
    for (int i = 0; i < infix.length(); ++i) {
        char ch = infix[i];
        if (isdigit(ch)) {
            postfix += ch; // Add digit to postfix
            // Handle multi-digit numbers
            while (i + 1 < infix.length() && isdigit(infix[i + 1])) {
                postfix += infix[++i];
            }
            postfix += " "; // Add a space to separate numbers
        } else if (ch == '(') {
            st.push(ch);
        } else if (ch == ')') {
            while (!st.empty() && st.top() != '(') {
                postfix += st.top();
                st.pop();
                postfix += " ";
            }
            if (!st.empty()) st.pop(); // Pop the '('
        } else if (isOperator(ch)) {
            while (!st.empty() && precedence(ch) <= precedence(st.top())) {
                postfix += st.top();
                st.pop();
                postfix += " ";
            }
            st.push(ch);
        }
    }
    while (!st.empty()) {
        postfix += st.top();
        st.pop();
        postfix += " ";
    }
    return postfix;
}


//Initialize an empty stack to hold operands (numbers).
//
//Iterate over each character of the postfix expression from left to right.
//
//If the character is an operand (a digit or a sequence representing a multi-digit number), do the following:
//
//For multi-digit numbers, you may need to read ahead until you find a non-digit character, concatenating all consecutive digits to form the full number.
//Convert the string representation of the number to an integer or floating-point number as required.
//Push the operand onto the stack.
//If the character is an operator (+, -, *, /, ^ for exponentiation), perform the following steps:
//
//Pop the top two operands from the stack. The first pop gives you the second operand, and the second pop gives you the first operand, due to the stack's Last In, First Out (LIFO) nature.
//Apply the operator to these two operands in the correct order.
//Push the result of this operation back onto the stack.
//Repeat steps 3 and 4 until the entire postfix expression has been processed.
//
//The stack should now contain one element, which is the result of evaluating the postfix expression. Pop and return this as the final result.



// Function to evaluate the postfix expression
int evaluatePostfix(const string& postfix) {
    stack<int> stack;
    int i = 0;
    while (i < postfix.length()) {
        if (isdigit(postfix[i])) {
            int num = 0;
            while (i < postfix.length() && isdigit(postfix[i])) {
                num = num * 10 + (postfix[i] - '0');
                i++;
            }
            stack.push(num);
        } else if (postfix[i] != ' ') {
            int val2 = stack.top();
            stack.pop();
            int val1 = stack.top();
            stack.pop();
            switch (postfix[i]) {
                case '+': stack.push(val1 + val2); break;
                case '-': stack.push(val1 - val2); break;
                case '*': stack.push(val1 * val2); break;
                case '/': stack.push(val1 / val2); break;
                case '^': stack.push(pow(val1, val2)); break; // Handle exponentiation
            }
            i++; // Move to the next character
        } else {
            i++; // Skip spaces
        }
    }
    return stack.top();
}

// Driver code
int main() {
    string exp = "1+2*(3^2-4)^(2+2*1)-9";
    cout << "Infix expression: " << exp << endl;
    string postFixExp = infixToPostfix(exp);
    cout << "Postfix expression: " << postFixExp << endl;
    cout << "Evaluation Result: " << evaluatePostfix(postFixExp) << endl;
    return 0;
}
