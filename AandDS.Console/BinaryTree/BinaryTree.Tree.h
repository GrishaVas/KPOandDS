#pragma once
#include "BinaryTree.Node.h"

namespace BinaryTree
{
	class Tree
	{
	public:
		Node* root = nullptr;

		void Remove(int value);
		void Add(int value);
		Node* Get(int value);
		void InOrderOutput();
		void PreOrderOutput();
		void PostOrderOutput();
		int GetNodesWithOneChildCount();

	private:
		Node* Remove(Node* node, int value);
		void Insert(Node* node, int value);
		Node* Get(Node* node, int value);
		Node* GetMinNode(Node* node, Node*& parent);
		string InOrderOutput(Node* node);
		string PreOrderOutput(Node* node);
		string PostOrderOutput(Node* node);
		string JoinStrings(string* strings, int length);
		int GetNodesWithOneChildCount(Node* node);
	};
}

