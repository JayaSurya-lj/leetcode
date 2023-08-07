class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        int m = matrix.size();
        int n = matrix[0].size();
        int minr=0,minc=0,maxr=m-1,maxc=n-1;
        int t = 0;
        int tne = m*n;
        while(minr<=maxr && minc<=maxc)
        {
            //Right
            for(int j=minc;j<=maxc && t<tne;j++)
            {
                result.push_back(matrix[minr][j]);
                t++;
            }
            minr++;
            //down
            for(int i=minr;i<=maxr  && t<tne;i++)
            {
                result.push_back(matrix[i][maxc]);
                t++;
            }
            maxc--;
            //left
            for(int j=maxc;j>=minc  && t<tne;j--)
            {
                result.push_back(matrix[maxr][j]);
                t++;
            }
            maxr--;
            //top
            for(int i=maxr;i>=minr  && t<tne;i--)
            {
                result.push_back(matrix[i][minc]);
                t++;
            }
            minc++;
        }
        return result;
    }
};
