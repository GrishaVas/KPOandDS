// A.Console.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <fstream>
#include "Adventures/Serializer.h"

using namespace Adventures;

void AdventureProgram();
void SaveAdventuresToFile(vector<Adventure> adventures);
vector<Adventure> LoadAdventuresFromFile();
void AddAventure(vector<Adventure> &adventures);
void GetTopRatedCity(vector<Adventure> adventures);
void GetCitySights(vector<Adventure> adventures);

void StringConcatenationProgram();
char* strcat1(const char* destptr, const char* srcpt);

void MatricesProgram();

int GetTrib(int n);
void TribonacciProgram();
int GetTribIteration(int n);

int main()
{
    int programNumber = 0;

    while (true)
    {
        cout << "\n";
        cout << "Program: \n" <<
            "   1. String concatenation.\n" <<
            "   2. Adventures.\n" <<
            "   3. Matrix.\n" <<
            "   4. Tribonacci.\n" <<
            "   5. Exit.\n";
        cout << "Execute program: ";
        
        cin >> programNumber;

        system("cls");

        switch (programNumber)
        {
        case 1:
            StringConcatenationProgram();
            break;
        case 2:
            AdventureProgram();
            break;
        case 3:
            MatricesProgram();
            break;
        case 4:
            TribonacciProgram();
            break;
        case 5:
            return 0;
        default:
            cout << "Wrong program number.\n";
            break;
        }
    }
}

void TribonacciProgram()
{
    int n = 0;
    cout << "N: ";
    cin >> n;
    cout << "\n";

    cout << GetTrib(n);
}

int GetTrib(int n)
{
    if (n == 0 || n == 1)
        return 0;

    if (n == 2)
        return 1;
    else
        return GetTrib(n - 1) +
        GetTrib(n - 2) +
        GetTrib(n - 3);
}

int GetTribIteration(int n) {
    if (n == 0 || n == 1)
        return 0;
    if (n == 2)
        return 1;

    int a = 0;
    int b = 0;
    int c = 1;
    int result = 0;

    for (int i = 3; i <= n; ++i) {
        result = a + b + c;
        a = b;
        b = c;
        c = result;
    }
    return result;
}


void MatricesProgram()
{
    int matrixLength = 0;

    cout << "Matrix lenth: ";
    cin >> matrixLength;
    cout << "\n";

    bool isRandom;
    cout << "Random matrix(1:yes, 0: no): ";
    cin >> isRandom;
    cout << "\n";

    int** matrix = new int*[matrixLength];

    for (int i = 0; i < matrixLength; i++) {
        matrix[i] = new int[matrixLength];
    }

    if (isRandom)
    {
        int from, to;
        cout << "From: ";
        cin >> from;
        cout << "\n";
        cout << "To: ";
        cin >> to;

        std::srand(std::time(0));

        for (int i = 0; i < matrixLength; i++) {
            for (int j = 0; j < matrixLength; j++) {
                matrix[i][j] = from + rand() % (to - from + 1);
            }
        }
    }
    else {
        for (int i = 0; i < matrixLength; i++) {
            for (int j = 0; j < matrixLength; j++) {
                cin >> matrix[i][j];
            }
            cout << "\n";
        }
    }

    cout << "\n";
    for (int i = 0; i < matrixLength; i++) {
        for (int j = 0; j < matrixLength; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << "\n";
    }

    for (int i = 0; i < matrixLength; i++) {
        for (int j = i + 1; j < matrixLength; j++) {
            std::swap(matrix[i][j], matrix[j][i]);
        }
    }

    for (int j = 0; j < matrixLength; j++) {
        int top = 0;
        int bottom = matrixLength - 1;

        while (top < bottom) {
            std::swap(matrix[top][j], matrix[bottom][j]);
            top++;
            bottom--;
        }
    }

    cout << "\n";
    for (int i = 0; i < matrixLength; i++) {
        for (int j = 0; j < matrixLength; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << "\n";
    }
}

void StringConcatenationProgram()
{
    string string1;
    string string2;
    cin.ignore();
    cout << "String 1: ";
    getline(cin, string1);
    //cin >> string1;
    cout << "\n";
    cout << "String 2: ";
    getline(cin, string2);
    //cin >> string2;
    cout << "\n";
    char* result = strcat1(string1.data(), string2.data());
    cout << result << "\n";
}

char* strcat1(const char* destptr, const char* srcpt)
{
    const char* destenationStr = destptr;
    const char* sourceStr = srcpt;
    int destLenght = 0;
    int sourceLenght = 0;

    while (*destenationStr != '\0')
    {
        destenationStr++;
        destLenght++;
    }

    while (*sourceStr != '\0')
    {
        sourceStr++;
        sourceLenght++;
    }

    char* resultStr = (char*)malloc(sizeof(char) * (destLenght + sourceLenght + 1));
    char* resultStrStart = resultStr;

    for (size_t i = 0; i < destLenght; i++)
    {
        *resultStr = *destptr;
        resultStr++;
        destptr++;
    }

    for (size_t i = 0; i < sourceLenght; i++)
    {
        *resultStr = *srcpt;
        resultStr++;
        srcpt++;
    }

    *resultStr = '\0';

    return resultStrStart;
}


void AdventureProgram()
{
    vector<Adventure> adventures;
    int programNumber = 0;

    while (true)
    {
        cout << "\n";
        cout << "Actions: \n" <<
            "   1. Add Adventure.\n" <<
            "   2. Save Adventures.\n" <<
            "   3. Load Adventures.\n" <<
            "   4. Get city sights.\n" <<
            "   5. Get top rated city.\n" <<
            "   6. Clear.\n" <<
            "   7. Print.\n" <<
            "   8. Exit.\n";
        cout << "Execute program: ";

        cin >> programNumber;

        system("cls");

        switch (programNumber)
        {
        case 1:
            AddAventure(adventures);
            break;
        case 2:
            SaveAdventuresToFile(adventures);
            cout << "Saved" << "\n";
            break;
        case 3:
            adventures = LoadAdventuresFromFile();
            cout << "Loaded" << "\n";
            break;
        case 4:
            GetCitySights(adventures);
            break;
        case 5:
            GetTopRatedCity(adventures);
            break;
        case 6:
            adventures.clear();
            break;
        case 7:
            for (size_t i = 0; i < adventures.size(); i++)
            {
                adventures[i].Print();

            }
            break;
        case 8:
            return;
        default:
            cout << "Wrong program number.\n";
            break;
        }
    }

    return;
}

void SaveAdventuresToFile(vector<Adventure> adventures)
{
    ofstream adventuresFile("adventures.txt");

    for (size_t i = 0; i < adventures.size(); i++)
    {
        adventuresFile << Serializer::Serialize(adventures[i]) << "\n";
    }

    adventuresFile.clear();
}

vector<Adventure> LoadAdventuresFromFile()
{
    ifstream adventuresFile("adventures.txt");
    string line;
    vector<Adventure> adventures;

    while (getline(adventuresFile, line)) {

        adventures.push_back(Serializer::DeserializeAdventure(line));
    }

    adventuresFile.clear();

    return adventures;
}

void GetCitySights(vector<Adventure> adventures)
{
    string cityName = "";

    cout << "City Name: ";
    cin >> cityName;
    cout << "\n";

    for (size_t i = 0; i < adventures.size(); i++)
    {
        for (size_t j = 0; j < adventures[i].Cities.size(); j++)
        {
            if (adventures[i].Cities[j].Name == cityName)
            {
                vector<Sight> sights = adventures[i].Cities[j].GetSortedSights();

                for (size_t k = 0; k < sights.size(); k++)
                {
                    sights[k].Print(0);
                }

                return;
            }
        }
    }

    cout << "City not found\n";
}

void GetTopRatedCity(vector<Adventure> adventures)
{
    int topRate = 0;
    City* topRatedCity = nullptr;

    for (size_t i = 0; i < adventures.size(); i++)
    {
        for (size_t j = 0; j < adventures[i].Cities.size(); j++)
        {
            int cityRate = adventures[i].Cities[j].GetCityRate();

            if (topRate < cityRate)
            {
                topRate = cityRate;
                topRatedCity = &adventures[i].Cities[j];
            }
        }
    }

    if (topRatedCity == nullptr)
    {
        cout << "City not foud\n";
    }

    cout << "Rate: " << topRate;
    cout << "\n";
    topRatedCity->Print(0);
}

void AddAventure(vector<Adventure> &adventures)
{
    Adventure adventure;
    int cityCount = 0;
    cout << "City counts: ";
    //cin >> cityCount;
    if (!(cin >> cityCount))
    {
        cout << "Invalid input.";
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return;
    }
    cout << "\n";

    for (size_t i = 0; i < cityCount; i++)
    {
        City city;
        int sightsCount = 0;

        cout << "City Name: ";
        
        cin >> city.Name;
        cout << "\n";

        cout << "Sights counts: ";
        if (!(cin >> sightsCount))
        {
            cout << "Invalid input.";
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return;
        }

        cout << "\n";

        for (size_t j = 0; j < sightsCount; j++)
        {
            Sight sight;

            cout << "Sight Name: ";
            cin >> sight.Name;
            cout << "\n";

            cout << "Sight Rate: ";
            //cin >> sight.Rate;
            if (!(cin >> sight.Rate))
            {
                cout << "Invalid input.";
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                return;
            }
            cout << "\n";

            city.Sights.push_back(sight);
        }

        adventure.Cities.push_back(city);
    }

    adventures.push_back(adventure);
}