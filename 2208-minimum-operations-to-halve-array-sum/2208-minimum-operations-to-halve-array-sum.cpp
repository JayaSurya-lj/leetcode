class Solution {
public:
    int halveArray(vector<int>& nums) {
        priority_queue<double> pq;
        double sum = 0;
        for(int i=0;i<nums.size();i++){
            pq.push((double)nums[i]);
            sum += nums[i];
        }
        double s = sum;
        int k = 0;
        while(s>sum/2){
            double a = pq.top();
            s -= a;
            a /= 2;
            s += a;
            pq.pop();
            pq.push(a);
            k++;

        }
        return k;

        
    }
};