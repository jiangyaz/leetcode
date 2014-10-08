
/* Longest Substring Without Repeating Characters 
Given a string, find the length of the longest substring without repeating characters. 
For example, the longest substring without repeating letters for "abcabcbb" is "abc", 
which the length is 3. For "bbbbb" the longest substring is "b", with the length of 1.
*/

int lengthOfLongestSubstring(string s) {
	int start = 0, end = 0;
	int maxLen = 0;
	unordered_set<char> table;

	while (end < s.length()) {
		if (table.find(s[end]) == table.end()) {
			// If the character is not found, move the end pointer
			table.insert(s[end]);
			maxLen = max(maxLen, end-start+1);
			end++;
		} else {
			table.erase(s[start]);
			start++;
		}
	}
	return maxLen;
}