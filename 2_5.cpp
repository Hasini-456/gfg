// User function Template for C++

class Solution {
  public:
        //return max(maxBeauty(j+1, N, K, B), B[j]+maxBeauty(j+2, N, K-1, B));
        //this is main idea,so, a dp table, dp[j][k] -- j : 0 to N-1, K = 0 to K;


    long long maximumBeauty(int N, int K, vector<int> &B) {
        // code here
        vector<vector<long long>> dp(N+2, vector<long long>(K+1, -1));
        
        for(int i=0; i<=N; i++){
            dp[i][0] = 0;
        }
        
        long long sum = 0;
        for(int k=1; k<=K; k++){
            int index = N-2*k+1;
            if(index >= 0){
                sum += B[index];
                dp[index][k] = sum;
            }
        }
        
        for(int k = 1; k<=K; k++){
            for(int i = N -2*k; i>=0; i--){
                long long take, skip;
                take = skip = -1;
                skip = dp[i+1][k];
                
                if(dp[i+2][k-1] != -1){
                    take = B[i]+dp[i+2][k-1];
                }
                
                dp[i][k] = max(skip, take);
            }
        }
        return dp[0][K];

    }
};
