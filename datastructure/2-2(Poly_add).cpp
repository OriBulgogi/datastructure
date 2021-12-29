#include <iostream>
using namespace std;
#define No_of_Terms 20

struct poly {
	int coef;
	int expon;
};

int main() {

	//poly terms[No_of_Terms] = { {3,5}, {2,3}, {2,0},{4,4}, {5,3},{2,1} };  //원래 값
	//poly terms[No_of_Terms] = { {4,5}, {1,3}, {2,0},{7,4}, {2,3},{3,1} };  //계수 변경
	poly terms[No_of_Terms] = { {5,3}, {3,3}, {0,2},{4,4}, {3,3},{1,3} }; //모두 변경


	int cnt=0;
	int As = 0, Ae = 2, Bs=3, Be=5, Cs=0, Ce=0,avail=6;
	
	Cs = avail;
	while (As <= Ae && Bs <= Be) {
		if (terms[As].expon > terms[Bs].expon) {
			terms[Cs].coef = terms[As].coef;
			terms[Cs].expon = terms[As].expon;
			As = As+1;
		}
		else if (terms[As].expon == terms[Bs].expon) {
			terms[Cs].coef = terms[As].coef + terms[Bs].coef;
			terms[Cs].expon = terms[As].expon;
			As = As+1;
			Bs = Bs+1;
		}
		else { // <
			terms[Cs].coef = terms[Bs].coef;
			terms[Cs].expon = terms[Bs].expon;
			Bs = Bs+1;
		}
		Cs = Cs+1;
		avail = Cs + 1;
		cnt++;
	}
	for (int i = As; i <= Ae; i++) {
		terms[Cs] = terms[i];
		Cs = Cs + 1;
		avail = Cs + 1;
		cnt++;
	}
	for (int i = Bs; i <= Be; i++) {
		terms[Cs] = terms[i];
		Cs = Cs + 1;
		avail = Cs + 1;
		cnt++;
	}

	Ce = avail - 1;
	cout << "coef : ";
	for (int i = 0; i < Ce; i++) {
		cout << terms[i].coef << " ";
	}
	cout << endl << "expon: ";
	for (int i = 0; i < Ce; i++) {
		cout << terms[i].expon << " ";
	}
	cout << endl << "loop: " << cnt;

	
	return 0;
}
