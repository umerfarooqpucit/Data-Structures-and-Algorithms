//#include<iostream>
//using namespace std;
//class node
//{
//public:
//	int num;
//	node *right, *left;
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
//			}
//			else
//			{
//				n->num = no;
//				prev->left = n;
//				n->right = NULL;
//				n->left = NULL;
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
//	void traverse(int n)
//	{
//		if (n == 1)
//			inorder(head);
//		else if (n == 2)
//			postorder(head);
//		else
//			preorder(head);
//
//	}
//	void inorder(node *temp)
//	{
//		if (temp == NULL)
//			return;
//		inorder(temp->left);
//		cout << temp->num<<",";
//		inorder(temp->right);
//	}
//	void preorder(node *temp)
//	{
//		if (temp == NULL)
//			return;
//		cout << temp->num << ",";
//		preorder(temp->left);
//		preorder(temp->right);
//	}
//	void postorder(node *temp)
//	{
//		if (temp == NULL)
//			return;
//		postorder(temp->left);
//		postorder(temp->right);
//		cout << temp->num << ",";
//	}
//
//};
//void main()
//{
//	binTree obj;
//	int n;
//	bool test;
//	for (int i = 0; i < 10; i++)
//	{
//		cout << "enter value# " << (i + 1) << ": ";
//		cin >> n;
//		obj.addElement(n);
//
//	}
//	cout << "enter value to search in tree : ";
//	cin >> n;
//	test = obj.search(n);
//	if (test)
//		cout << "\n\n\t\tFOUND! ! !\n";
//	else
//		cout << "\n\n\t\tNOT FOUND! ! !\n";
//	cout << "\n\tINORDER: ";
//	obj.traverse(1);
//	cout << "\n\n\tPOSTORDER: ";
//	obj.traverse(2);
//	cout << "\n\n\tPREORDER: ";
//	obj.traverse(3);
//	cout << endl;
//}