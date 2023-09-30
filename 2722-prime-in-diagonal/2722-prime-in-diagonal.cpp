class Solution {
public:
    bool isPrime(int n)
    {
        if(n==1) return false;
        for(int i=2;i<=sqrt(n);i++)
        {
            if(n%i==0)
            {
                return false;
            }
        }
        return true;
    }
    int diagonalPrime(vector<vector<int>>& nums) {
        int n = nums.size();
        int m = nums[0].size();
        int maxs = 0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==j||i+j==n-1)
                {
                    if(isPrime(nums[i][j]))
                    {
                       maxs = max(nums[i][j],maxs);
                    }
                }
            }
        }
        return maxs;
    }
};