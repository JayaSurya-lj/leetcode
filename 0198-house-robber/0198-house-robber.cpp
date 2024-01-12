class Solution {
public:
    void robTheHouses(vector<int>&nums,int curr,vector<int>& mem)
    {
        if(curr<0) return;
        if(curr+2<nums.size())
        mem[curr] = nums[curr] + mem[curr+2];
        for(int i=curr+3;i<nums.size();i++)
        {
            if(i<nums.size())
            mem[curr] = max(mem[curr],nums[curr] + mem[i]);
        }
        cout<<mem[curr]<<" ";
        robTheHouses(nums,curr-1,mem);
    }
    int rob(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        if(nums.size()==2) return max(nums[0],nums[1]);
        if(nums.size()==3){
            int test = max(max(nums[0],nums[1]),nums[2]);
            int a = nums[0] + nums[2];
            int b = max(a,nums[1]);
            return max(test,b);
        }
        vector<int> mem(nums.size());
        mem[nums.size()-1] = nums[nums.size()-1];
        mem[nums.size()-2] = nums[nums.size()-2];
        cout<<mem[nums.size()-1]<<" "<<mem[nums.size()-2]<<" ";
        robTheHouses(nums,nums.size()-3,mem);
        return max(mem[0],mem[1]);
        
    }
};