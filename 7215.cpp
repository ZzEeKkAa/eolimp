#include <iostream>
#include <fstream>
#include <queue>
#include <stack>
#define MAX 10000

using namespace std;

int n,m;
int used[MAX];
int dist[MAX];
int parent[MAX];
int a[MAX];
queue<int> line;
stack<char> way;

int bfs(int start, int &finish){
    int from, to;
    int _n, _m;

    dist[start]=0;
    used[start]=1;
    line.push(start);

    while(!line.empty()){
        from=line.front();
        _n=from%n;
        _m=from/n;
        cout<<_n<<" "<<_m<<endl;

        if(_n==0 || _n==n-1 || _m==0 || _m==m-1) {finish=from; return dist[from]; }

        if(_n+1<n && a[from+1]==1 && used[from+1]==0){
            dist[from+1]=dist[from]+1;
            used[from+1]=1;
            parent[from+1]=from;
            line.push(from+1);
        }
        if(_n-1>=0 && a[from-1]==1 && used[from-1]==0){
            dist[from-1]=dist[from]+1;
            used[from-1]=1;
            parent[from-1]=from;
            line.push(from-1);
        }
        if(_m+1<m && a[from+n]==1 && used[from+n]==0){
            dist[from+n]=dist[from]+1;
            used[from+n]=1;
            parent[from+n]=from;
            line.push(from+n);
        }
        if(_m-1>=0 && a[from-n]==1 && used[from-n]==0){
            dist[from-n]=dist[from]+1;
            used[from-n]=1;
            parent[from-n]=from;
            line.push(from-n);
        }

        line.pop();
    }

    return -1;
}

int main(){
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    int tmp;
    int start,finish;
    int len;
    char ch;
    string s;

    fin>>m>>n;
    len=n*m;

    getline(fin,s);
    for(int i=0; i<m; i++){
        getline(fin,s);
        for(int j=0; j<n; j++){
            ch=s[j];
            used[i*n+j]=0;
            if(ch==' ')
                a[i*n+j]=1;
            else if(ch=='+'){
                start=i*n+j;
                a[start]=1;
            }
            else
                a[i*n+j]=0;
        }
    }
    for(int i=0; i<len; i++){
        if(i%n==0)
        cout<<endl;
        cout<<a[i];
    }

    len=bfs(start,finish);

    fout<<len<<endl;
    for(int i=0; i<len; i++){
        tmp = parent[finish] - finish;
        if(tmp == -1)
            way.push('e');
        else if(tmp == 1)
            way.push('w');
        else if(tmp == -n)
            way.push('s');
        else if(tmp == n)
            way.push('n');
        finish=parent[finish];
    }

    while(!way.empty()){
        fout<<way.top();
        way.pop();
    }
    if(len>0) fout<<endl;

    fin.close();
    fout.close();
}
