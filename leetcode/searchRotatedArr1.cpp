/* Search in Rotated Sorted Array
Suppose a sorted array is rotated at some pivot unknown to you beforehand.
(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
You are given a target value to search. If found in the array return its index, 
otherwise return -1.
You may assume no duplicate exists in the array.
*/

int search(int A[], int n, int target) {
	if (n == 0) return -1;
	int start = 0, end = n-1;
	while (start <= end) {
		int mid = (start+end)/2;
		if (target == A[mid]) {
			return mid;
		} else if (target > A[mid]) {
			if (A[end] >= A[mid]) {  // normal order
				if (target > A[end]) {
					end = mid - 1;
				} else {
					start = mid + 1;
				}
			} else {
				start = mid + 1;
			}
		} else {  // target < A[mid]
			if (A[mid] >= A[start]) { // normal order
				if (target >= A[start]) {
					end = mid - 1;
				} else {
					start = mid + 1;
				}
			} else {
				end = mid - 1;
			}
		}
	}
	return -1;
}