class Solution {
public:
    bool canpossible(vector<int>&piles,int s,int h){
        int count =0;
        for(int i=0;i<piles.size();i++){
            count += piles[i]/s;
            if(piles[i]%s>0)count++;
        }
        return count<=h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n =piles.size();
        int sum = *max_element(piles.begin(),piles.end());
        int left =1 ,right =sum;
        int ans =sum;
        while(left<=right){
            int mid = left +(right-left)/2;
            if(canpossible(piles,mid,h)){
                ans = min(ans,mid);
                right = mid-1;
            }else{
                left = mid+1;
            }
        }
        return ans;
    }
};
