/* First Missing Positive
Given an unsorted integer array, find the first missing positive integer.

For example,
Given [1,2,0] return 3,
and [3,4,-1,1] return 2.

Your algorithm should run in O(n) time and uses constant space.
*/

int firstMissingPositive(int A[], int n) {
    if (n == 0) return 1;
    
    for (int i = 0; i < n;) {
        // If x = A[i] is a positive number, swap with A[x-1]
	    if (A[i] != i+1 && A[i] > 0 && A[i] <= n) {
		    int tmp = A[A[i]-1];
		    A[A[i]-1] = A[i];
		    A[i] = tmp;
	    } 
	    // This part is soooo tricky ....
	    if (A[i] <= 0 || A[i] > n || A[A[i]-1] == A[i]) {
	        i++;
	    }
    }    

    for (int i = 0; i < n; i++) {
	    if (A[i] != i+1)
		    return i+1;
    }    
    return n+1; 
}