#include <iostream>
#include <cstdio>
#include <sstream>
#include <vector>

using namespace std;

int n;
vector<int> t;
vector<bool> a;

void init(int nn){
    n=nn;
    t.assign(n,0);
    //for(int i=0; i<n; ++i) t[i]=0;
}

int sum(int i){
    int res=0;
    for(; i>=0; i=(i&(i+1))-1)
        res+=t[i];
    return res;
}

void add(int i, int d){
    for(;i<n;i=(i|(i+1)))
        t[i]+=d;
}

int sum(int l, int r){
    return sum(r)-sum(l-1);
}

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    init(2000201);
    a.assign(2000201,0);

    int x, y;
    string line;
    stringstream ss;
    while(getline(cin,line)){
        ss<<line;
        ss>>x; x+=1000010;
        if(ss.eof()){
            //printf("add %d\n",x);
            if(!a[x]){
                add(x,1);
                a[x]=1;
            }
        } else{
            ss>>y; y+=1000010;
            //printf("query %d %d\n",x,y);
            if(x>y) swap(x,y);
            printf("%d\n",sum(x,y));
        }
        ss.clear();
        line.clear();
    }

}


