/* Anagrams
Given an array of strings, return all groups of strings that are anagrams.
Note: All inputs will be in lower-case.
*/

vector<string> anagrams(vector<string> &strs) {
	vector<string> out;
	unordered_map<string, int> mp;
	for (int i = 0; i < strs.size(); i++) {
		string str = strs[i];
		sort(str.begin(), str.end());
		if (mp.find(str) != mp.end()) { 
			out.push_back(strs[i]);
			if (mp[str] != -1) {  
				out.push_back(strs[mp[str]]);
				mp[str] = -1;    // Set to -1, important!
			}
		} else {
			mp[str] = i;  // Store it's index
		}
	}        
	return out;
}