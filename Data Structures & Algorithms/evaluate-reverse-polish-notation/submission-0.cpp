class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s = {};

        for (string c : tokens) {
            if (c == "+" || c == "-" || c == "*" || c == "/") {
                int y = static_cast<int>(s.top());
                s.pop();
                int x = static_cast<int>(s.top());
                s.pop();
                if (c == "+") { s.push(x+y); }
                else if (c == "-") { s.push(x-y); }
                else if (c == "*") { s.push(x*y); }
                else { s.push(x/y); } // truncates towards 0 by default.
            } else {
                int z = stoi(c);
                s.push(z);
            }
        }
        return s.top();
    }
};
