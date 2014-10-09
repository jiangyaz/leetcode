/* Combination Sum II 
Given a collection of candidate numbers (C) and a target number (T), find all unique combinations in C 
where the candidate numbers sums to T.

Each number in C may only be used once in the combination.

Note:
All numbers (including target) will be positive integers.
Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
The solution set must not contain duplicate combinations.
For example, given candidate set 10,1,2,7,6,1,5 and target 8, 
A solution set is: 
[1, 7] 
[1, 2, 5] 
[2, 6] 
[1, 1, 6]
*/

vector<vector<int> > combinationSum2(vector<int> &num, int target) {
 	vector<vector<int> >res;
 	vector<int> sol;
 	sort(num.begin(), num.end());
 	getCombinationSum(res, sol, num, target, 0);
 	return res;
}

void getCombinationSum(vector<vector<int> >&res, vector<int> &sol, vector<int> &num, int sum, int start) {
	if (sum == 0) {
		res.push_back(sol);
		return;
	}
	for (int i = start; i < num.size(); i++) {
		if (num[i] <= sum) {
			sol.push_back(num[i]);
			getCombinationSum(res, sol, num, sum - num[i], i+1);  // i+1: because each number can only used once
			sol.pop_back();
			while (num[i] == num[i+1] && i <num.size()-1) { i++; }
		}
	}
}