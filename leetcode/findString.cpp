/* Substring with Concatenation of All Words 
You are given a string, S, and a list of words, L, that are all of the same length. Find all starting indices of substring(s) in S that is a concatenation of each word in L exactly once and without any intervening characters.

For example, given:
S: "barfoothefoobarman"
L: ["foo", "bar"]

You should return the indices: [0,9].
(order does not matter).
*/

vector<int> findSubstring(string S, vector<string> &L) {
	unordered_map<string, int> mp, count;
	vector<int> res;
	int N = S.length();
	int n = L.size();       // number of string pieces
	if (n == 0) return res;
	int m = L[0].length();  // length of each string piece

	for (int i = 0; i < L.size(); i++) {
		mp[L[i]]++;
		count[L[i]] = 0;
	}

	for (int i = 0; i <= N - m*n; i++) {   // don't forget the "<="
		count.clear();
		int index = 0;
		while (index < n) {
			string str = S.substr(i + index * m, m);
			if (mp.find(str) != mp.end()) {
				count[str]++;
				if (count[str] > mp[str]) 
					break;
			} else {
				break;
			}
			index++;
		}
		if (index == n) {
			res.push_back(i);
		}
	}
	return res;
}