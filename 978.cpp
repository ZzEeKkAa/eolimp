#include <iostream>
#define MAX 100

using namespace std;

int n;
int used[MAX];
int a[MAX][MAX];

int dfs(int v, int p){
    static int c=0;
    used[v]=1;
    for(int i=0; i<n; i++){
        if(i!=p && a[v][i]==1 && used[]==0 && c<n){
            cout<<v+1<<" "<<i+1<<endl;
            dfs(i,v);
            c++;
        }

    }

    return 0;
}

int main() {
    int m;
    int v1, v2;
    cin >> n >> m;

    // Initialization
    for( int i = 0; i < n; i++ ){
        for ( int j = 0; j < n; j++ )
            a[i][j]=0;
        used[i]=0;
    }

    // Reading data
    for( int i = 0; i < m; i++ ){
        cin >> v1 >> v2;
        a[v1-1][v2-1] = 1;
        a[v2-1][v1-1] = 1;
    }

    for(int i=0; i<n; i++){
        if(used[i]==0){
            dfs(i,i);
        } else break;
    }



}
