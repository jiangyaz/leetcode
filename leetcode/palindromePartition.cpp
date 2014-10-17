/* Palindrome Partitioning

Given a string s, partition s such that every substring of the partition is a palindrome.

Return all possible palindrome partitioning of s.

For example, given s = "aab",
Return

  [
    ["aa","b"],
    ["a","a","b"]
  ]

*/

bool isPalidrome(string s) {
	if (s.length() <= 1) return true;
	int start = 0, end = s.length()-1;
	while (start < end) {
		if (s[start] != s[end]) 
			return false;
		start++;
		end--;
	}
	return true;
}

vector<vector<string>> partition(string s) {
	vector<vector<string> > res;
	vector<string> sol;
	getPartition(res, sol, s, 0);
	return res;
}

void getPartition(vector<vector<string> >&res, vector<string>&sol, string &s, int start) {
	if (start == s.length()) {
		res.push_back(sol);
		return;
	}
	for(int i = start+1; i <= s.length(); i++) {
		if (isPalidrome(s.substr(start, i-start))) {
			sol.push_back(s.substr(start, i-start));
			getPartition(res, sol, s, i);
			sol.pop_back();
		}
	}
}