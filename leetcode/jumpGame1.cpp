/* Jump Game
Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Determine if you are able to reach the last index.

For example:
A = [2,3,1,1,4], return true.

A = [3,2,1,0,4], return false.
*/

bool canJump(int A[], int n) {
	int curIndex = 0, maxIndex = 0;

	while (curIndex <= maxIndex && curIndex < n) {
		maxIndex = max(maxIndex, curIndex + A[curIndex]);
		if (maxIndex >= n-1) return true;
		curIndex++; 
	}
	return false;
}