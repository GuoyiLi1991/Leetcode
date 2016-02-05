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