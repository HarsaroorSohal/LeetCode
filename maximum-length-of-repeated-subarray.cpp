class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        int n = A.size();
        int m = B.size();
        vector<vector<int>> dp(n,vector<int>(m,0));
        int ans = 0;
9
10
11
12
13
14
15
16
17
18
19
20
21
22
