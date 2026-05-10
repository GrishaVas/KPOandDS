#pragma once
#include <string>
#include <vector>

using namespace std;

namespace ThreadedBinaryTree 
{
	class Node
	{
	public:
		Node* RightSubNode;
		Node* LeftSubNode;
		bool RightThread;
		int Value;
		int Height;

		Node();
		Node(int value);
	};
}
