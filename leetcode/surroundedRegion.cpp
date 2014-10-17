/* Surrounded region
Given a 2D board containing 'X' and 'O', capture all regions surrounded by 'X'.

A region is captured by flipping all 'O's into 'X's in that surrounded region.

*/

void dfs(vector<vector<char>> &board, int i, int j, vector<vector<bool> > &visited) {
	int m = board.size();
	int n = board[0].size();

	if (i < 0 || i >= m || j < 0 || j >= n) return;
	if (board[i][j] != 'O' || visited[i][j]) return;

	visited[i][j] = true;
	dfs(board, i, j-1, visited);
	dfs(board, i, j+1, visited);
	dfs(board, i+1, j, visited);
	dfs(board, i-1, j, visited);
}


void solve(vector<vector<char>> &board) {
	int m = board.size();
	if (m == 0) return;
	int n = board[0].size();
	vector<vector<bool> >visited(m, vector<bool>(n, false));

	// Check up and botton sides
	for (int i = 0; i < n; i++) {
		dfs(board, 0, i, visited);
		dfs(board, m-1, i, visited);
	}

	// Check left and right sides 
	for (int i = 1; i < m-1; i++) {
		dfs(board, i, 0, visited);
		dfs(board, i, n-1, visited);
	}

	// Go through again
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (board[i][j] == 'O' && !visited[i][j]) 
				board[i][j] = 'X';
		}
	}
}