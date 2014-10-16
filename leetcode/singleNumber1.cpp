/* Single Number
Given an array of integers, every element appears twice except for one. 
Find that single one.

Note:
Your algorithm should have a linear runtime complexity. 
Could you implement it without using extra memory?
*/

int singleNumber(int A[], int n) {
	if (n == 0) return 0;
	int out = A[0];        
	for (int i = 1; i < n; i++) {
		out = out ^ A[i];
	}
	return out;
}
