//#include<iostream>
//#include<string>
//using namespace std;
//const int size = 20;
////int hashF(string);
////bool search(string[],string);
////void main()
////{
////	string str[size], str1;
////	for (int i = 0; i < 5; i++)
////	{
////		cout << "enter : ";
////		cin >> str1;
////		int no = hashF(str1);
////		str[no] = str1;
////	}
////	cout << "enter string you want to search : ";
////	cin >> str1;
////	bool test = search(str, str1);
////	if (test)
////		cout << "found!!!\n\n";
////	else
////		cout << "not found!!!\n\n";
////}
////bool search(string str[],string s)
////{
////	int no = hashF(s);
////	if (str[no] == s)
////		return true;
////	else
////		return false;
////}
////int hashF(string s)
////{
////	int i = 0;
////	int sum = 0;
////	while (s[i] != NULL)
////	{
////		sum = sum + int(s[i]);
////		i++;
////	}
////	return (sum % 20);
////}