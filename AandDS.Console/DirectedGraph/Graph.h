#include <string>
#include <vector>
#include "Vertex.h"
#pragma once

using namespace std;

namespace DirectedGraph
{
	class Graph
	{
	public:
		vector<vector<int>> AdjacencyMatrix;
		vector<Vertex> GetShortestPathes(int from);
		int GetTheMostAccessibleVertex();
		vector<int> GetAdjacentVertices(int vertex);
		vector<int> GetFromVertices(int vertex);
		void SetAdjacencyMatrix();
		void PrintAdjacencyMatrix();
		static vector<string> SplitString(string value, char delimiter);
	private:
		void GetShortestPathes(int from, vector<Vertex>& vertices);
	};
}



