class LRUCache {
public:
    class node {
    public:
        int key;
        int val;
        node *next;
        node *prev;
        node(int key_, int value_) {
            key = key_;
            val = value_;
        }
    };

    node *head = new node(-1, -1);
    node *tail = new node(-1, -1);
    int cap;
    unordered_map<int, node *> mpp;

    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }

    void addnode(node *newnode) {
        node *temp = head->next;
        newnode->next = temp;
        newnode->prev = head;
        head->next = newnode;
        temp->prev = newnode;
    }

    void deletenode(node *delnode) {
        node *delprev = delnode->prev;
        node *delnext = delnode->next;
        delprev->next = delnext;
        delnext->prev = delprev;
    }

    int get(int key_) {
        if (mpp.find(key_) != mpp.end()) {
            node *resnode = mpp[key_];
            int res = resnode->val;
            mpp.erase(key_);
            deletenode(resnode);
            addnode(resnode);
            mpp[key_] = head->next;
            return res;
        } else {
            return -1;
        }
    }

    void put(int key, int value) {
        if (mpp.find(key) != mpp.end()) {
            node *existingnode = mpp[key];
            existingnode->val = value;
            mpp.erase(key);
            deletenode(existingnode);
        }

        if (mpp.size() == cap) {
            mpp.erase(tail->prev->key);
            deletenode(tail->prev);
        }

        addnode(new node(key, value));
        mpp[key] = head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key, value);
 */
