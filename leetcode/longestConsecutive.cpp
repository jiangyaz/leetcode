 /* Longest Consecutive Sequence 
Given an unsorted array of integers, 
find the length of the longest consecutive elements sequence.

For example,
Given [100, 4, 200, 1, 3, 2],
The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4.

Your algorithm should run in O(n) complexity.
*/


int longestConsecutive(vector<int> &num) {
	int n = num.size();
	if (n == 0) return 0;
	vector<bool> visited(n, false);
	unordered_map<int, int> mp;

	for (int i = 0; i < n; i++) {
		mp[num[i]] = i;
	}        
	int maxLen = 0;
	for (int i = 0; i < n; i++) {
		if (!visited[i]) {
			int len = 1;
			visited[i] = true;
			int curNum = num[i] + 1;
			while (mp.find(curNum) != mp.end()) {
				visited[mp[curNum] = true;
				len++;
				off++;
			}
			curNum = num[i] - 1;
			while (mp.find(curNum) != mp.end()) {
				visited[mp[curNum] = true;
				len++;
				off--;
			}
			maxLen = max(maxLen, len);
		}
	}
	return maxLen;
}

// Version 2, passes the test
int longestConsecutive(vector<int> &num) {
    int n = num.size();
    if (n == 0) return 0;
    unordered_map<int, int> mp;

    for (int i = 0; i < n; i++) {
	    mp[num[i]] = i;
    }        
    int maxLen = 0;
    for (int i = 0; i < n; i++) {
        mp.erase(num[i]);
		int len = 1, curNum = num[i]+1;
		while (mp.find(curNum) != mp.end()) {
		    mp.erase(curNum);
			len++;
			curNum++;
		}
		curNum = num[i]-1;
		while (mp.find(curNum) != mp.end()) {
		    mp.erase(curNum);
			len++;
			curNum--;
		}
		maxLen = max(maxLen, len);
    }
    return maxLen;
}