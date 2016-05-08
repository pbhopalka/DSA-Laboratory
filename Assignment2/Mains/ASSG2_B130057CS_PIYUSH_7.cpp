#include <iostream>
#include <ctime>
#include <cstdio>
#include <climits>

using namespace std;

int data[100000001];
int leftArray[100000001]; 
int rightArray[100000001];

int merge (int start, int mid, int end){
	int leftLength = mid - start + 1;
	int rightLength = end - mid;
	int i;
	for (i = 0; i < leftLength; i++)
		leftArray[i] = data[start + i];
	leftArray[i] = INT_MAX;
	for (i = 0; i < rightLength; i++)
		rightArray[i] = data[mid + i + 1];
	rightArray[i] = INT_MAX;
	int j = 0;
	i = 0;
	for (int k = start; k <= end; k++){
		if (leftArray[i] <= rightArray[j]){
			data[k] = leftArray[i];
			i++;
		}
		else {
			data[k] = rightArray[j];
			j++;
		}
	}
	return 0;
}

int mergesort (int start, int end){
	if (start < end){
		int mid = (start + end)/2;
		//cout << 'p' << endl;
		mergesort (start, mid);
		mergesort (mid+1, end);
		merge (start, mid, end);
	}
	return 0;
}

int main(){
	int arraySize;
	clock_t start, end;
	if (! (cin >> arraySize)){
		cout << "Error in input";
		return 0;
	}
	char c = getchar();
	if (! (c == '\n') && !(c == ' ')){
		cout << "Error in input";
		return 0;
	}
	//cin.ignore();
	for (int i = 0; i < arraySize; i++){
		if (! (cin >> data[i])){
			cout << "Error in input";
			return 0;
		}
		char c = getchar();
		if (c == '\n' || c == ' ')
			continue;
		else{
			cout << "Error in input";
			return 0;
		}
	}
	start = clock();
	mergesort(0, arraySize-1);
	end = clock();
	cout << "\n";
	for (int i = 0; i < arraySize; i++)
		cout << data[i] << "\n";
	cout << "The running time is: " << (double)(end - start)/CLOCKS_PER_SEC << " s\n";
	return 0;
}
