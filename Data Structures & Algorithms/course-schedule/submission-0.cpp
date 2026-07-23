class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& pre) {
        vector<vector<int>>adj(n);
        vector<int>indegree(n,0);
        for(int i=0;i<pre.size();i++){
            adj[pre[i][1]].push_back(pre[i][0]);
            indegree[pre[i][0]]++;
        }

    queue<int>q;
    int count=0;
    for(int i=0;i<n;i++){
        if(indegree[i]==0){
            q.push(i);
            
        }
    }
    while(!q.empty()){
        int ele = q.front();
        q.pop();
        count++;
        for(auto ad:adj[ele]){
            indegree[ad]--;
            if(indegree[ad]==0){
                q.push(ad);
            }
        }
    }
    return count==n;
    }
};
