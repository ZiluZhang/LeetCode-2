class Solution {
public:
    bool isValid(string s) {
        stack<char> tmp;
        for (char c: s) {
            switch (c) {
                case '(': tmp.push(c); break;
                case '[': tmp.push(c); break;
                case '{': tmp.push(c); break;
                case ')':
                    if (tmp.empty() || tmp.top() != '(') return false;
                    else tmp.pop();
                    break;
                case ']':
                    if (tmp.empty() || tmp.top() != '[') return false;
                    else tmp.pop();
                    break;
                case '}':
                    if (tmp.empty() || tmp.top() != '{') return false;
                    else tmp.pop();
                    break;
            }
        }
        return tmp.empty();
    }
};