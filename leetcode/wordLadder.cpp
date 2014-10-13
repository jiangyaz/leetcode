/* word ladder 
Given two words (start and end), and a dictionary, find the length of shortest transformation sequence from start to end, such that:

Only one letter can be changed at a time
Each intermediate word must exist in the dictionary
For example,

Given:
start = "hit"
end = "cog"
dict = ["hot","dot","dog","lot","log"]
As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
return its length 5.
*/


int ladderLength(string start, string end, unordered_set<string> &dict) {
	unordered_map<string, int> dist;
	queue<string> q;
	q.push(start);
	dist[start] = 0;

	while (!q.empty()) {
		string curStr = q.front();
		int curDist = dist[curStr];
		q.pop();
		if (curStr == end) return curDist;

		for (int i = 0; i < curStr.length(); i++) {
            for (char ch = 'a'; ch <= 'z'; ch++) {
            	if (ch != curStr[i]) {
            		string testStr = curStr;
            		testStr[i] = ch;
            		if (dict.find(testStr) != dict.end() && dist.find(testStr) == dist.end()) {
            			dist[testStr] = curDist + 1;
            			q.push(testStr);
            		}
            	}
            }
        }
	}
	return 0;
}