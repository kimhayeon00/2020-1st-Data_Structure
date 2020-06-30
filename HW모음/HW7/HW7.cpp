/////////////////////////////////////////////////////////////////////////////////////////////////
//  Name:  김하연
//  Student ID  :   20191580
//  Program ID  :   HW7
//  Description :   Kruskal’s Algorithm (MST)
//  Algorithm   : 
//      1) 데이터를 입력받아 한 간선씩 mst 배열에 저장한다.
//      2) 비용의 크기를 기준으로 간선을 오름차순 정렬한다.
//      3) kruskal 함수에서 먼저 이어진 정점중 큰 문자를 확인한다(A<B)
//      4) visited 에서 큰 문자는 작은 문자로 바꿔주어 방문을 확인한다.
//      5) 방문하지 않았으면 sum을 더해주며 출력해준다.
//  Variables:
//      1) visited : 방문을 확인하는 배열
//      2) mst[10] : 데이터 파일로부터 정점과 cost를 입력받아 넣을 배열
//      3) visitedinit() : visited 배열 초기화 하는 함수
//      4) InputPrint() : input파일 출력
//      5) sorted() : cost를 기준으로 오름차순 정렬해주는 함수
//      6) kruskal() : 최소비용 신장트리 생성하여 출력하는 함수
////////////////////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <fstream>
using namespace std;

const int MAX = 10;		//간선 수
const int V = 6;		//정점 수

int visited[V] = { 0, };		
////////////////////////////////////////////////////////////////
// Function    : struct MST
// Description : 정점 x, y 와 간선 비용 cost를 갖고있는 MST 구조체 생성
/////////////////////////////////////////////////////////////////
struct MST {		
	char x;
	char y;
	int cost;
};

MST mst[10];		//데이터 파일로부터 x,y,cost를 입력 받아 넣기

////////////////////////////////////////////////////////////////
// Function    : visitedinit
// Description : visited 배열을 초기화
/////////////////////////////////////////////////////////////////
void visitedinit() {		

	for (int i = 0; i < V; ++i) {
		visited[i] = i;
	}
}


void Inputrint() {		//Input Data를 출력

	cout << "Input Data : " << endl;
	for (int i = 0; i < MAX; ++i) {
		cout << mst[i].x << " " << mst[i].cost << " " << mst[i].y << " " << "\t";
	}
	cout << endl;

}
////////////////////////////////////////////////////////////////
// Function    : sorted
// Description : 정렬되지 않은 MST 구조체 배열을 오름차순으로 정렬하는 함수
// Variables: min - 남은 것 중 가장 작은 수를 찾기위한 변수
/////////////////////////////////////////////////////////////////

void sorted() {			

	for (int i = 0; i < MAX; ++i) {
		int min = mst[i].cost;
		int minpos = i;
		for (int j = i; j < MAX; ++j) {
			if (mst[j].cost < min) {
				min = mst[j].cost;
				minpos = j;
			}
		}
		MST temp;
		temp = mst[i];
		mst[i] = mst[minpos];
		mst[minpos] = temp;

	}
}
void sortedprint() {		//정렬된 Sorted Data를 출력
	cout << "Sorted Data : " << endl;
	for (int i = 0; i < MAX; ++i)
		cout << mst[i].x  << " " << mst[i].cost << " " << mst[i].y  << " " << "\t";
	cout << endl;
}


////////////////////////////////////////////////////////////////
// Function    : kruskal
// Description : 최소비용 신장트리를 생성하여 출력하는 함수
// Variables: accept - 방문을 확인하기 위한 임의의 변수
/////////////////////////////////////////////////////////////////

void kruskal() {		
 
	int sum = 0;	//Total Cost를 저장할 sum 변수
    int a = 1;
	cout << "Minimum Spanning Tree : " << endl;

	for (int i = 0; i < MAX; ++i) {		
		if (visited[mst[i].x - 'A'] < visited[mst[i].y-'A']) {	
			int accept = visited[mst[i].y - 'A'];			
			for (int j = 0; j < V; j++) {
				if (visited[j] == accept) {		
					visited[j] = visited[mst[i].x - 'A'];
				}
			}
			sum += mst[i].cost;	//선택된 간선의 가중치를 sum에 더해준다

			cout <<"Edge "<< a++ << ": "<<  mst[i].x  << " " << mst[i].cost << " " << mst[i].y  << " " << endl;	//선택된 간선을 출력
		}
		else if (visited[mst[i].x - 'A'] > visited[mst[i].y - 'A']) {	
			int accept = visited[mst[i].y - 'A'];			
			for (int j = 0; j < V; j++) {
				if (visited[j] == accept) {		
					visited[j] = visited[mst[i].y - 'A'];
				}
			}
			sum += mst[i].cost;	

			cout <<  mst[i].x  << " " << mst[i].cost << " " << mst[i].y  << " " << endl;	
			break;
		}
	}
	cout << endl;
	cout << "Total Cost : " << sum << endl;
}

int main() {

	ifstream fin;
	fin.open("input.txt");
	for (int i = 0; i < MAX; i++)
		fin >> mst[i].x >> mst[i].cost >> mst[i].y ;
	
	Inputrint();		
	sorted();			
	sortedprint();		
	visitedinit();
	kruskal();			
}
