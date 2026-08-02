class Solution {
  public:
    string preToInfix(string s) {
        // Write your code here
        int n = s.size();
        stack<string> st;
        int i = n-1;
        while(i>=0){
            if((s[i]>='A'&&s[i]<='Z')||
               (s[i]>='a'&&s[i]<='z')||
               (s[i]>='0'&&s[i]<='9')
            ){
                st.push(string(1,s[i]));
            }
            else{
               string f1 = st.top();
               st.pop();
               string f2 = st.top();
               st.pop();
               string ans = "";
               ans = "(" + f1 + s[i] + f2 +")";
               st.push(ans);
            }
            i--;
        }
        return st.top();
    }
}