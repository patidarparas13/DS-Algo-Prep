#include<iostream>
#include<list>
#include<queue>
using namespace std;

class Graph{
    int V;
    list<int> *l;
    public:
        Graph(int v){
            V = v;
            l = new list<int>[V];
        }

        void addEdge(int i,int j){
            l[i].push_back(j);
                l[j].push_back(i);
        }
        bool dfs(int node,vector<bool> &visited,int parent){
            visited[node] = true;
            for(auto nbr:l[node]){
                if(!visited[nbr]){
                    bool nbrFoundACycle = dfs(nbr,visited,node);
                        if(nbrFoundACycle){
                            return true;
                        }
                }
                else if(nbr!=parent){
                    return true;
                }
            }
            return false;
        }

  bool contains_cycle(){
      //Graph is a single component
      vector<bool> visited(V,false);
      return dfs(0,visited,-1);
  }
};

int main(){
    Graph g(3);
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(2,3);
    cout<<g.contains_cycle();

    return 0;
    
}
