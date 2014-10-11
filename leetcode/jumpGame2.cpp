/* Jump Game II 
Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Your goal is to reach the last index in the minimum number of jumps.

For example:
Given array A = [2,3,1,1,4]

The minimum number of jumps to reach the last index is 2. (Jump 1 step from index 0 to 1, then 3 steps 
to the last index.)
*/

int jump(int A[], int n) {
    if (n <= 1) return 0;
    int curMax = 0, nextMax = 0, curIndex = 0, step = 1;

    while (curIndex < n) {
    	while (curIndex <= curMax) {
		    nextMax = max(nextMax, curIndex + A[curIndex]);
		    if (nextMax >= n - 1) return step;
		    curIndex++;
	    }
	    step++;
	    curMax = nextMax;
    }   
    return step;
}