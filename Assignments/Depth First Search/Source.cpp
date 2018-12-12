//#include<iostream>
//#include<queue>
//#include<vector>
//using namespace std;
//std::queue<int>qobj;
//int time = 0;
//bool *visited;
//int *parent;
//class node
//{
//public:
//	int vert;
//	node *next;
//	
//};
//class link_list
//{
//	node *head;
//	node *tail;
//	int stime;
//	int ftime;
//public:
//	link_list()
//	{
//		head = NULL;
//		tail = NULL;
//	}
//	
//	void insert(int v)
//	{
//		node *n = new node();
//		n->vert = v;
//		node *temp = head;
//		n->next = NULL;
//		if (head == NULL)
//		{
//			head = n;
//			tail = n;
//
//		}
//		else
//		{
//			tail->next = n;
//			tail = n;
//
//		}
//	}
//	node* get_list()
//	{
//		return head;
//	}
//	void set_stime(int t)
//	{
//		stime = t;
//	}
//	void set_ftime(int t)
//	{
//		ftime = t;
//	}
//	void print_time()
//	{
//		cout << stime << "--" << ftime;
//	}
//};
//class graph
//{
//	link_list *data;
//	int size;
//public:
//	graph(int s)
//	{
//		size = s;
//		data = new link_list[size];
//	}
//	void addEdge(int v, int u)
//	{
//		data[v].insert(u);
//	}
//	void dfs()
//	{
//		visited = new bool[size];
//		parent = new int[size];
//		for (int i = 0; i < size; i++)
//		{
//			visited[i] = false;
//			parent[i] = -1;
//		}
//		for (int i = 0; i < size; i++)
//		{
//			if (visited[i] == false)
//				dfs_visit(i);
//		}
//
//	}
//	void dfs_visit(int i)
//	{
//		time = time + 1;
//		cout << i << ", ";
//		visited[i] = true;
//		node *temp = data[i].get_list();
//		data[i].set_stime(time);
//		while (temp != NULL)
//		{
//			int c = temp->vert;
//			if (visited[c] == false)
//			{
//				parent[c] = i;
//				dfs_visit(c);
//				time = time + 1;
//				data[i].set_ftime(time);
//			}
//			temp = temp->next;
//		}
//	}
//
//	void displayPath(int s, int d){
//		if (s == d){
//			cout << d;
//		}
//		else{
//			displayPath(s, parent[d]);
//			cout << "->" << d;
//		}
//	}
//	bool isConnected(int u, int v)
//	{
//		node *temp = data[u].get_list();
//		while (temp != NULL)
//		{
//			if (temp->vert == v)
//				return true;
//			temp = temp->next;
//		}
//		return false;
//	}
//
//	void cout_time()
//	{
//		for (int i = 0; i < size; i++)
//		{
//			cout << i << "-> ";
//			data[i].print_time();
//			cout << endl;
//		}
//	}
//
//};
//void main()
//{
//	graph obj(7);
//	obj.addEdge(0, 1);
//	obj.addEdge(0, 2);
//	obj.addEdge(1, 3);
//	obj.addEdge(2, 1);
//	obj.addEdge(3, 2);
//	obj.addEdge(4, 3);
//	obj.addEdge(4, 5);
//	obj.addEdge(5, 6);
//	//obj.addEdge(6, 5);
//	//obj.addEdge(5, 4);
//	cout << "\ntraversal: ";
//	obj.dfs();
//	cout << endl;
//	obj.displayPath(0, 3);
//	cout << endl;
//	/*bool test = obj.isConnected(2, 1);
//	if (test)
//		cout << "\n\tconnected\n";
//	else
//		cout << "\n\tnot connected\n";*/
//	obj.cout_time();
//}