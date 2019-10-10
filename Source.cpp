#include <stack>
#include <fstream>
#include <iostream>
#include <algorithm>
#include "Header.h"

using std::string;
using std::stack;

bool sogl(const char a, const char b)
{
	if ((a == '{' || a == '[')&&b==a+2)
		return 1;
	if (a == '(' && b == ')')
		return 1;
	return 0;
}

stack<char> get_stack(const string a)
{
	stack <char> b;
	for (int i = a.size()-1; i!=-1; i--)
		b.push(a[i]);
	return b;
}

bool first_sogl_skobki(stack <char> &a)
{
	auto b = a;
	int p = a.size();
	bool o = false;
	for (int i = 0; i < p; i++)
	{
		char u = b.top();
		b.pop();
		if(b.size()!=0)
		if (sogl(u, b.top()))
		{
			o = true;
			b.pop();
			string r;
			for (int k = 0; k < i; k++)
			{
				r.push_back(a.top());
				a.pop();
			}
			for (int k = 0; k < i; k++)
				b.push(r[i-k-1]);
			a = b;
			break;
		}
	}
	return o;
}

bool BraceChecker::isBalanced(const string h)
{
	auto a = get_stack(h);
	while (first_sogl_skobki(a));
	if (a.size() == 0)
		return 1;
	return 0;
}