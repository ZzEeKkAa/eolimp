#include <iostream>
#include <fstream>
#include <queue>
#define MAX 100

using namespace std;

int n, f, s;
int a[MAX][MAX];
int used[MAX];

queue<int> line;
int last;
int lvl;

int bfs(){
    int v;
    while(!line.empty()){
        v=line.front();
        if(v==f) return 1;
        for(int i=0; i<n; i++){
            if(a[v][i]==1 && used[i]==0){
                used[i]=1;
                line.push(i);
            }
        }
        if(last==v) {lvl++; last=line.back(); }
        line.pop();
    }
    return 0;
}

int main(){

    ifstream fin("input.txt");
    ofstream fout("output.txt");

    fin>>n>>s>>f;
    s--;
    f--;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            fin>>a[i][j];
        }
        used[i]=0;
    }

    used[s]=1;
    line.push(s);
    last=s;
    lvl=0;

    if(bfs()==1) {
        fout<<lvl<<endl;
    } else {
        fout<<0<<endl;
    }

    fin.close();
    fout.close();

    return 0;
}
