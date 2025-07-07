#include <iostream>
#include <stack>
using namespace std;
bool isBalanced(const string& str) {
    stack<char> s;
    for (char ch : str) {
        if (ch == '(' || ch == '{' || ch == '[') {
            s.push(ch);
        } else if (ch == ')' || ch == '}' || ch == ']') {
            if (s.empty()) return false;
            char top = s.top();
            s.pop();
            if ((ch == ')' && top != '(') ||
                (ch == '}' && top != '{') ||
                (ch == ']' && top != '[')) {
                return false;
            }
        }
    }
    return s.empty();
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string input;
    cin >> input;

    if (isBalanced(input)) {
        cout << "Balanced\n";
    } else {
        cout << "Not Balanced\n";
    }

    return 0;
}