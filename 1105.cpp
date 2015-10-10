#include <iostream>
#include <fstream>

#define MAX 11
#define INF 0x3F3F3F3F

using namespace std;

int n;
int g[MAX][MAX];
int used[MAX];
int s, sum, cnt, mint;

void floyd(){
    for(int k=0; k<=n; ++k)
    for(int i=0; i<=n; ++i)
    for(int j=0; j<=n; ++j)
        if(g[i][k]+g[k][j]<g[i][j]) g[i][j] = g[i][k] + g[k][j];
}

int gamilt(int v){
    if(n==cnt){
        sum+=g[v][0];
        if(sum<mint)
            mint=sum;
        cout<<sum<<endl;
        sum-=g[v][0];
        return 1;
    }

    for(int i=0; i<=n; i++) if(!used[i]){
        cnt++;
        sum+=g[v][i];
        used[i]=1;
        if(gamilt(i)==1) return 1;
        used[i]=0;
        sum-=g[v][i];
        cnt--;
    }

    return 0;
}

int main(){
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    fin>>n;

    for(int i=0; i<=n; i++){
        for(int j=0; j<=n; j++){
            fin>>g[i][j];
        }
        used[i]=0;
    }

    floyd();

    cnt=0;
    sum=0;
    mint=INF;
    used[0]=1;

    gamilt(0);

    fout<<mint<<endl;

    fin.close();
    fout.close();
}
