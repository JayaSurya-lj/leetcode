bool cmp(vector<int>& a1,vector<int>& a2){
    return a1[1]<a2[1];
}
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int ans = 0;
        sort(points.begin(),points.end(),cmp);
        int lastEndTime = points[0][1];
        for(int i=1;i<points.size();i++){
            if(points[i][0]<=lastEndTime){
                ans++;
            }
            else{
                lastEndTime = points[i][1];
            }
        }
        return points.size() - ans;
        
    }
};