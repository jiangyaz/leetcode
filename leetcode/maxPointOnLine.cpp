/* Max Points on a Line
Given n points on a 2D plane, find the maximum number of points 
that lie on the same straight line.
*/

int maxPoints(vector<Point> &points) {
	unordered_map<double, int> mp;
	int maxNum = 0;
	for (int i = 0; i < points.size()-1; i++) {
		mp.clear();
		for (int j = 1; j < points.size(); j++) {
			double key = points[i].x == points[j].x ? 
					INT_MAX : (double) (points[i].y - points[j].y)/ (points[i].x - points[j].x);
			mp[key]++;
		}
		unordered_map<double, int>::iterator it;
		for (it = mp.begin(); it < mp.end(); it++) {
			maxNum = max(maxNum, it->second + 1);
		}
	}   
	return maxNum;     
}