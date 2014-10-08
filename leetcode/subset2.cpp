/* Subsets II 
Given a collection of integers that might contain duplicates, S, return all possible subsets.

Note:
Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.
For example,
If S = [1,2,2], a solution is:
[
  [2],
  [1],
  [1,2,2],
  [2,2],
  [1,2],
  []
]
*/


vector<vector<int> > subsetsWithDup(vector<int> &S) {
	vector<vector<int>> res(1);
	vector<int> sol;
	sort(S.begin(), S.end());
	getSubsetsWithDup(res, sol, S, 0); 
	return res;
}

void getSubsetsWithDup(vector<vector<int> > &res, vector<int> &sol, vector<int>&S, int level) {
	if (level == S.size()) {
		return;
	} 
	for (int i = level; i < S.size(); i++) {
		sol.push_back(S[i]);
		res.push_back(sol);
		getSubsetsWithDup(res, sol, S, i+1); 
		sol.pop_back();
		while (S[i] == S[i+1] && i < S.size()-1) { i++; }  // This line is crucial!
	}
}