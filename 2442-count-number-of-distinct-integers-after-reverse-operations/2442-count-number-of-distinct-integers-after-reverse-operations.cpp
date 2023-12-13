class Solution {
public:
    int reverse(int n)
    {
        int r = 0;
        while(n>0)
        {
            r *= 10;
            r += (n%10);
            n/=10;
        }
        return r;
    }
    int countDistinctIntegers(vector<int>& nums) {
        unordered_set<int> s;
        for(int i=0;i<nums.size();i++)
        {
            s.insert(nums[i]);
        }
        for(int i=0;i<nums.size();i++)
        {
            int req = reverse(nums[i]);
            if(s.find(req)==s.end())
            s.insert(req);
        }
        int size = s.size();
        return size;
        
    }
};