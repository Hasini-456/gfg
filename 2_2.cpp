
class Solution {
  public:
    int findFun(int n) {
        // code here
        if(n == 0) return 2;
        if(n == 1) return 5;
        if(n == 2) return 9;
        if(n == 3) return 7;
        
        // int a, b;
        // if(n%2 == 0){
        //     a = findFun(n-2);
        //     b = findFun(n-4);
        //     return (a*(n-2))+(b*(n-4));
        // }else{
        //     a = findFun(n-1);
        //     b = findFun(n-3);
        //     return (a*(n-1))+(b*(n-3));
        // }
        int M = 1e9+7;
        vector<long long> dp(n+1, 0);
        dp[0] =2;
        dp[1] = 5;
        dp[2] = 9;
        dp[3] = 7;
        for(int i=4; i<=n; i = i+2){
            dp[i] = ((dp[i-2]*(i-2))%M + (dp[i-4]*(i-4))%M)%M;
        }
        if(n%2 == 1) dp[n]= ((dp[n-1]*(n-1))%M+(dp[n-3]*(n-3))%M)%M;
        
        return dp[n];
    }
};
