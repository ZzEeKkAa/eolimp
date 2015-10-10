#include <iostream>
#include <vector>
#define MAX 50000

using namespace std;

int n;
int num[MAX+1];
int mcg[MAX+1]; // max children group
vector<vector<int> > a;

int dfs(int v, int p){
    num[v]=1;

    for(int i=0; i<a[v].size(); i++){
        if(a[v][i]!=p){
            dfs(a[v][i],v);
            num[v]+=num[a[v][i]];
        }
    }

    // Getting length of the biggest children group
    mcg[v]=n-num[v];

    for(int i=0; i<a[v].size(); i++){
        if ( mcg[v] < num[a[v][i]] && a[v][i]!=p) mcg[v] = num[a[v][i]];
    }

    return 0;
}


int main() {
    int fathers[MAX], numOfFathers=0, minChilden;

    int v1, v2;
    cin >> n;

    // Initialization
    for(int i=0; i<=n; i++){
        a.insert(a.end(),vector<int>());
    }
    // Reading data
    for( int i = 0; i < n-1; i++ ){
        cin >> v1 >> v2;
        a[v1].insert(a[v1].end(),v2);
        a[v2].insert(a[v2].end(),v1);
    }

    dfs(1,1);


    // Searching vertexes with the least the biggest length of group
    minChilden=mcg[1];
    numOfFathers=1;
    fathers[0]=1;
    for(int i = 2; i <= n; i++){
        if(minChilden==mcg[i]){
            fathers[numOfFathers] = i;
            numOfFathers++;
        } else if(minChilden > mcg[i]){
            numOfFathers=1;
            fathers[0]=i;
            minChilden = mcg[i];
        }
    }

    // Results
    cout << fathers[0];
    for(int i=1; i<numOfFathers; i++){
        cout<<" "<<fathers[i];
    }
    cout << endl;
}
