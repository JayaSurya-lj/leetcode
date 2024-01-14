#define pp pair<int,pair<int,int>>
class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {  
        priority_queue<pp, vector<pp>, greater<pp>> pq;
        for(int i=0;i<nums1.size();i++)
        {
            pq.push({nums1[i]+nums2[0], {i,0}});
        }
        pp ans;
        vector<vector<int>> res;
        while(k-- && !pq.empty()){
            ans = pq.top();
            pq.pop();
            int sum = ans.first;
            int a = ans.second.first;
            int b = ans.second.second;
            res.push_back({nums1[a],nums2[b]});
            if(b+1<nums2.size()){
                pq.push({nums1[a]+nums2[b+1], {a,b+1}});
            }
        }
        return res;
    }
};