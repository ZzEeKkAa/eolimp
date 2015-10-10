#include <stdio.h>

#define MAX 26
#define MAX_LEN 11
#define MAX_VOC 500


using namespace std;

bool error;
bool m[MAX][MAX];
char voc[MAX_VOC][MAX_LEN];

void clear_m(){
    for(int i=0; i<MAX; ++i)
    for(int j=0; j<MAX; ++j)
        m[i][j]=0;
}

void build(int s, int e, int p){
    //printf("%d - %d\n",s,e);
    if(s==e) return;
    if(p+1==MAX_LEN) return;
    if(p>0 && voc[s][p-1]==0) return;
    char pr=voc[s][p];
    int start=s;
    for(int i=s; i<=e; ++i){
        if(voc[i][p]!=pr){
            if(voc[i][p]==0) {error = true; return;}

            build(start,i-1,p+1);
            if(error) return;

            if(pr!=0){
                m[pr-'a'][voc[i][p]-'a']=1;
                //printf("%c->%c\n",pr,voc[i][p]);
            }
            start=i;
            pr=voc[i][p];
        }
    }

    build(start,e,p+1);
    if(pr!=0 && voc[e][p]!=0 && pr!=voc[e][p])
    m[pr-'a'][voc[e][p]-'a']=1;
}

void floyd(){
    if(error) return;
    for(int k=0; k<MAX; ++k)
    for(int i=0; i<MAX; ++i)
    for(int j=0; j<MAX; ++j)
        if(m[i][k] && m[k][j]){
            //if(i==j) printf("floyd: %d<->%d\n",i,k);
            m[i][j] = 1;
        }
}

bool check(){
    if (error) return false;
    for(int i=0; i<MAX; ++i) if(m[i][i]) return false;
    return true;
}

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int n;
    while(scanf("%d",&n)==1){
        if(n==0) break;
        for(int i=0; i<n; ++i){
            scanf("%s",voc[i]);
        }

        clear_m();

        error=false;
        build(0,n-1,0);
/*
        if(error) printf("Error!\n");
        for(int i=0; i<3; ++i){
        for(int j=0; j<3; ++j)
            printf("%d ", m[i][j]); printf("\n");}
        printf("\n");
*/
        floyd();

        if(check()){
            printf("yes\n");
        } else {
            printf("no\n");
        };
/*
        for(int i=0; i<3; ++i){
        for(int j=0; j<3; ++j)
            printf("%d ", m[i][j]); printf("\n");}
        printf("\n");

        printf("------------------------------------\n\n");*/
    }



}
