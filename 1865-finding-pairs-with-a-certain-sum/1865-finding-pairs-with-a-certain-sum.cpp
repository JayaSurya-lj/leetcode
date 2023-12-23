class FindSumPairs {
public:
    vector<int> v1;
    vector<int> v2;
    unordered_map<int,int> mp1;
    unordered_map<int,int> mp2;

    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        this->v1 = nums1;
        this->v2 = nums2;
        for(int i=0;i<nums1.size();i++)
        {
            mp1[nums1[i]]++;
        }
        for(int i=0;i<nums2.size();i++)
        {
            mp2[nums2[i]]++;
        }
        
    }
    
    void add(int index, int val) {
        mp2[v2[index]]--;
        if(mp2[v2[index]]==0) mp2.erase(v2[index]);
        v2[index] += val;
        mp2[v2[index]]++;
        
    }
    
    int count(int tot) {
        int c = 0;
        for(int i=0;i<v1.size();i++)
        {
            if(mp2.find(tot-v1[i])!=mp2.end())
            {
                c+=mp2[tot-v1[i]];
            }

        }
        return c;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */