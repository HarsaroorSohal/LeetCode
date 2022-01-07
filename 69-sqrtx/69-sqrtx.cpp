class Solution {
public:
    int mySqrt(int x) {
        if(x == 0 || x == 1) return(x);
        int l = 1;
        int r = x;
        int ans = 0;
        while( l <= r)
        {
            int mid = l + (r-l)/2;
            cout << l << " " << r << " " << mid << endl;
            if(mid == (x/mid))
            {
                cout << "yolo1";
                return(mid);
            }
            else if(mid > x/mid)
            {
                cout << "yolo2";
                r = mid - 1;
            }
            else
            {
                cout << "yolo3";
                l = mid + 1;
                ans = mid;
            }
        }
        return(ans);
    }
};