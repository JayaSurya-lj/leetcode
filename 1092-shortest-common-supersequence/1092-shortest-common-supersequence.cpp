class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int m = str1.size();
        int n = str2.size();
        vector<vector<int>> dp (m+1, vector<int>(n+1,0));
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(str1[i-1]==str2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else{
                    int p1 = dp[i-1][j];
                    int p2 = dp[i][j-1];
                    dp[i][j] = max(p1,p2);
                }
            }
        }
        string lcs = "";
        int i = m, j = n;
        while(i>0 && j>0){
            if(str1[i-1]==str2[j-1]){
                lcs = lcs + str1[i-1];
                i--;
                j--;
            }
            else{
                if(dp[i-1][j]>=dp[i][j-1]){
                    i--;
                }
                else{
                    j--;
                }
            }
        }
        reverse(lcs.begin(),lcs.end());
        i=0,j=0;
        string ans = "";
        for(int k=0;k<lcs.size();k++){
            while(str1[i]!=lcs[k]){
                ans += str1[i++];
            }
            i++;
            while(str2[j]!=lcs[k]){
                ans += str2[j++];
            }
            j++;
            ans += lcs[k];
        }
        while(i<m){
            ans += str1[i++];
        }
        while(j<n){
            ans += str2[j++];
        }
        return ans;
        
    }
};