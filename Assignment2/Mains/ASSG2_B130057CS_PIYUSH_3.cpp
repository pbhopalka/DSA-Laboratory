#include <iostream>
#include <ctime>
#include <cstdio>

using namespace std;

int data[100000001];

long long insertionSort(int arraySize){
	long long inversion = 0;
	for (int j = 1; j < arraySize; j++){
		int key = data[j];
		int i = j - 1;
		while ((i >= 0) && (data[i] > key)){
			data[i+1] = data[i];
			inversion++;
			i--;
		}
		data[i+1] = key;
	}
	return inversion;
}

int main(){
	int arraySize;
	clock_t start, end;
	/*cin >> arraySize;
	for (int i = 0; i < arraySize; i++)
		cin >> data[i];
	*/
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
	long long inv = insertionSort(arraySize);
	end = clock();
	cout << "\n";
	for (int i = 0; i < arraySize; i++)
		cout << data[i] << "\n";
	cout << "Number of inversions: " << inv << "\n";
	cout << "The running time is: " << (double)(end - start)/CLOCKS_PER_SEC << " s\n";
	return 0;
}
