class MedianFinder {
    priority_queue<double, vector<double>, greater<double> > secondHalf;
    priority_queue<double> firstHalf;

public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(firstHalf.empty() && secondHalf.empty()){
            firstHalf.push(num);
            return;
        }

        if(num < firstHalf.top()){
            firstHalf.push(num);
            if(firstHalf.size() - secondHalf.size() > 1) {secondHalf.push(firstHalf.top()); firstHalf.pop();}
        } else {
            secondHalf.push(num);
            if(secondHalf.size() - firstHalf.size() > 1) {firstHalf.push(secondHalf.top()); secondHalf.pop();}

        }
    }
    
    double findMedian() {
        if(firstHalf.size() < secondHalf.size()) return secondHalf.top();
        else if(secondHalf.size() < firstHalf.size()) return firstHalf.top();
        return (double(firstHalf.top()) + double(secondHalf.top())) / 2;
    }
};

