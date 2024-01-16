class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        priority_queue<int> pq;
        int mini = INT_MAX, res = INT_MAX;
        for(auto x:nums){
            if(x%2!=0) x*= 2;
            pq.push(x);
            mini = min(mini,x);
        }
        while(true){
            int val = pq.top();
            pq.pop();
            res = min(res, val - mini);
            if(val%2 != 0) break;
            mini = min(mini, val/2);
            pq.push(val/2);
        }
        return res;
    }
};