class FreqStack {
    priority_queue<pair<int,pair<int,int>>> pq;
    unordered_map<int,int>mpp;
    int counter =0;
public:

    FreqStack() {
        counter =0;
    }
    
    void push(int val) {
        if(mpp.find(val)!=mpp.end()){
            pq.push({mpp[val]+1,{counter,val}});
            mpp[val]++;
        }else{
            pq.push({1,{counter,val}});
            mpp[val] =1;
        }
        counter++;
    }
    
    int pop() {
        int x = pq.top().second.second;
        pq.pop();
        mpp[x]--;
        return x;
        }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */