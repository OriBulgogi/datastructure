#include <iostream>
using namespace std;
/*
typedef short int SINT; //긴 자료형을 간략히
const double const_PI = 3.14; //변수를 읽기전용으로 만듦, 변수를 상수화할 때 사용   const / define 차이 중요
#define define_PI 3.14;// 이건 코드내 PI를 찾아 3로바꾸는 "찾아바꾸기"  

int main()
{
	
	cout << "hello world" << endl;
	int num =3; //3, num= 문자열과 같은거: 값의 내용을 바로 파악할수있는것 : 리터럴 상수
				//endl: 이름을 갖는것 심볼릭 상수, 네임드
	cout << "num= " << num << endl;

	short int num1 = 3;
	SINT num2 = 4;
	
	double radius = 3;

	//cin, cout 
	int int_var;
	double double_var;
	char ch;
	cout << "문자값 입력:";
	cin >> int_var >> double_var >> ch;
	
	cout << "int_var: " << int_var << endl;
	cout << "int_double: " << double_var << endl;
	cout << "ch: " << ch << endl;

	num1 = 3, num2 = 3;
	int num3 = ++(++num1); // (num1++)++; : error
	int num4 = (++num2)++; // 선증감 대입후 후증감
	
	// (~~~)? A:B ~~~가 맞으면 A실행 false면 B
	// 둘다 int일때  num1 / num2 하나의 변수만 double로 형변환 해주면 정상작동
	// 가장 큰값과 가장 작은값은 띠처럼 연결되어있음
	char num1 = 127, num2 = -128;
	num1 + 1; //overflow = (-128)
	num2 - 1; //underflow = (+127)
	
	*/

	//-----03월 18일 배열, 포인터 강의------
	/*
	int i_num=3;
	int* i_ptr;
	double d_num = 1.1;
	double* d_ptr;
	
	i_ptr = &i_num;
	d_ptr = &d_num;
	
	cout << "i_num의 주소 :" << (int)&i_num <<endl;
	cout << "i_ptr의 깂 :" << (int)&i_num << endl;
	cout << "i_num의 주소 :" << (int)&i_num << endl;
	cout << "i_num의 주소 :" << (int)&i_num << endl;

	
	cout << *i_ptr;
	
	


	return 0;
}
*/

void Swap(int* x, int* y) { //주소에의한 전달
	int temp = *x;
	*x = *y;
	*y = temp;
}

void Swap(int &x, int &y) { //참조에의한 전달(어떤 변수의 "이름만" 추가해주는것이다. 메모리할당 따로 xxx
	int temp = x;
	x = y;
	y = temp;
}

int main() {
	int num1 = 3, num2 = 4;
	Swap(&num1, &num2);
	Swap(num1, num2);
	
	return 0;
}
