#include <fstream>
#include <iostream>
#include <map>
#include <queue>
#include <cmath>

#define MAXN 8

using namespace std;

int n,k;
int needed;
int lvl, last;

map < int, int > used;
queue<int> line;

int bfs(){
    int a,bkpa;
    int ra, na;
    int zk,z1,z2;
    zk=1;
    for(int i=0; i<k; i++)
        zk*=10;

    map<int,int>::iterator ifind;
    while(!line.empty()){

        //Setting default
        a=line.front();
        z1=zk;
        z2=1;
        bkpa=a;

        // Checking end
        if(a==needed) {
            line=queue<int>();
            return 1;
        }

        // Getting out positions
        for(int i=n-k; i>=0; i--){
            // Getting new a
            na=(a/z1)*z1;
            a%=z1;

            na+=a%z2;
            a/=z2;

            ra=0;
            for(int j=0; j<k; j++){
                ra*=10;
                ra+=a%10;
                a/=10;
            }
            na+=ra*z2;

            // Adding to line new a
            ifind=used.find(na);
            if(ifind==used.end()){
                used[na]=1;
                line.push(na);
            }

            // End cycle changes
            a=bkpa;
            z1*=10;
            z2*=10;
        }

        if(a==last) { lvl++; last=line.back(); }
        line.pop();
    }

    return 0;
}

int main(){
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    int tmp[MAXN];
    int a;

    while(fin>>n>>k){
        a=0;
        needed=0;
        lvl=0;

        for(int i=0; i<n; i++){
            fin>>tmp[i];
            a*=10;
            a+=tmp[i];
        }

        for(int i=0; i<n; i++)
            for(int j=i+1; j<n; j++)
                if(tmp[i]>tmp[j]) swap(tmp[i],tmp[j]);

        for(int i=0; i<n; i++){
            needed*=10;
            needed+=tmp[i];
        }
        //cout<<a<<endl<<needed<<endl;

        last=a;
        line.push(a);
        used[a]=1;
        if(bfs()==1) fout<<lvl<<endl;
        else fout<<-1<<endl;
        used.clear();

    }


    fin.close();
    fout.close();

    return 0;
}
