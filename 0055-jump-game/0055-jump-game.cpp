class Solution {
public:
    bool helper(vector<int>& nums,vector<int>& dp,int i){
        if(i>=nums.size()-1) return true;
        if(dp[i]!=-1) return dp[i];
        bool flag = false;
        if(nums[i]>=nums.size()-1-i) return true;
        for(int j=1;j<=nums[i];j++){
            flag = flag || helper(nums,dp,i+j);
            if(flag) break;
        }
        return dp[i] = flag;
    }
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,-1);
        return helper(nums,dp,0);
    }
};