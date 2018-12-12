//#include<iostream>
//#include<string>
//using namespace std;
//const int size = 20;
//class node
//{
//public:
//	char str;
//	node *next;
//};
//class link
//{
//	node *head;
//public:
//	link()
//	{
//		head = NULL;
//	}
//	void addNode(char val)
//		{
//			node *n = new node;
//			n->str = val;
//			node *temp = head;
//			if (temp == NULL)
//			{
//				head = n;
//				n->next = NULL;
//		
//			}
//			else
//			{
//				while (temp->next != NULL)
//					temp = temp->next;
//				temp->next = n;
//				n->next = NULL;
//			}
//		}
//	bool find(char s)
//	{
//		node *temp = head;
//		while (temp != NULL)
//		{
//			if (temp->str == s)
//				return true;
//			temp = temp->next;
//		}
//		return false;
//	}
//};
//int hashF(char ch);
//bool search(link[], string);
//void main()
//{
//	string str1;
//	link *obj;
//		obj = new link[size];
//
//	cout << "enter 1st string: ";
//	cin >> str1;
//	int i = 0;
//	while (str1[i] != NULL)
//	{
//		int no = hashF(str1[i]);
//		char ch = str1[i];
//		obj[no].addNode(ch);
//		i++;
//	}
//	cout << "enter 2nd string: ";
//	cin >> str1;
//	i = 0;
//	int count = 0;
//	while (str1[i] != NULL)
//	{
//		int no = hashF(str1[i]);
//		bool f=obj[no].find(str1[i]);
//		if (!f)
//		{
//			count++;
//		}
//			
//		i++;
//	}
//	if (count>1)
//	cout << "\n\tnot anagram\n";
//	else
//	cout << "\n\tanagram\n";
//}
////bool search(link obj[], string s)
////{
////	int no = hashF(s);
////	if (obj[no].find(s))
////		return true;
////	else
////		return false;
////}
//int hashF(char s)
//{
//	return int(s % 20);
//}