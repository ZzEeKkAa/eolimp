#include <stdio.h>
#include <vector>

using namespace std;

int n,t, tpos;
vector<vector<int> > g, cv;
vector<int> color, bk, d, f, ans, tg;

void dfs(int v){
    int nv = ++tpos;
    tg[v] = nv; bk[nv]=v;
    cv[color[v]].push_back(nv);
    d[nv]=++t;

    for(vector<int>::iterator to = g[v].begin(); to<g[v].end(); ++to){
        dfs(*to);
    }

    f[nv]=++t;
}

void dfsans(int v){
    for(vector<int>::iterator to = g[v].begin(); to<g[v].end(); ++to){
        dfsans(*to);
        ans[tg[v]]+=ans[tg[*to]];
    }
}

int main(){
    int c,p,v;
    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);

    scanf("%d",&n);

    // Default
    t=0; tpos=0;
    color.assign(n+1,0);
    f.assign(2*n+1,0); bk.assign(2*n+1,0);
    d.assign(2*n+1,0);
    ans.assign(n+1,0);
    g.assign(n+1, vector<int>());
    cv.assign(n+1, vector<int>());
    tg.assign(n+1, 0);

    // Input
    for(int i=1; i<=n; ++i){
        scanf("%d %d", &p, &c);
        g[p].push_back(i);
        color[i]=c;
    }

    dfs(g[0][0]);

    int v1,v2, minv, maxv, curv;

    f[0]=-1;
    for(int i=1; i<=n; ++i){
        //printf("Checking color %d\n", i);
        v1=0;
        for(int j = cv[i].size()-1; j>=0; --j){
            v2 = cv[i][j];

            //printf("Checking v = %d (%d/%d)  // previous v = %d \n",v2,d[v2],f[v2],v1);

            if(v1==0) {
                v1 = v2;
                ++ans[v2];
                continue;
            }

            if(f[v2]>f[v1]){ // If v2 parent of v1
                continue;
            } else {         // If v2 brother of v1
                ++ans[v2];

                minv=1;
                maxv=v1-1;

                /*while(minv<maxv){
                    curv = (minv+maxv+1)/2;
                    if(d[curv]<d[v2] && f[v1]<f[curv]){ // curf is parent of both v1 and v2
                        minv=curv;
                    } else {
                        maxv=curv-1;
                    }
                } curv=minv;*/
                curv=v1-1;
                while(!(d[curv]<d[v2] && f[v1]<f[curv]))

                --ans[curv];
                //printf("(%d,%d) - %d\n",v2,v1,curv);
                v1=v2;
            }

        }
    }

    /*
    for(int i=1; i<=n; ++i){
        //printf("Color: %d\n",i);
        if(cv[i].size()>0){
            v=0;
            vector<int>::iterator it=cv[i].end(); --it;
            for(; it>=cv[i].begin(); --it){

                //printf("%d, %d\n",v,*it);
                if(f[v]>f[*it]) {
                    //printf("++\n");
                    ++ans[*it];
                    if(v==0) {
                        v=*it;
                        continue;
                    }

                    int maxf=2*n, minf=f[*it]+1, curf;

                    while(minf<maxf){
                        curf=(minf+maxf)/2;
                        while(bk[curf]==0) curf--;
                        if(curf>f[v] && d[bk[curf]]<d[*it]){
                            maxf=curf;
                        } else {
                            minf=curf+1;
                        }
                    }

                    //printf("%d (%d)\n",minf,bk[minf]);
                    //while(bk[minf]==0) minf++;
                    --ans[bk[minf]];

                    v=*it;
                }

            }
        }
    }*/

    dfsans(g[0][0]);

    printf("%d",ans[tg[1]]);
    for(int i=2; i<=n; ++i){
        printf(" %d",ans[tg[i]]);
    }
    printf("\n");/**/

    return 0;
}
