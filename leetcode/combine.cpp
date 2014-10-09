/* Combinations 
Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

For example,
If n = 4 and k = 2, a solution is:

[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]
*/

vector<vector<int> > combine(int n, int k) {
	vector<vector<int> >res;
	vector<int> sol;
	getCombination(res, sol, 1, n, k);
	return res;
}

void getCombination(vector<vector<int> > &res, vector<int> &sol, int start, int n, int k) {
	if (sol.size() == k) {
		res.push_back(sol);
		return;
	}
	for (int i = start; i <= n; i++) {
		sol.push_back(i);
		getCombination(res, sol, i+1, n, k);
		sol.pop_back();
	}
}