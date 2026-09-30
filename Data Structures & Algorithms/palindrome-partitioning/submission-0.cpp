class Solution {
public:
    bool pali(string s,int i,int j){
        while(i<=j){
            if(s[i]!=s[j]){return false;}
            i++;j--;
        }
        return true;
    }
    void func(string s, int start,int end,vector<string>& temp,vector<vector<string>>&ans){
        if(end==s.size()){
            int count=0;
            for(int i=0;i<temp.size();i++){
                count += temp[i].size();
            }
            if(count==s.size()){
                ans.push_back(temp);
            }
            return ;
        }

        if(pali(s,start,end)){
            string t = "";
            for(int k =start;k<=end;k++){
                t += s[k];
            }
            temp.push_back(t);
            func(s,end+1,end+1,temp,ans);
            temp.pop_back();
        }
        func(s,start,end+1,temp,ans);
        
    }
    vector<vector<string>> partition(string s) {
        vector<string> temp;
        vector<vector<string>>ans;
        func(s,0,0,temp,ans);
        return ans;
    }
};