class Solution {
public:
    int minDeletionSize(vector<string>& A) {
        int num = A.size();
        int cnt = 0;
        if (num == 0) return cnt;
        int len = A[0].length();
        for (int i = 0; i < len; i++) {
            for (int j = 1; j < num; j++) {
                if (A[j][i] < A[j-1][i]) {
                    cnt++;
                    break;
                }
            }
        }
        return cnt;
    }
};