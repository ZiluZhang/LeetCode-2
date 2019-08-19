class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> s1;
        unordered_set<int> s2;
        for (int n: nums1) s1.insert(n);
        for (int n: nums2) s2.insert(n);
        if (s1.size() < s2.size()) return getIntersect(s1, s2);
        else return getIntersect(s2, s1);
    }
    
    vector<int> getIntersect(unordered_set<int> s1, unordered_set<int> s2) {
        vector<int> res;
        for (auto it = s1.begin(); it != s1.end(); it++) {
            if (s2.count(*it)) res.push_back(*it);
        }
        return res;
    }
};