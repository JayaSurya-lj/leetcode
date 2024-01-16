class Solution {
public:
    string reorganizeString(string s) {
        int n = s.size();
        priority_queue<pair<int,char>> pq;
        unordered_map<char,int> mp;
        for(char i:s){
            mp[i]++;
            if(mp[i]*2>n+1) return "";
        }
        for(auto p:mp)
        {
            char key = p.first;
            int freq = p.second;
            pq.push({freq,key});
        }
        string ans(n,'?');
        int curr = 0;
        while(pq.size()){
            auto temp = pq.top();
            pq.pop();
            int p = temp.first;
            while(p--){
                ans[curr] = temp.second;
                curr += 2;
                if(curr>=n){
                    curr = 1;
                }
            }
        }
        return ans;
    }
};