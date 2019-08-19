class Solution {
public:
    int dayOfYear(string date) {
        vector<int> days = {31,28,31,30,31,30,31,31,30,31,30,31};
        int year = stoi(date.substr(0,4));
        int month = stoi(date.substr(5,2));
        int day = stoi(date.substr(8,2));
        if (year % 4 == 0) {
            if (year % 100 == 0 && year % 400 != 0) {
                days[1] = 28;
            } else {
                days[1] = 29;
            }
            
        }
        int res = 0;
        for (int i = 1; i < month; i++) {
            res += days[i-1];
        }
        res += day;
        return res;
    }
};