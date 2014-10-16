/* Pascal's Triangle II
Given an index k, return the kth row of the Pascal's triangle.

For example, given k = 3,
Return [1,3,3,1].

[
     [1],  k = 0 
    [1,1], k = 1
   [1,2,1], k = 2
  [1,3,3,1], k = 3
 [1,4,6,4,1]
]
*/

vector<int> getRow(int rowIndex) {
	vector<int> res(rowIndex+1, 1);
	for (int i = 1; i < rowIndex; i++) {
		for (int j = i; j >= 1; j--)
			res[j] = res[j] + res[j-1];
	}
	return res;
}