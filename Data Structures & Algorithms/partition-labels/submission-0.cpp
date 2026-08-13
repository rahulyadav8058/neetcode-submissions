class Solution {
   public:
    vector<int> partitionLabels(string s) {
        int n = s.size();
        vector<int> freq(26, 0);
        for (auto e : s) {
            freq[e - 'a']++;
        }

        int i = 0;
        vector<int> ans;
        while (i < n) {
            vector<int> freq2(26, 0);
            int j = i;
            while (j < n) {
                freq2[s[j] - 'a']++;
                int q = 0;
                for (q = 0; q < 26; q++) {
                    if (freq2[q] == 0 || freq2[q] == freq[q]) {
                        continue;
                    } else {
                        break;
                    }
                }
                if (q == 26) {
                    ans.push_back(j - i + 1);
                    j++;
                    break;    
                }
                j++;
            }
            i = j;
        }
        return ans;
    }
};
