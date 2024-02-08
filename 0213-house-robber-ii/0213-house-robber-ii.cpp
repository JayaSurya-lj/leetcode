class Solution {
public:
    int rob(vector<int>& arr) {
        if(arr.size()==1) return arr[0];
        vector<int> dp(arr.size());
        dp[0] = arr[0];
        if(arr.size()>1) dp[1] = max(arr[0],arr[1]);
        for(int i=2;i<arr.size()-1;i++){
            dp[i] = max(arr[i]+dp[i-2],dp[i-1]);
        }
        int max1 = dp[arr.size()-2];
        dp[1] = arr[1];
        if(arr.size()!=2) dp[2] = max(arr[1],arr[2]);
        for(int i=3;i<arr.size();i++){
            dp[i] = max(arr[i]+dp[i-2],dp[i-1]);
        }
        int max2 = dp[arr.size()-1];

        return max(max1,max2);
        
    }
};