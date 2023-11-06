class Solution {
public:
    string removeDuplicates(string s) {
        if(s.size()==0) return s; 
        stack<char> st;
        st.push(s[0]);
        for(int i=1;i<s.size();i++)
        {
            if(st.size()!=0 && s[i]==st.top()){
                st.pop();
                continue;
            }
            st.push(s[i]);
        }
        string ans = "";
        while(st.size()>0)
        {
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};