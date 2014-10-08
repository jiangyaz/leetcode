/* Sort Colors
Given an array with n objects colored red, white or blue, sort them so that objects of the same color are adjacent, with the colors in the order red, white and blue.

Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.
*/

void sortColors(int A[], int n) {
	int p1 = 0, p2 = n-1, cur = 0;

	while (cur <= p2) {
		if (A[cur] == 0) {
			swap(A[cur], A[p1]);
			p1++;
			cur++;  
		} else if (A[cur] == 2) {   //remember, when equals 2, don't do cur++
			swap(A[cur], A[p2]);
			p2--;
		} else {
			cur++;
		}
	}        
}