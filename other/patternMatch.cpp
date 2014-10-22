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
    // Tokenize the strings
    tokenize(p, pToken);
    tokenize(s, sToken);

    // First check if size is the same
    if (pToken.size() != sToken.size()) 
        return false;

    for (int i = 0; i < pToken.size(); i++) {
        // If the token is not in the map
        if (mp.find(pToken[i]) == mp.end()) {
            mp[pToken[i]] = sToken[i];
        } else {
            if (mp[pToken[i]] != sToken[i]) 
                return false;
        }
    }
    return true;
} 


bool matchPattern(string p, int startP, string s, int startS, unordered_map<char, string> &mp) {
    if (startP == p.length()) {
        return startS == s.length();
    }

    // First character of p is already in the map
    if (mp.find(p[startP]) != mp.end()) {
        int len = mp[p[startP]].length();
        if (mp[p[startP]] != s.substr(startS, len)) 
            return false;
        else
            return matchPattern(p, startP+1, s, startS + len, mp); 
    }

    // Loop through all posibilities of string s
    for (int i = startS; i < s.length(); i++) {
        string word = s.substr(startS, i-startS+1);
        mp[p[startP]] = word;
        if(matchPattern(p, startP+1, s, i+1, mp)) 
            return true;
        mp.erase(p[startP]);
    }
    return false;
}

// Without space
bool patternMatch2(string p, string s) {
    unordered_map<char, string> mp;
    return matchPattern(p, 0, s, 0, mp);
} 


