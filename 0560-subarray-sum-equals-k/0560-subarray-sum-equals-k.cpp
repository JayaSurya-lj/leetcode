class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        vector<int> pre;
        pre.push_back(nums[0]);
        for(int i=1;i<nums.size();i++)
        {
            pre.push_back(pre[i-1]+nums[i]);
        }
        int count = 0;
        unordered_map<int,int> m;
        for(int i=0;i<pre.size();i++)
        {
            if(pre[i]==k)
            {
                count++;
            }
            int rem = pre[i] - k;
            if(m.find(rem)!=m.end()) count+=m[rem];
            m[pre[i]]++;
            
        }
        return count;
        
    }
};