/* Trapping Rain Water
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.

For example, 
Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.
*/

int trap(int A[], int n) {
	vector<int> leftMax(n, 0);
	vector<int> rightMax(n, 0);
	// Scan from left, find the tallest bar on the left
	int maxVal = A[0];
	for (int i = 1; i < n; i++) {
		leftMax[i] = maxVal;
		maxVal = max(A[i], maxVal);
	}
	// Scan from right, find the tallest bar on the right
	maxVal = A[n-1];
	for (int i = n-2; i >= 0; i--) {
		rightMax[i] = maxVal;
		maxVal = max(A[i], maxVal);
	}

	int volume = 0;
	for (int i = 0; i < n; i++) {
		volume += max(0, min(leftMax[i], rightMax[i]) - A[i]);
	}
	return volume;
}
