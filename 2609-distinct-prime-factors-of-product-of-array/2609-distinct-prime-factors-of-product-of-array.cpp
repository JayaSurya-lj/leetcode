class Solution {
public:
    bool isPrime(int n)
    {
        if(n==1) return false;
        for(int i=2;i<=sqrt(n);i++)
        {
            if(n%i==0) return false;
        }
        return true;
    }
    int distinctPrimeFactors(vector<int>& nums) {
        int n = nums.size();
        int x = INT_MIN;
        for(int i=0;i<n;i++)
        {
            if(x<nums[i])
            {
                x = nums[i];
            }
        }
        int count = 0;
        vector<int> v;
        for(int i=2;i<=x;i++)
        {
            if(isPrime(i))
            {
                v.push_back(i);
            }
        }
        for(int i=0;i<v.size();i++)
        {
            bool flag = true;
            for(int j=0;j<nums.size();j++)
            {
                if(nums[j]%v[i]==0)
                {
                    flag = false;
                    break;
                }
            }
            if(flag==false) count++;
        }
        return count;
        
    }
};