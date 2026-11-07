class Solution {
public:
    bool isValid(string str) {
        stack<char> left;
        for (char c : str) {
            if (c == '(' || c == '{' || c == '[') {
                left.push(c);
            } else {
                if (!left.empty() && leftOf(c) == left.top()) {
                    left.pop();
                } else {
                    return false;
                }
            }
        }
        return left.empty();
    }

    char leftOf(char c) {
        switch (c) {
            case ')': return '(';
            case '}': return '{';
            case ']': return '[';
            default: return 0;
        }
    }
};
