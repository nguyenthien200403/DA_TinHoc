#include"header.h"

void createTree_BST(Tree_BST& t)
{
	t = NULL;
}

void create_Node(Tree_BST& t, int x)
{
	if (t == NULL)
	{
		Node* p = new Node();
		p->data = x;
		p->left = NULL;
		p->right = NULL;
		t = p;
	}
	else
	{
		if (x < t->data)
		{
			create_Node(t->left, x);
		}
		else if (x > t->data)
		{
			create_Node(t->right, x);
		}
		else
			cout << "\nTon tai Node";
	}
}

void Insert_Node_Tree(Tree_BST& t)
{
	int x;
	cout << "\nNhan -1 de dung them phan tu vao Cay BST";
	while (true)
	{
		cout << "\nThem phan tu: ";
		cin >> x;
		if (x == -1)
			break;
		create_Node(t, x);
	}
}

void PreOrder(Tree_BST t)
{
	if (t != NULL)
	{
		cout << t->data << " ";
		PreOrder(t->left);
		PreOrder(t->right);
	}
}

void InOrder(Tree_BST t)
{
	if (t != NULL)
	{
		InOrder(t->left);
		cout << t->data << " ";
		InOrder(t->right);
	}
}

void PostOrder(Tree_BST t)
{
	if (t != NULL) {
		PostOrder(t->left);
		PostOrder(t->right);
		cout << t->data << " ";
	}
}

bool check_PrimeNumber(int x)
{
	if (x < 2)
	{
		return false;
	}
	if (x == 2)
		return true;

	for (int i = 2; i < x; i++)
	{
		if (x % i == 0)
			return false;
	}
	return true;
}


void Count_PrimeNumber(Tree_BST t, int& count_primeNumber)
{
	if (t != NULL)
	{
		if (check_PrimeNumber(t->data))
		{
			count_primeNumber++;
		}
		Count_PrimeNumber(t->left, count_primeNumber);
		Count_PrimeNumber(t->right, count_primeNumber);
	}
}



void Output_PrimeNumber(Tree_BST t)
{
	if (t != NULL)
	{
		if (check_PrimeNumber(t->data))
			cout << t->data << " ";
		Output_PrimeNumber(t->left);
		Output_PrimeNumber(t->right);
	}
}

Node* Search_Node(Tree_BST &t, int x)
{
	if (t == NULL || t->data == x)
		return t;
	if (x < t->data)
		return Search_Node(t->left, x);
	else if (x > t->data)
		return Search_Node(t->right, x);
}

void Output_Node_La(Tree_BST t)
{
	if (t != NULL)
	{
		if (t->left == NULL && t->right == NULL)
		{
			cout << t->data << " ";
		}
		Output_Node_La(t->left);
		Output_Node_La(t->right);
	}
}

void Output_Node_1(Tree_BST t)
{
	if (t != NULL)
	{		
		if ((t->left != NULL && t->right == NULL) || (t->left == NULL && t->right != NULL))
		{
			cout << t->data << " ";
		}
		Output_Node_1(t->left); 
		Output_Node_1(t->right); 
	}
}


void Output_Node_2(Tree_BST t)
{
	if (t != NULL)
	{
		if (t->left != NULL && t->right != NULL)
		{
			cout << t->data << " ";
		}
		Output_Node_2(t->left);
		Output_Node_2(t->right);
	}
}

int Node_Max(Tree_BST t)
{
	if (t->left == NULL && t->right == NULL)
	{
		return t->data;
	}
	return Node_Max(t->right);
}


int Node_Min(Tree_BST t)
{
	if (t->left == NULL && t->right == NULL)
	{
		return t->data;
	}
	return Node_Min(t->left);
}

void LeftMostChild(Tree_BST&X,Tree_BST&Y)
{
	while (Y->left!=NULL)
	{
		Y = Y->left;
	}
	X->data = Y->data;
	X = Y;
	Y = Y->right;
}

void Delete_Node(Tree_BST& t, int node)
{
	if (t == NULL)
		return;
	if (t->data > node)
		Delete_Node(t->left, node);
	else if (t->data < node)
		Delete_Node(t->right, node);
	else
	{
		Node* X = t;
		if (t->left == NULL)
			t = t->right;
		else if (t->right == NULL)
			t = t->left;
		else
		{
			
			LeftMostChild(X, t->right);
		}
		delete X;
	}
}


void Remove_BST(Tree_BST& t)
{
	if (t == NULL)
		return;
	Remove_BST(t->left);
	Remove_BST(t->right);
	delete t;
	t = NULL;
}


void Menu(Tree_BST& t)
{	
	while (true)
	{
		system("cls");
		cout << "\n\n=========MENU==========";
		cout << "\n0.Thoat";
		cout << "\n1.Them phan tu vao cay:";
		cout << "\n2.Xuat danh sach PreOder";
		cout << "\n3.Xuat danh sach InOder";
		cout << "\n4.Xuat danh sach PostOder";
		cout << "\n5.Dem, hien thi so nguyen to co trong cay";
		cout << "\n6.Tim kim Node";
		cout << "\n7.Xuat cac Node la";
		cout << "\n8.Xuat cac Node co 1 con";
		cout << "\n9.Xuat cac Node co 2 con";
		cout << "\n10.Tim Node max";
		cout << "\n11.Tim Node min";
		cout << "\n12.Xoa Node";
		cout << "\n13.Huy cay";
		cout << "\n\n=========================";

		int chose, count_primeNumber = 0, Node_search, max, min, node;
		Node* FoundNode = NULL;
		cout << "\n\nNhap lua chon: ";
		cin >> chose;

		if (chose == 0)
			break;

		switch (chose)
		{
		case 1:
			Insert_Node_Tree(t);
			break;
		case 2:
			PreOrder(t);
			system("pause");
			break;
		case 3:
			InOrder(t);
			system("pause");
			break;
		case 4:
			PostOrder(t);
			system("pause");
			break;
		case 5:
			Count_PrimeNumber(t, count_primeNumber);
			cout << "\nCo: " << count_primeNumber << " nguyen to trong cay";
			cout << "\nCac so nguyen to: ";
			Output_PrimeNumber(t);
			system("pause");
			break;
		case 6:
			cout << "\nTim kim Node: ";
			cin >> Node_search;
			FoundNode = Search_Node(t, Node_search);
			if (FoundNode == NULL)
				cout << "\nKhong ton tai Node" << Node_search;
			else
				cout << "\nCo " << Node_search << " trong cay";
			system("pause");
			break;
		case 7:
			cout << "\nNode La: ";
			Output_Node_La(t);
			system("pause");
			break;
		case 8:
			cout << "\nNode co 1 con: ";
			Output_Node_1(t);
			system("pause");
			break;
		case 9:
			cout << "\nNode co 2 con: ";
			Output_Node_2(t);
			system("pause");
			break;
		case 10:
			max = Node_Max(t);
			cout << "\nNode lon nhat: " << max;
			system("pause");
			break;
		case 11:
			min = Node_Min(t);
			cout << "\nNode nho nhat: " << min;
			system("pause");
			break;
		case 12:
			cout << "\nNhap Node can xoa: ";
			cin >> node;
			Delete_Node(t, node);
			cout << "\nDanh sach sau khi xoa: ";
			PreOrder(t);
			system("pause");
			break;
		case 13:	
			Remove_BST(t);
			cout << "\n*****";
			cout << "\nCay da duoc huy";
			system("pause");
			break;
		default:
			cout << "\nLua chon khong hop le";
			system("pause");
			break;
		}
	}
	
}