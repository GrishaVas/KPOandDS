#include <iostream>
#include <vector>
#include "ThreadedBinaryTree.Node.h"

using namespace std;
using namespace ThreadedBinaryTree;

Node::Node()
{
	this->Height = 0;
	this->Value = 0;
	this->LeftSubNode = nullptr;
	this->RightSubNode = nullptr;
	this->RightThread = false;
}

Node::Node(int value)
{
	this->Value = value;
	this->Height = 0;
	this->LeftSubNode = nullptr;
	this->RightSubNode = nullptr;
	this->RightThread = false;
}

//string BinaryTreeNode::GetString()
//{
//	vector<vector<string>> vectors;
//
//	toString(this, vectors, 0, 0);
//
//	string output;
//
//	for (size_t i = 0; i < vectors.size(); i++)
//	{
//		string vectorStr;
//
//		for (size_t j = 0; j < vectors[i].size(); j++)
//		{
//			vectorStr += "[" +vectors[i][j] + "]";
//		}
//
//		output += vectorStr + "\n";
//	}
//
//	return output;
//}

//void BinaryTreeNode::toString(BinaryTreeNode* node, vector<vector<string>>& vectors, int row, int& col)
//{
//	if (node == nullptr)
//	{
//		return;
//	}
//
//	toString(node->LeftSubNode, vectors, row + 1, col - 1);
//	vectors[row + 1].push_back(to_string(node->Value));// have to detect layer thru return
//	toString(node->RightSubNode, vectors, row + 1, col + 1);
//
//	if (vectors.size() <= row)
//	{
//		vector<string> newVector;
//
//		vectors.push_back(newVector);
//	}
//
//	vectors[row].push_back(to_string(node->Value));
//}