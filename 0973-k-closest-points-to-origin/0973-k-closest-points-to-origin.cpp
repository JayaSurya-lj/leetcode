class Solution {
public:
    int distance(int x,int y){
        return ((x*x)+(y*y));
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue< pair<int, pair<int,int>> , vector<pair<int, pair<int,int>>> , greater<pair<int, pair<int,int>>>> pq;
        int i;
        for(i=0;i<points.size();i++){
            pq.push({distance(points[i][0],points[i][1]),{points[i][0],points[i][1]}});
        }
        pair<int, pair<int,int>> ans;
        vector<vector<int>> answer;
        while(k-- && !pq.empty()){
            ans = pq.top();
            pq.pop();
            int row = ans.second.first;
            int col = ans.second.second;
            answer.push_back({row,col});

        }
        return answer;
        
    }
};