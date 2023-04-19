#pragma once
#include<iostream>
using namespace std;
class DomensIP
{
	string* Domens;
	string* IPs;
	int size = 0;
	int maxSize;
	string CodeError = "None";
public:
	DomensIP()
	{
		Domens = new string[1];
		IPs = new string[1];
		maxSize = 1;
	}
	DomensIP(int s, string* D, string* I)
	{
		Domens = new string[s];
		IPs = new string[s];
		maxSize = s;
		size = s;
		for (int i = 0; i < s; i++)
		{
			Domens[i] = D[i];
			IPs[i] = I[i];
		}
	}
	~DomensIP()
	{
		if (Domens != NULL)
			delete[]Domens;
		if (IPs != NULL)
			delete[]IPs;
		size = 0;
	}
	void Add(string key, string value)
	{
		for (int i = 0; i < size; i++)
		{
			if (Domens[i] == key)
				return;
		}
		if (size == maxSize)
		{
			maxSize *= 2;
			string* D = new string[maxSize];
			string* I = new string[maxSize];
			for (int i = 0; i < size; i++)
			{
				D[i] = Domens[i];
				I[i] = IPs[i];
			}
			Domens = D;
			IPs = I;
		}
		Domens[size] = key;
		IPs[size] = value;
		size++;
	}
	void Pop(string key)
	{
		for (int i = 0; i < size; i++)
		{
			if (Domens[i] == key)
			{
				for (; i < size - 1; i++)
				{
					Domens[i] = Domens[i + 1];
					IPs[i] = IPs[i + 1];
				}
				Domens[size - 1] = "";
				IPs[size - 1] = "";
				size--;
			}
		}
	}
	void Pop()
	{
		if (size > 0)
		{
			Domens[size - 1] = "";
			IPs[size - 1] = "";
			size--;
		}
	}
	void Show()
	{
		for (int i = 0; i < size; i++)
		{
			cout << Domens[i] << " " << IPs[i] << endl;
		}
	}
	string& operator[](string index) {
		for (int i = 0; i < size; i++)
		{
			if (Domens[i] == index)
			{
				return IPs[i];
			}
		}
		CodeError = "Wrong index";
	}
	string& operator()(string index) {
		return (*this)[index];
	}
};