class CountSquares {
public:
    unordered_map<int,unordered_map<int,int>> pts;
    CountSquares() {
        
    }
    
    void add(vector<int> point) {
        pts[point[0]][point[1]]++;
    }
    
    int count(vector<int> point) {
        int x = point[0];
        int y = point[1];
        int cnt=0;
        for(auto ele : pts[x]){
            int y1 = ele.first;
            int freq1 = ele.second;
            int side = y1 -y;
            if(side==0)continue;

            int x1 = x-side,x2 = side+x;
            cnt += freq1*pts[x1][y]*pts[x1][y1];
            cnt += freq1 * pts[x2][y]*pts[x2][y1];
            
        }
        return cnt;
    }
};
