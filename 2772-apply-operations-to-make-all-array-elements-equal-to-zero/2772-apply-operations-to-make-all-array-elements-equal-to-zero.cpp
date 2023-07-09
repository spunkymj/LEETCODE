class SGTree_lazy{
  vector<long long> seg;
  vector<long long> lazy;
  public : 
  SGTree_lazy(int n){
    seg.resize(4*n+1,0);
    lazy.resize(4*n+1,0);
  }

  void build(long long idx,long long low,long long high,vector<int> &arr){
    if(low==high){
      seg[idx]=arr[low];
      return;
    }

    int mid=low+((high-low)/2);
    build(2*idx+1,low,mid,arr);
    build(2*idx+2,mid+1,high,arr);
    seg[idx]=(seg[2*idx+1]+seg[2*idx+2]);
  }

  void update(long long idx,long long low,long long high,int l,int r,long long val){
    //lazy propagation
    if(lazy[idx]!=0){
      seg[idx]+=(high-low+1)*lazy[idx];
      if(low!=high){
        lazy[2*idx+1]+=lazy[idx];
        lazy[2*idx+2]+=lazy[idx];
      }
      lazy[idx]=0;
    }

    //no overlap
    if(l>high || r<low){
      return;
    }


    //complete overlap
    if(low>=l && high<=r){
      seg[idx]+=(high-low+1)*val;
      if(low!=high){
        lazy[2*idx+1]+=val;
        lazy[2*idx+2]+=val;
      }
      return ;
    }

    //partial overlap
    int mid=low+((high-low)/2);
    update(2*idx+1,low,mid,l,r,val);
    update(2*idx+2,mid+1,high,l,r,val);
    seg[idx]=(seg[2*idx+1]+seg[2*idx+2]);
  }

  int query(long long idx,long long low,long long high , int l,int r){
    //lazy propagation
    if(lazy[idx]!=0){
      seg[idx]+=(high-low+1)*lazy[idx];
      if(low!=high){
        lazy[2*idx+1]+=lazy[idx];
        lazy[2*idx+2]+=lazy[idx];
      }
      lazy[idx]=0;
    }

    // no overlap
    if(high<l || low>r){
      return 0;
    }

    //complete overlap
    if(low>=l && high<=r){
      return seg[idx];
    }

    //partial overlap
    int mid=low+((high-low)/2);
    int left=query(2*idx+1,low,mid,l,r);
    int right=query(2*idx+2,mid+1,high,l,r);
      
    return (left+right);
  }
};

class Solution {
public:
    bool checkArray(vector<int>& nums, int k){
        int n=nums.size();
        SGTree_lazy sg(n);
        sg.build(0,0,n-1,nums);
        for(int i=0 ; i<n ; i++){
            int curr=sg.query(0,0,n-1,i,i);
            if(curr<0){
                return false;
            }
            if(curr==0){
                continue;
            }
            if((i+k-1)<=n-1){
                sg.update(0,0,n-1,i,i+k-1,(-1)*curr);
            }
            else{
                if(curr!=0){
                    return false;
                }
            }
        }
        return true;
    }
};