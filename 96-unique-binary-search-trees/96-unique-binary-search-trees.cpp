class Solution {
public:
    int helper(int n)
    {
        if(n == 0 || n == 1)
            return(1);
        int ways = 0;
        for(int i=0;i<=n-1;i++)
        {
            ways += helper(i) * helper(n-i-1);
        }
        return ways;
    }
    int numTrees(int n) {
        return(helper(n));
    }
};