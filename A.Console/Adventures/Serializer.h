#pragma once
#include "Adventure.h"

using namespace std;

namespace Adventures
{
	class Serializer
	{
	public: 
		static string Serialize(vector<Adventure> adventures);
		static string Serialize(vector<City> cities);
		static string Serialize(vector<Sight> sights);
		static string Serialize(Adventure adventures);
		static vector<Adventure> DeserializeAdventures(string adventuresString);
		static Adventure DeserializeAdventure(string adventureString);
		static vector<City> DeserializeCities(string citiesString);
		static vector<Sight> DeserializeSights(string sightsString);
	private:
		static string Serialize(City cities);
		static string Serialize(Sight sights);
		static City DeserializeCity(string cityString);
		static Sight DeserializeSight(string sightStirng);
		static vector<string> SplitString(string value, string delimiter);
	};
}


