#include <iostream>
#include <fstream>
#include <queue>
#include <vector>

using namespace std;

int used  [10000];
int parent[10000];
queue<int> line;
int a,b;
vector<int> way;

int bfs(){

    int a;
    int a1,a2,a3,a4;
    int tmp;

    while(!line.empty()){
        a=line.front();
        if(a==b) return 1;

        tmp=a/1000+1;
        if(tmp<=9){
            a1=tmp*1000+a%1000;
            if(used[a1]==0){
                line.push(a1);
                used[a1]=1;
                parent[a1]=a;
            }
        }
        tmp=a%10-1;
        if(tmp>0){
            a2=(a/10)*10+tmp;
            if(used[a2]==0){
                line.push(a2);
                used[a2]=1;
                parent[a2]=a;
            }
        }
        tmp=a/1000;
        a3=(a%1000)*10+tmp;
        if(used[a3]==0){
            line.push(a3);
            used[a3]=1;
            parent[a3]=a;
        }

        tmp=a%10;
        a4=a/10+tmp*1000;
        if(used[a4]==0){
            line.push(a4);
            used[a4]=1;
            parent[a4]=a;
        }

        line.pop();
    }

    return 0;
}

int main() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    for(int i=1111; i<9999; i++) used[i]=0;

    fin>>a>>b;
    line.push(a);
    used[a]=1;

    if(bfs()==1){
        while(b!=a){
            way.insert(way.begin(),b);
            b=parent[b];
        }
        fout<<a<<endl;
        for(int i=0; i<way.size(); i++){
            fout<<way[i]<<endl;
        }
    } else {
        cout<<"ooops!"<<endl;
    }



    fin.close();
    fout.close();

}
