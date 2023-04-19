#include <iostream>
#include "Lab4Exmaple.h"
#include "ComplexVector.h"
#include "ComplexMatrix.h"
#include "MyAssoc.h"
#include "VectorDouble.h"
#include "DomensIP.h"


int mainExample1() {
	setlocale(LC_CTYPE, "ukr");
	VectorDouble a = VectorDouble(2, new double[2] {3, 4});
	cout << "a: " << a << endl;
	cout << "a%2:";
	cout << endl << a % 2 << endl;
	cout << "-a:" << endl;
	cout << -a << endl;
	cout << "a/=2:";
	a /= 2;
	cout << endl;
	cout << a << endl;
	cout << "a*=4:";
	a *= 4;
	cout << endl << endl;
	cout << a << endl;
	VectorDouble b = VectorDouble(2, new double[2] {2.5, 6});
	cout << "b: " << b;
	cout << "a==b (перевiрка за розмiром i поелементно):" << endl << (a == b) << endl;
	cout << "a<b (перевiрка за розмiром i модулем):" << endl << (a < b) << endl;
	cout << "a>=b (перевiрка за розмiром i модулем): " << endl << (a >= b) << endl;
	cout << "b=a: " << (b = a);
	cout << "a==b (перевiрка за розмiром i поелементно):" << endl << (a == b) << endl;
	return 0;
}

int mainExample2() {
	DomensIP DIP = DomensIP();
	cout << "DPI" << endl;
	DIP.Add("Valto", "192.168.0.0");
	DIP.Add("Shulcek", "192.168.0.1");
	DIP.Show();
	cout << "DPI[\"Valto\"] = " << DIP["Valto"] << endl;
	cout << "DPI(\"Shulcek\") = " << DIP["Shulcek"] << endl;
	cout << "DPI(\"asdasdasd\") = " << DIP("asdasdasd") << endl;
	cout << DIP;
	//виконане 2 завдання
	return 3;
}
int mainExample3() {

	return 4;
}

