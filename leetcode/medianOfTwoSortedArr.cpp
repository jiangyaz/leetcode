/* Median of Two Sorted Arrays
There are two sorted arrays A and B of size m and n respectively. 
Find the median of the two sorted arrays. 
The overall run time complexity should be O(log (m+n)).
*/

double findMedianSortedArrays(int A[], int m, int B[], int n) {
	if ((m+n)%2 == 0) {
		return (findMedian(A, m, B, n, (m+n)/2) + findMedian(A, m, B, n, (m+n)/2+1))/2;
	}  else {
		return findMedian(A, m, B, n, (m+n)/2+1);
	}     
}

double findMedian(int A[], int m, int B[], int n, int k) {
	if (m == 0) return B[n/2];
	if (n == 0) return A[m/2];
}