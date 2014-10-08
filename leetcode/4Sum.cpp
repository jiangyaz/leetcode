/* 4Sum
Given an array S of n integers, are there elements a, b, c, and d in S such that 
a + b + c + d = target? Find all unique quadruplets in the array which gives the 
sum of target.
Elements in a quadruplet (a,b,c,d) must be in non-descending order. 
(ie, a ≤ b ≤ c ≤ d)
The solution set must not contain duplicate quadruplets.
    For example, given array S = {1 0 -1 0 -2 2}, and target = 0.

    A solution set is:
    (-1,  0, 0, 1)
    (-2, -1, 1, 2)
    (-2,  0, 0, 2)
*/

vector<vector<int> > fourSum(vector<int> &num, int target) {
	vector<vector<int> >res;
	vector<int> sol;
	if (num.size() == 0) return res;
	sort(num.begin(), num.end());

	for (int i = 0; i < num.size()-1; i++) {
		if (i > 0 && num[i] == num[i-1]) 
			continue;
		for (int j = i+1; j < num.size(); j++) {
			if (j > i+1 && num[j] == num[j-1]) 
				continue;
			int targetSum = target - num[i] - num[j];
			int start = j+1, end = num.size() -1;
			while (start < end) {
				if (num[start] + num[end] == targetSum) {
					sol.push_back(num[i]);
					sol.push_back(num[j]);
					sol.push_back(num[start]);
					sol.push_back(num[end]);
					res.push_back(sol);
					sol.clear();
					start++; end--;
					while (num[start] == num[start-1]) start++;
					while (num[end] == num[end+1]) end--;
				} else if (num[start] + num[end] > targetSum) {
					end--;
				} else {
					start++;
				}
			}
		}
	} 
	return res;       
}