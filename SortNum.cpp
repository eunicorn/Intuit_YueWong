#include <iostream>  //std::cout
#include <algorithm> //std::sort

using namespace std;

void sortNum(int arr[], int size);

int main()
{
	int toSort[12] = {1,10,5,63,29,71,10,12,44,29,10,-1};
	sortNum(toSort, 12);
	return 0;
}

void sortNum(int arr[], int size)
{
	sort(arr, arr + size);
	for (int i = 0; i < size; ++i)
	{
		cout << arr[i] << " ";
	}
}
