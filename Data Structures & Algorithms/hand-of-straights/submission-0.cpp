class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int k) {
        int n = hand.size();
        if(n%k)return false;
        map<int,int>freq;
        for(auto e:hand){
            freq[e]++;
        }
        while(!freq.empty()){
            int first = freq.begin()->first;

            for(int i =0;i<k;i++){
                if(freq.find(first+i)==freq.end())return false;
                freq[first+i]--;
                if(freq[first+i]==0){
                    freq.erase(first+i);
                }
            }

        }
        return true;
    }
};
