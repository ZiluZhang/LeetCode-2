class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> s;
        vector<int> res(nums.size(), 0);
        for (int i = nums.size()-1; i >= 0; i--) {
            int left = 0, right = s.size();
            while (left < right) {
                int mid = left + (right - left) / 2;
                if (s[mid] < nums[i]) {
                    left = mid + 1;
                } else {
                    right = mid;
                }
            }
            res[i] = right;
            s.insert(s.begin()+right, nums[i]);
            // cout << s.size() << endl;
        }
        return res;
    }
};