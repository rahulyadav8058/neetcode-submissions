class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> hash, windows;

        for (char c : t)
            hash[c]++;

        int have = 0;
        int need = hash.size();

        int l = 0;
        int start = -1;
        int minLen = INT_MAX;

        for (int i = 0; i < s.size(); i++) {
            windows[s[i]]++;

            if (hash.count(s[i]) && windows[s[i]] == hash[s[i]])
                have++;

            while (have == need) {
                if (i - l + 1 < minLen) {
                    minLen = i - l + 1;
                    start = l;
                }

                windows[s[l]]--;

                if (hash.count(s[l]) && windows[s[l]] < hash[s[l]])
                    have--;

                l++;
            }
        }

        if (start == -1)
            return "";

        return s.substr(start, minLen);
    }
};