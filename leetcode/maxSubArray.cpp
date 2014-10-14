/* Max Subarray
Find the contiguous subarray within an array (containing at least one number) which has the largest sum.

For example, given the array [−2,1,−3,4,−1,2,1,−5,4],
the contiguous subarray [4,−1,2,1] has the largest sum = 6.
*/

int maxSubArray(int A[], int n) {
	int prev = A[0], maxSum = A[0], cur;
	for (int i = 1; i < n; i++) {
		cur = (prev > 0) ? prev + A[i] : A[i];
		maxSum = max(maxSum, cur);
		prev = cur;
	}
	return maxSum;
}