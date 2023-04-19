#pragma once
#include <iostream>
using namespace std;
enum STATE {
	OK, BAD_INIT, BAD_DIV
};
class VectorDouble
{
	double* vec;
	int state = OK;
	int size;
	static int count;
public:
	VectorDouble()
	{
		size = 1;
		vec = new double[1] {0};
		count++;
	}   // 	 конструктор без параметрів
	VectorDouble(int c)
	{
		if (c > 0)
		{
			state = OK;
			size = c;
			vec = new double [c] {0};
			count++;
		}
		else state = BAD_INIT;
		size = 0;
	}
	VectorDouble(int c, double n)
	{
		state = OK;
		size = c;
		vec = new double[c];
		for (int i = 0; i < size; i++)
		{
			vec[i] = n;
		}
		count++;
	}
	VectorDouble(int a, double* v);
	~VectorDouble() {
		count--;
		if (vec != NULL)
			delete[]vec;
	}
	VectorDouble(const VectorDouble&);
	static int getCount() {
		if (count <= 0) cout << " Немає об'єктів VectorDouble ";
		return count;
	}
	int getState() { return state; }
	int GetAt(int i)
	{
		if (i > -1 && i < size)
			return vec[i];
		else
		{
			state = BAD_INIT;
			return vec[0];
		}
	}
	void SetAt(int i, double value)
	{
		if (i > -1 && i < size)
			vec[i] = value;
		else
		{
			state = BAD_INIT;
		}
	}
	bool Equals(const VectorDouble& s)
	{
		if (size != s.size)return false;
		for (int i = 0; i < size; i++)
		{
			if (vec[i] != s.vec[i])return false;
		}
		return true;
	}
	int Compare(const VectorDouble& s)
	{
		if (size != s.size)
		{
			if (size > s.size)return 1;
			return -1;
		}
		double abs1 = 0, abs2 = 0;
		for (int i = 0; i < size; i++)
		{
			abs1 += (vec[i] * vec[i]);
			abs2 += (s.vec[i] * s.vec[i]);
		}
		if (abs1 == abs2)return 0;
		if (abs1 > abs2)return 1;
		if (abs1 < abs2)return -1;
	}
	static void operator delete(void* p) {
		cout << endl << "Operator delete worked" << endl;
		delete p;
	}
	static void* operator new(size_t a)
	{
		cout << endl << "Operator new worked" << endl;
		VectorDouble temp = VectorDouble(a);
		return &temp;
	}
	VectorDouble operator-();
	VectorDouble& operator=(const VectorDouble&);
	bool operator!();
	VectorDouble& operator++();
	VectorDouble& operator--();
	VectorDouble operator++(int);
	VectorDouble operator--(int);
	double& operator[](int);
	double operator()();
	VectorDouble operator+(VectorDouble);
	VectorDouble operator-(VectorDouble);
	VectorDouble operator*(double);
	VectorDouble operator/(double);
	VectorDouble operator%(int);
	VectorDouble& operator+=(VectorDouble);
	VectorDouble& operator-=(VectorDouble);
	VectorDouble& operator*=(double);
	VectorDouble& operator/=(double);
	VectorDouble& operator%=(int);
	friend ostream& operator<<(ostream&, const VectorDouble&);
	friend istream& operator>>(istream&, VectorDouble&);
	VectorDouble Add(VectorDouble& d);
	VectorDouble Sub(VectorDouble& d);
	VectorDouble Mul(double d);
	VectorDouble Div(double d);
	void Input();
	void Output() const;

};
VectorDouble::VectorDouble(const VectorDouble& s) {
	state = OK;
	size = s.size;
	vec = new double[size];
	for (int i = 0; i < size; i++)
	{
		vec[i] = s.vec[i];
	}
	count++;
};
VectorDouble::VectorDouble(int a, double* b) {
	if (a > 0)
	{
		state = OK;
		size = a;
		vec = new double[a];
		for (int i = 0; i < size; i++)
		{
			vec[i] = b[i];
		}
		count++;
	}
	else
	{
		state = BAD_INIT;
		VectorDouble();
	}
};
VectorDouble VectorDouble::Add(VectorDouble& s) {
	if (s.size == size)
	{
		VectorDouble tmp = VectorDouble(size);
		for (int i = 0; i < size; i++)
		{
			tmp.vec[i] = vec[i] + s.vec[i];
		}
		return tmp;
	}
	return *this;
}

VectorDouble VectorDouble::Sub(VectorDouble& s) {
	if (s.size == size)
	{
		VectorDouble tmp = VectorDouble(size);
		for (int i = 0; i < size; i++)
		{
			tmp.vec[i] = vec[i] - s.vec[i];
		}
		return tmp;
	}
	return  *this;
}
VectorDouble VectorDouble::Div(double d) {
	if (d == 0) {
		this->state = BAD_DIV;
		cout << " Error div \n";
		return *this;
	}
	VectorDouble temp = *this;
	for (int i = 0; i < size; i++)
	{
		temp.vec[i] /= d;
	}
	return temp;
}
VectorDouble VectorDouble::Mul(double d) {
	VectorDouble temp = *this;
	for (int i = 0; i < size; i++)
	{
		temp.vec[i] *= d;
	}
	return temp;
}
VectorDouble& VectorDouble::operator=(const VectorDouble& s) {
	if (size != s.size)
	{
		if (vec) delete[] vec;
		size = s.size;
		vec = new double[size];
	}
	for (int i = 0; i < size; i++)
		vec[i] = s.vec[i];
	state = s.state;
	return *this;
}
void VectorDouble::Input()
{
	cout << "Input " << size << " elements of vector" << endl;
	for (int i = 0; i < size; i++)
	{
		cin >> vec[i];
	}
}
void VectorDouble::Output() const {
	for (int i = 0; i < size; i++)
	{
		cout << vec[i] << " ";
	}
	cout << endl << "State: " << state << endl;
}

bool VectorDouble::operator!() {

	return size != 0;
}
VectorDouble VectorDouble::operator%(int n)
{
	if (n == 0)
	{
		this->state = BAD_DIV;
		cout << " Error div \n";
		return *this;
	}
	VectorDouble temp = *this;
	for (int i = 0; i < size; i++)
	{
		temp[i] = (int)temp[i] % n;
	}
	return temp;
}
VectorDouble& VectorDouble::operator++() {
	for (int i = 0; i < size; i++)
	{
		vec[i]++;
	}
	return *this;
}
VectorDouble& VectorDouble::operator--() {
	for (int i = 0; i < size; i++)
	{
		vec[i]--;
	}
	return *this;
}
VectorDouble VectorDouble::operator++(int) {
	VectorDouble temp = *this;
	++* this;
	return temp;
}
VectorDouble VectorDouble::operator--(int) {
	VectorDouble temp = *this;
	--* this;
	return temp;
}
VectorDouble VectorDouble::operator-()
{
	VectorDouble temp = *this;
	for (int i = 0; i < size; i++)
	{
		temp[i] = -temp[i];
	}
	return temp;
}
bool operator==(VectorDouble& s1, VectorDouble& s2) {

	return s1.Equals(s2);
}
bool operator>(VectorDouble& s1, VectorDouble& s2) {

	return s1.Compare(s2) == 1;
}
bool operator<(VectorDouble& s1, VectorDouble& s2) {

	return s1.Compare(s2) == -1;
}
bool operator>=(VectorDouble& s1, VectorDouble& s2) {

	return s1.Compare(s2) > -1;
}
bool operator<=(VectorDouble& s1, VectorDouble& s2) {

	return s1.Compare(s2) < 1;
}
double& VectorDouble::operator[](int i) {

	if (i >= 0 && i < size)
		return vec[i];
	state = BAD_INIT;
	return vec[max(size - 1, 0)];
}
double VectorDouble::operator()() {
	double abs = 0;
	for (int i = 0; i < size; i++)
	{
		abs += (vec[i] * vec[i]);
	}
	return sqrt(abs);
}
VectorDouble VectorDouble::operator+(VectorDouble a)
{
	return Add(a);
}
VectorDouble VectorDouble::operator-(VectorDouble a)
{
	return Sub(a);
}
VectorDouble VectorDouble::operator*(double a)
{
	return Mul(a);
}
VectorDouble VectorDouble::operator/(double  a)
{
	return Div(a);
}
VectorDouble& VectorDouble::operator+=(VectorDouble a)
{
	return *this = Add(a);
}
VectorDouble& VectorDouble::operator-=(VectorDouble a)
{
	return *this = Sub(a);
}
VectorDouble& VectorDouble::operator*=(double a)
{
	return *this = Mul(a);
}
VectorDouble& VectorDouble::operator/=(double  a)
{
	Div(a);
	return *this = (Div(a));
}
VectorDouble& VectorDouble::operator%=(int n)
{
	return *this = (*this % n);
}
ostream& operator<<(ostream& os, const VectorDouble& v)
{
	for (int i = 0; i < v.size; i++)
	{
		os << v.vec[i] << " ";
	}
	os << endl << "State: " << v.state << endl;
	return os;
}
istream& operator>>(istream& is, VectorDouble& v)
{
	cout << "Enter size of vector" << endl;
	is >> v.size;
	if (v.vec)
		delete[] v.vec;
	if (v.size <= 0)
		v.state = BAD_INIT;
	v.size = max(v.size, 1);
	v.vec = new double(v.size);
	cout << "Enter " << v.size << " elements of vector" << endl;
	for (int i = 0; i < v.size; i++)
	{
		is >> v.vec[i];
	}
	return is;
}
int VectorDouble::count = 0;