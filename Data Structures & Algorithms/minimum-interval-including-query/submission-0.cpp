class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals,
                            vector<int>& queries) {

        int n = queries.size();

        // {query value, original index}
        vector<pair<int, int>> q;

        for (int i = 0; i < n; i++) {
            q.push_back({queries[i], i});
        }

        sort(q.begin(), q.end());
        sort(intervals.begin(), intervals.end());

        // {interval size, end}
        priority_queue<pair<int, int>,
                       vector<pair<int, int>>,
                       greater<pair<int, int>>> pq;

        vector<int> ans(n, -1);

        int j = 0;
        int m = intervals.size();

        for (auto [query, index] : q) {

            // Add all intervals that start <= query
            while (j < m && intervals[j][0] <= query) {

                int start = intervals[j][0];
                int end = intervals[j][1];

                int size = end - start + 1;

                pq.push({size, end});

                j++;
            }

            // Remove intervals that don't contain query
            while (!pq.empty() && pq.top().second < query) {
                pq.pop();
            }

            // Smallest valid interval
            if (!pq.empty()) {
                ans[index] = pq.top().first;
            }
        }

        return ans;
    }
};