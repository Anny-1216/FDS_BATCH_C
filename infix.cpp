#include <iostream>
#include <stack>
using namespace std;

int precedence(char c) {
    if (c == '^')
        return 3;
    else if (c == '/' || c == '*')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}

void infix2postfix(string exp) {
    stack<char> st;
    string result;

    for (int i = 0; i < exp.length(); i++) {
        char c = exp[i];

        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
            result += c;
        else if (c == '(')
            st.push('(');
        else if (c == ')') {
            while (!st.empty() && st.top() != '(') {
                result += st.top();
                st.pop();
            }
            if (!st.empty() && st.top() == '(')
                st.pop(); // Pop the opening parenthesis
        } else {
            while (!st.empty() && precedence(c) <= precedence(st.top())) {
                result += st.top();
                st.pop();
            }
            st.push(c);
        }
    }

    while (!st.empty()) {
        result += st.top();
        st.pop();
    }

    cout << "Postfix Expression: " << result << endl;
}

int main() {
    string infixExpression;
    cout << "Enter infix expression: ";
    cin >> infixExpression;

    infix2postfix(infixExpression);

    return 0;
}
