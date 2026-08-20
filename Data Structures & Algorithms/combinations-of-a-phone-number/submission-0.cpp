class Solution {
public:
    vector<string> mpp = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

    void func(int ind, string digits, string temp, vector<string>& ans) {
        if(ind == digits.size()) {
            ans.push_back(temp);
            return;
        }

        string s = mpp[digits[ind] - '0'];

        for(int i = 0; i < s.size(); i++) {
            temp.push_back(s[i]);

            func(ind + 1, digits, temp, ans);

            temp.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        vector<string> ans;

        if(digits.empty()) return ans;

        func(0, digits, "", ans);

        return ans;
    }
};