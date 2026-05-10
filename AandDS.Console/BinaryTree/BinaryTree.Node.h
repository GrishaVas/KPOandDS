#pragma once
#include <string>
#include <vector>

using namespace std;

namespace BinaryTree
{
	class Node
	{
	public:
		Node* RightSubNode;
		Node* LeftSubNode;
		int Value;
		int Height;

		Node();
		Node(int value);
	};
}