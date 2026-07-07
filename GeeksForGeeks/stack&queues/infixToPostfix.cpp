class Solution {
public:
//use stack
    int priority(char c)
    {
        if(c == '^') return 3;
        if(c == '*' || c == '/') return 2;
        if(c == '+' || c == '-') return 1;
        return -1;
    }

    string infixToPostfix(string &s) {

        stack<char> st;
        string ans = "";

        for(int i = 0; i < s.size(); i++)
        {
            char ch = s[i];

            if(isalnum(ch))
            {
                ans += ch;
            }

            else if(ch == '(')
            {
                st.push(ch);
            }

            else if(ch == ')')
            {
                while(!st.empty() && st.top() != '(')
                {
                    ans += st.top();
                    st.pop();
                }
                st.pop();     
            }

          
            else
            {
                while(!st.empty() &&
                     ((priority(ch) < priority(st.top())) ||
                     (priority(ch) == priority(st.top()) && ch != '^')))
                {
                    ans += st.top();
                    st.pop();
                }

                st.push(ch);
            }
        }

        while(!st.empty())
        {
            ans += st.top();
            st.pop();
        }

        return ans;
    }
};