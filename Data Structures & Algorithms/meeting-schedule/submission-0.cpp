/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    static bool compare(Interval &a,Interval &b) {
        return a.start<b.start;
    }
    bool canAttendMeetings(vector<Interval>& intervals) {
      sort(intervals.begin(),intervals.end(),compare);
      int lastLimit=intervals[0].end;
      for(int i=1;i<intervals.size();i++) {
        if(intervals[i].start<lastLimit) {
            return false;
        }
        else {
            lastLimit=intervals[i].end;
        }
      }
      return true;  
    }
};
