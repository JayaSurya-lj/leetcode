class Solution {
public:
    int reverse(int n)
    {
        int r = 0;
        while(n>0)
        {
            r *= 10;
            r += n%10;
            n /= 10;
        }
        return r;
    }
    int countNicePairs(vector<int>& nums) {
        for(int i=0;i<nums.size();i++)
        {
            nums[i] = nums[i] - reverse(nums[i]);
        }
        unordered_map<int,int> m;
        int count = 0;
        for(int i=0;i<nums.size();i++)
        {
            if(m.find(nums[i])!=m.end())
            {
                count%= 1000000007;
                count += m[nums[i]];
            }
            m[nums[i]]++;
        }

        return count % (1000000007);
        
    }
};