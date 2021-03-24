#include <iostream>
#include <windows.h>
using namespace std;

void PrintChars(char ch, int i) {
	while (i) 
	{
		cout << ch;
		i--;
	}
}
void PrintChars(int ch, int i) { //첫번째 파라메터 입력값이 정수일때 
	while (i)
	{
		cout << ch;
		i--;
	}
}
int main() {
	while (true)
	{
		char print_ch;
		int repeat_ch = 1;
		int repeat_num = 0;
		int temp = 0;
		cout << endl << "문자<char>와 숫자<int> 입력: ";
		cin >> print_ch >> repeat_num;
		temp = repeat_num-1; //repeat_num을 출력으로 쓰기위해 temp 선언 
		if (repeat_num < 1 || 10 < repeat_num || (repeat_num % 2 == 0)) //입력정수 조건검사
		{
			cout << "잘못된 입력값, 프로그램 종료" << endl; break;
		}
		else
		{
			for (int i = 0; i < repeat_num; i++) { // "숫자 문자 숫자" 표현을위해 3번의 PrintChar 호출
				PrintChars(i, temp); 
				PrintChars(print_ch, repeat_ch); 
				PrintChars(i, temp);
				repeat_ch += 2; //다음에 출력될 문자수 +2
				temp--; //다음에 출력될 숫자수 -1 (숫자는 2번 호출되므로)
				cout << endl; 
			}
		}
	}
	return 0;
}

