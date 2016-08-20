class ZigzagIterator {
    vector<int> v;
    int p;
public:
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        p = 0;
        int p1 = 0, p2 = 0;
        int n1 = v1.size(), n2 = v2.size();
        while (p1 < n1 && p2 < n2){
            v.push_back(v1[p1++]);
            v.push_back(v2[p2++]);
        }
        while (p1 < n1)
            v.push_back(v1[p1++]);
        while (p2 < n2)
            v.push_back(v2[p2++]);
    }

    int next() {
        return v[p++];
    }

    bool hasNext() {
        return (p < v.size());
    }
};

/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * ZigzagIterator i(v1, v2);
 * while (i.hasNext()) cout << i.next();
 */


 ///////solution 2: store iterators, then no need to
 // keep the global vector
 class ZigzagIterator {
    vector<int>::iterator begin[2], end[2]; //store the beginning and ending indices
    int p;
public:
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        p = 0;
        begin[0] = v1.begin();
        begin[1] = v2.begin();
        end[0] = v1.end();
        end[1] = v2.end();
    }

    int next() {
        p++;
        if (begin[0] == end[0]) //v1 finish
            return *begin[1]++;
        else if (begin[1] == end[1]) //v0 finish
                return *begin[0]++;
        else { //v0 and v1 haven't finished
            int i = p % 2;
            if (i == 0)
                return *begin[1]++;
            else
                return *begin[0]++;
        }
    }

    bool hasNext() {
        return !(begin[0] == end[0] && begin[1] == end[1]);
    }
};

/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * ZigzagIterator i(v1, v2);
 * while (i.hasNext()) cout << i.next();
 */

 class ZigzagIterator {
    queue<pair<vector<int>::iterator, vector<int>::iterator>> q;
public:
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        if (!v1.empty())
            q.push(make_pair(v1.begin(), v1.end()));
        if (!v2.empty())
            q.push(make_pair(v2.begin(), v2.end()));
    }

    int next() {
        vector<int>::iterator begin = q.front().first;
        vector<int>::iterator end = q.front().second;
        q.pop();
        if (begin + 1 != end)
            q.push(make_pair(begin + 1, end));
        return *begin;
    }

    bool hasNext() {
        return !q.empty();
    }
};

 ////////////
 // Follow up: compatible with k vectors
 // Key: Using a queue
 class ZigzagIterator {
    queue<pair<vector<int>::iterator, vector<int>::iterator>> q;
public:
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        if (!v1.empty())
            q.push(make_pair(v1.begin(), v1.end()));
        if (!v2.empty())
            q.push(make_pair(v2.begin(), v2.end()));
    }

    int next() {
        vector<int>::iterator begin = q.front().first;
        vector<int>::iterator end = q.front().second;
        q.pop();
        if (begin + 1 != end)
            q.push(make_pair(begin + 1, end));
        return *begin;
    }

    bool hasNext() {
        return !q.empty();
    }
};

/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * ZigzagIterator i(v1, v2);
 * while (i.hasNext()) cout << i.next();
 */