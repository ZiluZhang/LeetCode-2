class Solution {
public:
    
    int check(int tag, vector<int>& A, vector<int>& B) {
        int len = A.size();
        int a = 0;
        int b = 0;
        for (int i = 0; i < len; i++) {
            if (A[i] != tag && B[i] != tag) return -1;
            if (A[i] != tag) a++;
            if (B[i] != tag) b++;
        }
        return min(a, b);
    }
    
    int minDominoRotations(vector<int>& A, vector<int>& B) {
        int res = check(A[0], A, B);
        if (A[0] == B[0] || res != -1) return res;
        return check(B[0], A, B);
    }
};