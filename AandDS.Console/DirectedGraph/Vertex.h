#include <vector>
#pragma once

using namespace std;

namespace DirectedGraph 
{
	class Vertex
	{
	public:
		int PathValue;
		vector<int> PathVertices;

		Vertex();
		void Print();
	};
}


