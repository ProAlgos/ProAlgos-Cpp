#include<bits/stdc++.h>

#define f(i,a,b) for(int i=int(a);i<=int(b);i++)
#define endl '\n'
#define needforspeed() ios_base::sync_with_stdio(false);cin.tie(NULL);
#define maxn 100000

using namespace std;

int n;
int arr[maxn],tree[4*maxn+1];

void initTree()
{
  f(i,1,4*n+1)
    tree[i]=-1;
}
void BuildSegTree(int index,int start,int end)
{
  if(start>end)
     return;
  if(start==end) {
     tree[index]=arr[start];
     return;
   }

  int mid=(start+end)/2;
  BuildSegTree(2*index,start,mid);
  BuildSegTree(2*index+1,mid+1,end);

  tree[index]=min(tree[2*index],tree[2*index+1]);
}

int minQuery(int index,int start,int end,int s,int e)
{
  if(s>end || e<start)
    return INT_MAX;

  if(s>=start && e<=end)
    return tree[index];

  int mid=(start+end)/2;
  return min(minQuery(2*index,start,mid,s,e),minQuery(2*index+1,mid+1,end,s,e));
}
int main()
{
    needforspeed()
    int i,j;
    cin>>n;
    f(i,0,n-1)
    cin>>arr[i];
    initTree();
    BuildSegTree(1,0,n-1);
    int q;
    cin>>q;
    while(q--)
    {
      int s,e;
      cin>>s>>e;
      cout<<minQuery(1,0,n-1,s,e)<<endl;
    }
    return 0;
}
