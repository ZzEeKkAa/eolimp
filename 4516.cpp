#include <fstream>
#include <iostream>

#define MAXN 1000

using namespace std;

int n;

int a[MAXN][MAXN];
int used[MAXN];
int l, minL, maxL;

int col;

int dfs(int v, int c){
    used[v]=c;

    for(int i=0; i<n; i++) if(v!=i && a[v][i]>=l){
        if(used[i]==c) col=0;
        if(used[i]==0){
            dfs(i,3-c)==1;
        }
    }

    return 0;
}

int main() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    // Reading data
    fin>>n;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            fin>>a[i][j];
            a[j][i]=a[i][j];
        }
    }

    // Setting default
    maxL=a[0][1];
    minL=a[0][1];
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(a[i][j]>maxL) maxL=a[i][j];
            if(a[i][j]<minL) minL=a[i][j];
        }
        a[i][i]=0;
    }

    l=(minL+maxL)/2;
    //cout<<minL<<" "<<maxL<<endl;
    // Calculating
    while(minL<maxL){
        col=1;
        for(int i=0; i<n; i++){
            used[i]=0;
        }


            //cout<<l<<": ";
        for(int i=0; i<n; i++){
            if(used[i]==0) dfs(i,1);
            if(col==0) break;
        }
            //cout<<col<<endl;

        if(col==1){
            maxL=l-1;
        } else {
            minL=l;
        }

        l=(minL+maxL+1)/2;
    }

    if(n==2) l=0;
    fout<<l<<endl;


    fin.close();
    fout.close();

    return 0;
}
