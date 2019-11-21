class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> m;
        m[0] = -1;
        int cnt = 0;
        int res = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) cnt--;
            if (nums[i] == 1) cnt++;
            if (m.find(cnt) != m.end()) {
                res = max(i - m[cnt], res);
            } else {
                m[cnt] = i;
            }
        }
        return res;
    }
};