/* word break II
Given a string s and a dictionary of words dict, add spaces in s to construct a sentence 
where each word is a valid dictionary word.

Return all such possible sentences.

For example, given
s = "catsanddog",
dict = ["cat", "cats", "and", "sand", "dog"].

A solution is ["cats and dog", "cat sand dog"].
*/

vector<string> wordBreak(string s, unordered_set<string> &dict) {
    vector<string> res;
    string sol;
    vector<bool> tab(s.length()+1, true);
    getWordBreak(res, sol, dict, s, 0, tab);
    return res;
}

void getWordBreak(vector<string> &res, string &sol, unordered_set<string> &dict, string s, int start, vector<bool> &tab) {
    if (start == s.length()) {
	    sol.pop_back();
	    res.push_back(sol);
	    return;
    }
    for (int i = start; i < s.length(); i++) {
	    string curStr = s.substr(start, i-start+1);
	    if (dict.find(curStr) != dict.end() && tab[i+1]) { // it's in the dictionary
		    int len = sol.length();
		    sol += (curStr + ' ');
		    int solNum = res.size();
		    getWordBreak(res, sol, dict, s, i+1, tab);
		    if (res.size() == solNum) 
		    	tab[i+1] = false;
		    sol.resize(len);
	    }
    }
}