/* LURCache
Design and implement a data structure for Least Recently Used (LRU) cache. 
It should support the following operations: get and set.

get(key) - Get the value (will always be positive) of the key if the key exists 
in the cache, otherwise return -1.
set(key, value) - Set or insert the value if the key is not already present. 
When the cache reached its capacity, it should invalidate the least recently 
used item before inserting a new item.

*/

class LRUCache{

struct Node {
	int val;
	int key;
	Node* next;
	Node* prev;
	Node(int x, int k): val(x), key(k), next(NULL), prev(NULL) {};
};

private:
	int cp;
	unordered_map<int, Node *> mp;
	Node* head;
	Node* tail;

	void moveToFront(Node *node) {
		node->prev->next = node->next;
		if (node->next) {
			node->next->prev = node->prev;
		} else {
			tail = node->prev;
		}
		node->next = head;
		head->prev = node;
		head = node;
	}

public:
    LRUCache(int capacity) {
        cp = capacity;
        head = NULL;
        tail = NULL;
    }
    
    int get(int key) {
        if (mp.find(key) == mp.end()) 
        	return -1;
        Node *node = mp[key];
        moveToFront(node);
        return node->val;
    }
    
    void set(int key, int value) {
    	if (mp.find(key) != mp.end()) { // found
    		mp[key]->val = value;
    		moveToFront(mp[key]);
    	} else {   // key not found;
    		if (mp.size() == cp) {   // if capacity full
    			mp.erase(tail->key);
    			tail = tail->prev;
    			tail->next = NULL;
    		} 
    		Node *newNode = new Node(value, key);
    		mp[key] = newNode;
    		newNode->next = head;
    		head->prev = newNode;
    		head = newNode;
    	}     
    }
};