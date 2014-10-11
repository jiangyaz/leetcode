/* Insert Interval
Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).

You may assume that the intervals were initially sorted according to their start times.

Example 1:
Given intervals [1,3],[6,9], insert and merge [2,5] in as [1,5],[6,9].

Example 2:
Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] in as [1,2],[3,10],[12,16].

This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10].
*/


vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
	vector<Interval>::iterator it = intervals.begin();

	while (it!= intervals.end()) {
		if (newInterval.end < it->start) {
			intervals.insert(it, newInterval);
			return intervals;
		} else if (newInterval.start > it->end) {
			it++;
		} else {
			newInterval.start = min(newInterval.start, it->start);
			newInterval.end = max(newInterval.end, it->end);
			it = intervals.erase(it);
		}
	}
	intervals.push_back(newInterval);
	return intervals;        
}