#include <iostream>
#include <cstring>
#include <ctime>

using namespace std;

char list[10000001][9] = {0};
char sortedList[10000001][9] = {0};
int temp[100000001];

int getDigit(int i, int index){
	int length = strlen(list[i]);
	if ((length - index) < 0)
		return 0;
	return (list[i][length - index] - '0');
}
  

int countingSort (int arraySize, int digitIndex){
	int max = 0;
	for (int i = 0; i < arraySize; i++){
		temp[i] = getDigit(i, digitIndex);
		if (max < temp[i])
			max = temp[i];
	}
	int temp2[1000] = {0};
	for (int i = 0; i < arraySize; i++){
		temp2 [temp[i]]++;
	}
	for (int i = 1; i <= max; i++){
		temp2[i] = temp2[i] + temp2[i-1];
	}
	for (int i = arraySize - 1; i >= 0; i--){
		strcpy(sortedList[temp2 [temp[i]] - 1], list[i]);
		temp2 [temp[i]]--; 
	}
	for (int i = 0; i < arraySize; i++){
		strcpy(list[i], sortedList[i]);
	}
	return 0;
}

int radixSort (int arraySize){
	for (int i = 1; i <= 8; i++){
		countingSort(arraySize, i);
	}
	return 0;
}

int errorCheck (char word[]){
	int length = strlen(word);
	if (length > 8){
		cout << "Input not in range.\n";
		return 1;
	}
	for (int i = 0; i < length; i++){
		if ((!((word[i] > 64) && (word[i] < 71))) && (!((word[i] > 47) && (word[i] < 59))))
			return 1;
	}
	return 0;
}

int main(){
	int arraySize;
	clock_t start, end;
	cin >> arraySize;
	for (int i = 0; i < arraySize;i++){
		cin >> list[i];
		if (errorCheck (list[i]) == 1){
			cout << "Error in input\n";
			return 0;
		}
	}
	start = clock();
	radixSort (arraySize);
	end = clock();
	cout << "\n";
	for (int i = 0; i < arraySize; i++)
		cout << list[i] << "\n"; 
	cout << "The running time is: " << (double) (end-start)/CLOCKS_PER_SEC << "s\n";
	return 0;
}
