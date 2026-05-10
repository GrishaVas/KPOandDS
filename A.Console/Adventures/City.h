#pragma once
#include "Sight.h"
#include <vector>

using namespace std;

namespace Adventures
{
	class City
	{
	public:
		string Name;
		vector<Sight> Sights;
		vector<Sight> GetSortedSights();
		int GetCityRate();
		void Print(int tabs);
	};
}
