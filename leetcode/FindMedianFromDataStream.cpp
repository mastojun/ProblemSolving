/**
 * 두개의 priority queue를 두어서
 * small에는 내림차순으로 작은 숫자들을
 * large에는 오름차순으로 큰 숫자들을 넣습니다.
 * small과 large의 최대 차이는 1이 되도록 유지하여
 * addNum은 O(log n)으로, findMedian은 O(1)에 수행되도록 함.
 */ 
class MedianFinder {
public:
    bool sorted;
    priority_queue<int> small;
    priority_queue<int, vector<int>, greater<int>> large;

    void addNum(int num) {
        if(large.size() == small.size()) {
            if(large.size() == 0 || large.top() > num) {
                small.push(num);
            } else {
                large.push(num);
            }
        } else if(large.size() > small.size()) {
            if(large.top() < num) {
                small.push(large.top()); large.pop();
                large.push(num);
            } else {
                small.push(num);
            }
        } else {
            if(small.top() > num) {
                large.push(small.top()); small.pop();
                small.push(num);
            } else {
                large.push(num);
            }
        }
    }

    double findMedian() {
        if(large.size() == small.size()) {
            return (large.top() + small.top()) / 2.;
        }
        if(large.size() > small.size()) {
            return large.top();
        }
        return small.top();
    }
};
