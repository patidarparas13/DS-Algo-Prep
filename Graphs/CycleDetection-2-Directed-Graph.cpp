#include<iostream>
#include<list>
#include<vector>
using namespace std;

class Graph{
    int V;
    list<int> *l;
    public:
    Graph(int v){
        this->V = v;
        l = new list<int>[V];
    }

    void addEdge(int x,int y){
        l[x].push_back(y);
    }

    bool dfs(int node,vector<bool> &visited,vector<bool> &stack){
        // return true if backedge is found, else false
        //Arrive at Node
            visited[node] = true;
            stack[node] = true;
        //do some work at node, return true if backedge is found here itself
            for(int nbr:l[node]){
                // Immediately BackEdge
                if(stack[nbr]==true){
                    return true;
                }
                // If Nbr recursively leads to BackEdge
                else if(visited[nbr]==false){
                    bool nbrFoundACycle = dfs(nbr,visited,stack);
                    if(nbrFoundACycle){
                        return true;
                    }
                }
            }

        //Going Back
        stack[node] = false;
        return false;
    }

    bool contains_cycle(){
        vector<bool> visited(V,false);
        vector<bool> stack(V,false);

        for(int i=0;i<V;i++){
            if(!visited[i]){
                if(dfs(i,visited,stack)){
                    return true;
                }
            }
        }
        return false;

    }
};

int main(){
    Graph g(3);
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(2,0);
    cout<<g.contains_cycle()<<endl;
    return 0;
}
