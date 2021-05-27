#include<bits/stdc++.h>
using namespace std;
class Heap{
	int *heap;
	int capacity,size;
	public:
		Heap(int cap){
			capacity = cap;
			size=0;
			heap = new int[cap];
		}
		void insert(int data);
		void removeRoot();
		int getmax();
		void heapify(int i);
		int parent(int i) { return (i-1)/2; }
		int left(int i) { return (2*i + 1); }
		int right(int i) { return (2*i + 2); }
		void swap(int*,int*);
		void printHeap(){
			for(int i=0;i<size;i++)
			cout<<heap[i]<<" ";
		}
};

void Heap :: insert(int data){
	size++;
	heap[size-1] = data;
	int i = size-1;
	while(i!=0 && heap[parent(i)] < heap[i]){
		swap(&heap[i],&heap[parent(i)]);
		i = parent(i);
	}
}
int Heap :: getmax(){
	return heap[0];
}
void Heap :: swap(int* x,int* y){
	int temp = *x;
    *x = *y;
    *y = temp;
}
void Heap :: removeRoot(){
	if(size == 0)
	return;
	if(size == 1){
		size--;
		return;
	}
	heap[0] = heap[size-1];
	size--;
	heapify(0);
}
void Heap :: heapify(int i){
	int l = left(i);
    int r = right(i);
    int largest = i;
    if (l < size && heap[l] > heap[i])
        largest = l;
    if (r < size && heap[r] > heap[largest])
        largest = r;
    if (largest != i)
    {
        swap(&heap[i], &heap[largest]);
        heapify(largest);
    }
}

int main(){
	Heap h(6);
	h.insert(5);
	h.insert(2);
	h.insert(0);
	h.insert(1);
	h.insert(6);
	h.insert(3);
//	h.removeRoot();
//	h.removeRoot();
//	for(int i=0;i<6;i++)
//	h.heapify(i);
//	h.HeapSort();
//	cout<<h.getmin()<<endl;
	h.printHeap();
}

