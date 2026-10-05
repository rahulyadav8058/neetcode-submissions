class Solution {
   public:
    int numRescueBoats(vector<int>& people, int limit) {
        int n = people.size();
        sort(people.begin(), people.end());
        int ans = 0;
        int j = 0;
        for (int i = n - 1; i >= j; i--) {
            if (people[j] + people[i] <= limit) {
                j++;
            }
            ans++;
        }
        return ans;
    }
};