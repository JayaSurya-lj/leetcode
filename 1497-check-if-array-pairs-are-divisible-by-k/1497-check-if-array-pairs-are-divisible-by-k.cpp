class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        unordered_map<int,int> mp;
        for(int ele:arr)
        {
            int e;
            if(ele>=0)
            e = ele%k;
            else e = (k + (ele%k))%k;
            mp[e]++;
        }
        for(auto p:mp)
        {
            int key = p.first;
            int value = p.second;
            int rem = k-key;
            if(key==0)
            {
                if(value%2!=0) return false;
            }
            else if(mp.find(rem)==mp.end()) return false;
            else
            {
                int freq = mp[rem];
                if(value!=freq) return false;
            }
        }
        return true;
    }
};