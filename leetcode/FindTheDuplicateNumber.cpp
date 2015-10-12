/**
 * 각 비트의 1의 갯수가 기대한 갯수보다 더 크면 1로 / 그렇지 않으면 0으로
 * 시간 복잡도는 O(n log n)
 */
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int result = 0;
        for(int i = 0; nums.size() >> i; i++) {
            int expected = 0;
            int count1 = 0;
            for(int idx = 0; idx < nums.size(); idx++) {
                expected += ((1 << i) & idx) ? 1 : 0;
                count1 += ((1 << i) & nums[idx]) ? 1 : 0;
            }
            if(expected < count1) result |= 1 << i;
        }

        return result;
    }
};

