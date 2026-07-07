class Solution {
public:
    bool isBalanced(string& s) {
        stack<char> st;
        int n = s.size();

        for (int i = 0; i < n; i++) {

            if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
                st.push(s[i]);
            }
            else {
                if (st.empty()) return false;

                if (s[i] == ')') {
                    char c = st.top();
                    st.pop();
                    if (c != '(') return false;
                }

                if (s[i] == '}') {
                    char c = st.top();
                    st.pop();
                    if (c != '{') return false;
                }

                if (s[i] == ']') {
                    char c = st.top();
                    st.pop();
                    if (c != '[') return false;
                }
            }
        }

        return st.empty();
    }
};