class Solution {
public:
    void func(int i,int o,vector<string>& ans, string temp){
        if(i ==0 && o==0){
            ans.push_back(temp);
            return;
        }
        if(i>0){
            temp += "(";
            func(i-1,o+1,ans,temp);
            temp.pop_back();
        }
        if(o>0){
            temp += ")";
            func(i,o-1,ans,temp);
            temp.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string temp;
        func(n,0,ans,temp);
        return ans;
    }
};
