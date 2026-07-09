class Solution {
public:
    string postToInfix(string &s) {
        int n = s.size();
        stack<string> st;
        int i = 0;

        while (i < n) {
            if ((s[i] >= 'A' && s[i] <= 'Z') ||
                (s[i] >= 'a' && s[i] <= 'z') ||
                (s[i] >= '0' && s[i] <= '9')) {
// this is imp yeh nect line char ko string me convert karke push karega 
                st.push(string(1, s[i]));
            }
            else {
                string fi = st.top();
                st.pop();

                string f2 = st.top();
                st.pop();

                string ans = "";
                ans = "(" + f2 + s[i] + fi + ")";
                st.push(ans);
            }
            i++;
        }

        return st.top();
    }
};