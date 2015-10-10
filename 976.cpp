#include <iostream>
#include <fstream>

#define MAX 100
#define INF 200

using namespace std;

int n;
int m[MAX][MAX];
int p[MAX][MAX];
int ans[MAX][MAX];

void floyd(){
    for(int k=0; k<n; ++k)
        for(int i=0; i<n; ++i)
            for(int j=0; j<n; ++j)
                if(m[i][k]!=INF && m[k][j]!=INF)
                    if(m[i][k]+m[k][j]<m[i][j]){ m[i][j]=m[i][k]+m[k][j];
                    p[i][j]=k;
                }
}

void getans(){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(m[i][j]!=INF)
                ans[i][j]=1;
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            for(int k=0; k<n; k++){
                if(m[k][k]<0 && m[i][k]<INF && m[k][j]<INF) {
                    ans[i][j]=2;
                    break;
                }
            }
        }
    }
}

int main(){
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    fin>>n;

    for(int i=0; i<n; ++i){
        for(int j=0; j<n; ++j){
            fin>>m[i][j];
            if(m[i][j]==0 && i!=j) m[i][j]=INF;
            p[i][j]=INF;
            ans[i][j]=0;
        }
    }

    floyd();

    getans();

    //cout<<"here"<<endl;

    for(int i=0; i<n; ++i){
        fout<<ans[i][0];
        for(int j=1; j<n; ++j){
            fout<<" "<<ans[i][j];
        }
        fout<<endl;
    }

    fin.close();
    fout.close();
}
