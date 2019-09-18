class Solution {
public:
    int calculate(string s) {
        int res = 0;
        stack<int> st;
        int len = s.length();
        int num = 0;
        char op = '+';
        unordered_set<char> ops({'+','-','*','/'});
        for (int i = 0; i < len; i++) {
            if ('0' <= s[i] && s[i] <= '9') {
                num = num * 10 + (s[i] - '0');
            }
            if (ops.count(s[i]) || i == len-1) {
                // cout << op << ' ' << num << endl;
                if (op == '+') {
                    st.push(num);
                } else if (op == '-') {
                    st.push(-num);
                } else if (op == '*') {
                    int tmp = st.top() * num;
                    st.pop();
                    st.push(tmp);
                } else if (op == '/') {
                    int tmp = st.top() / num;
                    st.pop();
                    st.push(tmp);
                }
                op = s[i];
                num = 0;
            }
        }
        while (!st.empty()) {
            res += st.top();
            st.pop();
        }
        return res;
    }
};