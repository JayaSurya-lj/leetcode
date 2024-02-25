class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& arr) {
        for(int i=0;i<arr.size();i++){
            for(int j=0;j<arr[i].size();j++){
                if(arr[i][j]==1){
                    arr[i][j]=-1;
                }
            }
        }
        for(int i=0;i<arr.size();i++){
            if(arr[i][0]==-1) break;
            arr[i][0] = 1;
        }
        for(int i=0;i<arr[0].size();i++){
            if(arr[0][i]==-1) break;
            arr[0][i] = 1;
        }
        for(int i=1;i<arr.size();i++){
            for(int j=1;j<arr[i].size();j++){
                if(arr[i][j]==-1) continue;
                if(arr[i-1][j]==-1){
                    arr[i][j] += arr[i][j-1];
                }
                else if(arr[i][j-1]==-1){
                    arr[i][j] += arr[i-1][j];
                }
                else{
                    arr[i][j] = arr[i-1][j] + arr[i][j-1];
                }

            }
        }
        if(arr[arr.size()-1][arr[0].size()-1]==-1) return 0;
        return arr[arr.size()-1][arr[0].size()-1];
        
        
    }
};