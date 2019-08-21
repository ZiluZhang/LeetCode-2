class Solution {
public:
    bool isMonotonic(vector<int>& A) {
        int len = A.size();
        bool increasing = true;
        bool decreasing = true;
        for (int i = 1; i < len; i++) {
            if (A[i-1] < A[i]) {
                decreasing = false;
            }
            if (A[i-1] > A[i]) {
                increasing = false;
            }
        }
        return increasing || decreasing;
    }
};