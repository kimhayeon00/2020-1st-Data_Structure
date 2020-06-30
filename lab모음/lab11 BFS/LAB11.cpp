#include<iostream>
#include<fstream>
using namespace std;

#define MAX 8
int DATA1[8][8] = { 
	{0,1,1,0,0,0,0,0},
	{1,0,0,1,1,0,0,0},
	{1,0,0,0,0,1,1,0},
	{0,1,0,0,0,0,0,1},
	{0,1,0,0,0,0,0,1},
	{0,0,1,0,0,0,0,1},
    {0,0,1,0,0,0,0,1},
    {0,0,0,1,1,1,1,0}
};

int DATA2[6][6] = {
    {0,1,1,0,0,0},
    {1,0,1,1,0,0},
    {1,1,0,0,0,1},
    {0,1,0,0,1,1},
    {0,0,0,1,0,1},
    {0,0,1,1,1,0}

};

class Node{
private:
	int data;
	Node* link;
	friend class Graph;
};

class Graph{
private:
	Node* graph[8];	
	Node *front;
	Node *rear;
	int arr[8][8];	
	bool visited[8];
public:
	Graph();
	void init();
	void print();
	void insert();
    void print2();
	void insert2();
	void insertG(int num1, int num2);
	void enqueue(int num);
	int dequeue();
	void bfs(int num);	
	void printG();	
};

Graph::Graph()
	:front(0), rear(0)
{
	init();
}

void Graph::init()
{
	for (int a = 0; a < MAX; a++)
	{
		graph[a] = 0;
		visited[a] = false;

		for (int b = 0; b < MAX; b++)
			arr[a][b] = 0;
	}
}

void Graph::insertG(int num1, int num2)
{
	Node* temp = new Node();
    temp ->data = num2;

	if (graph[num1] == 0)
		graph[num1] = temp;
	else
	{
		Node* p = graph[num1];
		Node* q;

		while (p != 0 && p->data < num2)
		{
			q = p;
			p = p->link;
		}
		q->link = temp;
		temp->link = p;
	}
}


void Graph::enqueue(int num)
{
	Node* temp = new Node();
    temp -> data = num;
	if (front == 0)
	{
		front = temp;
		rear = front;
	}
	else
	{
		rear->link = temp;
		rear = temp;
	}
}

int Graph::dequeue()
{
	if (front)
	{
		Node* p = front;
		int data = p->data;

		if (front == rear)
		{
			front = 0;
			rear = 0;
		}
		else
		{
			front = front->link;
		}

		delete p;

		return data;
	}
	else
		return 0;
}

void Graph::bfs(int num)	
{
    Node *p;
	visited[num] = true;
	enqueue(num);
	cout << num << " ";

	while (front)
	{
		num = dequeue();

		for (p = graph[num]; p; p = p->link)
		{
			if (!visited[p->data])
			{
				enqueue(p->data);
				visited[p->data] = true;
				cout << p->data << " ";
			}
		}
	}
	cout << endl;

}


void Graph::print(){
	cout << "   ";
	for (int a = 0; a < MAX; a++)
		cout << 'v' << a << " ";
	cout << endl;
	for (int b = 0; b < MAX; b++)
	{
		cout << 'v' << b << "  ";
		for (int c = 0; c < MAX; c++)
		{
			cout << DATA1[b][c] << "  ";
		}
		cout << endl;
	}
}

void Graph::print2(){
	cout << "   ";
	for (int a = 0; a < 6; a++)
		cout << 'v' << a << " ";
	cout << endl;
	for (int b = 0; b < 6; b++)
	{
		cout << 'v' << b << "  ";
		for (int c = 0; c < 6; c++)
		{
			cout << DATA2[b][c] << "  ";
		}
		cout << endl;
	}
}

void Graph::insert()
{
	for (int a = 0; a < MAX; a++)
		for (int b = 0; b < MAX; b++)
		{
			if (DATA1[a][b])
			{
				insertG(a, b);
				arr[a][b] = DATA1[a][b];
			}
		}
}

void Graph::insert2()
{
	for (int a = 0; a < 6; a++)
		for (int b = 0; b < 6; b++)
		{
			if (DATA2[a][b])
			{
				insertG(a, b);
				arr[a][b] = DATA2[a][b];
			}
		}
}


int main()
{
	Graph g;
	g.insert();
    g.print();
    cout << "Breadth First Search -> ";
    g.bfs(0);

    Graph w;
    w.insert2();
    w.print2();
    cout << "Breadth First Search -> ";
    w.bfs(0);
	return 0;
}