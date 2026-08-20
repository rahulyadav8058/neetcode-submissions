class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n  = gas.size();
        int gas_sum =0;
        int cost_sum =0;
        for(int i =0;i<n;i++){
            gas_sum += gas[i];
            cost_sum += cost[i];
        }
        if(cost_sum>gas_sum)return -1;
        int total =0;
        int ind =0;
        for(int i =0;i<n;i++){
            total += gas[i] - cost[i];
            if(total<0){
                ind = i+1;
                total =0;
            }
        }
        return ind;
    }
};