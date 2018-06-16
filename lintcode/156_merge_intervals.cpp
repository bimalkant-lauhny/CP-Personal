/**
 * Definition of Interval:
 * classs Interval {
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

#include <algorithm>

bool comp(Interval const a, Interval const b) {
        if (a.start < b.start) {
            return true;
        } else if (a.start == b.start) {
            if (a.end < b.end)
                return true;
            else
                return false;
        } else {
            return false;
        }
    }
    
class Solution {
public:
    /**
     * @param intervals: interval list.
     * @return: A new interval list.
     */
    
    
    vector<Interval> merge(vector<Interval> &intervals) {
        
        std::sort(intervals.begin(), intervals.end(), comp);
        
        vector <Interval> newIntervals;
        
        if (intervals.size() == 0) {
            return newIntervals;
        }
        
        int i = 0;
        newIntervals.push_back(intervals[i]);
        ++i;
        
        while(i != intervals.size()) {
            Interval prev = newIntervals[newIntervals.size()-1];
            Interval cur = intervals[i];
            if (cur.start <= prev.end) {
                Interval newInterval(prev.start, max(prev.end, cur.end));
                newIntervals.pop_back();
                newIntervals.push_back(newInterval);
            } else {
                newIntervals.push_back(cur);
            }
            ++i;
        }
        
        return newIntervals;
    }
};


// challenge solution

/**
 * Definition of Interval:
 * classs Interval {
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */
#include <algorithm>

bool comp(Interval const a, Interval const b) {
        if (a.start < b.start) {
            return true;
        } else if (a.start == b.start) {
            if (a.end < b.end)
                return true;
            else
                return false;
        } else {
            return false;
        }
    }

class Solution {
public:
    /**
     * @param intervals: interval list.
     * @return: A new interval list.
     */


    vector<Interval> merge(vector<Interval> &intervals) {

        std::sort(intervals.begin(), intervals.end(), comp);

        if (intervals.size() == 0) {
            return intervals;
        }

        int i = 0;
        ++i;

        while(i != intervals.size()) {
            if (intervals[i].start <= intervals[i-1].end) {
                Interval newInterval(intervals[i-1].start, max(intervals[i-1].end, intervals[i].end));
                intervals.erase(intervals.begin()+i-1, intervals.begin()+i+1);
                --i;
                intervals.insert(intervals.begin()+i, newInterval);
            }
            ++i;
        }

        return intervals;
    }
};
