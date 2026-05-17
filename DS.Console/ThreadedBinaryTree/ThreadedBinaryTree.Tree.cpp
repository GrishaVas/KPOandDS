#include "ThreadedBinaryTree.Tree.h"
#include <iostream>

using namespace ThreadedBinaryTree;

void Tree::Remove(int value)
{
	root = Remove(root, value, nullptr);

	if (root == nullptr)
	{
		return;
	}

	if (root->LeftSubNode != nullptr)
	{
		if (root->LeftSubNode->RightSubNode == nullptr || root->LeftSubNode->RightThread)
		{
			root->LeftSubNode->RightSubNode = root;
			root->LeftSubNode->RightThread = true;
		}
	}
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

int Tree::GetMinValue()
{
	return GetMinNode(root)->Value;
}

Node* Tree::Insert(Node* node, int value)
{
	if (value >= node->Value)
	{
		if (node->RightSubNode == nullptr || node->RightThread)
		{
			node->RightThread = false;
			node->RightSubNode = new Node(value);
			node->RightSubNode->Height = node->Height + 1;

			return node->RightSubNode;
		}
		else
		{
			return Insert(node->RightSubNode, value);
		}
	}
	else
	{
		if (node->LeftSubNode == nullptr)
		{
			node->LeftSubNode = new Node(value);
			node->LeftSubNode->Height = node->Height + 1;
			node->LeftSubNode->RightSubNode = node;
			node->LeftSubNode->RightThread = true;

			return node->LeftSubNode;
		}
		else
		{
			Node* insertedNode = Insert(node->LeftSubNode, value);

			if (insertedNode->RightSubNode == nullptr)
			{
				insertedNode->RightSubNode = node;
				insertedNode->RightThread = true;
			}

			return insertedNode;
		}
	}
}

 Node* Tree::Get(Node* node, int value)
{
	 node = GetMinNode(node);

	 while (node != nullptr)
	 {
		 if (node->Value == value)
		 {
			 return node;
		 }

		 if (node->RightThread)
		 {
			 node = node->RightSubNode;
		 }
		 else
		 {
			
			 return Get(node->RightSubNode, value);
		 }
	 }

	 return nullptr;
}

 Node* Tree::Remove(Node* node, int value, Node* parentNode)
 {
	 if (!node) return nullptr;

	 if (value < node->Value) {
		 node->LeftSubNode = Remove(node->LeftSubNode, value, node);
		 if (node->LeftSubNode) {
			 Node* p = node->LeftSubNode;
			 while (!p->RightThread) p = p->RightSubNode;
			 p->RightSubNode = node;
			 p->RightThread = true;
		 }
		 return node;
	 }

	 if (value > node->Value) {
		 if (!node->RightThread)
			 node->RightSubNode = Remove(node->RightSubNode, value, parentNode);
		 if (!node->RightSubNode) {
			 node->RightSubNode = parentNode;
			 node->RightThread = true;
		 }
		 return node;
	 }

	 if (!node->LeftSubNode) {
		 Node* temp = node;
		 node = node->RightThread ? nullptr : node->RightSubNode;
		 delete temp;
		 return node;
	 }

	 if (node->RightThread || node->RightSubNode == nullptr) {
		 Node* left = node->LeftSubNode;
		 Node* p = left;
		 while (!p->RightThread) p = p->RightSubNode;
		 p->RightSubNode = parentNode;
		 p->RightThread = true;
		 delete node;
		 return left;
	 }

	 Node* minNode = node->RightSubNode;
	 while (minNode->LeftSubNode) minNode = minNode->LeftSubNode;
	 node->Value = minNode->Value;
	 node->RightSubNode = Remove(node->RightSubNode, minNode->Value, parentNode);
	 if (!node->RightSubNode) {
		 node->RightSubNode = parentNode;
		 node->RightThread = true;
	 }
	 return node;
 }

 Node* Tree::GetMaxNode(Node* node)
 {
	 if (node == nullptr)
	 {
		 return node;
	 }

	 if (node->RightSubNode != nullptr && !node->RightThread)
	 {
		 return GetMaxNode(node->RightSubNode);
	 }

	 return node;
 }

Node* Tree::GetMinNode(Node* node,  Node*& parent)
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

Node* Tree::GetMinNode(Node* node)
{
	if (node == nullptr)
	{
		return node;
	}

	if (node->LeftSubNode != nullptr)
	{
		return GetMinNode(node->LeftSubNode);
	}

	return node;
}

string Tree::InOrderOutput(Node* node)
{
	string output = "";
	node = GetMinNode(node);

	while (node != nullptr)
	{
		if (node->RightThread)
		{
			output += to_string(node->Value) + " ";
			node = node->RightSubNode;
		}
		else
		{
			output += to_string(node->Value) + " ";
			output += InOrderOutput(node->RightSubNode);

			return output;
		}
	}

	return output;
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
