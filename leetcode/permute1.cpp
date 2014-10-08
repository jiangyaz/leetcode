/* Permutations
Given a collection of numbers, return all possible permutations.

For example,
[1,2,3] have the following permutations:
[1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], and [3,2,1].
*/

vector<vector<int> > permute(vector<int> &num) {
	vector<vector<int> > res;
	vector<int> sol;
	vector<bool> visited(num.size(), false);

	getPermute(res, sol, num, visited, 0);
	return res;
}

void getPermute(vector<vector<int> >&res, vector<int> sol, vector<int> &num, vector<bool> &visited, int level) {
	if (level == num.size()) {
		res.push_back(sol);
		return;
	}
	for (int i = 0; i < num.size(); i++) {
		if (visited[i] == false) {
			visited[i] = true;
			sol.push_back(num[i]);
			getPermute(res, sol, num, visited, level+1);
			sol.pop_back();
			visited[i] = false;
		}
	}
}