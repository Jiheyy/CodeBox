/*
민지혜
https://www.acmicpc.net/problem/1517 (버블소트)
*/
#include <iostream>

using namespace std;

int arr[500001];
int tmp[500001];
long long result = 0;


void merge(int start, int mid, int last) {

	int i = start;
	int j = mid + 1;
	int idx = start;
	int cnt = 0;

	while(i <= mid || j <= last) {

		// left finish, right attach
		if(i > mid) { 
			tmp[idx++] = arr[j++];
			cnt++;
		}
		// right finish, left attach
		else if (j > last){ 
			tmp[idx++] = arr[i++];
			result += (long long)cnt;
		} 
		// swap
		else if(arr[i] > arr[j]) {
			tmp[idx++] = arr[j++];
			cnt++;
		}
		else {
			tmp[idx++] = arr[i++];
			result += (long long)cnt;
		}
	}

	for(int t=start; t<=last; t++)
		arr[t] = tmp[t];
}


void mergesort(int start, int last) {

	if(start < last) {
		int mid = (start+last) / 2;

		mergesort(start, mid);
		mergesort(mid+1, last);

		merge(start, mid, last);
	}
}


int main() {

	int N;
	
	scanf("%d", &N);

	for(int i=0; i<N; i++) {
		scanf("%d", &arr[i]);
	}

	mergesort(0, N-1);

	printf("%lld\n", result);

}
