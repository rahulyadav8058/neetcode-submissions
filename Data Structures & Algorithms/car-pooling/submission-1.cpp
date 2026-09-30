class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int cap) {
        int n = trips.size();

        vector<pair<int, int>> start;
        vector<pair<int, int>> end1;

        for (int i = 0; i < n; i++) {
            start.push_back({trips[i][1], trips[i][0]});
            end1.push_back({trips[i][2], trips[i][0]});
        }

        sort(start.begin(), start.end());
        sort(end1.begin(), end1.end());

        int i = 0;

        for (int j = 0; j < n; j++) {

            int x = start[j].first;

            while (i < j && end1[i].first <= x) {
                cap += end1[i].second;
                i++;
            }

            cap -= start[j].second;

            if (cap < 0)
                return false;
        }

        return true;
    }
};