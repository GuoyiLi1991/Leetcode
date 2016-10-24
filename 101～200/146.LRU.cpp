class Compare  //determining the priority by accessing time
{
public:
    bool operator()(pair<int, int> a, pair<int, int> b)
    {
        return (a.second > b.second);
    }
};

class LRUCache{
    int maxCap;
    int t=0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> PQ;  //pair<value, time>
    unordered_map<int, int> valuetable;  
    unordered_map<int, int> timetable;
    
public:
    LRUCache(int capacity) {
        maxCap = capacity;
    }
    
    int get(int key) {
        t++;
        //query valuetable
        if (valuetable.find(key) == valuetable.end())  //if not exist, return -1
            return -1;
        else //if exist, return value
        {
            timetable[key] = t;
            return valuetable[key];
        }
    }
    
    void set(int key, int value) {
        t++;
        //if present, then just update the time
        if (valuetable.find(key) != valuetable.end())
        {
            timetable[key] = t;
            valuetable[key] = value;
        }
        else         //if not present, insert the pair<value, time> to PQ
        {
            //before insertion, check the capacity
            if (PQ.size() >= maxCap) //need to remove PQ.top() first
            {
                while (PQ.top().second != timetable[PQ.top().first])
                {
                    pair<int, int> x = PQ.top();
                    x.second = timetable[x.first];
                    PQ.pop();
                    PQ.push(x);
                }
                valuetable.erase(PQ.top().first);
                PQ.pop();
            }
            //insertion
            valuetable[key] = value;
            timetable[key] = t;
            PQ.push(make_pair(key, t));
        }
    }
    
};


/////////
// deque TLE
class LRUCache{
    deque<int> keys;
    unordered_map<int, deque<int>::iterator> ht; //<key, itr>
    int cap;
    unordered_map<int, int> dict; //<key, value>
    
    void touch(int key) {
       // auto pos  = find(keys.begin(), keys.end(), key);
        keys.erase(ht[key]);
        keys.push_back(key);
        ht[key] = keys.end();
    }
    
public:
    LRUCache(int capacity) {
        //if (cap >1000) exit(0);
        cap = capacity;
    }
    
    int get(int key) {
        if (dict.count(key) == 0) 
            return -1;
        touch(key);
        return dict[key];
    }
    
    void set(int key, int value) {
        if (dict.count(key) != 0) {// found
            touch(key);
            dict[key] = value;
            ht[key] = keys.end();
            return;
        }
        
        //if not found
        if (keys.size() == cap) {
            //remove oldest one
            dict.erase(keys.front());
            ht.erase(keys.front());
            keys.pop_front();
        }
        keys.push_back(key);
        ht[key] = keys.end();
        dict[key] = value;
    }
};

///////////////
// Priority queue rewrite
struct Elem{
    int time;
    int key;
  // int value;
};

struct Cmp {
    bool operator()(Elem& a, Elem& b) { //min heap
        return a.time > b.time;
    }
};
class LRUCache{
    //typedef pair<int, int> Elem; //<time, key>
    int cap;
    int t;
    unordered_map<int, int> key_time;
    unordered_map<int, int> key_value;
    priority_queue<Elem, vector<Elem>, Cmp> pq; //older has higher priority
public:
    LRUCache(int capacity) {
        cap = capacity;
        t = 0;
    }
    
    int get(int key) {
        t++;
        if (key_value.count(key) == 0)
            return -1;
        
        key_time[key] = t;
        return key_value[key];
    }
    
    void set(int key, int value) {
        t++;
        
        //already in cache, just update timestamp and value
        if (key_value.count(key)) {
            key_time[key] = t;
            key_value[key] = value;
        }
        else {
            if (pq.size() >= cap) {
                while (pq.top().time != key_time[pq.top().key]) { 
                    Elem x = pq.top();
                    x.time = key_time[x.key];
                    pq.pop();
                    pq.push(x);
                }
                
                int oldKey = pq.top().key;
                key_value.erase(oldKey);
                key_time.erase(oldKey);
                pq.pop();
            }
            
            //insert
            key_value[key] = value;
            key_time[key] = t;
            pq.push(Elem{t, key});
        }
    }
};


class Node {
public:
    Node* prev;
    Node* next;

    int key;
    int value;

    Node() {}
    Node(int k, int v) {
        key = k;
        value = v;
    }
};

class LRUCache {
    unordered_map<int, Node*> key_node_table;
    Node *head; //the oldest
    Node *tail; // the newest

    int cap;

    void appendTail(Node* node) {
        node->next = tail;
        node->prev = tail->prev;
        tail->prev->next = node;
        tail->prev = node;
    }

public:
    LRUCache(int capacity) {
        cap = capacity;
        head = new Node(); //dummy node
        tail = new Node(); //dummy node

        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if (key_node_table.count(key) == 0) //not found
            return -1;
        else { //touch the node, and return value with the ht
            Node* node = key_node_table[key];
            //remove node from the list
            node->prev->next = node->next;
            node->next->prev = node->prev;

            appendTail(node);
            return node->value;
        }

    }

    void set(int key, int value) {
        if (key_node_table.count(key)) { //found in the cache
            Node* node = key_node_table[key];
            node->value = value;
            key_node_table[key] = node;

            node->prev->next = node->next;
            node->next->prev = node->prev;

            appendTail(node);
            return;
        }
        else { //not in the cache
            if (key_node_table.size() == cap) { //if full, remove one
                //remove head
                Node* tmp = head->next;
                head->next = head->next->next;
                head->next->prev = head;
                key_node_table.erase(tmp->key);
            } 
            //else if not full, skip remvoving

            Node* node = new Node(key, value);
            appendTail(node);
            key_node_table[key] = node;
        }
    }
};






























