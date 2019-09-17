class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int res = 0;
        int left = 0, right = n-1;
        int left_max = -1, right_max = -1;
        while (left < right) {
            if (height[left] < height[right]) {
                // update left_max, not trapping water at this point
                if (height[left] >= left_max) {
                    left_max = height[left];
                } else {
                    res += left_max - height[left];
                }
                left++;
            } else {
                if (height[right] >= right_max) {
                    right_max = height[right];
                } else {
                    res += right_max - height[right];
                }
                right--;
            }
        }
        return res;
    }
};