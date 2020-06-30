#include <iostream>
#include <fstream>

using namespace std;
#define infinit 10000
#define MAX 7

int choose(int distance[], int n, bool visited[]) {
    int i, min = infinit, tmp;

    for (i = 0; i < n; i++) {
        if (distance[i] <= min && !visited[i]) {
            min = distance[i];
            tmp = i;
        }
    }
    return tmp;
}

void shortestpath(int v, int cost[MAX][MAX], int distance[], int n, bool visited[]) {
    for (int i = 0; i < n; i++) {
        visited[i] = false;
        distance[i] = cost[v][i];
    }

    int u;
    visited[v] = true;
    distance[v] = v;
    cout << "start from vertex " << " : " << v  <<"  ";
    for (int i = 0; i < n - 1; i++) {

        cout << "Distance -> \t";
        for (int i = 0; i < n; i++) {
            cout << distance[i] << " ";
        }
        cout << endl;
        u = choose(distance, n, visited);
        cout << "Select Node : " << u << "\t\t";
        visited[u] = true;

        for (int w = 0; w < n; w++) {
            if (!visited[w]) {
                if (distance[u] + cost[u][w] < distance[w])
                    distance[w] = distance[u] + cost[u][w];
            }
        }
    }

    cout << "Distance -> \t";
    for (int i = 0; i < n; i++) {
        cout << distance[i] << " ";
    }
    cout << endl;
}


int main() {
    int distance[MAX] = {0,};
    bool visited[MAX];
    int cost_matrix[MAX][MAX];

    ifstream is("input.txt");
    for(int i = 0; i < MAX; i++){
        for(int j = 0; j < MAX; j++){
            is >> cost_matrix[i][j];
        }
    }

    cout << "***** Adjacency matrix *****" << endl;
    cout << endl;
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++){
            cout << cost_matrix[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl;
    cout << "***** Shortest path *****" << endl;
    cout << endl;
    shortestpath(0, cost_matrix, distance, MAX, visited);

    int distance2[MAX] = {0,};
    bool visited2[MAX];
    int cost_matrix2[MAX][MAX];

    for(int i = 0; i < MAX; i++){
        for(int j = 0; j < MAX; j++){
            is >> cost_matrix2[i][j];
        }
    }
    cout << "***** Adjacency matrix *****" << endl;
    cout << endl;
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++){
            cout << cost_matrix2[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl;
    cout << "***** Shortest path *****" << endl;
    cout << endl;
    shortestpath(0, cost_matrix2, distance2, MAX, visited2);

 
    
    
}