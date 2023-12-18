class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int,int> mp;
        for(int i=0;i<arr2.size();i++)
        {
            mp[arr2[i]] = i;
        }
        for(int i=0;i<arr1.size();i++)
        {
            for(int j=i+1;j<arr1.size();j++)
            {
                if(mp.find(arr1[i])==mp.end())
                {
                    int temp = arr1[i];
                    arr1[i] = arr1[j];
                    arr1[j] = temp;

                }
                else
                {
                    if(mp.find(arr1[j])!=mp.end())
                    {
                        if(mp[arr1[i]]>mp[arr1[j]])
                        {
                            int temp = arr1[i];
                            arr1[i] = arr1[j];
                            arr1[j] = temp;
                        }
                    }
                }
            }
        }
        int i;
        for(i=0;i<arr1.size();i++)
        {
            if(mp.find(arr1[i])==mp.end()) break;
        }
        sort(arr1.begin()+i,arr1.end());
        return arr1;

        
    }
};