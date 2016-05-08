#include <iostream>
#include <ctime>
#include <cstdio>

using namespace std;

int data[100000001];

int linearSearch (int element, int arraySize){
	//std::cout << "Going on\n";
	if ((arraySize == 0) || (linearSearch (element, arraySize - 1) == -1)){
		if (data[arraySize] == element)	
			return arraySize;
		else
			return -1;
	}
	//std::cout << "Searching in progress\n";
	return linearSearch (element, arraySize - 1);
		 
}


int main(){
	int arraySize, k;
	clock_t start, end;
	/*if (!(std::cin >> arraySize))
		std::cout << "No valid array size inputted.\n";
	for (i = 0; i < arraySize; i++)
		std::cin >> data[i];
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
	cin >> k;	
	start = clock();
	//cout << "Searching started\n\n";
	cout << linearSearch(k , arraySize-1) << "\n";
	end = clock();
	cout << "The running time is: " << (double)(end-start)/CLOCKS_PER_SEC << " s\n";
}
