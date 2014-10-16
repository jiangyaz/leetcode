/* triangle
Given a triangle, find the minimum path sum from top to bottom. 
Each step you may move to adjacent numbers on the row below.

For example, given the following triangle
[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]
The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).

*/

int minimumTotal(vector<vector<int> > &triangle) {
	int n = triangle.size();
	if (n == 0) return 0;
	vector<int> d(triangle[n-1].begin(), triangle[n-1].end());

	for (int i = n-2; i >= 0; i--) {
		for (int j = 0; j <= i; j++) {
			d[j] =  triangle[i][j] + min(d[j], d[j+1]);
		}
	}        
	return d[0];
}