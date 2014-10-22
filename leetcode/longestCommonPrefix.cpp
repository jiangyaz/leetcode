/* Longest Common Prefix
Write a function to find the longest common prefix string amongst 
an array of strings.
*/

string longestCommonPrefix(vector<string> &strs) {
	string res;
	if (strs.size() == 0) return res;
	
	int index = 0;
	while (index < strs[0].size()) {
		char ch = strs[0][index];
		for (int i = 1; i < strs.size(); i++) {
			if (strs[i].length() < index+1 || strs[i][index] != ch)
				return res;
		}
		res.push_back(ch);
		index++;
	}
	return res;
}