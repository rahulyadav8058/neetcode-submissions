class Solution {
public:
    
    bool checkValidString(string s) {
        int mini =0,maxi =0;
        //int count =0,c2=0;
        for(int i =0;i<s.size();i++){
            if(s[i] =='('){
                maxi++;
                mini++;
            }
            else if(s[i]==')'){
                mini--;
                maxi--;
            }else{
                maxi++;
                mini--;
            }
            if(maxi<0)return false;
            if(mini<0)mini=0;
        }
        return mini==0;
    }
};
