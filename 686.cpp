#include <stdio.h>
#include <cstdlib>

using namespace std;

struct Node{
    int key,priority;
    Node*left,*right;
    Node(){};
    Node(int key, int priority): key(key), priority(priority),left(NULL),right(NULL){};
};

typedef Node* Tree;
//void print_tree(Tree tree, int lvl);

void Split(Tree t, int key, Tree &l, Tree &r){
    //if(key==11)
    //    printf("Split:\n"),print_tree(t,0);
    if(!t)
        l=r=NULL;
    else if(t->key<key)
        Split(t->right,key,t->right,r), l=t;
    else
        Split(t->left,key,l,t->left), r=t;
}

void Insert(Tree &t, Node* node){
    if(!t)
        t=node;
    else if(t->priority<node->priority){
        Split(t,node->key,node->left,node->right);
        t=node;
    } else {
        if(t->key>node->key)
            Insert(t->left,node);
        else
            Insert(t->right,node);
    }
}

void Merge(Tree l, Tree r, Tree&t){
    if(!l) t=r; else
    if(!r) t=l; else
    if(l->priority<r->priority)
        Merge(l,r->left,r->left),t=r;
    else
        Merge(l->right,r,l->right),t=l;
}


/*void print_tree(Tree tree, int lvl){
    for(int i=0; i<lvl; ++i) printf("  ");
    if(!tree) {printf("NULL\n"); return;}
    printf("(%d, %d)\n",tree->key,tree->priority);
    print_tree(tree->left,lvl+1);
    print_tree(tree->right,lvl+1);
}/**/

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    Tree tree = NULL;

    int n,x,pr=0; char c;
    scanf("%d",&n);

    for(int i=0; i<n; ++i){
        scanf("%c",&c);
        if(c=='+'){
            scanf("%d",&x);
            x+=pr; pr=0;
            x%=1000000000;
            x+=1000000000;
            x%=1000000000;
            Node* node=new Node(x,rand());
            Insert(tree,node);
            //printf("Insert %d\n",x);
            //print_tree(tree,0);
        } else if(c=='?'){
            scanf("%d",&x);
            Tree l,r,tmp;
            //print_tree(tree,0);

            Split(tree,x,l,r);

            //print_tree(l,0);
            //print_tree(r,0);
            if(r){
                for(tmp=r; tmp->left; tmp=tmp->left);
                printf("%d\n",tmp->key);
                pr=tmp->key;
            }
            else{
                printf("-1\n");
                pr=-1;
            }

            Merge(l,r,tree);



            //print_tree(tree,0);
        } else --i;

    }


        /*for(int i=0; i<20; ++i){
            if(rand()%2==0) printf("? %d\n",rand()%20);
            else printf("+ %d\n",rand()%20);
        }*/

    return 0;
}
