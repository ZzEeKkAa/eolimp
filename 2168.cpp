#include <iostream>
#define MAX 100

using namespace std;

int n,m;
int num=0;
int used[MAX][MAX];
int a[MAX][MAX];

int dfs(int i, int j){
    used[i][j]=num;
    if(i+1<n  && a[i+1][j]==0 && used[i+1][j]==0) dfs(i+1,j);
    if(i-1>=0 && a[i-1][j]==0 && used[i-1][j]==0) dfs(i-1,j);
    if(j+1<m  && a[i][j+1]==0 && used[i][j+1]==0) dfs(i,j+1);
    if(j-1>=0 && a[i][j-1]==0 && used[i][j-1]==0) dfs(i,j-1);
}

int main(){
    cin>>n>>m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>a[i][j];
            used[i][j]=0;
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(a[i][j]==0 && used[i][j]==0) {
                num++;
                dfs(i,j);
            }
        }
    }

    cout<<num<<endl;


}
