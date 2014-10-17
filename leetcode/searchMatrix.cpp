/* Search a 2D Matrix
Write an efficient algorithm that searches for a value in an m x n matrix. 
This matrix has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.
For example,

Consider the following matrix:

[
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
Given target = 3, return true.
*/

bool searchMatrix(vector<vector<int> > &matrix, int target) {
	int m = matrix.size();
    if (m == 0) return false;
    int n = matrix[0].size();

    // Search row
    int start = 0, end = m-1;
    while (start < end - 1) {    // Stop when start = end - 1
	    int mid = (start + end)/2;
	    if (matrix[mid][0] == target) {
		    return true;
	    } else if (matrix[mid][0] > target) {
		    end = mid - 1;
	    } else {
		    start = mid;
	    }
    }   
    int row = (target >= matrix[end][0]) ? end: start;
    // Search column
    start = 0, end = n - 1;
    while (start <= end) {      
	    int mid = (start + end)/2;
	    if (matrix[row][mid] == target) {
		    return true;
	    } else if (target > matrix[row][mid]) {
		    start = mid + 1;
	    } else {
		    end = mid - 1;
	    }
    }   
    return false; 
}