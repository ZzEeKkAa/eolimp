#include <stdio.h>
#include <string>
#include <vector>

using namespace std;
int p[1000001];

bool Greater(vector<int> &a, vector<int> &b){

}

void multiply(vector<int> &a, vector<int> &b, vector<int> &res){

}


int main(){

    int t;
    string s;
    vector<int> a,b,res,tmp;
    vector<vector<int> > d;

    scanf("%n", t);

    for(int i=0; i<t; ++i){
        scanf("%s", &s);
        for(int i=s.size()-1; i>=0; ++i){
            if(s[i]>='0' && s[i]<='9')
                a.push_back(s[i]-'0');
        }
        scanf("%s", &s);
        for(int i=s.size()-1; i>=0; ++i){
            if(s[i]>='0' && s[i]<='9')
                b.push_back(s[i]-'0');
        }

        tmp=b;

        int i;
        while(b.size()>0 && b!=0){
            // Decreasing a
            i=0;

        }




    }


}
