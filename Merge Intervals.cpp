/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
bool comp(const Interval & i1, const Interval &i2) {
    return i1.start<i2.start;
}     
class Solution {
public:

    vector<Interval> merge(vector<Interval> &intervals) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (intervals.size()<=1) {
            return intervals;
        }
        
        sort(intervals.begin(), intervals.end(), comp);
        vector<Interval> ret;
        
        int cbegin = intervals[0].start;
        int cend = intervals[0].end;
        for (int i = 1; i< intervals.size(); i++) {
            if (intervals[i].start>cend) {
                Interval ival(cbegin, cend);
                ret.push_back(ival);
                cbegin=intervals[i].start;
                cend = intervals[i].end;
            }
            else {
                if (intervals[i].end>cend)
                    cend = intervals[i].end;
            }
        }
        Interval ival(cbegin, cend);
        ret.push_back(ival);
        return ret;
    }
};