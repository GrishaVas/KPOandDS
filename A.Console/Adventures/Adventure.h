#pragma once
#include "City.h"

using namespace std;

namespace Adventures
{
	class Adventure
	{
	public:
		vector<City> Cities;
		City* GetCity(string name);
		City* GetCityWithTopRate();
		void Print();
	};
}



