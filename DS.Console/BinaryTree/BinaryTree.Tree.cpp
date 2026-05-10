#include "BinaryTree.Tree.h"
#include <iostream>

using namespace BinaryTree;

void Tree::Remove(int value)
{
	root = Remove(root, value);
}

void Tree::Add(int value)
{
	if (root == nullptr)
	{
		root = new Node(value);

		return;
	}

	Insert(root, value);
}

Node* Tree::Get(int value)
{
	return Get(root, value);
}

void Tree::InOrderOutput()
{
	cout << InOrderOutput(root) << "\n";
}

void Tree::PreOrderOutput()
{
	cout << PreOrderOutput(root) << "\n";
}

void Tree::PostOrderOutput()
{
	cout << PostOrderOutput(root) << "\n";
}

int Tree::GetNodesWithOneChildCount()
{
	return GetNodesWithOneChildCount(root);
}

int Tree::GetNodesWithOneChildCount(Node* node)
{
	if (node == nullptr)
	{
		return 0;
	}

	int left = GetNodesWithOneChildCount(node->LeftSubNode);
	int right = GetNodesWithOneChildCount(node->RightSubNode);

	if (!((node->LeftSubNode == nullptr && node->RightSubNode == nullptr) ||
		(node->LeftSubNode != nullptr && node->RightSubNode != nullptr)))
	{
		return 1 + left + right;
	}

	return left + right;
}

void Tree::Insert(Node* node, int value)
{
	if (value >= node->Value)
	{
		if (node->RightSubNode == nullptr)
		{
			node->RightSubNode = new Node(value);
			node->RightSubNode->Height = node->Height + 1;
		}
		else
		{
			Insert(node->RightSubNode, value);
		}
	}
	else
	{
		if (node->LeftSubNode == nullptr)
		{
			node->LeftSubNode = new Node(value);
			node->LeftSubNode->Height = node->Height + 1;
		}
		else
		{
			Insert(node->LeftSubNode, value);
		}
	}
}

Node* Tree::Get(Node* node, int value)
{
	if (node == nullptr)
	{
		return nullptr;
	}

	if (node->Value == value)
	{
		return node;
	}

	if (node->Value > value)
	{
		Node* left = Get(node->LeftSubNode, value);

		return left;
	}

	Node* right = Get(node->RightSubNode, value);

	return right;
}

Node* Tree::Remove(Node* node, int value)
{
	if (node == nullptr)
	{
		return nullptr;
	}

	if (node->Value > value)
	{
		node->LeftSubNode = Remove(node->LeftSubNode, value);
	}

	if (node->Value < value)
	{
		node->RightSubNode = Remove(node->RightSubNode, value);
	}

	if (node->Value == value)
	{
		Node* minNodeParent;
		Node* minNode = GetMinNode(node->RightSubNode, minNodeParent);

		if (minNode != nullptr)
		{
			node->Value = minNode->Value;
			node->RightSubNode = Remove(node->RightSubNode, minNode->Value);

			return node;
		}

		Node* next = node->LeftSubNode;

		delete node;

		return next;
	}

	return node;
}

Node* Tree::GetMinNode(Node* node, Node*& parent)
{
	if (node == nullptr)
	{
		return node;
	}

	if (node->LeftSubNode != nullptr)
	{
		parent = node;

		return GetMinNode(node->LeftSubNode, parent);
	}

	return node;
}

string Tree::InOrderOutput(Node* node)
{
	if (node == nullptr)
	{
		return "";
	}

	string strings[3];

	strings[0] = InOrderOutput(node->LeftSubNode);
	strings[1] = to_string(node->Value);
	strings[2] = InOrderOutput(node->RightSubNode);

	return JoinStrings(strings, 3);
}

string Tree::PreOrderOutput(Node* node)
{
	if (node == nullptr)
	{
		return "";
	}

	string strings[3];

	strings[0] = to_string(node->Value);
	strings[1] = PreOrderOutput(node->LeftSubNode);
	strings[2] = PreOrderOutput(node->RightSubNode);

	return JoinStrings(strings, 3);
}

string Tree::PostOrderOutput(Node* node)
{
	if (node == nullptr)
	{
		return "";
	}

	string strings[3];

	strings[0] = PostOrderOutput(node->LeftSubNode);
	strings[1] = PostOrderOutput(node->RightSubNode);
	strings[2] = to_string(node->Value);

	return JoinStrings(strings, 3);
}

string Tree::JoinStrings(string* strings, int length)
{
	if (length < 2)
	{
		return strings[0];
	}

	string result = strings[0];

	for (size_t i = 1; i < length; i++)
	{
		if (!result.empty() && !strings[i].empty())
		{
			result += ", " + strings[i];
		}
		else
		{
			result += strings[i];
		}
	}

	return result;
}
