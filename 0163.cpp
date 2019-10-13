class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        long l = lower;
        vector<string> res;
        for (int i = 0; i <= nums.size(); i++) {
            long r;
            if (i < nums.size() && nums[i] <= upper) {
                r = nums[i];
            } else {
                r = (long)upper+1;
            }
            if (l == r) l++;
            else if (l == r-1) {
                res.push_back(to_string(l));
                l = r+1;
            } else if (r - l > 1) {
                res.push_back(to_string(l) + "->" + to_string(r-1));
                l = r+1;
            }
        }
        return res;
    }
};