class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int max_len =0;
        string ans ="";
        for(int i =0;i<n;i++){
            int j =i;
            int k=i;
            // int len =0;
            while(j>=0 && k<n && s[j] == s[k]){
                j--;k++;
                if(k-j>max_len){
                    max_len = k-j-1;
                    ans = s.substr(j+1,k-j-1);
                }
            }
            j=i;
            k=i+1;
            while(j>=0 && k<n && s[j] == s[k]){
                j--;k++;
                if(k-j>max_len){
                    max_len = k-j-1;
                    ans = s.substr(j+1,k-j-1);
                }
            }

        }
        return ans;
    }
};
