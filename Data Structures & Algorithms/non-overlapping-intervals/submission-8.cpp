class Solution {
public:
    static bool compare(vector<int> &a, vector<int> &b) {
        if (a[1] != b[1]) {
            return a[1] < b[1];
        }
        return a[0] < b[0];
    }

    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), compare);

        int ans = 0;

        int lastEnd = intervals[0][1];

        for (int i = 1; i < intervals.size(); i++) {

            if (intervals[i][0] < lastEnd) {
                ans++;
            }
            else {
                lastEnd = intervals[i][1];
            }
        }

        return ans;
    }
};