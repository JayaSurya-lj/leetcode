class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> n2;
        for(int i=0;i<nums2.size();i++)
        {
            n2.insert(nums2[i]);
        }
        vector<int> ans;
        for(int i=0;i<nums1.size();i++)
        {
            if(n2.find(nums1[i])!=n2.end())
            {
                ans.push_back(nums1[i]);
                n2.erase(nums1[i]);
            }
        }
        return ans;
    }
};