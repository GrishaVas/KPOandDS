#pragma once
#include "ThreadedBinaryTree.Node.h"

namespace ThreadedBinaryTree {
	class Tree
	{
	public:
		Node* root = nullptr;

		void Remove(int value);
		void Add(int value);
		Node* Get(int value);
		void InOrderOutput();
		int GetMinValue();
		Node* GetMinNode(Node* node, Node*& parent);

	private:
		Node* Remove(Node* node, int value, Node* parentNode);
		Node* Insert(Node* node, int value);
		Node* Get(Node* node, int value);
		Node* GetMaxNode(Node* node);
		Node* GetMinNode(Node* node);
		string InOrderOutput(Node* node);
		string JoinStrings(string* strings, int length);
	};
}

