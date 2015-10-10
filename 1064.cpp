#include <iostream>
#include <fstream>

#define MAXN 50

using namespace std;

int n;

int a[MAXN][MAXN];
int pr1[MAXN][MAXN];
int pr2[MAXN][MAXN];

int line1[MAXN*MAXN];
int line2[MAXN*MAXN];
int used[MAXN][MAXN];

int pos;
int length;
int level;

int r,c;

int bfs(){
    while(pos<length){
        r=line1[pos];
        c=line2[pos];

        if(a[r][c]==2){
            return 1;
        }

        if(r-2>=0 && c-1>=0 && used[r-2][c-1]==0 && a[r-2][c-1]!=1) {
            used[r-2][c-1]=1;

            line1[length]=r-2;
            line2[length]=c-1;
            length++;

            pr1[r-2][c-1]=r;
            pr2[r-2][c-1]=c;
        }
        if(r-2>=0 && c+1<n && used[r-2][c+1]==0 && a[r-2][c+1]!=1) {
            used[r-2][c+1]=1;
            line1[length]=r-2;
            line2[length]=c+1;
            length++;

            pr1[r-2][c+1]=r;
            pr2[r-2][c+1]=c;
        }

        if(r+2<n && c-1>=0 && used[r+2][c-1]==0 && a[r+2][c-1]!=1) {
            used[r+2][c-1]=1;
            line1[length]=r+2;
            line2[length]=c-1;
            length++;

            pr1[r+2][c-1]=r;
            pr2[r+2][c-1]=c;
        }
        if(r+2<n && c+1<n && used[r+2][c+1]==0 && a[r+2][c+1]!=1) {
            used[r+2][c+1]=1;
            line1[length]=r+2;
            line2[length]=c+1;
            length++;

            pr1[r+2][c+1]=r;
            pr2[r+2][c+1]=c;
        }

        if(c-2>=0 && r-1>=0 && used[r-1][c-2]==0 && a[r-1][c-2]!=1) {
            used[r-1][c-2]=1;
            line1[length]=r-1;
            line2[length]=c-2;
            length++;

            pr1[r-1][c-2]=r;
            pr2[r-1][c-2]=c;
        }
        if(c-2>=0 && r+1<n && used[r+1][c-2]==0 && a[r+1][c-2]!=1) {
            used[r+1][c-2]=1;
            line1[length]=r+1;
            line2[length]=c-2;
            length++;

            pr1[r+1][c-2]=r;
            pr2[r+1][c-2]=c;
        }

        if(c+2<n && r-1>=0 && used[r-1][c+2]==0 && a[r-1][c+2]!=1) {
            used[r-1][c+2]=1;

            line1[length]=r-1;
            line2[length]=c+2;
            length++;

            pr1[r-1][c+2]=r;
            pr2[r-1][c+2]=c;
        }
        if(c+2<n && r+1<n && used[r+1][c+2]==0 && a[r+1][c+2]!=1) {
            used[r+1][c+2]=1;
            line1[length]=r+1;
            line2[length]=c+2;
            length++;

            pr1[r+1][c+2]=r;
            pr2[r+1][c+2]=c;
        }

        pos++;
    }

    return 0;
}

int main(){
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    char ch;
    string row;
    int p;

    pos=0;
    length=0;
    level=0;
    fin>>n;

    ch='@';
    getline(fin,row);
    for(int i=0; i<n; i++){
        getline(fin,row);
        //cout<<row<<endl;
        p=0;
        for(int j=0; j<n; j++){
            used[i][p]=0;

            //fin>>ch;

            ch=row[p];
            if(ch=='#')
                a[i][j]=1;
            else if(ch=='.')
                a[i][j]=0;
            else if(ch=='@'){
                a[i][j]=2;
                if(length==0)
                {
                    a[i][j]=3;
                    line1[0]=i;
                    line2[0]=j;
                    length=1;
                    used[i][j]=1;
            //cout<<i<<" "<<j<<endl;
                }
            } else{
                j--;
            }
            p++;
        }
    }

    int nr, nc;
    if(bfs()==1){
        r=line1[pos];
        c=line2[pos];
        //cout<<"From: "<<r<<" "<<c<<endl;
        while(!(r==line1[0] && c==line2[0])){
            //cout<<r<<" "<<c<<endl;
            a[r][c]=2;
            nr=pr1[r][c];
            nc=pr2[r][c];
            r=nr;
            c=nc;
        }

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                fin>>ch;

                if(a[i][j]==1)
                    fout<<"#";
                else if(a[i][j]==0)
                    fout<<".";
                else
                    fout<<"@";
            }
            fout<<endl;
        }

    } else {
        fout<<"Impossible"<<endl;
    }

    fin.close();
    fout.close();

}
