#include <regex>
#include "Serializer.h"

using namespace Adventures;

string Serializer::Serialize(vector<Adventure> adventures)
{
	string outputString = "[";

	for (size_t i = 0; i < adventures.size(); i++)
	{
		outputString += Serialize(adventures[i]);

		if (i != adventures.size() - 1)
		{
			outputString += ", ";
		}
	}

	return outputString + "]";
}

string Serializer::Serialize(vector<City> city)
{
	string outputString = "[";

	for (size_t i = 0; i < city.size(); i++)
	{
		outputString += Serialize(city[i]);

		if (i != city.size() - 1)
		{
			outputString += ", ";
		}
	}

	return outputString + "]";
}

string Serializer::Serialize(vector<Sight> sights)
{
	string outputString = "[";

	for (size_t i = 0; i < sights.size(); i++)
	{
		outputString += Serialize(sights[i]);

		if (i != sights.size() - 1)
		{
			outputString += ", ";
		}
	}

	return outputString + "]";
}

string Serializer::Serialize(Adventure adventure)
{
	return "{" + Serialize(adventure.Cities) + "}";
}

string Serializer::Serialize(City city)
{
	return "{" + city.Name + ", " + Serialize(city.Sights) + "}";
}

string Serializer::Serialize(Sight sight)
{
	return "{" + sight.Name + ", " + to_string(sight.Rate) + "}";
}

vector<Adventure> Serializer::DeserializeAdventures(string adventuresString)
{
	vector<Adventure> adventures;
	string patern = R"(\{\[\{[\w\.]+, \[(\{[\w\.]+, [0-9]+\}(, )?)*\]\}(, )?\]\})";
	regex rExp(patern);
	string::const_iterator searchStart = adventuresString.cbegin();

	smatch match;

	while (regex_search(searchStart, adventuresString.cend(), match, rExp))
	{
		Adventure adventure = DeserializeAdventure(match.str());

		adventures.push_back(adventure);
		searchStart = match[0].second;
	}

	return adventures;
}

Adventure Serializer::DeserializeAdventure(string adventureString)
{
	Adventure adventure;

	adventure.Cities = DeserializeCities(adventureString.substr(1, adventureString.length() - 2));

	return adventure;
}

vector<City> Serializer::DeserializeCities(string citiesString)
{
	vector<City> cities;
	string patern = R"(\{[\w\.]+, \[(\{[\w\.]+, [0-9]+\}(, )?)*\]\})";
	regex rExp(patern);
	string::const_iterator searchStart = citiesString.cbegin();

	smatch match;

	while (regex_search(searchStart, citiesString.cend(), match, rExp))
	{
		City city = DeserializeCity(match.str());

		cities.push_back(city);
		searchStart = match[0].second;
	}

	return cities;
}

City Serializer::DeserializeCity(string cityString)
{
	City city;
	int delimiterIndex = cityString.find(",");
	city.Name = cityString.substr(1, delimiterIndex - 1);
	int endIndex = cityString.length() - (delimiterIndex + 2);
	city.Sights = DeserializeSights(cityString.substr(delimiterIndex + 1, endIndex));

	return city;
}

vector<Sight> Serializer::DeserializeSights(string sightsString)
{
	vector<Sight> sights;
	string patern = R"(\{[\w\.]+, [0-9]+\})";
	regex rExp(patern);
	string::const_iterator searchStart = sightsString.cbegin();

	smatch match;

	while (regex_search(searchStart, sightsString.cend(), match, rExp))
	{
		Sight sight = DeserializeSight(match.str());

		sights.push_back(sight);
		searchStart = match[0].second;
	}

	//vector<Sight> sights;

	//sightsString = sightsString.substr(sightsString.find('[') + 2, sightsString.length() - 2);
	//
	//vector<string> sightStrings = SplitString(sightsString, "}, {");

	//for (size_t i = 0; i < sightStrings.size(); i++)
	//{
	//	Sight sight = DeserializeSight(sightStrings[i]);

	//	sights.push_back(sight);
	//}

	return sights;
}

Sight Serializer::DeserializeSight(string sightString)
{
	Sight sight;

	sightString = sightString.substr(sightString.find('{') + 1, sightString.find('}'));

	vector<string> strings = SplitString(sightString, ", ");

	sight.Name = strings[0];

	string rate = strings[1];

	sight.Rate = stoi(strings[1]);

	return sight;
}

vector<string> Serializer::SplitString(string value, string delimiter)
{
	vector<string> strings;
	int index = 0;

	for (size_t i = 0; i < value.length() - delimiter.length(); i++)
	{
		if (value.substr(i, delimiter.length()) == delimiter)
		{
			strings.push_back(value.substr(index, i - index));
			index = i + delimiter.length();
		}
	}

	strings.push_back(value.substr(index, value.length() - index));

	return strings;
}
