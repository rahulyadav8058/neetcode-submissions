class Solution {
public:
    bool isHappy(int n) {
        unordered_map<int,int>mpp;
        mpp[n] =1;
        if(n==1)return true;
        while(true){
            int temp =0;
            while(n!=0){
                temp += pow(n%10,2);
                n = n/10;
            }
            if(mpp.count(temp))return false;
            if(temp ==1)return true;
            mpp[temp] = 1;
            n = temp;
        }
        return false;
    }
};
