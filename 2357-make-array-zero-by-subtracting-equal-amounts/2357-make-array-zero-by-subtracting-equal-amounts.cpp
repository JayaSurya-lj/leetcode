class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int count = 0;
        unordered_set<int> s;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=0)
            s.insert(nums[i]);
        }
        return s.size();  
    }
};