class Solution {
   public:
    bool checkInclusion(string s1, string s2) {
        vector<int> freq1(26, 0);
        vector<int> freq2(26, 0);
        int c = 0;

        for (auto ele : s1) {
            freq1[ele - 'a']++;
            if (freq1[ele - 'a'] == 1) c++;
        }

        int count = 0;
        int j = 0;
        for (int i = 0; i < s2.size(); i++) {
            int x = s2[i] - 'a';
            freq2[x]++;

            if (freq2[x] == freq1[x]) {
                count++;
            }

            while (j <= i && freq2[x] > freq1[x]) {
                // count = 0;
                int y = s2[j] - 'a';

                if (freq2[y] == freq1[y]) count--;
                freq2[y]--;
                j++;
            }
            
            if (count == c) return true;
        }
        return false;
    }
};
