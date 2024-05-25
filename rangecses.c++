#include<bits/stdc++.h>
using namespace std;
#define int long long
class segment
{
  public:
  vector<int>seg;
  segment(int n)
  {
    seg.resize(4*n+1);

  }
void build(int ind,int low,int high,int arr[])
{
    if(low==high)
    {
        seg[ind]=arr[low];
        return ;
    }
    int mid=(low+high)/2;
    build(2*ind+1,low,mid,arr);
    build(2*ind+2,mid+1,high,arr);
    seg[ind]=min(seg[2*ind+1],seg[2*ind+2]);

}
int query(int ind,int low,int high,int l,int r)
{
  //no overlap 
  //l r low high or low high l r
  if(r<low ||high<l)
  {
    return INT_MAX;
  }
  if(low>=l && high<=r)
  {
    return seg[ind];
  }

  int mid=(low+high)/2;
  int left=query(2*ind+1,low,mid,l,r);
  int right=query(2*ind+2,mid+1,high,l,r);
  return min(left,right);

}
void update(int ind, int low, int high,int i,int val)
{
  if(low==high)
  {
  seg[ind]=val;
  return ;
  }
  int mid=(low+high)/2;
  if(i<=mid)
  {
    update(2*ind+1,low,mid,i,val);
  }
  else
  update(2*ind+2,mid+1,high,i,val);
seg[ind]=min(seg[2*ind+1],seg[2*ind+2]);


}
};
void solve()
{
    int n;
    cin >> n;
     int q;
    cin >> q;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    segment ss(n);
   
    ss.build(0,0,n-1,arr);
   
    while(q--)
    {
      int t;
      cin>>t;
      if(t==1)
      {
        int ind;
        int val;
        cin>>ind>>val;
        arr[ind]=val;
        ss.update(0,0,n-1,ind,val);

      }
      else
      {
        int l,r;
        cin>>l>>r;
        cout<<ss.query(0,0,n-1,l,r)<<endl;
      }
    }
}
int32_t main()
{
    
       solve();
    
}

