class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n = nums.size();
        int left = 1;
        int right = 1e6;
        int ans;
        while(left <= right)
        {
            int mid = left + (right-left)/2;
            int sum = 0;
                for(int i : nums)
                {
                    sum+= (i+mid-1)/mid;
                }
                if(sum <= threshold)
                {
                    ans = mid;
                    right = mid - 1;
                }
                else
                {
                    left = mid + 1;
                }
        }
        return(ans);
    }
};
