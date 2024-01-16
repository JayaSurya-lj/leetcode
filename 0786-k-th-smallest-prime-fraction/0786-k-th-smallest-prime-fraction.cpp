class cmp{
public:
    bool operator()(pair<int,int>& a,pair<int,int>& b){
        double a1 = a.first/(a.second*(1.0));
        double b1 = b.first/(b.second*(1.0));
        return a1 > b1;
    }
};
class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, cmp> pq;
        for(int i=0;i<arr.size();i++)
        {
            for(int j=i+1;j<arr.size();j++)
            {
                pq.push({arr[i],arr[j]});
            }
        }
        while(--k && !pq.empty()){
            pq.pop();
        }
        if(pq.size()==0) return {};

        return {pq.top().first,pq.top().second};

    }
};