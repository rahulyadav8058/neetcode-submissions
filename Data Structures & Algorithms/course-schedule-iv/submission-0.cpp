
class Solution {
public:
    vector<bool> checkIfPrerequisite(
        int n, vector<vector<int>>& pre, vector<vector<int>>& q) {

        vector<vector<int>> adj(n);
        vector<vector<int>> grid(n, vector<int>(n, 0));
        vector<int> indegree(n, 0);

        for (auto p : pre) {
            adj[p[0]].push_back(p[1]);
            indegree[p[1]]++;
        }

        queue<int> que;

        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                que.push(i);
            }
        }

        while (!que.empty()) {
            int x = que.front();
            que.pop();

            for (auto a : adj[x]) {
                grid[x][a] = 1;

                for (int k = 0; k < n; k++) {
                    if (grid[k][x] == 1) {
                        grid[k][a] = 1;
                    }
                }

                indegree[a]--;
                if (indegree[a] == 0) {
                    que.push(a);
                }
            }
        }

        vector<bool> ans;

        for (auto w : q) {
            ans.push_back(grid[w[0]][w[1]] == 1);
        }

        return ans;
    }
};