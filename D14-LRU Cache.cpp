
/*
Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.
Implement the LRUCache class:
* LRUCache(int capacity) Initialize the LRU cache with positive size capacity.
* int get(int key) Return the value of the key if the key exists, otherwise return -1.
* void put(int key, int value) Update the value of the key if the key exists. Otherwise, add the key-value pair to the cache. 
    If the number of keys exceeds the capacity from this operation, evict the least recently used key.
The functions get and put must each run in O(1) average time complexity.
*/

/*
Time: O(1)
Space: O(n)
Doubly Linked List + Hashmap.
*/


class LRUCache {
public:
    
    class Node {
        public:
        int key;
        int value;
        Node* next;
        Node* prev;
        Node (int x, int y){
            key = x;
            value = y;
            next = NULL;
            prev = NULL;
        }
    };
    
    unordered_map<int , Node*>mp;
    Node* head = new Node(-1,-1);
    Node* tail = new Node(-1,-1);
    
    int cap;
     LRUCache(int capacity) {
        this->cap = capacity;
         head->next = tail;
         tail->prev = head;
    }
    
    void addnode(Node* x){
        Node* temp = head->next;
        x->next = temp;
        head->next = x;
        temp->prev = x;
        x->prev = head;
    }
    
    
    void deletenode(Node* x){
        Node* dprev = x->prev;
        Node* dnex = x->next;
        dprev->next = dnex;
        dnex->prev = dprev;
    }
    
    int get(int key) {
        if(mp.find(key) != mp.end()){
            Node* resnode = mp[key];
            int val = resnode->value;
            deletenode(resnode);
            addnode(resnode);
            mp.erase(key);
            mp[key] = head->next;
            return val;
        }
        
        return -1;
    }
    
    void put(int key, int value) {
        if(mp.find(key) != mp.end()){
            Node* resnode = mp[key];
            deletenode(resnode);
            mp.erase(key);
        }
        if(mp.size() == cap){
            mp.erase(tail->prev->key);
            deletenode(tail->prev);
        }
        addnode(new Node(key,value));
        mp[key] = head->next;

    }
};