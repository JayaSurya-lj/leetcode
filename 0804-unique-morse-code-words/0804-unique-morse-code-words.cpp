class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> pattern = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        char ch ='a';
        unordered_map<char,string> patt;
        for(int i=0;i<26;i++)
        {
            patt[ch++] = pattern[i];
        }
        unordered_set<string> req;
        for(int i=0;i<words.size();i++)
        {
            string code = "";
            string real = words[i];
            for(int j=0;j<real.size();j++)
            {
                code += patt[real[j]];
            }
            req.insert(code);
        }
        return req.size();
    }
};