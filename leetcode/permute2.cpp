/* Permutations II 
Given a collection of numbers that might contain duplicates, 
return all possible unique permutations.

For example,
[1,1,2] have the following unique permutations:
[1,1,2], [1,2,1], and [2,1,1].
*/

vector<vector<int> > permuteUnique(vector<int> &num) {
	vector<vector<int> >res;
	vector<int> sol;
	vector<bool> visited(num.size(), false);
 	sort(num.begin(), num.end());

 	getPermuteUnique(res, sol, num, visited, 0);
 	return res;

}

void getPermuteUnique(vector<vector<int> >&res, vector<int> &sol, vector<int> &num, vector<bool> &visited, int level) {
	if (level == num.size()) {
		res.push_back(sol);
		return;
	} 

	for (int i = 0; i < num.size(); i++) {
		if (visited[i] == false) {
			// if (i > 0 && num[i] == num[i-1] && visited[i-1] == false)   // the only difference here
		    //    continue;                                                // are these 2 lines.
			visited[i] = true;
			sol.push_back(num[i]);
			getPermute(res, sol, num, visited, level+1);
			sol.pop_back();
			visited[i] = false;
			while (num[i] == num[i+1] && i < num.size()-1) {i++;}
		}
	}
}