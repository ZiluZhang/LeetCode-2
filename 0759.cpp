/*
// Definition for an Interval.
class Interval {
public:
    int start;
    int end;

    Interval() {}

    Interval(int _start, int _end) {
        start = _start;
        end = _end;
    }
};
*/
class comp{
public:
    bool operator()(Interval* a, Interval* b) {
        return a->start < b->start;
    }
};
class Solution {
public:
    vector<Interval*> employeeFreeTime(vector<vector<Interval*>> schedule) {
        int n = schedule.size();
        vector<Interval*> v;
        for (int i = 0; i < n; i++) {
            v.insert(v.end(), schedule[i].begin(), schedule[i].end());
        }
        // sort(v.begin(), v.end(), [](Interval* a, Interval* b) {return a->start < b->start;});
        sort(v.begin(), v.end(), comp());
        Interval* t = v[0];
        vector<Interval*> res;
        for (int i = 1; i < v.size(); i++) {
            if (t->end < v[i]->start) {
                res.push_back(new Interval(t->end, v[i]->start));
                t = v[i];
            } else {
                if (t->end < v[i]->end) {
                    t = v[i];
                }
            }
        }
        return res;
    }
};
