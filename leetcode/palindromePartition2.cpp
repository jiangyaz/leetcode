/* Palindrome Partitioning II
Given a string s, partition s such that every substring of the partition is a palindrome.

Return the minimum cuts needed for a palindrome partitioning of s.

For example, given s = "aab",
Return 1 since the palindrome partitioning ["aa","b"] could be produced using 1 cut.
*/

int minCut(string s) {
	int n = s.length();
	vector<vector<bool> > isPalin(n, vector<bool>(n, false));

	for (int i = 0; i < n; i++) {
		isPalin[i][i] = true;
		if (i < n-1 && s[i] == s[i+1]) 
			isPalin[i][i+1] = true;
	}
	for (int i = n-2; i >= 0; i--) {     // important!
		for (int j = i+2; j < n; j++) {
			if (s[i] == s[j] && isPalin[i+1][j-1])
				isPalin[i][j] = true;
		}
	}

	vector<int> d(n, 0);
	for (int i = 1; i < n; i++) {
		d[i] = d[i-1] + 1;
		for (int k = 0; k <= i; k++) {
			if (k == 0 && isPalin[0][i]) {
				d[i] = 0;
			} else if (isPalin[k][i]) {
				d[i] = min(d[i], d[k-1]+1);
			}
		}
	}   
	return d[n-1];     
}