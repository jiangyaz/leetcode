/* Subset
Given a set of distinct integers, S, return all possible subsets.

Note:
Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.
For example,
If S = [1,2,3], a solution is:
[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]
*/

vector<vector<int> > subsets(vector<int> &S) {
	vector<vector<int>> res(1);
	vector<int> sol;
	sort(S.begin(), S.end());
	getSubsets(res, sol, S, 0); 
	return res;
}

void getSubsets(vector<vector<int> > &res, vector<int> &sol, vector<int>&S, int level) {
	if (level == S.size()) {
		return;
	} 
	for (int i = level; i < S.size(); i++) {
		sol.push_back(S[i]);
		res.push_back(sol);
		getSubsets(res, sol, S, i+1); 
		sol.pop_back();
	}
}