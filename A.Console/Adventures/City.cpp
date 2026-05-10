#include "City.h"
#include <iostream>
#include <iomanip>

using namespace Adventures;

vector<Sight> City::GetSortedSights()
{
	vector<Sight> sortedSights;

	for (size_t i = 0; i < this->Sights.size(); i++)
	{
		Sight sight = this->Sights[i];

		int index = 0;

		while (sortedSights.size() != 0 && index < sortedSights.size() && sortedSights[index].Rate <= sight.Rate)
		{
			index++;
		}

		if (index == sortedSights.size())
		{
			sortedSights.insert(sortedSights.end(), sight);
		}
		else
		{
			sortedSights.insert(sortedSights.begin() + index, sight);
		}		
	}

	return sortedSights;
}

int City::GetCityRate()
{
	int rate = 0;

	for (size_t i = 0; i < this->Sights.size(); i++)
	{
		rate += this->Sights[i].Rate;
	}

    return rate;
}

void City::Print(int tabs)
{
	for (size_t i = 0; i < tabs; i++)
	{
		cout << " ";
	}
	cout << "City\n";
	for (size_t i = 0; i < tabs; i++)
	{
		cout << " ";
	}
	cout << " Name: " << this->Name << "\n";

	for (size_t i = 0; i < this->Sights.size(); i++)
	{
		this->Sights[i].Print(tabs + 1);
	}
}
