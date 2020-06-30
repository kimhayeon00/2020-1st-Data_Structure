/////////////////////////////////////////////////////////////////////////////////////////////////
//  Name:  김하연
//  Student ID  :   20191580
//  Program ID  :   HW6 
//  Description :   Graph Search (Depth First Search: DFS) 
//  Algorithm   : 
//   1) init       - graph 배열과 visited 배열을 초기화 해준다.
//   2) buildGraph - input파일에서 두개의 숫자를 가져온다. 이를 num1, num2 라고 한다.
//                 - graph[num1] 이 비어있으면 num1을 데이터값으로 갖는 노드를 넣어준다.
//                 - graph[num2] 이 비어있으면 num2를  데이터 값으로 갖는 노드를 넣어준다.
//                 - num1과 num2를 연결시킨다.
//   3) printGraph - 연결된 순서대로 data값을 출력한다.
//   4) dfs        - visited 배열에서 입렵받은 숫자 v 위치에 방문했다고 표시한다.
//                 - graph[v]부터 연결된 노드들을 돌면서 방문하지 않은 곳은 dfs(p->data) 하여 방문해준다.
//                 - 모든 노드를 방문하였으면 그만한다.
//   5) main       - 먼저 graph 배열과 visited 배열을 초기화 해준다.
//                 - input 파일에서 Adjacency list를 읽어와서 buildGraph 함수에 넣어준다.
//                 - 인접한 노드를 나타내기위해 printGraph 함수를 불러온다.
//                 - dfs 함수에 0을 넣어주어 v0부터 방문한 노드를 순서대로 보여준다.
//  Variables:
//   1) data - 노드가 갖는 데이터 값
//   2) link - 노드와 노드를 연결하기 위한 링크
//   3) graph - 노드를 묶어서 리스트로 나타내기 위함
//   4) visited - 방문한 곳을 확인하기 위한 배열
//   5) initGraph() - graph를 초기화하기 위함
//   6) initVisited() - visited를 초기화하기 위함
//   7) buildGraph() - graph에 노드를 연결하여 넣기 위함
//   8) printGraph() - 인접한 노드를 출력하기 위함
//   9) dfs(int v) - 정점부터 연결된 노드를 타고 가며 방문 표시를 하기 위함
////////////////////////////////////////////////////////////////////////////////////////////////


#include <iostream>
#include <fstream>
using namespace std;

const int MAX = 10; // 인풋파일에 있는 최대 줄 수가 10

class Node {
private:
	int data;
	Node* link;
public:
	Node(int num) :data(num), link(NULL) {}
	friend class Graph;
};

class Graph {
private:
	Node * graph[MAX]; //노드 리스트
	bool visited[MAX]; //방문했는지 확인
public:
	void initGraph();
	void initVisited();
	void buildGraph(int num1, int num2);
	void printGraph();
	void dfs(int v);
};
////////////////////////////////////////////////////////////////
// Function    : initGraph
// Description : graph를 NULL로 초기화 해준다.
/////////////////////////////////////////////////////////////////
void Graph::initGraph() {
	for (int i = 0; i < MAX; i++)
		graph[i] = NULL;
}

////////////////////////////////////////////////////////////////
// Function    : initVisited
// Description : visited를 false로 초기화 해준다.
/////////////////////////////////////////////////////////////////
void Graph::initVisited() {
	for (int i = 0; i < MAX; i++)
		visited[i] = false;
}

////////////////////////////////////////////////////////////////
// Function    : buildGraph
// Description : input 파일에서 읽어온 값을 이용하여 노드를 연결시켜 그래프를 완성한다.
// variables : num = 읽어온 숫자
//             tmp = 입력받은 수를 데이터 값으로 갖는 새로운 노드
/////////////////////////////////////////////////////////////////
void Graph::buildGraph(int num1, int num2) {
	if (graph[num1] == NULL) { //graph[num1] 에 노드가 없을 때
		Node* tmp1 = new Node(num1);
		graph[num1] = tmp1;
	}
	if (graph[num2] == NULL) {
		Node* tmp2 = new Node(num2);
		graph[num2] = tmp2;
	}

	Node* p = graph[num1];
	Node* q = new Node(num2);
	while (p->link != NULL) p = p->link;
	p->link = q; // 노드 연결 시켜주기

	p = graph[num2];
	Node* w = new Node(num1);
	while (p->link != NULL) p = p->link;
	p->link = w;
}

////////////////////////////////////////////////////////////////
// Function    : printGraph
// Description : 인접한 노드를 출력하기 위한 함수
/////////////////////////////////////////////////////////////////
void Graph::printGraph() {
	for (int i = 0; i < 10; i++) {
		if (graph[i] != NULL) {
			Node* p = graph[i];
			if(p != NULL){
				cout << "Graph[" << p -> data << "] -> ";
				p = p->link;
			}
			
			while (p != NULL) {
				cout << p->data << " ";
				p = p->link;
			}
			cout << endl;
		}
	}
}

////////////////////////////////////////////////////////////////
// Function    : dfs
// Description : 그래프를 깊이우선탐색하여 순서대로 출력하기 위함
/////////////////////////////////////////////////////////////////
void Graph::dfs(int v) {
	Node* p;
	visited[v] = true;	//방문한거 표시
	cout <<"V"<< v;

	for (p = graph[v]; p; p = p->link) {
		if (!visited[p->data]){ // 더이상 방문할 노드가 없으면 끝
            cout << " -> ";
            dfs(p->data);
        }	
	}
}

int main(void) {
	Graph g;
	g.initGraph();
	g.initVisited();
	ifstream inStream;
	inStream.open("input.txt");
	cout << "\n<<   Graph data 1   >>" << endl;
	int num1, num2;
	for (int i = 0; i < MAX; i++) {
		inStream >> num1 >> num2;
		g.buildGraph(num1, num2);
	}

	cout << endl;
	g.printGraph();
	cout << endl;
	cout << "Depth first search result\n";
	g.dfs(0);
	cout << endl << endl;

	Graph t;
	t.initGraph();
	t.initVisited();
	cout << "<<   Graph data 2   >>" << endl;
	for (int i = 0; i < 8; i++) {
		inStream >> num1 >> num2;
		t.buildGraph(num1, num2);
	}

	cout << endl;
	t.printGraph();
	cout << endl;
	cout << "Depth first search result\n";
	t.dfs(0);
	cout << endl;

	inStream.close();

	return 0;
}