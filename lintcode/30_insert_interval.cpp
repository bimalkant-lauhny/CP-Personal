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

class Solution {
public:
    /**
     * @param intervals: Sorted interval list.
     * @param newInterval: new interval.
     * @return: A new interval list.
     */
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        vector<Interval> res {newInterval};
        if (intervals.size() == 0) {
            return res;
        }
        
        for (auto const &cur: intervals) {
            Interval lastres = res[res.size() - 1];
            if (cur.end < lastres.start) {
                // cur is strictly smaller than lastres 
                res.pop_back();
                res.push_back(cur);
                res.push_back(lastres);
            } else if (cur.start > lastres.end) {
                // cur is strictly larger than lastres 
                res.push_back(cur);
            } else {
                // cur and lastres overlap
                res.pop_back();
                res.push_back(Interval(min(cur.start, lastres.start),
                                       max(cur.end, lastres.end)));
            }
        }
        
        return res;
    }
};
