class Solution {
public:
    bool checkPerfectNumber(int num) {
        int sum = 0;
        for(int i=1;i<sqrt(num);i++)
        {
            if(num%i==0)
            {
                sum+=i;
            }
        }
        for(int i=sqrt(num);i>=1;i--)
        {
            if(num%i==0)
            {
                if(num/i!=num)
                sum+=(num/i);
            }
        }
        cout<<sum;
        if(sum==num)
        {
            return true;
        }
        else
        {
            return false;
        }
        
    }
};