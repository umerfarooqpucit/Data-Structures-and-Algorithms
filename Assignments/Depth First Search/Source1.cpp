//#include <iostream>
//#include <queue>
//using namespace std;
//int *parent;
//
//struct comparator {
//	bool operator()(int i, int j) {
//		return i > j;
//	}
//};
//class node
//{
//public:
//	int vert;
//	int weight;
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
//	void insert(int v, int w)
//	{
//		node *n = new node();
//		n->vert = v;
//		n->weight = w;
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
//	void addEdge(int v, int u, int w)
//	{
//		data[v].insert(u, w);
//	}
//	void dijestra(int s)
//	{
//		queue<int> q;
//		bool *p;
//		p = new bool[size];
//		int *distance;
//		parent = new int[size];
//		distance = new int[size];
//		q.push(s);
//		for (int i = 0; i < size; i++)
//		{
//			p[i] = false;
//			distance[i]=numeric_limits<int>::max();
//			parent[i] = -1;
//		}
//      distance[s] = 0;
//		while (!q.empty())
//		{
//			int u = q.front();
//			q.pop();
//			node *temp = data[u].get_list();
//			while (temp != NULL)
//			{
//				int v = temp->vert;
//				if (distance[v] > (temp->weight+distance[u]))
//				{
//					distance[v] = distance[u] + temp->weight;
//					q.push(v);
//					parent[v] = u;
//				}
//				temp = temp->next;
//			}
//		}
//			
//}
//		void displayPath(int s, int d){
//			if (s == d){
//				cout << d;
//			}
//			else{
//				displayPath(s, parent[d]);
//				cout << "->" << d;
//			}
//		}
//		bool isConnected(int u, int v)
//		{
//			node *temp = data[u].get_list();
//			while (temp != NULL)
//			{
//				if (temp->vert == v)
//					return true;
//				temp = temp->next;
//			}
//			return false;
//		}
//
//		void cout_time()
//		{
//			for (int i = 0; i < size; i++)
//			{
//				cout << i << "-> ";
//				data[i].print_time();
//				cout << endl;
//			}
//		}
//
//	};
//
//void main()
//{
//	graph obj(7);
//		obj.addEdge(0, 1,2);
//		obj.addEdge(0, 2,4);
//		obj.addEdge(1, 2,1);
//		obj.addEdge(1, 3,4);
//		obj.addEdge(1, 4,2);
//		obj.addEdge(2, 4,3);
//		obj.addEdge(3, 5,2);
//		obj.addEdge(4, 5,2);
//		//obj.addEdge(6, 5);
//		//obj.addEdge(5, 4);
//		//cout << "\ntraversal: ";
//		obj.dijestra(0);
//		cout << endl;
//		obj.displayPath(0, 5);
//		cout << endl;
//		/*bool test = obj.isConnected(2, 1);
//		if (test)
//			cout << "\n\tconnected\n";
//		else
//			cout << "\n\tnot connected\n";*/
//		//obj.cout_time();
//}