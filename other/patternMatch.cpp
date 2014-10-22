

void tokenize(string str, vector<string> &tokens) {
	int index = 0;
	while (index < str.length()) {
		string token;
		// Skip the initial empty spaces
		while (str[index] == ' ' && index < str.length()) {
			index++;
		}
		// Loop through the non-space characters until hit space
		while (str[index] != ' ' && index < str.length()) {
			token += str[index++];
		}
		if (token.length() > 0) {
			tokens.push_back(token);
		}
	}
}


// With space
bool patternMatch1(string p, string s) {
	unordered_map<string, string> mp;
	vector<string> pToken, sToken;
	tokenize(p, pToken);
	tokenize(s, sToken);

	if (pToken.size() != s.Token.size()) return false;
	for (int i = 0; i < pToken.size(); i++) {
		// If the token is not in the map
		if (mp.find(pToken[i]) == mp.end()) {
			mp[pToken[i]] = sToken[i];
		} else {
			if (mp[pToken] != sToken[i]) 
				return false;
		}
	}
	return true;
} 


// Without space
bool patternMatch2(string p, string s) {
	unordered_map<char, string> mp;
	return matchPattern(p, 0, s, 0, mp);
} 

bool matchPattern(string p, int startP, string s, int startS, unordered_map<char, string> &mp) {
	if (startP == p.length() && startS == s.length()) return true;

	for (int i = startS; i < s.length(); i++) {
		string word = s.subStr(startS, i-startS+1);
		if (mp.find(p[startP]) == mp.end()) {    // If not found, add
			mp[p[startP]] = word;
			return matchPattern(p, startP+1, s, i+1, mp);
			mp.erase(p[startP]);
		} else {
			if (mp[p[startP]] == word) {
				return matchPattern(p, startP+1, s, i+1, mp);
			}
		}
	}
	return false;
}






