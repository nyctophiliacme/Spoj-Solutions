#include<bits/stdc++.h>
using namespace std;
#define M 8005
typedef long long ll;
int pre[M],post[M],in[M],ans[M],ind=0,k=0;
struct node
{
	int data;
	node *left, *right;
};
node *func(int start,int end)
{
	int i;
	if(start>end) return NULL;
	node *a=new node;
	a->data=pre[ind++];
	a->left=NULL;a->right=NULL;
	if(start==end) return a;
	for(i=start;i<=end;i++)
	{
		if(in[i]==a->data) break;
	} 
	a->left=func(start,i-1);
	a->right=func(i+1,end);
	return a;
}
void fpost(node *root)
{
	if(root==NULL) return;
	fpost(root->left);
	fpost(root->right);
	ans[k++]=root->data;
}
int main()
{
	int n,i;
	node *root;
	scanf("%d",&n);
	for(i=0;i<n;i++) scanf("%d",&pre[i]);
	for(i=0;i<n;i++) scanf("%d",&post[i]);
	for(i=0;i<n;i++) scanf("%d",&in[i]);
	root=func(0,n-1);
	fpost(root);
	int flag=0;
	for(i=0;i<n;i++)
	{
		if(ans[i]!=post[i]) flag=1;
	}
	if(flag) printf("no");else printf("yes");
} 
