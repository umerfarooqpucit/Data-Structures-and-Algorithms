#include<iostream>
#include<queue>
using namespace std;

class node
{
public:
	int num;
	node *right, *left,*parent;

};
std::queue<node*>Qobj;
std::queue<node*>sub;
class binTree
{
	node *head;
public:
	binTree()
	{
		head = NULL;
	}
	void addElement(int no)
	{
		int t = 0;
		node *temp = head;
		node *prev = head;
		if (head == NULL)
		{
			node *n = new node();
			n->num = no;
			n->right = NULL;
			n->left = NULL;
			n->parent = NULL;
			head = n;
		}
		else
		{
			node *n = new node();
			while (temp != NULL)
			{
				if (no >= temp->num)
				{
					t = 1;
					prev = temp;
					temp = temp->right;
				}
				else
				{
					t = 0;
					prev = temp;
					temp = temp->left;
				}
			}
			if (t == 1)
			{
				n->num = no;
				prev->right = n;
				n->right = NULL;
				n->left = NULL;
				n->parent = prev;
			}
			else
			{
				n->num = no;
				prev->left = n;
				n->right = NULL;
				n->left = NULL;
				n->parent = prev;
			}
		}
	}
	bool search(int no)
	{
		node *temp = head;
		while (temp != NULL)
		{
			if (no == temp->num)
				return true;
			else if (no > temp->num)
				temp = temp->right;
			else
				temp = temp->left;
		}
		return false;

	}
	node* findNode(int no)
	{
		node *temp = head;
		while (temp != NULL)
		{
			if (no == temp->num)
				return temp;
			else if (no > temp->num)
				temp = temp->right;
			else
				temp = temp->left;
		}
		return 0;
	}
	int minValue(int val)
	{
		node *temp = findNode(val);
		while (temp->left != NULL)
			temp = temp->left;
		return temp->num;
	}
	int maxValue(int val)
	{
		node *temp = findNode(val);
		while (temp->right != NULL)
			temp = temp->right;
		return temp->num;
	}
	int successor(int val)
	{
		node *temp = findNode(val);
		node *prev;
		if (temp->right != NULL)
			return minValue(temp->right->num);
		else
		{
			prev = temp->parent;
			while (prev != NULL&&temp == prev->right)
			{
				temp = prev;
				prev = prev->parent;
			}
			if (prev != NULL)
				return prev->num;
			else
				return 0;
		}
	}
	int predecessor(int val)
	{
		node *temp = findNode(val);
		node *prev;
		if (temp->left != NULL)
			return maxValue(temp->left->num);
		else
		{
			prev = temp->parent;
			while (prev != NULL&&temp == prev->left)
			{
				temp = prev;
				prev = prev->parent;
			}
			if (prev != NULL)
				return prev->num;
			else
				return 0;
		}
	}
	void deletion(int val)
	{
		node *temp = findNode(val);
		if (temp->left == NULL&&temp->right == NULL)
		{
			node *prev = temp->parent;
			if (prev->right == temp)
				prev->right = NULL;
			else
				prev->left = NULL;
			delete temp;
		}
		else if (temp->left == NULL||temp->right == NULL)
		{
			node *next;
			if (temp->left == NULL)
			{
				next = temp->right;
				temp = temp->parent;
				if (temp->num>next->num)
				temp->left = next;
				else
				temp->right = next;
				next->parent = temp;
			}
			else
			{
				next = temp->left;
				temp = temp->parent;
				if (temp->num>next->num)
				temp->left = next;
				else
				temp->right = next;
				next->parent = temp;
			}
		}
		else
		{
			int no = successor(temp->num);
			deletion(no);
			temp->num = no;
			
		}
	}
		void traverse(int n)
	{
		if (n == 1)
			inorder(head);
		else if (n == 2)
			postorder(head);
		else
			preorder(head);

	}
	void inorder(node *temp)
	{
		if (temp == NULL)
			return;
		inorder(temp->left);
		cout << temp->num << ",";
		inorder(temp->right);
	}
	void preorder(node *temp)
	{
		if (temp == NULL)
			return;
		cout << temp->num << ",";
		preorder(temp->left);
		preorder(temp->right);

	}
	void postorder(node *temp)
	{
		if (temp == NULL)
			return;
		postorder(temp->left);
		postorder(temp->right);
		cout << temp->num << ",";
	}
	int max_val(int a, int b)
	{
		if (a > b)
			return a;
		else
			return b;
	}
	int max_height(node *n)
	{
		int lh = 0,rh=0;
		if (n->left != NULL)
			lh = max_height(n->left);
		if (n->right != NULL)
			rh = max_height(n->right);
		return (max_val(lh, rh) + 1);

	}
	node* get_root()
	{
		return head;
	}
	bool is_balance(node *n)
	{
		int lh = 0, rh = 0;
		if (n->left != NULL)
		{
			 lh = max_height(n->left);
		}
		if (n->right != NULL)
		{
			 rh = max_height(n->right);
		}
		if (abs(lh - rh) > 1)
			return false;
		if (n->left != NULL)
		{
			if (!is_balance(n->left))
				return false;
		}
		if (n->right != NULL)
		{
			if (!is_balance(n->right))
				return false;
		}
		return true;

	}
	void level_printing()
	{
		node *temp = head;
		Qobj.push(temp);
		while (!(Qobj.empty()))
		{
			temp = Qobj.front();
			cout << temp->num << ", ";
			Qobj.pop();
			if (temp->left != NULL)
				Qobj.push(temp->left);
			if (temp->right != NULL)
				Qobj.push(temp->right);
		}

	}
	bool find_sub_tree(node *temp,node *temp1)
	{
		Qobj.push(temp);
		sub.push(temp1);
		while (!(Qobj.empty()))
		{
			temp = Qobj.front();
			if (sub.empty())
				return false;
			else
			temp1 = sub.front();
			if (temp->num != temp1->num)
				return false;
			if (temp->left != NULL)
				Qobj.push(temp->left);
			if (temp1->left != NULL)
				sub.push(temp1->left);
			if (temp->right != NULL)
				Qobj.push(temp->right);
			if (temp1->right != NULL)
				sub.push(temp1->right);
			Qobj.pop();
			sub.pop();
		}
		return true;

		
	}
	int top_value()
	{
		return head->num;
	}
	bool search_by_node(node *temp, int no)
	{
		while (temp != NULL)
		{
			if (no == temp->num)
				return true;
			else if (no > temp->num)
				temp = temp->right;
			else
				temp = temp->left;
		}
		return false;

	}
	int ansestor(node *temp, int no)
	{
		bool test = search_by_node(temp, no);
		if (test)
			return temp->num;
		else
		{
			node *p = temp;
			while (p != NULL)
			{
				p = temp->parent;
				if (p->left == temp)
				{
					test = search_by_node(p->right, no);
					if (test)
						return p->num;
				}
				else
				{
					test = search_by_node(p->left, no);
					if (test)
						return p->num;

				}
				temp = p;
			}
		}
		return -1;
	}
};
void main()
{
	binTree obj,sub_obj;
	int n;
	bool test;
	for (int i = 0; i < 10; i++)
	{
		cout << "enter value# " << (i + 1) << ": ";
		cin >> n;
		obj.addElement(n);

	}
	/*int no1, no2;
	cout << "enter 1st value : ";
	cin >> no1;
	cout << "enter second value : ";
	cin >> no2;
	node *t = obj.findNode(no1);
	int anses = obj.ansestor(t, no2);
	if (anses != -1)
		cout << "lowest common ansestor is : " << anses << endl;
	else
		cout << "\nnot found!!\n";*/
	/*cout << "enter subtree\n\n ";
	for (int i = 0; i < 6; i++)
	{
		cout << "enter value# " << (i + 1) << ": ";
		cin >> n;
		sub_obj.addElement(n);

	}
	int num = sub_obj.top_value();
	node *temp = obj.findNode(num);
	node *temp1 = sub_obj.findNode(num);
	bool check = obj.find_sub_tree(temp, temp1);
	if (check)
		cout << "found\n\t";
	else
		cout << "not found\n\t";*/
	/*cout << "enter value for find minimum: ";
	cin >> n;
	n = obj.minValue(n);
	cout << "minimum num is : " << n << endl;*/
	/*cout << "enter value for find sucessor: ";
	cin >> n;
	n = obj.successor(n);
	if (n!=0)
	cout << "sucessor is : " << n << endl; 
	else
		cout << "sucessor not found : " << endl;*/
	/*cout << "enter value for find predecessor: ";
	cin >> n;
	n = obj.predecessor(n);
	if (n != 0)
		cout << "predecessor is : " << n << endl;
	else
		cout << "predecessor not found : " << endl;	*/
	/*cout << "enter value you want to delete: ";
	cin >> n;
	obj.deletion(n);*/
	node *nd = obj.get_root();
	/*int h = obj.max_height(nd);
	cout << "height is : " << h << endl;*/
	/*test = obj.is_balance(nd);
	if (test)
		cout << "balanced\n\n";
	else
		cout << "not balanced\n\n";*/

	/*obj.traverse(1);
	cout << endl;
	obj.traverse(2);
	cout << endl;
	obj.traverse(3);
	cout << endl;*/
	//obj.level_printing();
}