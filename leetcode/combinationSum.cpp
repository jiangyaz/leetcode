/* Combination Sum
Given a set of candidate numbers (C) and a target number (T), find all unique combinations in C where 
the candidate numbers sums to T.

The same repeated number may be chosen from C unlimited number of times.

Note:
All numbers (including target) will be positive integers.
Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
The solution set must not contain duplicate combinations.
For example, given candidate set 2,3,6,7 and target 7, 
A solution set is: 
[7] 
[2, 2, 3] 
*/

vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
	sort(candidates.begin(), candidates.end());
	vector<vector<int> > res;
	vector<int> sol;
	getCombinationSum(res, sol, candidates, target, 0);
	return res;
}

void getCombinationSum(vector<vector<int> >&res, vector<int> &sol, vector<int> &candidates, int sum, int start) {
	if (sum == 0) {
		res.push_back(sol);
		return;
	}
	for (int i = start; i < candidates.size(); i++) {
		if (candidates[i] <= sum) {
			sol.push_back(candidates[i]);
			getCombinationSum(res, sol, candidates, sum - candidates[i], i);
			sol.pop_back();
		}
	}
}