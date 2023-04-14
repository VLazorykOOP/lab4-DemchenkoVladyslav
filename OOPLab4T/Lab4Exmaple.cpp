#include <iostream>
#include "Lab4Exmaple.h"
#include "ComplexVector.h"
#include "ComplexMatrix.h"
#include "MyAssoc.h"
#include "Vec.h"



int mainExample1() {
	Vec a = Vec(2, new double[2] {3, 4});
	a.Output();
	cout << "a%2:" << endl;
	cout << endl << a % 2 << endl;
	cout << "-a:" << endl;
	cout << endl;
	(-a).Output();
	cout << "a/=2:" << endl;
	a /= 2;
	cout << endl << endl;
	a.Output();
	cout << "a*=4:" << endl;
	a *= 4;
	cout << endl << endl;
	a.Output();
	return 0;
}

int mainExample2() {
	return 3;
}
int mainExample3() {

	return 4;
}

