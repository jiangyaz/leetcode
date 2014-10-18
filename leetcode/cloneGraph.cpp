/* Clone Graph
Clone an undirected graph. 
ach node in the graph contains a label and a list of its neighbors.

/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */

UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
	if (node == NULL) return NULL;
	unordered_map<UndirectedGraphNode *, UndirectedGraphNode *> mp;
	queue<UndirectedGraphNode *>q;

	UndirectedGraphNode *copy = new UndirectedGraphNode(node->label);
	mp[node] = copy;
	q.push(node);   

	// Start BFS
	while (!q.empty()) {
		UndirectedGraphNode *cur = q.front();
		q.pop();
		// Copy its neighbors
		for (int i = 0; i < cur->neighbors.size(); i++) {
			UndirectedGraphNode *neighbor = cur->neighbors[i];
			if (mp.find(neighbor) != mp.end()) {   // The neighbor has been visited
				mp[cur]->neighbors.push_back(mp[neighbor]);
			} else {
				// Create a copy for neighbor
				UndirectedGraphNode *newCopy = new UndirectedGraphNode(neighbor->label);
				mp[neighbor] = newCopy;
				mp[cur]->neighbors.push_back(newCopy);
				q.push(neighbor);
			}
		}
	}    
	return copy;
}
