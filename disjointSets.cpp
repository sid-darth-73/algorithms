template <class T>
class dsu {
    vector<int> rank, size; 
    vector<T> parent;
public: 
    dsu(int n) {
        rank.assign(n+1, 0); 
        parent.resize(n+1);
        size.assign(n+1, 0); 
        for(int i = 0; i<=n; i++) {
            parent[i] = i; 
            size[i] = 1; 
        }
    }
 
    T find(T node) {
        if(node == parent[node])
            return node; 
        return parent[node] = find(parent[node]); 
    }
 
    void unite_rank(T u, T v) {
        int p_u = find(u); 
        int p_v = find(v); 
        if(p_u == p_v) return; 
        if(rank[p_u] < rank[p_v]) {
            parent[p_u] = p_v; 
        }
        else if(rank[p_v] < rank[p_u]) {
            parent[p_v] = p_u; 
        }
        else {
            parent[p_v] = p_u; 
            rank[p_u]++; 
        }
    }
 
    void unite_size(T u, T v) {
        T p_u = find(u); 
        T p_v = find(v); 
        if(p_u == p_v) return; 
        if(size[p_u] < size[p_v]) {
            parent[p_u] = p_v; 
            size[p_v] += size[p_u]; 
        }
        else {
            parent[p_v] = p_u;
            size[p_u] += size[p_v]; 
        }
    }
}; 