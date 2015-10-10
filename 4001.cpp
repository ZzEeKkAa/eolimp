#include <iostream>
#define MAX 10

using namespace std;

int a[MAX][MAX];
int used[MAX][MAX];
int s=0;
int n;

int dfs(int x, int y){
    used[y][x]=1;
    s++;
    if(x-1>=0 && used[y][x-1]==0 && a[y][x-1]==1) dfs(x-1,y);
    if(x+1<n  && used[y][x+1]==0 && a[y][x+1]==1) dfs(x+1,y);
    if(y-1>=0 && used[y-1][x]==0 && a[y-1][x]==1) dfs(x,y-1);
    if(y+1<n  && used[y+1][x]==0 && a[y+1][x]==1) dfs(x,y+1);
}

int main() {
    int x,y;
    string ss;
    cin>>n;
    getline(cin,ss);
    for(int i=0; i<n; i++){
        getline(cin,ss);
        for(int j=0; j<n; j++){
            if(ss[j]=='*') a[i][j]=0; else a[i][j]=1;
            used[i][j]=0;
        }
    }
    cin>>y>>x;
    x--; y--;

    dfs(x,y);

    cout<<s<<endl;
}
