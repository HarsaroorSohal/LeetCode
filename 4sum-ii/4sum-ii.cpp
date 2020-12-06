class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        map<int, int> store;
        int n = A.size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                int sum = A[i] + B[j];
                store[sum]++;
            }
        }
        int ans = 0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                int target = -C[i]- D[j];
                ans+= store[target];
            }
        }
        return(ans);
    }
};
