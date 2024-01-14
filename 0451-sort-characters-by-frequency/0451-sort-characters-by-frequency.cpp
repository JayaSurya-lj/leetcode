class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> mp;
        for(int i=0;i<s.size();i++){
            mp[s[i]]++;
        }
        priority_queue<pair<int,char>> pq;
        for(auto p:mp){
            int key = p.first;
            int val = p.second;
            pq.push({val,key});
        }
        string ans = "";
        while(!pq.empty()){
            int freq = pq.top().first;
            char ch = pq.top().second;
            pq.pop();
            for(int i=1;i<=freq;i++){
                ans += ch;
            }
        }
        return ans;

    }
};