class Solution {
public:
    int helper(vector<int>& nums, vector<int>& dp, int i) {
        if (i >= nums.size() - 1) return 0;
        if (dp[i] != -1) return dp[i];

        int ans = INT_MAX - 1;
        for (int j = 1; j <= nums[i]; j++) {
            ans = min(ans, 1 + helper(nums, dp, i + j));
        }

        return dp[i] = ans;
    }
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,-1);
        return helper(nums,dp,0);
        
    }
};