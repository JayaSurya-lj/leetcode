class Solution {
public:
    int helper(vector<int>&costs,vector<int>&days,int ind,vector<int>&dp){
        if(ind<0){
            return 0;
        }
        if(dp[days[ind]]!=-1){
            return dp[days[ind]];
        }
        int daypoint=costs[0]+helper(costs,days,ind-1,dp);
        int indweek=upper_bound(days.begin(),days.end(),days[ind]-7)-days.begin();
        indweek--;
        int weekpoint=costs[1]+helper(costs,days,indweek,dp);
        int indmonth=upper_bound(days.begin(),days.end(),days[ind]-30)-days.begin();
        indmonth--;
        int monthpoint=costs[2]+helper(costs,days,indmonth,dp);
        return dp[days[ind]]=min({daypoint,weekpoint,monthpoint});
    }

    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n=days.size();
        vector<int>dp(366,-1);
        return helper(costs,days,n-1,dp);
    }
};