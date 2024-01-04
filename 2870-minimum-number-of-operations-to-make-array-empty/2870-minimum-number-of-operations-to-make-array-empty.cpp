class Solution {
public:
    int minOperations(vector<int>& nums) {
        map<int,int> mp;
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]]++;
        }
        int sum = 0;
        for(auto p:mp)
        {
            int freq = p.second;
            if(freq<2) return -1;
            while(freq>0)
            {
                if(freq%3==0)
                {
                    freq -= 3;
                    sum++;
                }
                else
                {
                    freq -= 2;
                    sum++;

                }
            }
        }
        return sum;
    }
};