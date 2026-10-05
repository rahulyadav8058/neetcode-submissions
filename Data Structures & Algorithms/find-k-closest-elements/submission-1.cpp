class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        // priority_queue<pair<int,int>>pq;
        // for(int  i =0;i<arr.size();i++){
        //     pq.push({abs(arr[i] - x),arr[i]});
        //     if(pq.size()>k)pq.pop();
        // }
        // vector<int>ans;
        // while(!pq.empty()){
        //     ans.push_back(pq.top().second);
        //     pq.pop();
        // }
        // sort(ans.begin(),ans.end());
        int  i=0;
        int j = arr.size()-1;
        while(j-i+1>k){
            if(abs(arr[i]-x)>abs(arr[j]-x)){
                i++;
            }else{j--;}
        }
        return vector<int>(arr.begin() + i, arr.begin() + j+1);
    }
};