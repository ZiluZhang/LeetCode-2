// for loop O(n^2)
class Solution {
public:
    vector<int> anagramMappings(vector<int>& A, vector<int>& B) {
        int len = A.size();
        vector<int> res(len, 0);
        for (int i = 0; i < len; i++) {
            for (int j= 0; j < len; j++) {
                if (A[i] == B[j]) {
                    res[i] = j;
                    break;
                }
            }
        }
        return res;
    }
};

// unordered map O(n)
class Solution {
public:
    vector<int> anagramMappings(vector<int>& A, vector<int>& B) {
        int len = A.size();
        unordered_map<int, int> m;
        vector<int> res(len, 0);
        for (int i = 0; i < len; i++) {
            m[B[i]] = i;
        }
        for (int j = 0; j < len; j++) {
            res[j] = m[A[j]];
        }
        return res;
    }
};