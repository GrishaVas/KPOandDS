#include <iomanip>
#include <iostream>
#include "Sight.h"

using namespace Adventures;

void Sight::Print(int tabs)
{
	for (size_t i = 0; i < tabs; i++)
	{
		cout << " ";
	}
	cout << "Sight\n";
	for (size_t i = 0; i < tabs; i++)
	{
		cout << " ";
	}
	cout << " Name: " << this->Name << "\n";
	for (size_t i = 0; i < tabs; i++)
	{
		cout << " ";
	}
	cout << " Rate: " << this->Rate << "\n";
}
