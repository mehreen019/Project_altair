#include<bits/stdc++.h>
#define ll long long
#define maxx 200001
using namespace std;

vector<bool> visit(maxx, false);
map<ll,list<ll>> adj;
ll cou=0;

void addEdge(ll u, ll v){
    adj[u].push_back(v);
}

void dfs(ll n){
    if(visit[n]) return;


    visit[n]=true;
    cou++;
    for(auto it=adj[n].begin(); it!=adj[n].end();it++){
        if(!visit[*it]) dfs(*it);
    }
}

int main(void){
    int vertices, edge1, edge2;
    cout<<"Vertices: ";
    cin>>vertices;
    cout<<"Edges: ";
    for(int i=0;i<vertices;i++){
        cin>>edge1>>edge2;
        addEdge(edge1, edge2);
        addEdge(edge2, edge1);
    }
    dfs(0);
    if(cou!=vertices) cout<<"Output: false"<<endl;
    else cout<<"Output: true"<<endl;

}

