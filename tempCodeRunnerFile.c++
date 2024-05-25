#include<bits/stdc++.h>
using namespace std;
void build(int ind,int low,int high,int arr[],int seg[])
{
    if(low==high)
    {
        seg[ind]=arr[low];
        return ;
    }
    int mid=(low+high)/2;
    build(2*ind+1,low,mid,arr,seg);
    build(2*ind+2,mid+1,high,arr,seg);
    seg[ind]=min(seg[2*ind+1],seg[2*ind+2]);

}
int query(int ind,int low,int high,int l,int r,int seg[])
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
  int left=query(2*ind+1,low,mid,l,r,seg);
  int right=query(2*ind+2,mid+1,high,l,r,seg);
  return min(left,right);

}
void solve()
{
 int n;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int seg[4*n];
    build(0,0,n-1,arr,seg);
    int q;
    cin >> q;
    while(q--)
    {
        int l,r;
        cin>>l>>r;
        cout<<query(0,0,n-1,l,r,seg)<<endl;
    }
}
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
       solve();
    }
}

