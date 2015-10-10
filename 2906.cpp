#include <stdio.h>
#include <vector>
#include <cmath>
#include <algorithm>

#define INF 30000

using namespace std;

int n;
vector<int> a;

struct Node{
    int prefix,suffix,max,sum,leftPos,rightPos;
    Node* left, *right;
};

Node* build(vector<int> &a, int l, int r){
    if(l==r){
        Node * node = new Node();
        node->prefix=a[l];
        node->suffix=a[l];
        node->max=a[l];
        node->sum=a[l];
        node->leftPos=l;
        node->rightPos=r;
        node->left=NULL;
        node->right=NULL;
        return node;
    }
    int m=(l+r)/2;

    Node* left = build(a,l,m);
    Node* right = build(a,m+1,r);

    Node* tree = new Node();
    tree->left=left;
    tree->right=right;

    tree->sum=left->sum+right->sum;
    tree->prefix=max(left->prefix,left->sum+right->prefix);
    tree->suffix=max(right->suffix,right->sum+left->suffix);
    tree->max=max(max(left->max, right->max), left->suffix+right->prefix);

    tree->leftPos=l;
    tree->rightPos=r;

    return tree;
}

void GetMaxSum(Node* tree, int l, int r,int &sum, int &pr, int&suf, int&mm){
    //printf("[%d...%d] at (%d..%d):\n",l,r,tree->leftPos, tree->rightPos);
    if(l<tree->leftPos) l = tree->leftPos;
    if(r>tree->rightPos) r = tree->rightPos;
    if(l>r) { sum=0; pr=0; suf=0; mm=-INF;  return; }

    if(l==tree->leftPos && r==tree->rightPos) { /*printf("eq\n");*/ sum=tree->sum; pr=tree->prefix; suf=tree->suffix; mm=tree->max; /*printf("%d %d %d %d\n",pr,suf,sum,mm);*/ return; }

    if(tree->left->rightPos>=r){
        GetMaxSum(tree->left, l, r,sum,pr,suf,mm);
        return;
    }

    if(tree->right->leftPos<=l){
        GetMaxSum(tree->right, l, r,sum,pr,suf,mm);
        return;
    }

    int m=(tree->leftPos+tree->rightPos)/2; //printf("m=%d\n",m);

    int l_pr, l_suf, r_pr, r_suf, l_sum, r_sum,l_max,r_max;
    GetMaxSum(tree->left, l, m, l_sum, l_pr, l_suf, l_max);
    GetMaxSum(tree->right, m+1, r, r_sum, r_pr, r_suf, r_max);

    sum=l_sum+r_sum;
    pr=max(l_pr,l_sum+r_pr);
    suf=max(r_suf,r_sum+l_suf);
    mm=max(max(l_max, r_max), l_suf+r_pr);
    //printf("%d %d %d %d\n",pr,suf,sum,mm);
}

int main(){

    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    scanf("%d",&n);
    a.assign(n+1,0);
    for(int i=1; i<=n; ++i){
        scanf("%d",&a[i]);
    }

    Node* tree = build(a,1,n);

    //printf("prefix=%d, suffix=%d, sum=%d, max=%d\n",tree->prefix, tree->suffix, tree->sum, tree->max);


    int m,x,y;
    scanf("%d",&m);

    int sum,pr,suf,max;
    for(int i=0; i<m; ++i){
        scanf("%d %d",&x,&y);
        GetMaxSum(tree,x,y,sum,pr,suf,max);
        printf("%d\n",max);
    }

}
