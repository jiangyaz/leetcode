/* Spiral Matrix
Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.
For example,
Given the following matrix:

[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
You should return [1,2,3,6,9,8,7,4,5].
*/

vector<int> spiralOrder(vector<vector<int> > &matrix) {
	vector<int> res;
	int m = matrix.size();
	if (m == 0) return res;
	int n = matrix[0].size();

	int stepRow[4] = {0,1,0,-1};
	int stepCol[4] = {1,0,-1,0};

	int dir = 0, i = 0, j = 0;
	int rowTurn = 0, colTurn = n - 1;
	
	while (res.size() < m*n) {
		res.push_back(matrix[i][j]);
		if (i == rowTurn && j == colTurn) {
            if (dir == 0) {   // Go right
            	rowTurn = m - rowTurn - 1;
            } else if (dir == 1) {  // Go down
            	colTurn = n - colTurn - 1;
            } else if (dir == 2) {  // Go left
            	rowTurn = m - rowTurn;
            } else if (dir == 3) {  // Go up
            	colTurn = n - colTurn - 2;
            }
        	dir++;
        	if (dir > 3) dir = 0;
    	}
		i += stepRow[dir];
		j += stepCol[dir];
	}
	return res;
}