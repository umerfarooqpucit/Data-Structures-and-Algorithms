//#include<iostream>
//using namespace std;
//class node
//{
//public:
//	int num;
//	node *right, *left, *parent;
//
//};
//class binTree
//{
//	node *head;
//public:
//	binTree()
//	{
//		head = NULL;
//	}
//	void addElement(int no)
//	{
//		int t = 0;
//		node *temp = head;
//		node *prev = head;
//		if (head == NULL)
//		{
//			node *n = new node();
//			n->num = no;
//			n->right = NULL;
//			n->left = NULL;
//			n->parent = NULL;
//			head = n;
//		}
//		else
//		{
//			node *n = new node();
//			while (temp != NULL)
//			{
//				if (no >= temp->num)
//				{
//					t = 1;
//					prev = temp;
//					temp = temp->right;
//				}
//				else
//				{
//					t = 0;
//					prev = temp;
//					temp = temp->left;
//				}
//			}
//			if (t == 1)
//			{
//				n->num = no;
//				prev->right = n;
//				n->right = NULL;
//				n->left = NULL;
//				n->parent = prev;
//			}
//			else
//			{
//				n->num = no;
//				prev->left = n;
//				n->right = NULL;
//				n->left = NULL;
//				n->parent = prev;
//			}
//		}
//	}
//	bool search(int no)
//	{
//		node *temp = head;
//		while (temp != NULL)
//		{
//			if (no == temp->num)
//				return true;
//			else if (no > temp->num)
//				temp = temp->right;
//			else
//				temp = temp->left;
//		}
//		return false;
//
//	}
//	node* findNode(int no)
//	{
//		node *temp = head;
//		while (temp != NULL)
//		{
//			if (no == temp->num)
//				return temp;
//			else if (no > temp->num)
//				temp = temp->right;
//			else
//				temp = temp->left;
//		}
//		return 0;
//	}
//	int minValue(int val)
//	{
//		node *temp = findNode(val);
//		
//		while (temp->left != NULL)
//			temp = temp->left;
//		return temp->num;
//	}
//	int maxValue(int val)
//	{
//		node *temp = findNode(val);
//		while (temp->right != NULL)
//			temp = temp->right;
//		return temp->num;
//	}
//	int successor(int val)
//	{
//		node *temp = findNode(val);
//
//		if (temp->right != NULL)
//			return minValue(temp->right->num);
//		else
//		{
//			while (temp != NULL)
//			{
//				if (val < temp->num)
//					return temp->num;
//				temp = temp->parent;
//			}
//				return 0;
//		}
//	}
//	int predecessor(int val)
//	{
//		node *temp = findNode(val);
//		if (temp->left != NULL)
//			return maxValue(temp->left->num);
//		else
//		{
//			while (temp != NULL)
//			{
//				if (val < temp->num)
//					return temp->num;
//				temp = temp->parent;
//			}
//				return 0;
//		}
//	}
//
//};
//void main()
//{
//	binTree obj;
//	int n;
//	bool test;
//	for (int i = 0; i < 5; i++)
//	{
//		cout << "enter value# " << (i + 1) << ": ";
//		cin >> n;
//		obj.addElement(n);
//
//	}
//	/*cout << "enter value for find minimum: ";
//	cin >> n;
//	n = obj.minValue(n);
//	cout << "minimum num is : " << n << endl;*/
//	cout << "enter value for find sucessor: ";
//	cin >> n;
//	n = obj.successor(n);
//	if (n!=0)
//	cout << "sucessor is : " << n << endl;
//	else
//	cout << "sucessor not found  " << endl;
//	/*cout << "enter value for find predecessor: ";
//	cin >> n;
//	n = obj.predecessor(n);
//	if (n != 0)
//		cout << "predecessor is : " << n << endl;
//	else
//		cout << "predecessor not found : " << endl;*/
//
//
//
//}