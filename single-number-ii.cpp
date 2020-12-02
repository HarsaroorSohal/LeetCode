class Solution {
public:
    int singleNumber(vector<int>& nums) {
        vector<int>count(32,0);
        for(int i : nums)
        {
            for(int j=0;j<32;j++)
            {
                if((1 << j) & i) count[j]++;
            }
        }
        int ans = 0;
        for(int i=0;i<32;i++)
        {
            cout << i << " " << count[i] << endl;
            if(count[i]%3) ans = ans | (1 << i);
        }
        return(ans);
    }
};
