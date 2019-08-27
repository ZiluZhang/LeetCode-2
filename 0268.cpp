class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int len = nums.size();
        int sum = (1 + len) * len / 2;
        for (int num: nums) {
            sum -= num;
        }
        return sum;
    }
};