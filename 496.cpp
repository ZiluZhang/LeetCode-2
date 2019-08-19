class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> s;
        unordered_map<int, int> resMap;
        for (int n: nums2) {
            while (!s.empty() && s.top() < n) {
                resMap[s.top()] = n;
                s.pop();
            }
            s.push(n);
        }
        while (!s.empty()) {
            resMap[s.top()] = -1;
            s.pop();
        }
        vector<int> res;
        for (int n: nums1) {
            res.push_back(resMap[n]);
        }
        return res;
    }
};