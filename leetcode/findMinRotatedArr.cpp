/* Find Minimum in Rotated Sorted Array
Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

Find the minimum element.

You may assume no duplicate exists in the array.
*/

int findMin(vector<int> &num) {
	int start = 0, end = num.size() - 1;
	
	while (start < end-1) {
		int mid = (start + end)/2;
		if (num[end] > num[start]) return num[start];

		if (num[mid] >= num[start]) {
			start = mid + 1;
		} else {  // A[mid] < A[start]
			end = mid;
		}
	}  
	return min(num[start], num[end]);      
}