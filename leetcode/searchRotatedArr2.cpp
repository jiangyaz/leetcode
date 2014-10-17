/* Search in Rotated Sorted Array II 
Follow up for "Search in Rotated Sorted Array":
What if duplicates are allowed?

Would this affect the run-time complexity? How and why?

Write a function to determine if a given target is in the array.
*/

bool search(int A[], int n, int target) {
	if (n == 0) return -1;
	int start = 0, end = n-1;
	while (start <= end) {
		int mid = (start+end)/2;
		if (target == A[mid]) {
			return true;
		} else if (target > A[mid]) {
			if (A[end] >= A[mid]) {  // normal order
				if (target > A[end]) {
					end--;
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
					start++;
				}
			} else {
				end = mid - 1;
			}
		}
	}
	return false;   
}