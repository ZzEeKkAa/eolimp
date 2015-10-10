#include <iostream>
#define MAX 1000

using namespace std;

int n;
int used[MAX+1];
int a[MAX+1][MAX+1];

int dfs(int v, int p){
    used[v]=1;
    for(int i=1; i<=n; i++) if(a[v][i]==1 && i!=p){
        if(used[i]==1){
            used[v]=2;
            return 1;
        }
        if(used[i]==0){
            if(dfs(i,v)==1) { used[v]=2; return 1;}
        }
    }
    used[v]=2;

    return 0;
}

int main() {
    bool isWay=false;
    int m;
    int v1, v2;
    cin >> n >> m;

    // Initialization
    for( int i = 1; i <= n; i++ ){
        for ( int j = 1; j <= n; j++ )
            a[i][j]=0;
        used[i]=0;
    }

    // Reading data
    for( int i = 0; i < m; i++ ){
        cin >> v1 >> v2;
        a[v1][v2] = 1;
        a[v2][v1] = 1;
    }

    for(int i=1; i<=n; i++){
        if(used[i]==0){
            if(dfs(i,i)==1){
                isWay=true;
                break;
            }
        }
    }

    if(isWay) cout<< "YES" << endl; else cout << "NO" << endl;

}

