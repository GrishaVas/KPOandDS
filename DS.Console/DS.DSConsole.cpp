#include <iostream>
#include "BinaryTree/BinaryTree.Tree.h"
#include "DirectedGraph/Graph.h"
#include "ThreadedBinaryTree/ThreadedBinaryTree.Tree.h"

using namespace std;

void BinaryTreeProgramm();
BinaryTree::Tree* CreateRandomBinaryTree();
void AddBinaryTreeNode(BinaryTree::Tree tree);
void RemoveBinaryTreeNode(BinaryTree::Tree* tree);
void IsBinaryTreeNodeExists(BinaryTree::Tree* tree);

void ThreadedBinaryTreeProgram();
ThreadedBinaryTree::Tree* CreateRandomThreadedBinaryTree();
void AddThreadedBinaryTreeNode(ThreadedBinaryTree::Tree* tree);
void RemoveThreadedBinaryTreeNode(ThreadedBinaryTree::Tree* tree);
void IsThreadedBinaryTreeNodeExists(ThreadedBinaryTree::Tree tree);

void DirectedGraphProgram();
void GetGraphAdjacentVertices(DirectedGraph::Graph graph);
void GetGraphShortestPathes(DirectedGraph::Graph graph);
void GetGraphFromVertices(DirectedGraph::Graph graph);

int main()
{
    int programNumber = 0;

    while (true)
    {
        cout << "\n";
        cout << "Programs: \n" <<
            "   1. Binary Tree.\n" <<
            "   2. Directed Graph.\n" <<
            "   3. Threaded Binary Tree.\n" <<
            "   4. Exit.\n";
        cout << "Execute program: ";
        cin >> programNumber;

        system("cls");

        switch (programNumber)
        {
        case 1:
            BinaryTreeProgramm();
            break;
        case 2:
            DirectedGraphProgram();
            break;
        case 3:
            ThreadedBinaryTreeProgram();
            break;
        case 4:
            return 1;
        default:
            cout << "Wrong program number.\n";
            break;
        }
    }

    return 0;
}

void DirectedGraphProgram()
{
    DirectedGraph::Graph graph;

    int action = 0;

    while (true)
    {
        cout << "\n";
        graph.PrintAdjacencyMatrix();
        cout << "\n";
        cout << "Aciton: \n" <<
            "   1. Set adjacency matrix for Graph.\n" <<
            "   2. Get shortes pathes.\n" <<
            "   3. Get the most accessible vertex.\n" <<
            "   4. Get adjacent vertices.\n" <<
            "   5. Get from vertices.\n" <<
            "   6. Exit.\n";
        cout << "Execute program: ";
        cin >> action;

        system("cls");

        switch (action)
        {
        case 1:
            graph.SetAdjacencyMatrix();
            break;
        case 2:
            GetGraphShortestPathes(graph);
            break;
        case 3:
            cout << "Vertex number: " << graph.GetTheMostAccessibleVertex() << "\n";
            break;

        case 4:
            GetGraphAdjacentVertices(graph);
            break;

        case 5:
            GetGraphFromVertices(graph);
            break;

        case 6:
            return;
        default:
            cout << "Wrong action number.\n";
            break;
        }
    }

    return;
}

void GetGraphFromVertices(DirectedGraph::Graph graph)
{
    cout << "From: ";
    int fromVertex = 0;
    cin >> fromVertex;

    vector<int> vertecies = graph.GetFromVertices(fromVertex);
    cout << "\n";

    for (size_t i = 0; i < vertecies.size(); i++)
    {
        cout << vertecies[i] << " ";
    }

    cout << "\n";
}

void GetGraphShortestPathes(DirectedGraph::Graph graph)
{
    cout << "From: ";
    int fromVertex = 0;
    cin >> fromVertex;
    vector<DirectedGraph::Vertex> vertecies = graph.GetShortestPathes(fromVertex);

    cout << "\n";

    for (size_t i = 0; i < vertecies.size(); i++)
    {
        vertecies[i].Print();
        cout << "\n";
    }
}

void GetGraphAdjacentVertices(DirectedGraph::Graph graph)
{
    cout << "From: ";
    int fromVertex = 0;
    cin >> fromVertex;
    vector<int> vertecies = graph.GetAdjacentVertices(fromVertex);

    cout << "\n";

    for (size_t i = 0; i < vertecies.size(); i++)
    {
        cout << vertecies[i] << " ";
        
    }

    cout << "\n";
}


void BinaryTreeProgramm()
{
    int operationNumber = 0;
    BinaryTree::Tree* binaryTree = nullptr;

    while (true)
    {
        cout << "\n";
        if (binaryTree != nullptr)
        {
            cout << "InOrder: ";
            binaryTree->InOrderOutput();
            cout << "PostOrder: ";
            binaryTree->PostOrderOutput();
            cout << "PreOreder: ";
            binaryTree->PreOrderOutput();
        }

        cout << "Operaitons: \n" <<
            "   1. Create random binary tree.\n" <<
            "   2. Add node.\n" <<
            "   3. Remove node.\n" <<
            "   4. Is node exists.\n" <<
            "   5. Get nodes with one child count.\n" <<
            "   6. Exit.\n";
        cout << "Execute program: ";
        cin >> operationNumber;
        system("cls");

        switch (operationNumber)
        {
        case 1:
            binaryTree = CreateRandomBinaryTree();
            break;
        case 2:
            if (binaryTree == nullptr)
            {
                binaryTree = new BinaryTree::Tree();
            }

            AddBinaryTreeNode(*binaryTree);
            binaryTree->InOrderOutput();
            cout << "\n";
            break;
        case 3:
            RemoveBinaryTreeNode(binaryTree);
            break;
        case 4:
            IsBinaryTreeNodeExists(binaryTree);
            break;
        case 5:
            cout << binaryTree->GetNodesWithOneChildCount() << "\n";
            break;
        case 6:
            return;
        default:
            cout << "Wrong operation number.\n";
            break;
        }
    }
}

BinaryTree::Tree* CreateRandomBinaryTree()
{
    int nodesCount = 0;

    cout << "Nodes cout: ";
    cin >> nodesCount;
    cout << "\n";

    if (nodesCount == 0)
    {
        return nullptr;
    }

    BinaryTree::Tree* binaryTree = new BinaryTree::Tree();
    std::srand(std::time(0));
    for (size_t i = 0; i < nodesCount; i++)
    {
        binaryTree->Add(rand() % 101);
    }

    return binaryTree;
}

void AddBinaryTreeNode(BinaryTree::Tree tree)
{
    int nodeValue = 0;

    cout << "Node value: ";
    cin >> nodeValue;
    cout << "\n";

    tree.Add(nodeValue);
}

void RemoveBinaryTreeNode(BinaryTree::Tree* tree)
{
    int nodeValue = 0;

    cout << "Node value: ";
    cin >> nodeValue;

    tree->Remove(nodeValue);
}

void IsBinaryTreeNodeExists(BinaryTree::Tree* tree)
{
    int nodeValue = 0;
    cout << "Node: ";
    cin >> nodeValue;

    BinaryTree::Node* node = tree->Get(nodeValue);
    cout << "\n";

    if (node == nullptr)
    {
        cout << "Does not exist\n";

    }
    else
    {
        cout << "Exists\n";
    }
}

void ThreadedBinaryTreeProgram()
{
    int operationNumber = 0;
    ThreadedBinaryTree::Tree* binaryTree = nullptr;

    while (true)
    {
        cout << "\n";

        if (binaryTree != nullptr)
        {
            cout << "InOrder: ";
            binaryTree->InOrderOutput();
        }

        cout << "Operaitons: \n" <<
            "   1. Create random threaded binary tree.\n" <<
            "   2. Add node.\n" <<
            "   3. Remove node.\n" <<
            "   4. Is node exists.\n" <<
            "   5. Get min value.\n" <<
            "   6. Exit.\n";
        cout << "Execute program: ";
        cin >> operationNumber;

        system("cls");

        switch (operationNumber)
        {
        case 1:
            binaryTree = CreateRandomThreadedBinaryTree();
            break;
        case 2:
            if (binaryTree == nullptr)
            {
                binaryTree = new ThreadedBinaryTree::Tree();
            }

            AddThreadedBinaryTreeNode(binaryTree);
            break;
        case 3:
            if (binaryTree != nullptr)
            {
                RemoveThreadedBinaryTreeNode(binaryTree);
            }
            break;
        case 4:
            IsThreadedBinaryTreeNodeExists(*binaryTree);
            break;
        case 5:
            cout << binaryTree->GetMinValue() << "\n";
            break;
        case 6: 
            return;
        default:
            cout << "Wrong operation number.\n";
            break;
        }
    }
}

ThreadedBinaryTree::Tree* CreateRandomThreadedBinaryTree()
{
    int nodesCount = 0;

    cout << "Nodes cout: ";
    cin >> nodesCount;
    cout << "\n";

    if (nodesCount == 0)
    {
        return nullptr;
    }

    ThreadedBinaryTree::Tree* binaryTree = new ThreadedBinaryTree::Tree();
    std::srand(std::time(0));
    for (size_t i = 0; i < nodesCount; i++)
    {
        binaryTree->Add(rand() % 101);
    }

    return binaryTree;
}

void AddThreadedBinaryTreeNode(ThreadedBinaryTree::Tree* tree)
{
    int nodeValue = 0;

    cout << "Node value: ";
    cin >> nodeValue;
    cout << "\n";

    tree->Add(nodeValue);
}

void RemoveThreadedBinaryTreeNode(ThreadedBinaryTree::Tree* tree)
{
    int nodeValue = 0;

    cout << "Node value: ";
    cin >> nodeValue;

    tree->Remove(nodeValue);
}

void IsThreadedBinaryTreeNodeExists(ThreadedBinaryTree::Tree tree)
{
    int nodeValue = 0;

    cout << "Node value: ";
    cin >> nodeValue;

    ThreadedBinaryTree::Node* node = tree.Get(nodeValue);

    if (node != nullptr)
    {
        cout << "Node exists\n";
    }
    else
    {
        cout << "Node doesn't exists\n";
    }
}
