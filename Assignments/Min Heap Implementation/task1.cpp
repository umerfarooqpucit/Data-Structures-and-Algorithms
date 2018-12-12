#include<iostream>
using namespace std;
class heapnode
{
public:
	int key;	
	double data;
	heapnode(){
		key=0;
		data=0.0;
	}
};
class minheap
{
	heapnode *arr;
	int length;
	int numElements;
public:
	minheap(int l){
		l++;
		arr=new heapnode[l];
		length=l;
		numElements=0;
	}
	void Enqueue(int k,double d){
		numElements++;
		arr[numElements].data=d;
		arr[numElements].key=k;
		heapifyUp(0,length);
	}
	void heapifyUp(int root,int size){
		int i=numElements;
		while(i/2 > 0){
			if(arr[i/2].data>arr[i].key){
				swap(arr[i/2].key,arr[i].key);
				swap(arr[i/2].data,arr[i].data);
			}
			i=i/2;
		}
	}
	void printAll(){
		for(int i=1;i<=numElements;i++){
			cout<<arr[i].key<<" "<<arr[i].data<<endl;
		}
	}
	void dequeue(){
		arr[1]=arr[numElements];
		numElements--;
		heapifyDown(0,length);
	}
	void heapifyDown(int root,int size){
		int index=1;
		int indexSmall=0;
		while(index*2<=numElements){
			indexSmall=index*2;
			if((index*2+1<=numElements) && (arr[index*2+1].key < arr[index*2].key)){
				indexSmall=index*2+1;
			}
			if(arr[index].key< arr[indexSmall].key){
				break;
			}
			else{
				swap(arr[index].key,arr[indexSmall].key);
				swap(arr[index].data,arr[indexSmall].data);
			}
			index=indexSmall;
		}
	}
	int findMax(){
		int max=arr[1].key;
		int maxIndex=1;
		for(int i=2;i<=numElements;i++){
			if(max<arr[i].key){
				max=arr[i].key;
				maxIndex=i;
			}
		}
		cout<<"Max priority element: "<<arr[maxIndex].data<<endl;
		return max;
	}
	void deleteMax(){
		int max=arr[1].key;
		int maxIndex=1;
		for(int i=2;i<=numElements;i++){
			if(max<arr[i].key){
				max=arr[i].key;
				maxIndex=i;
			}
		}
		arr[maxIndex]=arr[numElements];
		numElements--;
		heapifyDown(0,length);
	}
	void displaylrp(int i){
		int p=i/2;
		int lc=i*2;
		int rc=i*2+1;
		if(p>0)
			cout<<"Parent: "<<arr[p].data<<endl;
		if(lc>=numElements)
			cout<<"Left child: "<<arr[lc].data<<endl;
		if(rc>=numElements)
			cout<<"Right child: "<<arr[rc].data<<endl;
	}
};
int main(){
	int size;
	cout<<"Enter size: "<<endl;
	cin>>size;
	minheap h1(size);
	int k;
	double d;
	for(int i=0;i<5;i++){
		cout<<"Enter key: "<<endl;
		cin>>k;
		cout<<"Enter data: "<<endl;
		cin>>d;
		h1.Enqueue(k,d);
	}
	cout<<"All elements: "<<endl;
	h1.printAll();
	h1.dequeue();
	cout<<"All elements: "<<endl;
	h1.printAll();
	h1.deleteMax();
	cout<<"All elements: "<<endl;
	h1.printAll();
	h1.displaylrp(2);
}