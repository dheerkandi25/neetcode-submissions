class Solution {
public:
    static bool compare(const Interval &a, const Interval &b) {
        return a.start < b.start;
    }

    int minMeetingRooms(vector<Interval>& intervals) {

        if (intervals.empty())
            return 0;

        sort(intervals.begin(), intervals.end(), compare);

        priority_queue<int, vector<int>, greater<int>> pq;

        pq.push(intervals[0].end);

        for (int i = 1; i < intervals.size(); i++) {

            // Earliest room becomes free
            if (intervals[i].start >= pq.top()) {
                pq.pop();
            }

            // Put this meeting into a room
            pq.push(intervals[i].end);
        }

        return pq.size();
    }
};