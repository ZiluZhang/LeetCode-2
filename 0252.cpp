class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {return a[0] < b[0];});
        for (int i = 1; i < n; i++) {
            if (intervals[i][0] < intervals[i-1][1]) {
                return false;
            }
        }
        return true;
    }
};