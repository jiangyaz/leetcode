/* Rotate Image

You are given an n x n 2D matrix representing an image.

Rotate the image by 90 degrees (clockwise).

Follow up:
Could you do this in-place?
*/

void rotate(vector<vector<int> > &matrix) {
	int n = matrix.size();
	// First flip it 45 degree
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n-i; j++) {
			int tmp = matrix[i][j];
			matrix[i][j] = matrix[n-j-1][n-i-1];  // notice: j and i switched!
			matrix[n-j-1][n-i-1] = tmp;
		}
	}
	// Flip it vertically
	for (int i = 0; i < n/2; i++) {
		for (int j = 0; j < n; j++) {
			int tmp = matrix[i][j];
			matrix[i][j] = matrix[n-i-1][j];
			matrix[n-i-1][j] = tmp;
		}
	}       
}