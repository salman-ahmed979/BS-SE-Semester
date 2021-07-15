#include<iostream>
#include<queue>
using namespace std;
class Graph {

    private:
        int **adj_matrix_graph;
        int vertices;
    public:

        Graph(int v) {
            vertices = v;
            adj_matrix_graph = new int*[vertices];
            for(int i=0; i < vertices; i++)
                adj_matrix_graph[i] = new int[vertices];
            for(int i=0; i < vertices; i++) 
                for(int j=0; j < vertices; j++)
                    adj_matrix_graph[i][j] = 0;
            cout << "Graph Created with " << vertices << " vertices.\n";
        }

        ~Graph() {
            if(adj_matrix_graph != 0) {
                for(int i=vertices-1; i >= 0; i--)
                    if(adj_matrix_graph[i] != 0) {
                        adj_matrix_graph[i] = 0;
                        delete [] adj_matrix_graph[i];
                    }
                adj_matrix_graph = 0;
                delete [] adj_matrix_graph;
            }
            cout << "\nObject deleted\n";
        }

        void insert(void) {
            for(int i=0; i < vertices; i++) {
                for(int j=0; j < vertices; j++) {
                    cout << "\nEnter edge in " << i << " row and " << j << " col: ";
                    cin >> adj_matrix_graph[i][j];
                }
                cout << "\n";
            }
        }

        void printGraph(void) {
            for(int i=0; i < vertices; i++) {
                for(int j=0; j < vertices; j++) {
                    cout << "\nEdges in " << i << " row and " << j << " col: ";
                    cout << adj_matrix_graph[i][j];
                }
                cout << "\n";
            }
        }

        void DFS(int v, bool visited[]) {
            visited[v] = true;
            //visit the vertex
            cout << " " << v << " "; 

            //for each vertex 'u' adjacent to v
            for(int i=0; i < vertices; i++) {
                if(adj_matrix_graph[v][i] == 1 && !visited[i]) 
                    DFS(i,visited);
            }
        }

        void DepthFirstSearch(void) {
            bool visited[vertices];
            for(int i=0; i < vertices; i++)
                visited[i] = false;
            for(int i=0; i < vertices; i++) {
                if(!visited[i])
                    DFS(i, visited);
            }
        }

        void BreadthFirstSearch(void) {
            queue<int> q1;
            bool visited[vertices];
            for(int i=0; i < vertices; i++)
                visited[i] = false;
            for(int index=0; index < vertices; index++) {
                if(!visited[index]) {
                    q1.push(index);
                    visited[index] = true;
                    cout << " " << index << " ";
                    while(!q1.empty()) {
                        int v = q1.front();
                        q1.pop();
                        for(int i=0; i < vertices; i++) 
                            if(adj_matrix_graph[v][i] == 1 && !visited[i])
                            {
                                q1.push(i);
                                visited[i] = true;
                                cout << " " << i << " ";
                            }
                    }
                    //end while
                }
            }
        }

        int minimum_distance(int dist[], bool visit[]) {
            int min = 100000, min_index = 0;
            for(int i=0; i < vertices; i++) {
                if(!visit[i] && min > dist[i])
                {
                    min = dist[i];
                    min_index = i;
                }
            }
            return min_index;
        }
        
        bool check_visit(bool visit[]) {
            int count = 0;
            for(int i=0; i < vertices; i++)
                if(visit[i] == true) count++;
            if(count == vertices-1) return true;
            return false;
        }

        void Dijkstra_Algorithm(int first) {
            //matrix for the distance for all vertices
            int dist[vertices], parent[vertices];
            for(int i=0; i < vertices; i++)
                dist[i] = 1000; // here 1000 is infinite
            dist[first] = 0; // starting vertex

            //for visiting checker
            bool visited[vertices];
            for(int i=0; i < vertices; i++)
                visited[i] = false;
            parent[0] = -1;
            
            for(int j=0; j < vertices -1; j++)
            {
                int min = minimum_distance(dist, visited);
                if(!visited[min]) {
                    visited[min] = true;
                    int v = min;

                    for(int i=0; i < vertices; i++) {
                        if(adj_matrix_graph[v][i] != 0 && !visited[i] && dist[v] != 1000 && dist[i] > dist[v] + adj_matrix_graph[v][i] ) {
                            dist[i] = dist[v] + adj_matrix_graph[v][i];
                            parent[i] = v;
                        }
                    }                    
                }
            }

            for(int i=0; i < vertices; i++) {
                cout << "Disances of " << i << " is: " << dist[i] << "\n";
                cout << "Parent of " << i << " is: " << parent[i] << "\n";
            }
        }

        void Ford_Algorithm(int first) {
            int dist[vertices], parent[vertices];
            for(int i=0; i < vertices; i++)
                dist[i] = 1000;
            dist[first] = 0;
            parent[first] = -1;
            for(int v=0; v < vertices -1; v++) {
                for(int i=0; i < vertices; i++) {
                    if(adj_matrix_graph[v][i] != 0 && dist[v] != 1000 && dist[i] > dist[v] + adj_matrix_graph[v][i])
                    {
                        dist[i] = dist[v] + adj_matrix_graph[v][i];
                        parent[i] = v;
                    }
                }
            }
            for(int i=0; i < vertices; i++) {
                cout << "Disances of " << i << " is: " << dist[i] << "\n";
                cout << "Parent of " << i << " is: " << parent[i] << "\n";
            }
        }
};
int main() {
    int n;
    cout << "\nEnter number of vertices in grapgh: ";
    cin >> n;
    Graph g1(n);
    g1.insert();
    g1.printGraph();
    // cout << "\nDoing depth first search\n";
    // g1.DepthFirstSearch();
    // cout << "\nDoing breadth first search\n";
    // g1.BreadthFirstSearch();
    //g1.Dijkstra_Algorithm(0);
    g1.Ford_Algorithm(0);
    return 0;
}