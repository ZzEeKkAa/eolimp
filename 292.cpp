#include <iostream>
#include <fstream>
#include <queue>

#define MAX 800

using namespace std;

int sr,sc,fr,fc;

int n,s;
int used[MAX][MAX];
int dist[MAX][MAX];
int a[MAX][MAX];
queue<int> lineR;
queue<int> lineC;

int bfs(int t){ // start & finish positions // for bear
 int r,c;
 int sns; // Step Number multiplied by S
 queue<int> lineR;
 queue<int> lineC;

 // Setting position for bear at 0 minute
 lineR.push(sr);
 lineC.push(sc);

 // Setting all unused
 for(int i=0; i<n; i++){
     for(int j=0; j<n; j++){
         used[i][j]=0;
     }
 }

 used[sr][sc]=1;
 dist[sr][sc]=0;

 // Making available bears house
 a[fr][fc]=1640000;

 // Steps edge for 1 minute
 sns=s;
 t++;

 while(!lineR.empty()){
     r = lineR.front();
     c = lineC.front();
     //cout<<"Checking: "<<r<<" "<<c<<" / "<<t<<endl;

     if(r==fr && c==fc){
         return 1;
     }

     if(dist[r][c]==sns){
         sns+=s;
         t++;
     }

     if(r-1>=0 && a[r-1][c]>t && used[r-1][c]==0){
         used[r-1][c]=1;
         dist[r-1][c]=dist[r][c]+1;
         if(!(dist[r-1][c]==sns && a[r-1][c]==t+1)){
             lineR.push(r-1);
             lineC.push(c);
         }
     }
     if(c-1>=0 && a[r][c-1]>t && used[r][c-1]==0){
         used[r][c-1]=1;
         dist[r][c-1]=dist[r][c]+1;
         if(!(dist[r][c-1]==sns && a[r][c-1]==t+1)){
             lineR.push(r);
             lineC.push(c-1);
         }
     }
     if(r+1<n && a[r+1][c]>t && used[r+1][c]==0){
         used[r+1][c]=1;
         dist[r+1][c]=dist[r][c]+1;
         if(!(dist[r+1][c]==sns && a[r+1][c]==t+1)){
             lineR.push(r+1);
             lineC.push(c);
         }
     }
     if(c+1<n && a[r][c+1]>t && used[r][c+1]==0){
         used[r][c+1]=1;
         dist[r][c+1]=dist[r][c]+1;
         if(!(dist[r][c+1]==sns && a[r][c+1]==t+1)){
             lineR.push(r);
             lineC.push(c+1);
         }
     }


     lineR.pop();
     lineC.pop();
 }

 return 0;

}

int bfs(){ // For bees
 int r,c;

 while(!lineR.empty()){
     r=lineR.front();
     c=lineC.front();

     if(r+1<n && a[r+1][c]==0){
         lineR.push(r+1);
         lineC.push(c);
         a[r+1][c] = a[r][c]+1;
     }
     if(c+1<n && a[r][c+1]==0){
         lineR.push(r);
         lineC.push(c+1);
         a[r][c+1] = a[r][c]+1;
     }

     if(r-1>=0 && a[r-1][c]==0){
         lineR.push(r-1);
         lineC.push(c);
         a[r-1][c] = a[r][c]+1;
     }
     if(c-1>=0 && a[r][c-1]==0){
         lineR.push(r);
         lineC.push(c-1);
         a[r][c-1] = a[r][c]+1;
     }

     lineR.pop();
     lineC.pop();
 }
}

int main(){
 ifstream fin("input.txt");
 ofstream fout("output.txt");
 int ch;
 int isPossible;
 int isWay;
 string str;
 int maxT;
 int t;
 int minT;

 fin>>n>>s;
 getline(fin,str);
 for(int i=0; i<n; i++){
     getline(fin,str);
     for(int j=0; j<n; j++){
         ch=str[j];
         if(ch=='T'){
             a[i][j]=-1;
         } else if(ch=='G'){
             a[i][j]=0;
         } else if(ch=='H'){
             a[i][j]=1;
             lineR.push(i);
             lineC.push(j);
         } else if(ch=='M'){
             a[i][j]=0;
             sr=i;
             sc=j;
         } else if(ch=='D'){
             a[i][j]=-1;
             fr=i;
             fc=j;
         }
     }
 }

 bfs();

 /*for(int i=0; i<n; i++){
     for(int j=0; j<n; j++)
         if(a[i][j]==-1) cout<<"T";
         else cout<<a[i][j];
     cout<<endl;
 }*/

 minT=0;
 maxT=a[sr][sc]-2;
 isWay=0;



 while(minT<maxT){
     //cout<<minT<<" / "<<maxT<<endl;
     t=(minT+maxT+1)/2;
     //cout<<"Checking time: "<<t<<" - ";
     isPossible = bfs(t);
     if(isPossible==1){
         isWay=1;
         //cout<<"true"<<endl;
         minT=t;
     } else {
         //cout<<"false"<<endl;
         maxT=t-1;
     }
 }

 if(bfs(maxT)==0)
     fout<<-1<<endl;
 else
     fout<<maxT<<endl;

 fin.close();
 fout.close();
 return 0;
}
