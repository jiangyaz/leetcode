/*  Sort for a Range

Given a sorted array of integers, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

For example,
Given [5, 7, 7, 8, 8, 10] and target value 8,
return [3, 4].
*/

vector<int> combineRange(vector<int> range1, vector<int> range2) {
	vector<int> out(2, -1);
	if (range1[0] == -1) {
		out[0] = range2[0]; 
	} else if (range2[0] == -1) {
		out[0] = range1[0];
	} else {
		out[0] = min(range1[0], range2[0]);
	}
	out[1] = max(range1[1], range2[1]);
	return out;
}

vector<int> searchRange(int A[], int n, int target) {
	return searchRangeHelper(A, 0, n-1, target);
}

vector<int> searchRangeHelper(int A[], int start, int end, int target) {
	vector<int> res(2, -1);
	if (start > end) {
		return res;
	}

	if (target == A[start] && target == A[end]) {
		res[0] = start;
		res[1] = end;
		return res;
	}

	int mid = (start + end)/2;

	if (target == A[mid]) {
		vector<int> left = searchRangeHelper(A, start, mid, target);
		vector<int> right = searchRangeHelper(A, mid+1, end, target);
		res = combineRange(left, right);

	} else if (target > A[mid]) {
		res = searchRangeHelper(A, mid+1, end, target);
	} else {
		res = searchRangeHelper(A, start, mid-1, target);
	}
	return res;
}