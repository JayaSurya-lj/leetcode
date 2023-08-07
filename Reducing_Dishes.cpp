class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(),satisfaction.end());
        int n = satisfaction.size();
        vector<int> suffix(n);
        suffix[n-1] = satisfaction[n-1];
        for(int i=n-2;i>=0;i--)
        {
            suffix[i] = suffix[i+1]+satisfaction[i];
        }
        int req = -1;
        for(int i=0;i<n;i++)
        {
            if(suffix[i]>0)
            {
                req = i;
                break;
            }
        }
        if(req==-1) return 0;
        int sum = 0;
        int k = 1;
        for(int i=req;i<n;i++)
        {
            sum += k*satisfaction[i];
            k++;

        }
        return sum;
    }
};
