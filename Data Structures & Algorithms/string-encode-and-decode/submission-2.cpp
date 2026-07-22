class Solution {
public:
    string encode(vector<string>& strs) {
        string ans = "";

        for (string s : strs) {
            ans += to_string(s.size());
            ans += '#';
            ans += s;
        }

        return ans;
    }

    vector<string> decode(string s) {
        vector<string> ans;
        int i = 0;

        while (i < s.size()) {
            int len = 0;

            while (i < s.size() && s[i] != '#') {
                len = len * 10 + (s[i] - '0');
                i++;
            }

            i++; 

            string temp = "";
            for (int j = 0; j < len; j++) {
                temp += s[i];
                i++;
            }

            ans.push_back(temp);
        }

        return ans;
    }
};