class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        vector<int> ans;
        int dup = -1;
        int miss = -1;
        for(int i=1;i<=nums.size();i++){
            if(mp.find(i)!=mp.end()){
                if(mp[i]==2){
                    dup = i;
                }
            }
            else{
                miss = i;
            }
        }
        ans.push_back(dup);
        ans.push_back(miss);
        return ans;
        
    }
};