class Solution {
public:
    double func(double x, int n ){
        if(n==1 || x==1)return x;
        if(n==0)return 1;
        if(!n%2){
           return func(x,n/2) * func(x,n/2);
        }
        else{
            return func(x,n-1)*x;
        }

    }
    double myPow(double x, int n) {
        
        if(n==0)return 1;
        if(x== -1 && n%2)return -1;
        if(x==-1)return 1;
        if(n==INT_MIN)return 0;
        if(n<0){
            return 1/func(x,abs(n));
        }
        return func(x,n);
    }
};
