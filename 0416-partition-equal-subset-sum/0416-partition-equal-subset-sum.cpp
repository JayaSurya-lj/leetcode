class Solution {
public:
    bool helper(int i,vector<int>& nums,int sum,int target,vector<vector<int>>& dp){
        if(i==nums.size()){
            if(sum==target) return true;
            else return false;
        }
        if(sum==target) return true;
        if(dp[i][sum]!=-1) return dp[i][sum];
        if(sum+nums[i]>target) return dp[i][sum] = helper(i+1,nums,sum,target,dp);
        else{
            int take = helper(i+1,nums,sum+nums[i],target,dp);
            int leave = helper(i+1,nums,sum,target,dp);
            return dp[i][sum] = take || leave;
        }
    }
    bool canPartition(vector<int>& nums) {
        int totalSum = 0;
        for(int ele: nums) totalSum += ele;
        if(totalSum%2!=0) return false;
        int target = totalSum/2;
        vector<vector<int>> dp (nums.size(),vector<int> (target+1,-1));
        return helper(0,nums,0,target,dp);
        
    }
};