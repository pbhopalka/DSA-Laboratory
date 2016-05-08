#include <iostream>
#include <cstring>
#include <ctime>

using namespace std;

char list[10000001][100];

int swap(int i, int j){
	char temp[100001];
	strcpy(temp, list[i]);
	strcpy(list[i], list[j]);
	strcpy(list[j], temp);
	return 0;
}


int stringCompare (char word1[], char word2[], int i){
	if (word1[i] > word2[i])
		return 1;
	else if (word1[i] < word2[i])
		return -1;
	else{
		i++;
		if ((word1[i] == '\0') || (word2[i] == '\0'))
			return 0; 
		return stringCompare(word1, word2, i);
	}
}		

int smallest (int start, int end){
	int small = start;
	for (int i = start + 1; i <= end; i++){
	//	cout << list[small] << list[i]<< 'p' << "\n";
		if (stringCompare (list[small], list[i], 0) > 0)
			small = i;
	//	cout << small << 's' << "\n";
	}
	return small;
}

int selectionSort (int arraySize){
	for (int i = 0; i < arraySize; i++){
		int min = smallest (i, arraySize);
	//	cout << min << 'y' << "\n";
		swap (i, min);
	}
	return 0;
}

int errorCheck (char word[]){
	int length = strlen(word);
	for (int i = 0; i < length; i++){
		if (!((word[i] > 96) && (word[i] < 123)))
			return 1;
	}
	return 0;
}

int main() {
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
	selectionSort(arraySize - 1);
	end = clock();
	cout << "\n";
	for (int i = 0; i < arraySize; i++)
		cout << list[i] << "\n"; 
	cout << "The running time is: " << (double) (end-start)/CLOCKS_PER_SEC << " s\n";
	return 0;
}
