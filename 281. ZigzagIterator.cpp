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