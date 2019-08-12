// 遍历 O(n)
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {
        int len = A.size();
        for (int i = 1; i < len; i++) {
            if (A[i] < A[i-1])
                return i-1;
        }
        return -1;
    }
};

// 二分 O(logn)
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {
        int right = A.size()-1; // 因为mid要和mid+1比大小，这样防止越界
        int left = 0;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (A[mid] < A[mid+1]) left = mid+1;
            else right = mid;
        }
        return right;
    }
};