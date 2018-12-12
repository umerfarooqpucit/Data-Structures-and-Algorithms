//#include<iostream>
//#include<string>
//using namespace std;
//string sort_check(string);
//void main()
//{
//	string str1, str2;
//	cout << "enter 1st string : ";
//	cin >> str1;
//	cout << "enter 2nd string :";
//	cin >> str2;
//	str1 = sort_check(str1);
//	str2 = sort_check(str2);
//	if (str1==str2)
//		cout << "\n\t\tanagrams\n";
//	else
//		cout << "\n\t\tnot anagrams\n";
//}
//string sort_check(string str1)
//{
//	int s1 = str1.size();
//	for (int i = 0; i < s1; i++)
//	{
//		for (int j = 0; j < s1 - i; j++)
//		{
//			if (str1[j] > str1[j + 1])
//			{
//				char ch = str1[j];
//				str1[j] = str1[j + 1];
//				str1[j + 1] = ch;
//			}
//		}
//	}
//			return str1;
//}