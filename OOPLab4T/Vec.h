#pragma once
#include <iostream>
using namespace std;
enum STATE {
	OK, BAD_INIT, BAD_DIV
};
class Vec
{
	double* vec;
	int state = OK;
	int size;
	static int count;
public:
	Vec()
	{
		size = 1;
		vec = new double[1] {0};
		count++;
	}   // 	 конструктор без параметрів
	Vec(int c)
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
	Vec(int c, double n)
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
	Vec(int a, double* v);
	~Vec() {
		count--;
		if (vec != NULL)
			delete[]vec;
	}
	Vec(const Vec&);
	Vec Add(Vec& d);
	Vec Sub(Vec& d);
	Vec Mul(double d);
	Vec Div(double d);
	void Input();   //  !!! Без первантаження операцій    
	void Output();  //  !!! Без первантаження операцій
	static int getCount() {
		if (count <= 0) cout << " Немає об'єктів Vec ";
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
	bool Equals(const Vec& s)
	{
		if (size != s.size)return false;
		for (int i = 0; i < size; i++)
		{
			if (vec[i] != s.vec[i])return false;
		}
		return true;
	}
	int Compare(const Vec& s)
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
		Vec temp = Vec(a);
		return &temp;
	}
	Vec operator-();
	Vec& operator=(const Vec&);
	bool operator!();
	Vec& operator++();
	Vec& operator--();
	Vec operator++(int);
	Vec operator--(int);
	double& operator[](int);
	double operator()();
	Vec operator+(Vec);
	Vec operator-(Vec);
	Vec operator*(double);
	Vec operator/(double);
	Vec operator%(int);
	Vec& operator+=(Vec);
	Vec& operator-=(Vec);
	Vec& operator*=(double);
	Vec& operator/=(double);
	Vec& operator%=(int);
};
Vec::Vec(const Vec& s) {
	//if (this == &s) return; //  // the expression is used in the old standard
	state = OK;
	size = s.size;
	vec = new double[size];
	for (int i = 0; i < size; i++)
	{
		vec[i] = s.vec[i];
	}
	count++;
};
Vec::Vec(int a, double* b) {
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
		Vec();
	}
};
void Vec::Output() {
	for (int i = 0; i < size; i++)
	{
		cout << vec[i] << " ";
	}
	cout << endl << "State: " << state << endl;
}

Vec Vec::Add(Vec& s) {
	if (s.size == size)
	{
		Vec tmp = Vec(size);
		for (int i = 0; i < size; i++)
		{
			tmp.vec[i] = vec[i] + s.vec[i];
		}
		return tmp;
	}
	return *this;
}

Vec Vec::Sub(Vec& s) {
	if (s.size == size)
	{
		Vec tmp = Vec(size);
		for (int i = 0; i < size; i++)
		{
			tmp.vec[i] = vec[i] - s.vec[i];
		}
		return tmp;
	}
	return  *this;
}
Vec Vec::Div(double d) {
	if (d == 0) {
		this->state = BAD_DIV;
		cout << " Error div \n";
		return *this;
	}
	Vec temp = *this;
	for (int i = 0; i < size; i++)
	{
		temp.vec[i] /= d;
	}
	return temp;
}
Vec Vec::Mul(double d) {
	Vec temp = *this;
	for (int i = 0; i < size; i++)
	{
		temp.vec[i] *= d;
	}
	return temp;
}
Vec& Vec::operator=(const Vec& s) {
	if (size != s.size)
	{
		if (vec) delete[] vec;
		size = s.size;
		vec = new double[size];
		state = 0;
	}
	for (int i = 0; i < size; i++)
		vec[i] = s.vec[i];
	return *this;
}
void Vec::Input()
{
	cout << "Input " << size << " elements of vector" << endl;
	for (int i = 0; i < size; i++)
	{
		cin >> vec[i];
	}
}
bool Vec::operator!() {

	return size != 0;
}
Vec Vec::operator%(int n)
{
	Vec temp = *this;
	for (int i = 0; i < size; i++)
	{
		temp[i] = (int)temp[i] % n;
	}
	return temp;
}
Vec& Vec::operator++() {
	for (int i = 0; i < size; i++)
	{
		vec[i]++;
	}
	return *this;
}
Vec& Vec::operator--() {
	for (int i = 0; i < size; i++)
	{
		vec[i]--;
	}
	return *this;
}
Vec Vec::operator++(int) {
	Vec temp = *this;
	++* this;
	return temp;
}
Vec Vec::operator--(int) {
	Vec temp = *this;
	--* this;
	return temp;
}
Vec Vec::operator-()
{
	Vec temp = *this;
	for (int i = 0; i < size; i++)
	{
		temp[i] = -temp[i];
	}
	return temp;
}
bool operator==(Vec& s1, Vec& s2) {

	return s1.Equals(s2);
}
bool operator>(Vec& s1, Vec& s2) {

	return s1.Compare(s2) == 1;
}
bool operator<(Vec& s1, Vec& s2) {

	return s1.Compare(s2) == -1;
}
bool operator>=(Vec& s1, Vec& s2) {

	return s1.Compare(s2) > -1;
}
bool operator<=(Vec& s1, Vec& s2) {

	return s1.Compare(s2) < 1;
}
double& Vec::operator[](int i) {

	if (i >= 0 && i < size)
		return vec[i];
	state = BAD_INIT;
	return vec[max(size - 1, 0)];
}
double Vec::operator()() {
	double abs = 0;
	for (int i = 0; i < size; i++)
	{
		abs += (vec[i] * vec[i]);
	}
	return sqrt(abs);
}
Vec Vec::operator+(Vec a)
{
	return Add(a);
}
Vec Vec::operator-(Vec a)
{
	return Sub(a);
}
Vec Vec::operator*(double a)
{
	return Mul(a);
}
Vec Vec::operator/(double  a)
{
	return Div(a);
}
Vec& Vec::operator+=(Vec a)
{
	return *this = Add(a);
}
Vec& Vec::operator-=(Vec a)
{
	return *this = Sub(a);
}
Vec& Vec::operator*=(double a)
{
	return *this = Mul(a);
}
Vec& Vec::operator/=(double  a)
{
	Vec temp = Div(a);
	return this->operator=(Div(a));
}
Vec& Vec::operator%=(int n)
{
	Vec temp = *this % n;
	return this->operator=(temp);
}
int Vec::count = 0;