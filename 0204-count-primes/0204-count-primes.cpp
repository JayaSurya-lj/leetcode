class Solution {
public:
    void fillSieve(vector<bool>& sieve) // pass by reference &
    {
        int n = sieve.size()-1;
        for(int i=2;i<=sqrt(n);i++)
        {
            if(sieve[i])
            {
                for(int j=i*2;j<=n;j+=i)
                {
                    sieve[j] = 0;
                }
            }

        }
        return;

    }
    int countPrimes(int n) {
        if(n<=2) return 0;
        n = n-1;
        int count = 0;
        vector<bool> sieve(n+1,1); //has all numbers marked as prime
        fillSieve(sieve); // to perform sieve of eratosthenes algorithm
        sieve[0] = 0; // since 0 is not a prime
        sieve[1] = 0; // since 1 is not a prime
        for(int i=2;i<=n;i++)
        {
            if(sieve[i]==1) count++;
        }
        return count;
        
        
    }
};