#include<iostream>
#include<string>
using namespace std;
const int size = 20;
class node
{							//hashing using linklist
public:
	string str;
	node *next;
};
class link
{
	node *head;
public:
	link()
	{
		head = NULL;
	}
	void addNode(string val)
		{
			node *n = new node;
			n->str = val;
			node *temp = head;
			if (temp == NULL)
			{
				head = n;
				n->next = NULL;
		
			}
			else
			{
				while (temp->next != NULL)
					temp = temp->next;
				temp->next = n;
				n->next = NULL;
			}
		}
	bool find(string s)
	{
		node *temp = head;
		while (temp != NULL)
		{
			if (temp->str == s)
				return true;
			temp = temp->next;
		}
		return false;
	}
};
int hashF(string);
bool search(link[], string);
void main()
{
	string str1;
	link obj[size];
	for (int i = 0; i < 6; i++)
	{
		cout << "enter : ";
		cin >> str1;
		int no = hashF(str1);
		obj[no].addNode(str1);
	}
	cout << "enter string you want to search : ";
	cin >> str1;
	bool test = search(obj, str1);
	if (test)
		cout << "found!!!\n\n";
	else
		cout << "not found!!!\n\n";
}
bool search(link obj[], string s)
{
	int no = hashF(s);
	if (obj[no].find(s))
		return true;
	else
		return false;
}
int hashF(string s)
{
	int i = 0;
	int sum = 0;
	while (s[i] != NULL)
	{
		sum = sum + int(s[i]);
		i++;
	}
	return (sum % 20);
}