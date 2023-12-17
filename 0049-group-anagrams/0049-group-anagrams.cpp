class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> mp;
        for(int i=0;i<strs.size();i++)
        {
            string check = strs[i];
            sort(check.begin(),check.end());
            mp[check].push_back(strs[i]);
        }
        vector<vector<string>> ans;
        for(auto p:mp)
        {
            vector<string> v = p.second;
            ans.push_back(v);

        }
        return ans;
        
    }
};