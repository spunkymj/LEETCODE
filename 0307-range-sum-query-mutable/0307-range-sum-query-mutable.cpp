class NumArray {
public:
    vector<int> seg;
    int n;

    void build(int idx, int low, int high, vector<int> &arr)
    {
        if (low == high)
        {
            seg[idx] = arr[low];
            return;
        }

        int mid = low + ((high - low) / 2);
        build(2 * idx + 1, low, mid, arr);
        build(2 * idx + 2, mid + 1, high, arr);
        seg[idx] = (seg[2 * idx + 1]+seg[2 * idx + 2]);
    }

    NumArray(vector<int>& nums) {
        n=nums.size();
        seg.resize(n*4+1,0);
        build(0,0,n-1,nums);
    }

    void upd(int idx,int low,int high,int i,int val) {
        if (low == high)
        {
            seg[idx] = val;
            return;
        }

        int mid = low + ((high - low) / 2);

        if (i <= mid)
        {
            upd(2 * idx + 1, low, mid, i, val);
        }
        else
        {
            upd(2 * idx + 2, mid + 1, high, i, val);
        }

        seg[idx] = (seg[2 * idx + 1]+seg[2 * idx + 2]);

    }

    
    void update(int index, int val) {
        upd(0,0,n-1,index,val);
    }

    int query(int idx, int low, int high, int l, int r)
    {

        // no overlap
        if (high < l || low > r)
        {
            return 0;
        }

        // complete overlap
        if (low >= l && high <= r)
        {
            return seg[idx];
        }

        // partial overlap
        int mid = low + ((high - low) / 2);
        int left = query(2 * idx + 1, low, mid, l, r);
        int right = query(2 * idx + 2, mid + 1, high, l, r);
        return (left+right);
    }
    
    int sumRange(int left, int right) {
        return query(0,0,n-1,left,right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */