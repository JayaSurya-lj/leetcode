class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int operations = 0;
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]]++;
        }
        cout<<mp.size();
        for(int i=0;i<nums.size();i++)
        {
            if(mp.find(nums[i])!=mp.end())
            {
                mp[nums[i]]--;
                if(mp[nums[i]]==0) mp.erase(nums[i]);
                if(mp.find(k-nums[i])!=mp.end())
                {
                    operations++;
                    cout<<i<<" "<<nums[i]<<" "<<k-nums[i]<<" "<<operations<<endl;
                    
                    mp[k-nums[i]]--;
                    if(mp[k-nums[i]]==0) mp.erase(k-nums[i]);
                }
            }
        }
        return operations;
    }
};