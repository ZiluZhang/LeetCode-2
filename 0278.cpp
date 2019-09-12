// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int minBad = n;
        int left = 1, right = n;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (isBadVersion(mid)) {
                minBad = min(minBad, mid);
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return minBad;
    }
};