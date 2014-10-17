/* Simplify Path
Given an absolute path for a file (Unix-style), simplify it.

For example,
path = "/home/", => "/home"
path = "/a/./b/../../c/", => "/c"
*/

string simplifyPath(string path) {
	if (path.size() == 0) return "";
	stack<string> sta;
	int index = 0, start, end;
	
	while (index < path.size()) {
		// Find the element between two "/" signs
		while (path[index] == '/' && index < path.size()) { index++; }
		if (index == path.size()) break;
		start = index;
		while (path[index] != '/' && index < path.size()) { index++;}
		end = index - 1;
		
		string elem = path.substr(start, end - start + 1);
		if (elem == "..") {
			if (!sta.empty()) sta.pop();
		} else if (elem != ".") {
			sta.push(elem);
		}
	} 
	string out;
	if (sta.empty()) return "/";
	while (!sta.empty()) {
		out = "/" + sta.top() + out;
		sta.pop();
	} 
	return out;      
}