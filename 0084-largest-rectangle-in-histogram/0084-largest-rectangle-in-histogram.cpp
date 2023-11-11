class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> next(n,-1);
        next[n-1] = n;
        stack<int> st;
        st.push(n-1);
        for(int i=n-2;i>=0;i--)
        {
            while(st.size()>0 && heights[st.top()]>=heights[i])
            {
                st.pop();
            }
            if(st.size()==0) next[i] = n;
            else next[i] = st.top();
            st.push(i);
        }
        vector<int> prev(n,-1);
        while(st.size()!=0) st.pop();
        st.push(0);
        for(int i=1;i<n;i++)
        {
            while(st.size()>0 && heights[st.top()]>=heights[i])
            {
                st.pop();
            }
            if(st.size()!=0) prev[i] = st.top();
            st.push(i);
        }

    int max = INT_MIN;
    for(int i=0;i<n;i++)
    {
        int area = heights[i] * (next[i]-prev[i]-1);
        if(area>max) max = area;
    }
    return max;


    }
};