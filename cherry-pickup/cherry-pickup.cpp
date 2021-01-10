class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int N=grid.size();
        int M=(N-1)*2;
        vector<vector<int>> dp(N,vector<int>(N,-1));
        dp[0][0]=grid[0][0];
        for(int m=1;m<=M;m++)
        {
            vector<vector<int>> dpnew(N,vector<int>(N,-1));
            for(int r1=N-1;r1>=0;r1--)
                for(int r2=N-1;r2>=0;r2--)
                {
                    if(m-r1<0 || m-r1>=N || m-r2<0 || m-r2>=N || grid[r1][m-r1]==-1 || grid[r2][m-r2]==-1) continue;
                    dpnew[r1][r2]=dp[r1][r2];
                    if(r1>0)
                        dpnew[r1][r2]=max(dpnew[r1][r2],dp[r1-1][r2]);
                    if(r2>0)
                        dpnew[r1][r2]=max(dpnew[r1][r2],dp[r1][r2-1]);
                    if(r1>0 && r2>0)
                        dpnew[r1][r2]=max(dpnew[r1][r2],dp[r1-1][r2-1]);
                    if(dpnew[r1][r2]<0) continue;//there is no valid path inherited from last step
                    dpnew[r1][r2] += grid[r1][m-r1]==1 ? 1 : 0;
                    if(r1!=r2)
                        dpnew[r1][r2] += grid[r2][m-r2]==1 ? 1 : 0;
                }
            dp=dpnew;
        }
        return max(0,dp[N-1][N-1]);
    }
};
