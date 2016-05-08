#include <iostream>
#include <cstring>
#include <ctime>

using namespace std;

char list[10000001][100];

int parent (int index){
	return index/2;
}

int leftChild (int index){
	return index*2;
}

int rightChild (int index){
	return leftChild(index)+1;
}

int swap (int i, int j){
	char temp[100001];
	strcpy(temp, list[i]);
	strcpy(list[i], list[j]);
	strcpy(list[j], temp);
	return 0;
}

int maxHeapify(int heapSize, int index) {
	int largest;
	int left = leftChild (index);
	int right = rightChild (index);
	if ((left <= heapSize) && (strcmp (list[left], list[index]) > 0))
		largest = left;
	else
		largest = index;
	if ((right <= heapSize) && (strcmp (list[right], list[largest]) > 0))
		largest = right;
	if (largest != index){
		swap (index, largest);
		maxHeapify(heapSize, largest);
	}
	return 0;
}

int buildHeap(int heapSize){
	for (int i = (heapSize/2); i >= 0; i--)
		maxHeapify(heapSize, i);
	return 0;
} 
	
int heapsort(int arraySize){
	buildHeap (arraySize);
	for (int i = arraySize; i > 0; i--){
		swap (0, i);
		arraySize--;
		maxHeapify(arraySize, 0);
	}
	return 0;
}	

int errorCheck (char word[]){
	int length = strlen(word);
	for (int i = 0; i < length; i++){
		if (!((word[i] > 64) && (word[i] < 91)))
			return 1;
	}
	return 0;
}

int main(){
	int arraySize;
	clock_t start, end;
	cin >> arraySize;
	for (int i = 0; i < arraySize; i++){
		cin >> list[i];
		if (errorCheck(list[i]) == 1){
			cout << "Error in input\n";
			return 0;
		}
	}
	start = clock();
	heapsort(arraySize - 1);
	end = clock();
	cout << "\n";
	//for (int i = 0; i < arraySize; i++)	
	//	cout << list[i] << "\n";
	cout << "The running time is:" << (double) (end-start)/CLOCKS_PER_SEC << " s\n";
	return 0;
}
