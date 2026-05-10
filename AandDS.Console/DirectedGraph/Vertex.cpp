#include "Vertex.h"
#include <iostream>

using namespace DirectedGraph;

Vertex::Vertex()
{
	PathValue = numeric_limits<int>::max();
}

void DirectedGraph::Vertex::Print()
{
	cout << "Path: ";

	for (size_t i = 0; i < this->PathVertices.size(); i++)
	{
		cout << this->PathVertices[i] << " ";
	}

	cout << "\n";
	cout << "Path value: " << this->PathValue << "\n";
}
