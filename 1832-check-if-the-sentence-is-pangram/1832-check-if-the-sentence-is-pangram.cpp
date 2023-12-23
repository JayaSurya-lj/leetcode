class Solution {
public:
    bool checkIfPangram(string sentence) {
        unordered_map<char,int> mp;
        char ch = 'a';
        for(int i=0;i<26;i++)
        {
            mp[ch] = 0;
            ch++;
        }
        for(int i=0;i<sentence.size();i++)
        {
            mp[sentence[i]]++;
        }
        for(auto p:mp)
        {
            if(p.second==0) return false;
        }
        return true;
    }
};