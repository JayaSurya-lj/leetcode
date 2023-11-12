class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> num(2*n);
        for(int i=0;i<2*n;i++){
            num[i] = nums[i % n];
        }
        vector<int> ans(2*n,-1);
        stack<int> st;
        st.push(num[n-1]);
        for(int i=(2*n)-2;i>=0;i--)
        {
            while(st.size()>0 && st.top()<=num[i])
            {
                st.pop();
            }
            if(st.size()!=0) ans[i] = st.top();
            st.push(num[i]);
        }
        for(int i=0;i<n;i++) nums[i] = ans[i];
        return nums;
        
    }
};