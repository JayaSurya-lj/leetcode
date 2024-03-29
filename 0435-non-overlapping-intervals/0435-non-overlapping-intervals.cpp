bool cmp(vector<int>& v1,vector<int>& v2){
    return v1[1]<v2[1];
}
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int ans = 0;
        sort(intervals.begin(),intervals.end(),cmp);
        int lastEndTime = intervals[0][1];
        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0]<lastEndTime){
                ans++;
            }
            else{
                lastEndTime = intervals[i][1];
            }
        }
        return ans;
    }
};