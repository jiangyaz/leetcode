/* Remove Duplicates from Sorted Array II 
Follow up for "Remove Duplicates":
What if duplicates are allowed at most twice?

For example,
Given sorted array A = [1,1,1,2,2,3],

Your function should return length = 5, and A is now [1,1,2,2,3].
*/

int removeDuplicates(int A[], int n) {
	if (n == 0) return 0;
	int lastNum = A[0], count = 1;
	int cur = 1;
	for (int i = 1; i < n; i++) {
		if (A[i] == lastNum) {
			if (count < 2) {
				A[cur++] = A[i];
				count++;
			} 
		} else {
			A[cur++] = A[i];
			lastNum = A[i];
			count = 1;
		}
	}
	return cur;      
}