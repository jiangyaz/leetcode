/* Minimum Window Substring
Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).

For example,
S = "ADOBECODEBANC"
T = "ABC"
Minimum window is "BANC".

Note:
If there is no such window in S that covers all characters in T, return the emtpy string "".

If there are multiple such windows, you are guaranteed that there will always be only one unique minimum window in S.
*/

string minWindow(string S, string T) {
    if (T.length() > S.length()) return "";

    unordered_map<char, int> mp, count;
    int minStart = 0, minLen = 0;
    int p1 = 0, p2 = 0;

    for (int i = 0; i < T.length(); i++) {
        mp[T[i]]++;
    }   

    int matchedNum = 0;
    while (p2 < S.length()) {
        // Step 1: move end pointer
        while (matchedNum < T.length() && p2 < S.length()) {
            if (mp.find(S[p2]) != mp.end() && count[S[p2]] < mp[S[p2]]) {  // attention!
                matchedNum++;      
            }
            count[S[p2]]++;
            p2++;
        }
        // Step 2: move start pointer
        while (matchedNum == T.length()) {
            // update min length, if necessary
            if (minLen == 0 || p2 - p1 < minLen) {
                minLen = p2 - p1;
                minStart = p1;
            }
            count[S[p1]]--;
            if (mp.find(S[p1]) != mp.end() && count[S[p1]] < mp[S[p1]]) {   // attention!
                matchedNum--;
            }
            p1++;
        }
    } 
    return S.substr(minStart, minLen);    
}






