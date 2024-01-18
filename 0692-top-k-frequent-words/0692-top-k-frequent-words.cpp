    struct compare{
        bool operator()(pair<int,string>& a,pair<int,string>& b){
            if(a.first==b.first)
                return a.second > b.second; //sort assending 
            return a.first<b.first; //sorts descending 
        }
    };
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string,int> mp;
        for(int i=0;i<words.size();i++){
            mp[words[i]]++;
        }
        priority_queue<pair<int,string>, vector<pair<int,string>>,compare> pq;
        for(auto p:mp){
            string word = p.first;
            int freq = p.second;
            pq.push({freq,word});
        }
        vector<string> ans;
        while(k--){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        for(int i=0;i<ans.size();i++)
        {
            for(int j=i+1;j<ans.size();j++){
                if(mp[ans[i]]<mp[ans[j]]){
                    string temp = ans[i];
                    ans[i] = ans[j];
                    ans[j] = temp;
                }
                else if(mp[ans[i]]==mp[ans[j]]){
                    if(ans[i]>ans[j]){
                        string temp = ans[i];
                        ans[i] = ans[j];
                        ans[j] = temp;

                    }
                }
            }
        }
        return ans;
    }
};