/* Pascal's Triangle
Given numRows, generate the first numRows of Pascal's triangle.

For example, given numRows = 5,
Return

[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]
*/

vector<vector<int> > generate(int numRows) {
	vector<vector<int> > res;
	vector<int> sol;
	for (int i = 0; i < numRows; i++) {
		for (int j = sol.size()-1; j >= 1; j--) {
			sol[j] = sol[j] + sol[j-1];
		}
		sol.push_back(1);
		res.push_back(sol);
	}        
	return res;
}