class Solution {
public:
    int reverse(int x) {
        string str = to_string(x);

        if (str[0] == '-') {
            std::reverse(str.begin() + 1, str.end());
        } 
        else {
            std::reverse(str.begin(), str.end());
        }

        long long num = stoll(str);

        if (num > INT_MAX || num < INT_MIN)
            return 0;

        return (int)num;
    }
};