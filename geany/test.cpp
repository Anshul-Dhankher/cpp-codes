#include<bits/stdc++.h>
using namespace std;
void build_tree(int arr[],int tree[],int l,int r,int index)
{
    if(l==r)
    {
        tree[index]=(arr[l]%5==0?1:0);
        return;
    }
    int mid=(l+r)/2;
    build_tree(arr,tree,l,mid,2*index);
    build_tree(arr,tree,mid+1,r,2*index+1);
    tree[index]=tree[2*index]+tree[2*index+1];
    return;
    
}

int query(int tree[],int ss,int se,int qs,int qe,int index)
{
    if(qs<=ss&&se<=qe)
    {
        return tree[index];
    }
    if(se<qs||qe<ss)
    return 0;
    
    int mid=(ss+se)/2;
    int left=query(tree,ss,mid,qs,qe,2*index);
    int right=query(tree,mid+1,se,qs,qe,2*index+1);
    return left+right;
}
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
      int n,q;
      cin>>n>>q;
      int arr[n];
      
      
      for(int i=0;i<n;i++)
        cin>>arr[i];
        int tree[4*n+1];
        build_tree(arr,tree,0,n-1,1);
        
        while(q--)
        {
            int l,r;
            cin>>l>>r;
            int ans=query(tree,0,n-1,l+1,r+1,1);
            cout<<ans<<endl;
        }
    }
	return 0;
}
