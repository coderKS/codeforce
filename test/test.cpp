#include<iostream>
using namespace std;
int main(void){
	const int max = 1e7;
	printf("%d", max);
	int arr[3]={0,0,0};
	int j = 1;
	arr[++j] = arr[j-1] + 1;
	printf("%d, %d, %d",arr[0],arr[1],arr[2]);
}
