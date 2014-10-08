/* Merge Sorted Array
Given two sorted integer arrays A and B, merge B into A as one sorted array.

Note:
You may assume that A has enough space (size that is greater or equal to m + n) 
to hold additional elements from B. The number of elements initialized in A and B are 
m and n respectively.
*/

void merge(int A[], int m, int B[], int n) {
    int pA = m-1, pB = n-1, p = m+n-1;
    while (p >= 0) {
        if (pB < 0) {
            A[p--] = A[pA--];
        } else if (pA < 0) {
            A[p--] = B[pB--];
        } else {
            if (A[pA] >= B[pB]) 
                A[p--] = A[pA--];
            else 
                A[p--] = B[pB--];
        }
   	}
}