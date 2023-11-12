class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n = prices.size();
        vector<int> ans(n,0);
        stack<int> st;
        st.push(prices[n-1]);
        for(int i=n-2;i>=0;i--) //next smaller
        {
            while(st.size()!=0 && st.top()>prices[i]) st.pop();
            if(st.size()!=0) ans[i] = st.top();
            st.push(prices[i]);
        }
        for(int i=0;i<n;i++)
        {
            ans[i] = prices[i] - ans[i];
        }
        return ans;
        
    }
};