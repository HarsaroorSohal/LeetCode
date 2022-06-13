class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        int MAX = INT_MAX;
        vector<vector<int>> moves;
        for(int i=0;i<n;i++)
        {
            int k = triangle[i].size();
            vector<int> temp;
            for(int j=0;j<k;j++)
                temp.push_back(MAX);
            moves.push_back(temp);
        }
        moves[0][0] = triangle[0][0];
        for(int i=1;i<n;i++)
        {
            int m = (int)triangle[i].size();
            for(int j=0;j<m;j++)
            {
                if(j-1 >=0) 
                    moves[i][j] = min(moves[i][j], triangle[i][j] + moves[i-1][j-1]);
                if(j >=0 && j!=m-1) 
                    moves[i][j] = min(moves[i][j], triangle[i][j] + moves[i-1][j]);
            }
        }
        int ans = MAX;
        for(int i=0;i<(int)moves[n-1].size();i++)
        {
            ans = min(ans,moves[n-1][i]);
        }
        return(ans);
    }
};