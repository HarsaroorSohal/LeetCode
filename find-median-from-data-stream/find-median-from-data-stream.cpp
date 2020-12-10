class MedianFinder {
public:
    /** initialize your data structure here. */
    priority_queue<int> low;
    priority_queue<int, vector<int>, greater<int>> high;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(low.empty() && high.empty())
        {
            low.push(num);
        }
        else if(low.size() > high.size())
        {
            low.push(num);
            int mx = low.top();
            low.pop();
            high.push(mx);
        }
        else if(low.size() == high.size())
        {
            low.push(num);
            int mx = low.top();
            low.pop();
            high.push(mx);
            int mn = high.top();
            high.pop();
            low.push(mn);
        }
    }
    
    double findMedian() {
        double med;
        if(((int)low.size() + (int)high.size())%2)
        {
            med = (double)low.top();
        }
        else
        {
            med = ((double)low.top() + (double)high.top())/2;
        }
        return(med);
    }
};
​
/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
