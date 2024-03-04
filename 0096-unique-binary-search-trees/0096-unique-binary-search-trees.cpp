class Solution {
public:
    int numTrees(int n) {
        // CATALAN NUMBER
        if(n==0||n==1) return 1;
        vector<int> dp(n+1,0);
        dp[0] = 1;
        dp[1] = 1;
        for(int i=2;i<=n;i++){
            int m = i-1;
            int n = 0;
            while(m>=0){
                dp[i] += (dp[m]*dp[n]);
                m--;
                n++;
            }
        }
        return dp[n];
    }
};