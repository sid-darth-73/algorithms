struct FenwickTree {
    int n;
    vector<int> bit;

    FenwickTree(vector<int> &a) : n(size(a)), bit(n + 1) {
        for (int i = 0; i < n; i++) upd(i, a[i]);
    }

    void upd(int i, int x) {
        for (i++; i <= n; i += i & -i) bit[i] += x;
    }

    int sum(int i) {
        int s = 0;
        for (i++; i > 0; i -= i & -i)  s += bit[i];
        return s;
    }

    int query(int l, int r) {
        return sum(r) - sum(l - 1);
    }
};

struct FenwickTree2D {
    int n, m;
    vector<vector<int>> bit;

    FenwickTree2D(vector<vector<int>> &a): n(size(a)), m(size(a[0])), bit(n + 1, vector<int>(m + 1)) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                upd(i, j, a[i][j]);
            }
        }
    }

    void upd(int r, int c, int x) {
        for (int i = r + 1; i <= n; i += i & -i) {
            for (int j = c + 1; j <= m; j += j & -j) {
                bit[i][j] += x;
            }
        }
    }

    int sum(int r, int c) {
        int s = 0;
        for (int i = r + 1; i > 0; i -= i & -i) {
            for (int j = c + 1; j > 0; j -= j & -j) {
                s += bit[i][j];
            }
        }
        return s;
    }

    int query(int r1, int c1, int r2, int c2) {
        return sum(r2, c2) - sum(r1 - 1, c2) - sum(r2, c1 - 1) + sum(r1 - 1, c1 - 1);
    }
};

struct SparseTable {
    int n, LOG;
    vector<vector<int>> table;

    int merge(int x, int y) {
        return min(x, y);
    }

    SparseTable(const vector<int> &a): n(size(a)), LOG(__lg(n)), table(n, vector<int>(LOG + 1, -1)) {
        for (int j = 0; j <= LOG; j++) {
            for (int i = 0; i <= n - (1 << j); i++) {
                if (j == 0) {
                    table[i][j] = a[i];
                } else {
                    table[i][j] = merge(table[i][j - 1], table[i + (1 << (j - 1))][j - 1]);
                }
            }
        }
    }

    int query(int l, int r) {
        int j = __lg(r - l + 1);
        return merge(table[l][j], table[r - (1 << j) + 1][j]);
    }
};