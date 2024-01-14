class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> pq;
    int k;
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        int i=0;
        for(i=0;i<k && i<nums.size();i++)
        {
            pq.push(nums[i]);
        }
        while(i<nums.size()){
            if(pq.top()<nums[i]){
                pq.pop();
                pq.push(nums[i]);
            }
            i++;
        }
    }
    
    int add(int val) {
        if(pq.size()<k){
            pq.push(val);
        }
        else if(pq.top()<val){
            pq.pop();
            pq.push(val);
        }
        return pq.top();
        
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */