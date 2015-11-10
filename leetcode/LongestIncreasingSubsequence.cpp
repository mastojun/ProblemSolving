/**
 * LIS의 O(n Log n) solution
 */

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        for (int num : nums) {
            insert(num);
        }
        return minNumber.size();
    }
private:
    vector<int> minNumber;

    void insert(int n) {
        int left = 0;
        int right = minNumber.size();
        while (left < right) {
            int mid = left + (right - left) / 2;
            if(minNumber[mid] < n) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        if (minNumber.size() > left) minNumber[left] = n;
        else minNumber.push_back(n);
    }
};

