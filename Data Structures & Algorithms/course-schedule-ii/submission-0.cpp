class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& pre) {
        vector<vector<int>>adj(n);
        vector<int>indegree(n,0);

        for(int i =0;i<pre.size();i++){
            adj[pre[i][1]].push_back(pre[i][0]);
            indegree[pre[i][0]]++;
        }

        queue<int>q;
        vector<int>ans; 

        for(int i =0;i<n;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int x = q.front();
            ans.push_back(x);
            q.pop();
            for(auto ele : adj[x]){
                indegree[ele] --;
                if(indegree[ele]==0){
                    q.push(ele);
                }
            }
        }
        if (ans.size() == n )return  ans ;
        return  {};
    }
};
