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
    int minSteps(int n) {
        if(n==1) return 0;
        if(isPrime(n)) return n;
        int hf = -1;
        for(int i=n/2;i>=2;i--)
        {
            if(n%i==0)
            {
                hf = i;
                break;
            }
        }
        return (n/hf) + minSteps(hf);
    }
};