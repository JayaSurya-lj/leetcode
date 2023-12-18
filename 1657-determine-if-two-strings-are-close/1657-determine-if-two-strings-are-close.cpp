class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if(word1.size()!=word2.size()) return false;
        unordered_map<char,int> mp1;
        for(int i=0;i<word1.size();i++)
        {
            mp1[word1[i]]++;
        }
        unordered_map<char,int> mp2;
        for(int i=0;i<word2.size();i++)
        {
            if(mp1.find(word2[i])==mp1.end()) return false;
            mp2[word2[i]]++;
        }
        unordered_map<int,int> freq1;
        for(auto p:mp1)
        {
            int freq = p.second;
            freq1[freq]++;
        }
        unordered_map<int,int> freq2;
        for(auto p:mp2)
        {
            int freq = p.second;
            freq2[freq]++;
        }
        for(auto p:freq1)
        {
            int a1 = p.first;
            int a2 = p.second;
            if(freq2.find(a1)==freq2.end()) return false;
            else
            {
                if(a2!=freq2[a1]) return false;
            }
        }
        return true;

        
    }
};