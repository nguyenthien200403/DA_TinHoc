#include<iostream>
#include<cstdlib>
using namespace std;

struct Node
{
	int data;
	Node* right;
	Node* left;
};

typedef Node* Tree_BST;

void createTree_BST(Tree_BST& t);
void create_Node(Tree_BST& t, int x);
void Insert_Node_Tree(Tree_BST& t);
void PreOrder(Tree_BST t);
void InOrder(Tree_BST t);
bool check_PrimeNumber(int x);
void Count_PrimeNumber(Tree_BST t, int& count_primeNumber);
void Output_PrimeNumber(Tree_BST t);
Node* Search_Node(Tree_BST &t, int x);
void Output_Node_La(Tree_BST t);
void Output_Node_1(Tree_BST t);
void Output_Node_2(Tree_BST t);
int Node_Max(Tree_BST t);
int Node_Min(Tree_BST t);
void Delete_Node(Tree_BST& t, int node);
void Remove_BST(Tree_BST& t);
void Menu(Tree_BST& t);

