// Author : Anirudh Achal
// Description : Max segment tree

// Instructions : 
// 1. To construct a new 'max_seg_tree' struct, use 'max_seg_tree <tree_name>(<vector_name>, <vector_size>)'
// 2. To update an entry in the ith location (zero indexed) to V, use '<tree_name>.update(i, V)'
// 3. To get the sum of a range of elements from L to R ie. [L, R), use '<tree_name>.get_max(L, R)'

// Points to remember :
// 1. Zero based indexed
// 2. Supports long long int
// 3. If memory limit exceeded try changing ll to int
// 4. Range L, R => [L, R) ie. including L excluding R

struct max_seg_tree {

    int size = 1;
    vector<ll> tree;

    void construct(vector<ll> &arr, int n)
    {
        while(size < n)
        {
            size *= 2;
        }

        tree = vector<ll>(2 * size, LLONG_MIN);

        construct(arr, 0, 0, size, n);
    }

    void construct(vector<ll> &arr, int node, int lx, int rx, int n)
    {
        if(rx - lx == 1)
        {
            if(lx < n)
            {
                tree[node] = arr[lx];
            }
            return;
        }

        int mid = lx + (rx - lx) / 2;

        construct(arr, 2 * node + 1, lx, mid, n);
        construct(arr, 2 * node + 2, mid, rx, n);

        tree[node] = max(tree[2 * node + 1], tree[2 * node + 2]);
    }

    void update(int pos, ll val)
    {
        update(pos, val, 0, 0, size);
    }

    void update(int pos, ll val, int node, int lx, int rx)
    {
        if(rx - lx == 1)
        {
            tree[node] = val;
            return;
        }

        int mid = lx + (rx - lx) / 2;

        if(pos < mid)
        {
            update(pos, val, 2 * node + 1, lx, mid);
        }
        else {
            update(pos, val, 2 * node + 2, mid, rx);
        }

        tree[node] = min(tree[2 * node + 1], tree[2 * node + 2]);
    }

    ll get_max(int l, int r)
    {
        return get_max(l, r, 0, 0, size);
    }

    ll get_max(int l, int r, int node, int lx, int rx)
    {
        if(l <= lx && rx <= r)
        {
            return tree[node];
        }

        if(lx >= r || l >= rx)
        {
            return LLONG_MIN;
        }

        int mid = lx + (rx - lx) / 2;

        ll max_left = get_max(l, r, 2 * node + 1, lx, mid);
        ll max_right = get_max(l, r, 2 * node + 2, mid, rx);

        return max(max_left, max_right);
    }
};


