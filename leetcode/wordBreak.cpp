/* Word break
Given a string s and a dictionary of words dict, determine if s can be segmented into a 
space-separated sequence of one or more dictionary words.

For example, given
s = "leetcode",
dict = ["leet", "code"].

Return true because "leetcode" can be segmented as "leet code".
*/

bool wordBreak(string s, unordered_set<string> &dict) {
	if (s.length() == 0) return true;
      
    for (int i = 1; i <= s.length(); i++) {
    	string curStr = s.substr(0, i);
    	if (dict.find(curStr) != dict.end())
    		return wordBreak(s.substr(i, s.length()-i), dict);
    }  
	return false;
}

// Another solution is dynamic programming (better!)