// sort O(n*logn)
class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        int len = A.size();
        vector<int> res(len, 0);
        for(int i = 0; i < len; i++) {
            res[i] = A[i]*A[i];
        }
        sort(res.begin(), res.end());
        return res;
    }
};

// two pointers O(n)
class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        int len = A.size();
        vector<int> res;
        int right = 0;
        while (right < len && A[right] < 0) {
            right++;
        }
        int left = right-1;
        while (0 <= left && right < len) {
            if(A[left]*A[left] < A[right]*A[right]) {
                res.push_back(A[left]*A[left]);
                left--;
            } else {
                res.push_back(A[right]*A[right]);
                right++;
            }
        }
        while (0 <= left) {
            res.push_back(A[left]*A[left]);
            left--;
        }
        while (right < len) {
            res.push_back(A[right]*A[right]);
            right++;
        }
        return res;
    }
};