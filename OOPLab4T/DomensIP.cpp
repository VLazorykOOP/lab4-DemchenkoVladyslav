#include "DomensIP.h"
ostream& operator<<(ostream& os, const DomensIP& v)
{
	for (int i = 0; i < v.size; i++)
	{
		os << v.Domens[i] << " " << v.IPs[i] << endl;
	}
	os << endl << "CodeError: " << v.CodeError << endl;
	return os;
}
istream& operator>>(istream& is, DomensIP& v)
{
	cout << "Enter size of collection: " << endl;
	is >> v.maxSize;
	if (v.Domens)
		delete[]v.Domens;
	if (v.IPs)
		delete[]v.IPs;
	v.maxSize = max(v.maxSize, 1);
	v.Domens = new string[v.maxSize];
	v.IPs = new string[v.maxSize];
	for (int i = 0; i < v.maxSize; i++)
	{
		cout << "Enter the domen and it`s IP: " << endl;
		is >> v.Domens[i] >> v.IPs[i];
	}
	v.size = v.maxSize;
	return is;
}