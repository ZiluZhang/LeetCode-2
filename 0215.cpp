class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        int left = 0, right = n-1;
        while (1) {
            int pos = qsort(nums, left, right);
            if (pos == k-1) return nums[pos];
            else if (pos > k-1) right = pos-1;
            else left = pos + 1;
        }
        return -1;
    }
    
    int qsort(vector<int>& nums, int left, int right) {
        int pivot = nums[left];
        int l = left+1, r = right;
        while (l <= r) {
            if (nums[l] < pivot && nums[r] > pivot) {
                swap(nums[l], nums[r]);
                l++;
                r--;
            }
            if (nums[l] >= pivot) l++;
            if (nums[r] <= pivot) r--;
        }
        swap(nums[left], nums[r]);
        return r;
    }
};