class Solution {
public:
    int minimumDeleteSum(string text1, string text2) {
        int m = text1.size();
        int n = text2.size();
        vector<vector<int>>dp(m+1,vector<int>(n+1,0));
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(text1[i-1]==text2[j-1]) dp[i][j] = static_cast<int>(text1[i-1]) + dp[i-1][j-1];
                else{
                    int p1 = dp[i-1][j];
                    int p2 = dp[i][j-1];
                    dp[i][j] = max(p1,p2);
                }
            }
        }
        int sum = 0;
        for (int i = 0; i < m; ++i) {
            sum += static_cast<int>(text1[i]);
        }

        for (int j = 0; j < n; ++j) {
            sum += static_cast<int>(text2[j]);
        }

        return sum - 2*(dp[m][n]);
          
    }
};