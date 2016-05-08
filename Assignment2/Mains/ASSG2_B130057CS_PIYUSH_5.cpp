#include <iostream>
#include <ctime>
#include <cstdio>

using namespace std;

double data[100000001];

int swap (int i, int j){
	double temp;
	temp = data[i];
	data[i] = data[j];
	data[j] = temp;
	return 0;
}

int partition (int start, int end){
	double key = data[end];
	int index = start - 1;
	for (int i = start; i <= end-1; i++){
		if (data[i] <= key){
			index++;
			swap(index, i);
		}
	}
	swap(index+1, end);
	return (index+1);
}  

int quickSort(int start, int end){
	if (start < end){
		int mid = partition(start, end);
		quickSort(start, mid-1);
		quickSort(mid+1, end);
	}
	return 0;
}

int main(){
	int arraySize;
	clock_t start, end;
		
	/*
	cin >> arraySize;
	for (int i = 1; i <= arraySize; i++)
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
		//cout << data[i];
		char c = getchar();
		if (c == '\n' || c == ' ')
			continue;
		else{
			cout << "Error in input";
			return 0;
		}
	}

	start = clock();
	quickSort(0, arraySize);
	end = clock();
	cout << "\n";
	for (int i = 1; i <= arraySize; i++)	
		cout << data[i] << "\n";
	cout << "The running time is: " << (double)(end-start)/CLOCKS_PER_SEC << " s\n";
	return 0;
}
