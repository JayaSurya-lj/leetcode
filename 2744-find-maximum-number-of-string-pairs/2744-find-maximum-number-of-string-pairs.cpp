class Solution {
public:
    string reverseStr(string str)
    {
        int i=0,j=str.size()-1;
        while(i<j)
        {
            char temp = str[i];
            str[i] = str[j];
            str[j] = temp;
            i++;
            j--;
        }
        return str;
    }
    int maximumNumberOfStringPairs(vector<string>& words) {
        unordered_set<string> s;
        for(int i=0;i<words.size();i++)
        {
            s.insert(words[i]);
        }
        int count = 0;
        for(int i=0;i<words.size();i++)
        {
            string target = reverseStr(words[i]);
            s.erase(words[i]);
            if(s.find(target)!=s.end())
            {
                
                count++;
            }
        }
        return count;
        
    }
};