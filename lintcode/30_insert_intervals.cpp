#include <iostream>
#include <vector>
using namespace std;

class Interval {
  public:
    int start, end;
    Interval(int start, int end) {
        this->start = start;
        this->end = end;
    }

    void showInterval() {
        cout << "(" << this->start << "," << this->end << ")" << endl;
    }
};

int insertPos(vector<Interval> &intervals, Interval newInterval) {
    int lo = 0;
    int hi = intervals.size() - 1;
    int mid;
    while (lo < hi) {
        mid = lo + (hi - lo) / 2;
        if (intervals[mid].start < newInterval.start) {
            lo = mid + 1;
        } else {
            hi = mid;
        }
    }

    if (intervals[lo].start < newInterval.start)
    	lo = intervals.size();

    return lo;
}


vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
    
    vector <Interval> newIntervals;

    int pos = insertPos(intervals, newInterval);

    bool done = false;
    int i = 0;

    while (i < pos-1) {
        newIntervals.push_back(intervals[i]);
        ++i;
    }

    while (i < intervals.size()) {
        int a = newInterval.start;
        int b = newInterval.end;
        int c = intervals[i].start;
        int d = intervals[i].end;

        // if newInterval has been inserted into newIntervals
        if (done) {
            newIntervals.push_back(intervals[i]);
            ++i;
            continue;
        }

        if (a <= c) {
            if (b >= c) {
                newInterval = Interval(a, max(b, d));
            }
            else {
                newIntervals.push_back(newInterval);
                done = true;
                newIntervals.push_back(intervals[i]);
            }
       } else {
           if (a > d) {
               newIntervals.push_back(intervals[i]);
           } else {
               newInterval = Interval(c, max(b, d));
           }
       }
       ++i;
    }
    if (!done)
        newIntervals.push_back(newInterval);

    return newIntervals;
}

int main(void) {
    vector <Interval> intervals = {Interval(4, 6), Interval(11, 14)};
    int s, e;
    cout << "Enter: ";
    cin >> s >> e;
    auto newIntervals = insert(intervals, Interval(s, e));
    for (auto it=newIntervals.begin(); it<newIntervals.end(); ++it) {
        it->showInterval();
    }
    return 0;
}
