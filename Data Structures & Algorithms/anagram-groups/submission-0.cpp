class Solution {
   public:
    vector<vector<string>> groupAnagrams(vector<string>& s) {
        vector<vector<string>> ans;
        int n = s.size();
        vector<int> vis(n, 0);
        for (int i = 0; i < n; i++) {
            // string temp = strs[i];
            if (vis[i]) continue;
            vector<string> tem;
            tem.push_back(s[i]);

            sort(s[i].begin(), s[i].end());

            for (int j = i + 1; j < n; j++) {
                string temp = s[j];
                if (vis[j] == 0) {
                    sort(s[j].begin(), s[j].end());
                    if (s[j] == s[i]) {
                        vis[j]++;
                        tem.push_back(temp);
                    }
                }
                s[j] = temp;
            }
            ans.push_back(tem);
        }
        return ans;
    }
};
