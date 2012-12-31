/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<Interval> ret;
        int i=0;
        int inserted = false;
        int start = newInterval.start;
        int end = newInterval.end;
        for (i=0; i<intervals.size(); i++) {
            if (end<intervals[i].start) {
                if (!inserted) {
                    Interval ins = Interval(start, end);
                    ret.push_back(ins);
                    inserted = true;
                }
                ret.push_back(intervals[i]);
                continue;
            }
            if (intervals[i].end<start) {
                ret.push_back(intervals[i]);
                continue;
            }
            start = start<intervals[i].start ? start : intervals[i].start;
            end = end > intervals[i].end ? end : intervals[i].end;
            
        }
        if (i==intervals.size() && !inserted) {
            Interval ins = Interval(start, end);
            ret.push_back(ins);
        }
        return ret;
    }
};
