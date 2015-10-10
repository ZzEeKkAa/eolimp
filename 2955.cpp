#include <stdio.h>

#define MAX 500001

int n;
int a[MAX];

struct Node {
    int v;
    Node*Left,*Right;
};

void Build(Node*tree, int l, int r){
    if(l==r) {
        tree->v=a[l];
        tree->Left=NULL;
        tree->Right=NULL;
    } else {
        int m=(l+r)/2;
        tree->Left = new Node();
        tree->Right = new Node();
        Build(tree->Left,l,m);
        Build(tree->Right,m+1,r);
    }
}

int GetValue(Node*tree,int l, int r, int i){
    if(l==r) return tree->v;
    int m=(l+r)/2;
    if(m<i) return GetValue(tree->Right,m+1,r,i);
    else GetValue(tree->Left,l,m,i);
}

Node* MakeNew(Node*oldTree, int l, int r, int i, int v){
    //printf("   %d %d\n",l,r);
    Node* newTree=new Node();
    if(l==r){
        //printf("      new\n");
        newTree->Left=NULL;
        newTree->Right=NULL;
        newTree->v=v;
    } else {
        newTree->Left =oldTree->Left;
        newTree->Right=oldTree->Right;
        int m=(l+r)/2;
        if(i>m) newTree->Right=MakeNew(oldTree->Right,m+1,r,i,v);
        else newTree->Left=MakeNew(oldTree->Left,l,m,i,v);
    }
    return newTree;
}

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    scanf("%d",&n);
    for(int i=1; i<=n; ++i){
        scanf("%d",a+i);
    }


    Node* PSTree[MAX];

    PSTree[1]=new Node();
    Build(PSTree[1],1,n);

    char c[10];
    int q,x,y,z;
    int trees=1;
    int num=0;
    scanf("%d",&q);
    for(int i=0; i<q; ++i){
        scanf("%s",c);
        if(c[0]=='c'){
            scanf("%d %d %d",&x,&y,&z);
            //printf("create %d %d %d\n",x,y,z);
            PSTree[++trees]=MakeNew(PSTree[x],1,n,y,z);
        } else{
            scanf("%d %d",&x,&y);
            //printf("%d %d\n",x,y);
            printf("%d\n",GetValue(PSTree[x],1,n,y));
        };
    }

}
