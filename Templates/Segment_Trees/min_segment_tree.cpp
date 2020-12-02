// Author : Anirudh Achal
// Description : Min segment tree

// Instructions : 
// 1. To construct a new 'min_seg_tree' struct, use 'min_seg_tree <tree_name>(<vector_name>, <vector_size>)'
// 2. To update an entry in the ith location (zero indexed) to V, use '<tree_name>.update(i, V)'
// 3. To get the sum of a range of elements from L to R ie. [L, R), use '<tree_name>.get_min(L, R)'

// Points to remember :
// 1. Zero based indexed
// 2. Supports long long int
// 3. If memory limit exceeded try changing ll to int
// 4. Range L, R => [L, R) ie. including L excluding R

struct min_seg_tree {

    int size = 1;
    vector<ll> tree;

    void construct(vector<ll> &arr, int n)
    {
        while(size < n)
        {
            size *= 2;
        }

        tree = vector<ll>(2 * size, LLONG_MAX);

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

        tree[node] = min(tree[2 * node + 1], tree[2 * node + 2]);
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

    ll get_min(int l, int r)
    {
        return get_min(l, r, 0, 0, size);
    }

    ll get_min(int l, int r, int node, int lx, int rx)
    {
        if(l <= lx && rx <= r)
        {
            return tree[node];
        }

        if(lx >= r || l >= rx)
        {
            return LLONG_MAX;
        }

        int mid = lx + (rx - lx) / 2;

        ll min_left = get_min(l, r, 2 * node + 1, lx, mid);
        ll min_right = get_min(l, r, 2 * node + 2, mid, rx);

        return min(min_left, min_right);
    }
};


