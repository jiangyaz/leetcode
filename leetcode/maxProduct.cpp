/* Maximum Product Subarray
Find the contiguous subarray within an array (containing at least one number) 
which has the largest product.

For example, given the array [2,3,-2,4],
the contiguous subarray [2,3] has the largest product = 6.
*/

int maxProduct(int A[], int n) {
	if (n == 0) return 0;
	int out = A[0], maxP = A[0], minP = A[0];

	for (int i = 1; i < n; i++) {
		int val1 = maxP * A[i];
		int val2 = minP * A[i];
		maxP = max(A[i], max(val1, val2));
		minP = min(A[i], min(val1, val2));
		out = max(out, maxP);
	}
	return out;        
}