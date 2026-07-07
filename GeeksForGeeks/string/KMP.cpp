class Solution {
public:
    vector<int> search(string &pat, string &txt) {
        vector<int> ans;

        int m = pat.size();
        int n = txt.size();

        vector<int> lsp(m, 0);

        int length = 0;
        int i = 1;

        while (i < m) {
            if (pat[i] == pat[length]) {
                length++;
                lsp[i] = length;
                i++;
            } else {
                if (length != 0) {
                    length = lsp[length - 1];
                } else {
                    lsp[i] = 0;
                    i++;
                }
            }
        }

        i = 0;
        int j = 0;

        while (i < n) {
            if (txt[i] == pat[j]) {
                i++;
                j++;
            }

            if (j == m) {
                ans.push_back(i - j );   
                j = lsp[j - 1];
            }
            else if (txt[i] != pat[j]) {
                if (j != 0) {
                    j = lsp[j - 1];
                } else {
                    i++;
                }
            }
        }

        return ans;
    }
};