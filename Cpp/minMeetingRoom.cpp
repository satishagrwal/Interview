/*
Given an array of meeting time interval objects consisting of start and end times [[start_1,end_1],[start_2,end_2],...] (start_i < end_i), find the minimum number of rooms required to schedule all meetings without any conflicts.

Note: (0,8),(8,10) is NOT considered a conflict at 8.

Example 1:

Input: intervals = [(0,40),(5,10),(15,20)]

Output: 2
Explanation:
day1: (0,40)
day2: (5,10),(15,20)

Example 2:

Input: intervals = [(4,9)]

Output: 1
Constraints:

0 <= intervals.length <= 500
0 <= intervals[i].start < intervals[i].end <= 1,000,000
*/

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        int n = intervals.size();
        if (n == 0) return 0;

        vector<int> startTimes;
        vector<int> endTimes;

        for (const auto& interval : intervals) {
            startTimes.push_back(interval.start);
            endTimes.push_back(interval.end);
        }

        sort(startTimes.begin(), startTimes.end());
        sort(endTimes.begin(), endTimes.end());

        int usedRooms = 0;
        int endPtr = 0;

        // We only need to loop through the start times
        for (int startPtr = 0; startPtr < n; startPtr++) {
            // If there's a meeting start before the oldest meeting ends,
            // we need a new room.
            if (startTimes[startPtr] < endTimes[endPtr]) {
                usedRooms++;
            } else {
                // Otherwise, a room became free. 
                // Move the end pointer to the next earliest end time.
                endPtr++;
            }
        }

        return usedRooms;
    }
};
