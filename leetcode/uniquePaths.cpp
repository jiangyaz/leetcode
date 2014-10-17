/* Unique Paths
A robot is located at the top-left corner of a m x n grid 
(marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. 
The robot is trying to reach the bottom-right corner of the grid 
(marked 'Finish' in the diagram below).

How many possible unique paths are there?
*/

int uniquePaths(int m, int n) {
	vector<vector<int> >d(m, vector<int>(n, 1));
	for (int i = 1; i < m; i++) {
		for (int j = 1; j < n; j++) {
			d[i][j] = d[i-1][j] + d[i][j-1];
		}
	}
    return d[m-1][n-1];
}