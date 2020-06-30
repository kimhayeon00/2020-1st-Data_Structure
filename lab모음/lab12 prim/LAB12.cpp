#include <iostream>
#include <fstream>
using namespace std;
#define MAX 6

int cost[MAX][MAX] = {  
	{ 100,6,1,5,100,100},
	{ 6,100,4,100,3,100 },
	{ 1,4,100,5,6,5 },
	{ 5,100,5,100,100,2 },
	{ 100,3,6,100,100,6 },
	{ 100,100,5,2,6,100 }
};

class primMST
{	
	int Edge1, Edge2, sum1 , sum2 ;
	int Lowcost[6];
	bool visited[6];
public:
    void init();
    int findLeast(int arr[]);
	void print(int v, int u);
	void print();
	void prim1(int v);
	void prim2(int v);
};

void primMST::init(){
    for (int i = 0; i < 6; i++)
	{
		visited[i] = false;
        Lowcost[i] = 100;
	}
}
void primMST::print(int v, int u)
{
	
	cout <<"v" << v+1 << "," << "v"<< u+1 << " ";
	visited[v] = true;
}

void primMST::print()
{
    
	cout << "\t";
	for (int i = 0; i < 6; i++)
	{
		cout << "v" << i+1 << "\t";
	}
	cout << endl;
	for (int i = 0; i < 6; i++)
	{	
		cout <<"v" <<i+1 << "\t";
		for (int j = 0; j < 6; j++)
		{
			cout << cost[i][j] << "\t";
		}
		cout << endl;
	}
    
}

void primMST::prim1(int v)
{
	int min = 100;
	int minidx;
	for (int i = 0; i < 6; i++)
	{
		if (cost[v][i] < min && visited[i] != true)
		{
			min = cost[v][i];
			minidx = i;
		}
	}
	sum1 += min;
	print(v, minidx);
	if (Edge1 < 4)
	{
		cout << "-> ";
	}
	else
	{
		cout << endl << "Total: " << sum1 << endl;
	}
	Edge1++;
	if (Edge1 < 5)
	{
		prim1(minidx);
	}
}
int primMST::findLeast(int arr[])
{
	int min = 100;
	int minidx = 0;
	for (int i = 0; i < 6; i++)
	{
		if (arr[i] < min && visited[i] != true)
		{
			min = arr[i];
			minidx = i;
		}
	}
	return minidx;
}
void primMST::prim2(int v)
{
	
	for (int i = 0; i < 6; i++)
	{
		if (Lowcost[i] > cost[v][i] && visited[i] == false)
		{
			Lowcost[i] = cost[v][i];
		}
	}
	while (Edge2 < 5)
	{
		int u = findLeast(Lowcost);
		int idx;
		for (int i = 0; i < 6; i++)
		{
			if (cost[i][u] == Lowcost[u])
			{
				idx = i;
			}
		}
		Lowcost[u] = 100;
		sum2 += cost[idx][u];
		print(idx, u);
		if (Edge2 != 4)
		{
			cout << "-> ";
		}
		else
		{
			cout << endl << "Total: " << sum2 << endl;
		}
		visited[u] = true;
		Edge2++;
		prim2(u);
	}
}

int main()
{   
    primMST MST;
	MST.init();
	MST.print();

	cout << endl;
	MST.prim1(0);
    MST.init();
	cout << endl << "Revised Prim's Algorithm" << endl;
	MST.prim2(0);

	return 0;
}
