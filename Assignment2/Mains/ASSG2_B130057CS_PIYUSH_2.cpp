#include <iostream>
#include <ctime>
#include <cstdio>

using namespace std;

int data[100000001];

int binarySearch (int element, int start, int end){
	//cout << start;
	int ans = -1, mid;
if (start <= end){
	mid = (start + end)/2;
	if (data[mid] == element)
		return mid;
	else if (data[mid] > element){
		if ((element < data[start]) && (data[start] <= data[mid])){
			ans = binarySearch (element, mid+1, end);
			//cout << ans << 'a';
		}
		else{
		//	cout << start;
			ans = binarySearch (element, start, mid-1);
			//cout << ans <<'q';
		}
	}
	else {
		if ((element > data[end]) && (data[end] >= data[mid])){
			ans = binarySearch(element, start, mid-1);
			//cout << ans << 'w';
		}
		else{
			ans = binarySearch(element, mid+1, end);
			//cout << ans << 's';
		}
	}
}
	return ans;
}

int main(){
	int arraySize, element;
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
	cin >> element;
	start = clock();
	int co = binarySearch(element, 0, arraySize - 1);
	end = clock();
	cout << "\n";
	if (co < 0)
		cout << "Element not present.\n";
	else
		cout << co << "\n";
	cout << "The running time is: " << (double) (end-start)/CLOCKS_PER_SEC << " s\n";
	return 0;
}
