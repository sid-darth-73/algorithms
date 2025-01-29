template <class T>
class dsu {
public:
    unordered_map<T, T> parent;
    unordered_map<T, pair<int, int>> repr; // set represents -> <set size, set rank>
    void makeSet(T e) {
        parent[e] = e;
        repr[e] = {1, 0};
    }
    void unite(T e1, T e2) {
        T repE1 = find(e1);
        T repE2 = find(e2);

        if (repE1 == repE2) {
            return;
        }
        int rankS1 = repr[repE1].second;
        int rankS2 = repr[repE2].second;

        if (rankS1 > rankS2) {
            parent[repE2] = repE1;
            repr[repE1].first += repr[repE2].first;
            repr.erase(repE2);
        } else {
            parent[repE1] = repE2;
            repr[repE2].first += repr[repE1].first;
            if (rankS1 == rankS2) {
                repr[repE2].second++;
            }
            repr.erase(repE1);
        }
    }

    T find(T e) {
        if (parent[e] == e) {
            return e;
        }
        return parent[e] = find(parent[e]);
    }

    int sizeOfSet(T e) {
        T rep = find(e);
        return repr[rep].first;
    }
};
