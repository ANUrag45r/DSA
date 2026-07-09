class Solution {
  private:
    int priority(char c) {
        if (c == '^') return 3;
        if (c == '*' || c == '/') return 2;
        if (c == '+' || c == '-') return 1;
        else return -1;
    }

  public:
    string infixToPrefix(string &s) {
        // code here
        // 1. reverse the string
        reverse(s.begin(), s.end());

        int n = s.size();

        for (int i = 0; i < n; i++) {
            if (s[i] == '(')
                s[i] = ')';
            else if (s[i] == ')')
                s[i] = '(';
        }

        // 2. actual infix to postfix
        int i = 0;
        string ans = "";
        stack<char> st;

        while (i < n) {
            if ((s[i] >= 'A' && s[i] <= 'Z') ||
                (s[i] >= 'a' && s[i] <= 'z') ||
                (s[i] >= '0' && s[i] <= '9')) {
                ans += s[i];
            }
            else if (s[i] == '(') {
                st.push(s[i]);
            }
            else if (s[i] == ')') {
                while (!st.empty() && st.top() != '(') {
                    ans += st.top();
                    st.pop();
                }
               
            }
            else {
                if (s[i] == '^') {
                    while (!st.empty() && priority(s[i]) >= priority(st.top())) {
                        ans += st.top();
                        st.pop();
                    }
                }
                else {
                    while (!st.empty() && priority(s[i]) < priority(st.top())) {
                        ans += st.top();
                        st.pop();
                    }
                }
                st.push(s[i]);
            }
            i++;
        }

        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }

        // step 3: reverse the string
        reverse(ans.begin(), ans.end());

        for (int i = 0; i < n; i++) {
            if (s[i] == '(')
                s[i] = ')';
            else if (s[i] == ')')
                s[i] = '(';
        }

        return ans;
    }
};