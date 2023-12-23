class Solution {
public:
    string decodeMessage(string key, string message) {
        unordered_map<char,char> mp;
        char ch = 'a';
        string keyans = "";
        for(int i=0;i<key.size();i++)
        {
            if(key[i]!=' ' && keyans.find(key[i])==-1) keyans += key[i];
        }
        for(int i=0;i<keyans.size();i++)
        {
            mp[keyans[i]] = ch++;
        }
        string ans = "";
        for(int i=0;i<message.size();i++)
        {
            if(message[i]==' ')
            {
                ans += message[i];
                continue;
            }
            ans += mp[message[i]];

        }
        return ans;
    }
};