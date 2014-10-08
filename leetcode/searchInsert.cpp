/* Search Insert Position
Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You may assume no duplicates in the array.

Here are few examples.
[1,3,5,6], 5 → 2
[1,3,5,6], 2 → 1
[1,3,5,6], 7 → 4
[1,3,5,6], 0 → 0
*/

// Recursive
int searchInsert(int A[], int n, int target) {
	return searchInsertPos(A, 0, n-1, target);
}

int searchInsertPos(int A[], int start, int end, int target) {
	if (start >= end) {
		if (target <= A[start])
			return start;
		else 
			return start + 1;
	}

	int mid = (start + end)/2;
	if (target == A[mid]) {
		return mid;
	} else if (target > A[mid]) {
		return searchInsertPos(A, mid+1, end, target);
	} else {
		return searchInsertPos(A, start, mid-1, target);
	}
}

/* Iterative 
int searchInsert(int A[], int n, int target) {
	int start = 0, end = n - 1;

	while (start < end) {
		int mid = (start + end)/2;
		if (target == A[mid]) {
			return mid;
		} else if (target > A[mid]) {
			start = mid + 1;
		} else {   //  target < A[mid] 
			end = mid - 1
		}
	}
	if (target <= A[start])
		return start;
	else 
		return start + 1;
}
*/

