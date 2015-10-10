#include <iostream>
#include <fstream>
#include <queue>
#include <vector>

#define MAX 50000

using namespace std;

int used[MAX];
int parent[MAX];
queue<int> line;
vector<int> a[MAX];
vector<int> way;

int n,m;

int bfs(int start, int finish){
    int to, from;
    int last=start, lvl=0;

    used[start]=1;
    line.push(start);

    while(!line.empty()){
        from=line.front();

        if(from==finish) return lvl;

        for(vector<int>::iterator it=a[from].begin(); it<a[from].end(); it++){
            to=*it;
            if(used[to]==0){
                used[to]=1;
                parent[to]=from;
                line.push(to);
            }
        }

        if(from==last) { last=line.back(); lvl++; }

        line.pop();
    }

    return -1;

}

int main(){
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    int a0,b0;
    int v1,v2;
    int lvl;

    fin>>n>>m>>a0>>b0;
    a0--;
    b0--;

    for(int i=0; i<m; i++){
        fin>>v1>>v2;
        v1--;
        v2--;
        a[v1].push_back(v2);
        a[v2].push_back(v1);
    }


    // Setting default
    for(int i=0; i<n; i++){
        used[i]=0;
    }

    lvl=bfs(a0,b0);

    fout<<lvl<<endl;
    if(lvl>0){
        for(int i=0; i<lvl; i++){
            way.insert(way.begin(),b0+1);
            b0=parent[b0];
        }
        fout<<a0+1;
        for(int i=0; i<lvl; i++)
            fout<<" "<<way[i];
        fout<<endl;
    }

    fin.close();
    fout.close();

    return 0;
}
