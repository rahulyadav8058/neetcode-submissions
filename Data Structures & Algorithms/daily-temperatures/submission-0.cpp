class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& tem) {
        int n  = tem.size();
        stack<pair<int,int>>st;
        vector<int>ans(n,0);
        for(int i=n-1;i>=0;i--){
            
            while(!st.empty() && st.top().first<=tem[i]){
                st.pop();
            }
            if(st.empty()){
                st.push({tem[i],i});
            }else {
                auto x = st.top();
                ans[i] = x.second-i;
                st.push({tem[i],i});
            }
        }
        return ans;
    }
};
