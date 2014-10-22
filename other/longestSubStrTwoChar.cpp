// Longest substring with at most 2 charaters 

string longestStrTwoChar(string &s) {
    int maxLen = 0, start = 0;
    int index1 = 0, index2 = -1;
    int startIndex = 0;

    for (int i = 0; i < s.length(); i++) {
        if (s[i] == s[index1]) {
            index1 = i;
        } else if (index2 == -1) {
            index2 = i;
        } else if (s[i] == s[index2]) {
            index2 = i;
        } else {
            if (index1 < index2) {
                start = index1 + 1;
                index1 = i;
            } else {
                start = index2 + 1;
                index2 = i;
            }
        }
        // update length
        if (i - start + 1 > maxLen) {
            maxLen = i - start + 1;
            startIndex = start;
        }
        // cout << s[i] << " 1:" << index1 << " 2:" << index2 << " len:" << maxLen << " start:" << start <<endl;
    }
    return s.substr(startIndex, maxLen);
}