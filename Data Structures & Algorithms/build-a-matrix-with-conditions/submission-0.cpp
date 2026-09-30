class Solution {
public:
    vector<int> topo(vector<vector<int>>& adj, vector<int>& inorder) {
        queue<int> q;
        int n = adj.size();

        for (int i = 1; i < n; i++) {
            if (inorder[i] == 0) {
                q.push(i);
            }
        }

        vector<int> ans;

        while (!q.empty()) {
            int ele = q.front();
            q.pop();

            ans.push_back(ele);

            for (auto e : adj[ele]) {
                inorder[e]--;

                if (inorder[e] == 0) {
                    q.push(e);
                }
            }
        }

        return ans;
    }

    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowC,
                                    vector<vector<int>>& colC) {

        vector<vector<int>> adj1(k + 1);
        vector<vector<int>> adj2(k + 1);

        vector<int> inorder1(k + 1, 0);
        vector<int> inorder2(k + 1, 0);

        for (int i = 0; i < rowC.size(); i++) {
            adj1[rowC[i][0]].push_back(rowC[i][1]);
            inorder1[rowC[i][1]]++;
        }

        vector<int> order1 = topo(adj1, inorder1);

        if (order1.size() != k)
            return {};

        for (int i = 0; i < colC.size(); i++) {
            adj2[colC[i][0]].push_back(colC[i][1]);
            inorder2[colC[i][1]]++;
        }

        vector<int> order2 = topo(adj2, inorder2);

        if (order2.size() != k)
            return {};

        vector<vector<int>> ans(k, vector<int>(k, 0));

        unordered_map<int, int> mpp;
        unordered_map<int, int> mpp2;

        for (int i = 0; i < order1.size(); i++) {
            mpp[order1[i]] = i;
        }

        for (int i = 0; i < order2.size(); i++) {
            mpp2[order2[i]] = i;
        }

        for (int i = 1; i <= k; i++) {
            ans[mpp[i]][mpp2[i]] = i;
        }

        return ans;
    }
};