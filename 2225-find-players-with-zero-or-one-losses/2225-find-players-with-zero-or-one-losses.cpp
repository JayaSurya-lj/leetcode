class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<int,int> winner;
        map<int,int> loser;
        for(int i=0;i<matches.size();i++){
            winner[matches[i][0]]++;
            loser[matches[i][1]]++;
        }
        vector<vector<int>> ans;
        vector<int> a;
        vector<int> b;
        for(auto p:winner){
            int person = p.first;
            int freq = p.second;
            if(loser.find(person)==loser.end()){
                a.push_back(person);
            }
        }
        for(auto p:loser){
            if(p.second==1){
                b.push_back(p.first);
            }
        }
        ans.push_back(a);
        ans.push_back(b);

        return ans;
        
    }
};