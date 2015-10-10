#include <iostream>
#include <fstream>
#include <queue>

#define MAX 100

using namespace std;

int used[MAX+1];
int dist[MAX+1];
queue<int> line;

int bfs(int m){
    int l;

    for(int i=0; i<MAX; i++){
        used[i]=0;
    }

    line.push(0);
    used[0]=1;
    dist[0]=0;


    while(!line.empty()){
        l=line.front();

        if(l==m) return dist[l];

        if(l-3>=0 && used[l-3]==0){
            used[l-3]=1;
            dist[l-3]=dist[l]+1;
            line.push(l-3);
        }
        if(l+3<=MAX && used[l+3]==0){
            used[l+3]=1;
            dist[l+3]=dist[l]+1;
            line.push(l+3);
        }
        if(l-5>=0 && used[l-5]==0){
            used[l-5]=1;
            dist[l-5]=dist[l]+1;
            line.push(l-5);
        }
        if(l+5<=MAX && used[l+5]==0){
            used[l+5]=1;
            dist[l+5]=dist[l]+1;
            line.push(l+5);
        }

        line.pop();
    }

    return -1;

}

int main(){
    int m;
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    fin>>m;
    fout<<bfs(m)<<endl;

    fin.close();
    fout.close();

    return 0;
}
