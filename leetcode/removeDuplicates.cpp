/* Remove Duplicates from Sorted Array
Given a sorted array, remove the duplicates in place such that each element appear only once 
and return the new length. Do not allocate extra space for another array, you must do this in 
place with constant memory.

For example,
Given input array A = [1,1,2],
Your function should return length = 2, and A is now [1,2].
*/

int removeDuplicates(int A[], int n) {
	if (n == 0) return 0;
	int cur = 1, lastNum = A[0];

	for (int i = 1; i < n; i++) {
		if (A[i] != lastNum) {
			A[cur++] = A[i];
			lastNum = A[i];
		}
	}
	return cur;
}