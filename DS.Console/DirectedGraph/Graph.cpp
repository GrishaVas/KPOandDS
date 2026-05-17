#include "Graph.h"
#include <iostream>

using namespace DirectedGraph;

vector<Vertex> Graph::GetShortestPathes(int from)
{
	vector<Vertex> vertices(AdjacencyMatrix.size());

	for (size_t i = 0; i < vertices.size(); i++)
	{
		vertices[i].PathVertices.push_back(i);
	}
	
	GetShortestPathes(from, vertices);

	return vertices;
}

int Graph::GetTheMostAccessibleVertex()
{
	int vertexIndex = 0;
	int maxPathes = 0;

	for (size_t i = 0; i < AdjacencyMatrix.size(); i++)
	{
		int vertexPathes = 0;

		for (size_t j = 0; j < AdjacencyMatrix.size(); j++)
		{
			if (AdjacencyMatrix[j][i] > 0)
			{
				vertexPathes++;
			}
		}

		if (maxPathes < vertexPathes)
		{
			maxPathes = vertexPathes;
			vertexIndex = i;
		}
	}

	return vertexIndex;
}

void Graph::GetShortestPathes(int from, vector<Vertex>& vertices)
{
	for (size_t i = 0; i < AdjacencyMatrix[from].size(); i++)
	{
		int edgeValue = AdjacencyMatrix[from][i];

		if (edgeValue > 0)
		{
			int vertexValue = 0;

			if (vertices[from].PathValue != numeric_limits<int>::max())
			{
				vertexValue = vertices[from].PathValue;
			}

			int pathValue = vertexValue + edgeValue;

			if (vertices[i].PathValue > pathValue)
			{
				vertices[i].PathValue = pathValue;
				vertices[i].PathVertices.clear();
				vertices[i].PathVertices.insert(vertices[i].PathVertices.end(), vertices[from].PathVertices.begin(), vertices[from].PathVertices.end());
				vertices[i].PathVertices.push_back(i);
			}

			GetShortestPathes(i, vertices);
		}
	}
}

vector<int> Graph::GetAdjacentVertices(int vertex)
{
	vector<int> vertices;

	for (size_t i = 0; i < AdjacencyMatrix[vertex].size(); i++)
	{
		if (AdjacencyMatrix[vertex][i] > 0)
		{
			vertices.push_back(i);
		}
	}

	for (size_t i = 0; i < AdjacencyMatrix.size(); i++)
	{
		if (AdjacencyMatrix[i][vertex] > 0)
		{
			if (count(vertices.begin(), vertices.end(), i) < 1)
			{
				vertices.push_back(i);
			}
		}
	}

	return vertices;
}

vector<int> Graph::GetFromVertices(int vertex)
{
	vector<int> vertices;

	for (size_t i = 0; i < AdjacencyMatrix.size(); i++)
	{
		if (AdjacencyMatrix[i][vertex] > 0)
		{
			vertices.push_back(i);
		}
	}

	return vertices;
}

void Graph::SetAdjacencyMatrix()
{
	string matrix; 
	
	cin.ignore();
	getline(cin, matrix);

	vector<string> rows = SplitString(matrix, ';');

	for (size_t i = 0; i < rows.size(); i++)
	{
		vector<string> items = SplitString(rows[i], ' ');
		vector<int> values(items.size());

		for (size_t j = 0; j < items.size(); j++)
		{
			values[j] = stoi(items[j]);
		}

		AdjacencyMatrix.push_back(values);
	}
}

void Graph::PrintAdjacencyMatrix()
{
	for (size_t i = 0; i < AdjacencyMatrix.size(); i++)
	{
		string row;

		for (size_t j = 0; j < AdjacencyMatrix[i].size(); j++)
		{
			row += to_string(AdjacencyMatrix[i][j]) + " ";
		}

		cout << row << "\n";
	}
}

vector<string> Graph::SplitString(string value, char delimiter)
{
	vector<string> strings;
	int index = 0;

	for (size_t i = 0; i < value.length(); i++)
	{
		if (value[i] == delimiter)
		{
			strings.push_back(value.substr(index, i - index));
			index = i + 1;
		}
	}

	strings.push_back(value.substr(index, value.length() - index));

	return strings;
}
