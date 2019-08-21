class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_multiset<int> s(nums1.begin(), nums1.end());
        vector<int> res;
        for (int n: nums2) {
            if (s.find(n) != s.end()) {
                res.push_back(n);
                s.erase(s.find(n));
            }
        }
        return res;
    }
};