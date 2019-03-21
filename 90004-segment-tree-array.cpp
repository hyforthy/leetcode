class NumArray
{
  public:
    NumArray(vector<int> nums)
    {
        if (nums.empty()) {
            return;
        }
        len = nums.size();
        tree.resize(len * 4);
        build(nums);
    }

    // build segment tree, set the value of tree[idx]
    void build(vector<int> nums)
    {
        for (int i = 0; i < len; i++) {
            update(i, nums[i]);
        }
    }

    void update(int i, int val) {
        update(1, len, i + 1, val, 1);
    }
    
    void update(int start, int end, int i, int val, int idx) {
        // leaf node. update element.
        if (start == end) {
            tree[idx] = val;
            return;
        }
        
        int mid = (start + end) / 2;
        
        // left tree
        if (i <= mid) {
            update(start, mid, i, val, 2 * idx);
        }
        // right tree
        else {
            update(mid + 1, end, i, val, 2 * idx + 1);
        }
        
        tree[idx] = tree[2 * idx] + tree[2 * idx + 1];
    }

    int sumRange(int i, int j) {
        return sumRange(1, len, i + 1, j + 1, 1);
    }
    
    int sumRange(int start, int end, int i, int j, int idx) {
        // segment completely outside range, represents a null node
        if (start > j || end < i)
            return 0;
        
        // segment completely inside range
        if (i <= start && j >= end)
            return tree[idx];
        
        int mid = (start + end) / 2;
        
        return sumRange(start, mid, i, j, 2 * idx) +
            sumRange(mid + 1, end, i, j, 2 * idx + 1);
    }
private:
    vector<int> tree;
    int len ;
};