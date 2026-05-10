#include "Adventure.h"
#include <iostream>

using namespace Adventures;

City* Adventure::GetCity(string name)
{
	for (size_t i = 0; i < this->Cities.size(); i++)
	{
		if (this->Cities[i].Name == name)
		{
			return &this->Cities[i];
		}
	}
    return nullptr;
}

City* Adventure::GetCityWithTopRate()
{
	int maxRate = 0;
	City* city = nullptr;

	for (size_t i = 0; i < this->Cities.size(); i++)
	{
		int cityRate = this->Cities[i].GetCityRate();

		if (cityRate > maxRate)
		{
			maxRate = cityRate;
			city = &this->Cities[i];
		}
	}

	return city;
}

void Adventure::Print()
{
	cout << "Adventure\n";

	for (size_t i = 0; i < this->Cities.size(); i++)
	{
		this->Cities[i].Print(1);
	}
}
