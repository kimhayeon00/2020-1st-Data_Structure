//////////////////////////////////////////////////////
//Lab1: Basic Exercise
//Name: 김하연
//ID: 20191580
//Program Description: Exercising File I/O
//Algorithm: 데이터 파일에서 한 줄씩 읽어옴 > 공백을 기준으로 단어를 세어 저장 > 총 단어 갯수에 더해줌 > 읽어온 것과 단어 갯수 출력
//Variable: buffer[]: 데이터 파일에서 데이터를 저장
//          line: 문장에서 한 줄만 읽어옴
///////////////////////////////////////////////////////
#include <iostream>
#include <fstream>
#include <cstdio>

using namespace std;

void WordCount(string buffer, int *wc) {
    int i = 0;
    const int IN = 1 , OUT = 0; //단어 시작시 IN
    int state = 0;
    *wc = 0;

    while (buffer[i] != '\0') { //한 줄 끝날 때 까지
        if (isalpha(buffer[i])) {
            if (state == OUT) { 
                ++*wc;
                state = IN; //문자이고 state가 IN 이면 아무것도 하지 않음
            }
        } else if (buffer[i] == ' ') {
            state = OUT;
        }
        i++;
    }
}

int main() {

    ifstream infile;

    char buffer[80];
    int wc = 0;
    int total = 0;

    infile.open("Lab1-1.dat", ios::in);

    if (infile.fail()) {
        cout << "can't open the input file" << endl;
        exit(1);
    }

    while (infile.getline(buffer, 80)) {
        cout << buffer << endl;
        WordCount(buffer, &wc);
        cout << wc << endl;
        total = total + wc;
    }
    cout << endl;
    cout << "Total Number of Words :" << total << endl;

    return 0;
}