#include<bits/stdc++.h>
#define ll long long
#define maxx 200001
using namespace std;

vector<bool> visit(maxx, false);//boolean array to keep count of whether the vertices have been visited or not
map<ll,list<ll>> adj;       //main graph map
ll cou=0;                   //keeping count of how many vertices have been traversed

void addEdge(ll u, ll v){
    adj[u].push_back(v);
}

void dfs(ll n){
    if(visit[n]) return;    //if the graph has been visited once before, no need to visit it again


    visit[n]=true;
    cou++;                  //increasing the count of the vertices
    for(auto it=adj[n].begin(); it!=adj[n].end();it++){
        if(!visit[*it]) dfs(*it);      //running dfs on all adjacent vertices
    }
}

int main(void){
    int vertices, edge1, edge2;
    cout<<"Vertices: ";
    cin>>vertices;
    cout<<"Edges: ";
    for(int i=0;i<vertices;i++){
        cin>>edge1>>edge2;
        addEdge(edge1, edge2);  //edges are pushed back into the graph bothways
        addEdge(edge2, edge1);
    }
    dfs(0);                    //running a dfs starting from the first vertex. if it's a connected graph all vertices will be visited
    if(cou!=vertices) cout<<"Output: false"<<endl; //if all the vertices aren't connected, it's an unconneced graph thus the output is false
    else cout<<"Output: true"<<endl;

}

