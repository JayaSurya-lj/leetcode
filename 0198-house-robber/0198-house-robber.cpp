class Solution {
public:
    int rob(vector<int>& arr) {
        vector<int> dp(arr.size());
        dp[0] = arr[0];
        if(arr.size()>1) dp[1] = max(arr[0],arr[1]);
        for(int i=2;i<arr.size();i++){
            dp[i] = max(arr[i]+dp[i-2],dp[i-1]);
        }
        return dp[arr.size()-1];
    }
};