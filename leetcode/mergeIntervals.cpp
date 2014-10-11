/* Merge Intervals

Given a collection of intervals, merge all overlapping intervals.

For example,
Given [1,3],[2,6],[8,10],[15,18],
return [1,6],[8,10],[15,18].
*/


void insert(vector<Interval> &intervals, Interval newInterval) {
    vector<Interval>::iterator it = intervals.begin();
    while (it!= intervals.end()) {
    	if (newInterval.end < it->start) {
		    intervals.insert(it, newInterval);
		    return;
	    } else if (newInterval.start > it->end) {
		    it++;
	    } else {
		    newInterval.start = min(newInterval.start, it->start);
		    newInterval.end = max(newInterval.end, it->end);
		    it = intervals.erase(it);
	    }
    }
    intervals.push_back(newInterval);       
}

vector<Interval> merge(vector<Interval> &intervals) {
    vector<Interval> res;
    for (int i = 0; i < intervals.size(); i++) {
	    insert(res, intervals[i]);
    }        
    return res;
}