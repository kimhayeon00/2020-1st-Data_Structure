////////////////////////////////////////////////////////////////
// Name:  김하연
// Student ID  :   20191580
// Program ID :   HW3 Maze Problem
// Description:   주어진 matrix 안에서, stack을 이용하여 길을 찾고 path와 matrix를 출력한다.
// Algorithm :  
//      1)  시작점과 도착점을 정해준다.
//      2)  N,NE,E,SE,S,SW,W,NW에 대한 배열을 선언해준다.
//      3)  [i][j]에서 sw로 이동한 후 [g][h]위치가 되었다면 g= i+ move[sw].vert; h= j+ move[sw].horiz;
//      4)  현위치를 저장하고 북쪽부터 시계방향으로 선택한다.
//      5)  잘못된 경로로 들어가면 mark[row][col]=1;을 해주어 다시 들어가지 않도록 한다.
//      6)  방문된 좌표는 모두 스택에 저장하고 종료시 출력한다.
//      7)  종료는 도착점에 도착하면 종료된다.
//      8)  저장한 스택을 이용하여 miro path와 marked matrix를 출력해준다
// Variables:   
//      element - 행(row), 열(col), 방향(dir) 을 저장하는 구조체
//      offsets - 수직(vert), 수평(horiz) 을 저장하는 구조체
//      void MOVE(offsets move[]); - 8개의 방위 배열 선언하는 함수
//      void miroPath(int maze[6][6],int mark[6][6]); - miro path를 찾아 출력해주는 함수
//      void create_stack() - 스택 초기화
//      int isEmpty() - 스택이 비어있는지 확인
//      void push(int row , int col, int dir) - 스택 top에 row, col, dir 저장
//      element pop() - top에 있는 row, col, dir 을 보여주고 top-1 해준다.
//      maze - 탈출 할 matrix
//      mark - 지나가는 길을 표시
/////////////////////////////////////////////////////////////////

#include<iostream>

using namespace std;

typedef struct{ int row; int col; int dir;} element; //행 열 방향을 나타내는 구조체 element
typedef struct{ int vert; int horiz;} offsets; // 수직, 수평 방향을 나타내는 구조체 offsets

const int stackSize = 100;
element stack[stackSize]; //stack 선언
element pop(); //stack에 있는 값 반환

int top;
void MOVE(offsets move[]);
void miroPath(int maze[6][6],int mark[6][6]);
    
void create_stack() { top = -1;}

int isEmpty(){ //스택이 비어있을 때
    if(top == -1)
        return true;
    else return false;
}

void push(int row , int col, int dir){ // push
    ++top;
    stack[top].row = row;
    stack[top].col = col;
    stack[top].dir = dir;
}

element pop(){ // pop
    return(stack[top--]);
}
        
int maze[6][6] =  { 0,1,1,1,1,1, 
                    1,0,1,1,1,1, 
                    1,0,0,0,0,1, 
                    1,1,0,1,1,1, 
                    1,0,1,0,0,1, 
                    1,1,1,1,1,0 }; //미로, 1 = 벽

int mark[6][6] =  { 0,0,0,0,0,0, 
                    0,0,0,0,0,0, 
                    0,0,0,0,0,0, 
                    0,0,0,0,0,0, 
                    0,0,0,0,0,0, 
                    0,0,0,0,0,0 }; //지나가는 길을 표시하기 위함

int main(){
    create_stack(); //스택 초기화
    push(0,0,0); // 처음 값 설정
	miroPath(maze, mark);//길을찾는 함수
	return 0;


}

void MOVE(offsets move[]){
    move[0].vert = -1;  move[0].horiz = 0; // N 
    move[1].vert = -1;  move[1].horiz = 1; // NE
    move[2].vert = 0;  move[2].horiz = 1; // E 
    move[3].vert = 1;  move[3].horiz = 1; // SE
    move[4].vert = 1;  move[4].horiz = 0; // S 
    move[5].vert = 1;  move[5].horiz = -1; // SW
    move[6].vert = 0;  move[6].horiz = -1; // W 
    move[7].vert = -1;  move[7].horiz = -1; // NW
}
////////////////////////////////////////////////////////////////
// Function: miroPath
// Description:   미로를 찾으며 지나간 길을 기록하고 출력한다.
// Variables:   
//      bool found - 도착점을 찾았는지 판별,도착점에 도달하면 true
//      int row, col, dir - 행, 열, 방향
//      int next_row - 다음 행
//      int next_col=0 - 다음 열
//      element position - 현재 위치 
//      offsets move[8]; - 이동 방향에대한 배열 선언
//      int EXIT_ROW , EXIT_COL - 도착점 선언 
/////////////////////////////////////////////////////////////////

void miroPath(int maze[6][6],int mark[6][6]){
    bool found = false; //도착점에 도달하면 true
    int row, col, dir;
    int next_row=0; // 다음 행
    int next_col=0; // 다음 열
    element position; 
    offsets move[8]; // move 선언
    MOVE(move);

    int EXIT_ROW = 5;
    int EXIT_COL = 5; // 도착점 설정
    mark[0][0] = 1;  //시작 위치인 진입좌표 1,1
    

    while (!isEmpty() && !found){ //스택이 비어있지 않고 도착점이 아닐 때
        position = pop(); // 최근 값 리턴
        row = position.row; 
        col = position.col;
        dir = position.dir;

        while (dir < 8 && !found){ // 도착점 전까지 8방향을 확인한다
            next_row = row + move[dir].vert; 
            next_col = col + move[dir].horiz;
        
            if(next_row == EXIT_ROW && next_col == EXIT_COL){ // 도착점에 도착하면
                mark[EXIT_ROW][EXIT_COL] = 1; //도착점 표시 해주기
                push(row, col, dir++);
                found = true; 
               
                
            }
            else if (!maze[next_row][next_col] && !mark[next_row][next_col]){ //이미 지나간 길인지 벽인지 판단
                mark[next_row][next_col]=1; //지나갔다는 표시를 해준다
                push(row,col,dir); //찾은 길 넣어주기

                row = next_row;
                col = next_col;
                dir = 0;

            }
            
            else {
            
                dir++;
            }
            

        }

    }
    if(found){
        cout << "The Path is\n\n";
        cout << "row\tcol\n";
        cout << "-----------\n";

        for(int i=0; i<6;i++){
            for(int j=0; j<6; j++){
                if(mark[i][j]==1){
                    cout << i<<"\t"<< j<<endl;
                }
            }
        }

        cout << "Marked Matrix\n";
        cout << "-------------\n";
        for(int i=0; i<6;i++){
            for(int j = 0; j<6;j++){
                cout << mark[i][j]<<" ";
            }
            cout << endl;
        }

    }
    
    

}
