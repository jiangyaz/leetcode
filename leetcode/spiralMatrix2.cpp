/* Spiral Matrix II

Given an integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.

For example,
Given n = 3,

You should return the following matrix:
[
 [ 1, 2, 3 ],
 [ 8, 9, 4 ],
 [ 7, 6, 5 ]
]

*/

vector<vector<int> > generateMatrix(int n) {
	vector<vector<int> >out(n, vector<int>(n, 0));
	int stepRow[4] = {0, 1, 0, -1};
	int stepCol[4] = {1, 0, -1, 0};
	int rowTurn = 0, colTurn = n - 1;
	int i = 0, j = 0, dir = 0, count = 1;

	while (count <= n * n) {
		out[i][j] = count;
		count++;
		if (i == rowTurn && j == colTurn) {
			if (dir == 0) {
				rowTurn = n - rowTurn - 1;
			} else if (dir == 1) {
				colTurn = n - colTurn - 1;
			} else if (dir == 2) {
				rowTurn = n - rowTurn;
			} else {
				colTurn = n - colTurn - 2;
			}
			dir++;
			if (dir > 3) dir = 0;
		}
		i += stepRow[dir];
		j += stepCol[dir];
	}
	return out;        
}