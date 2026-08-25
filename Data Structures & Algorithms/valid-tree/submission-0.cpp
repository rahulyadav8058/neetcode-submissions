class Solution {
public:
    bool dfs(vector<vector<int>>& adj, int node, int par,vector<int>& vis){
        vis[node] = 1;
        for(auto ele: adj[node]){
            if(ele == par)continue;
            if(vis[ele])return false;
            if(dfs(adj,ele,node,vis)==false)return false;
        }
        return true;
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(auto ed : edges){
            int u = ed[0];
            int v = ed[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> vis(n,0);
        bool ans = dfs(adj,0,-1,vis);
        for(int i=0;i<n;i++){
            if(vis[i]==0)return false;
        }
        return ans;

    }
};
