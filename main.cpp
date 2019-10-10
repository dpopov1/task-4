#include <iostream>
#include "Header.h"

int main()
{
	const std::string a = "{{{}{(())}}}";
	std::cout << BraceChecker::isBalanced(a)<<std::endl;
	system("pause");
}