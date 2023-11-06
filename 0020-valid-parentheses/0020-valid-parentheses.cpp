class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        int n = s.size();
        bool flag = false;
        for(int i=0;i<n;i++)
        {
            if((flag==false) && (s[i]==')'||s[i]=='}'||s[i]==']')) return false;
           if(s[i]=='('||s[i]=='{'||s[i]=='[')
           {
               st.push(s[i]);
               flag = true;
           }
           else if((s[i]==')'||s[i]=='}'||s[i]==']'))
           {
               bool check = false;
               if(st.size()==0) return false;
               char ch = st.top();
               if(ch=='(' && s[i]==')')
               {
                   st.pop();
                   check = true;
               }
               if(ch=='{' && s[i]=='}')
               {
                   st.pop();
                   check = true;
               }
               if(ch=='[' && s[i]==']')
               {
                   st.pop();
                   check = true;
               }

               if(check==false) return false;
           }
        }
        cout<<st.size();
        if(flag==false) return false;
        if(st.size()==0) return true;
        return false;

        
    }
};