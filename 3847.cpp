#include <fstream>
#include <iostream>

#define MAX 10001

using namespace std;

int c[MAX]; // cost in each hour

int p[MAX];  // position in c
int pp[MAX]; // position in heap
int hp[MAX]; // heap

int res[MAX]; // number to buy in each hour

void heap_swap(int i, int j){
    int c=hp[i]; hp[i]=hp[j]; hp[j]=c;
    c=p[i]; p[i]=p[j]; p[j]=c;
    c=pp[p[i]]; pp[p[i]]=pp[p[j]]; pp[p[j]]=c;
}

int push_heap(int *a, int n){
    int pn=n/2;
    if(pn==0) return 0;
    if(a[pn]>=a[n]) {
        heap_swap(pn,n);
        push_heap(a,pn);
    }

    return 0;
}

int make_heap(int *a, int n){
    if(n==1) return 0;
    make_heap(a,n-1);
    push_heap(a,n);

    return 0;
}

int check_heap(int *a, int n, int i){
    int r,l,t;
    int change = 0;
    r=i*2; l=r+1;

    if(r>n) { push_heap(a,i); return 0; }

    if(l>n) t=r; else{
        if(a[r]<a[l])
            t=r;
        else
            t=l;
    }

    if(a[t]<a[i]){
        heap_swap(t,i);
        check_heap(a,n,t);
    } else
        push_heap(a,i);

    return 0;
}

int main(){

    ifstream fin("input.txt");
    ofstream fout("output.txt");
    string s;
    int n, h, b, e;
    int len;

    while(fin>>n){
        fin>>h>>b>>e;
        for(int i=1; i<b; i++) fin>>c[1];
        n=e-b+1;
        for(int i=1; i<=n; i++){
            fin>>c[i];
            res[i]=0;

            if(i>h){
                //cout<<"Changing"<<endl;
                hp[pp[i-h]]=c[i];
                pp[i]=pp[i-h];
                p[pp[i]]=i;
                check_heap(hp,h,pp[i]);
            } else {
                hp[i]=c[i];
                p[i]=i;
                pp[i]=i;
                push_heap(hp,i);
            }

            cout<<i<<": "<<p[1]<<endl;
            res[p[1]]+=1;

        }

        fout<<res[1];
        for(int i=2; i<=n; i++) fout<<"\t"<<res[i]; fout<<endl;

        getline(fin,s);
    }

    fin.close();
    fout.close();
}
