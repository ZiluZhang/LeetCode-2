class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        int i = 0;
        int j = 0;
        int len = A.size();
        for (j = 0; j < len; j++) {
            if (A[j] % 2 == 0) {
                int tmp = A[i];
                A[i] = A[j];
                A[j] = tmp;
                i++;
            }
        }
        return A;
    }
};