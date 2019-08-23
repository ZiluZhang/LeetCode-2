class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        int k = 0;
        while (i < n) {
            int cur = nums[i];
            while (i + 1 < n && nums[i] == nums[i+1]) {
                i++;
            }
            nums[k] = cur;
            k++;
            i++;
        }
        return k;
    }
};