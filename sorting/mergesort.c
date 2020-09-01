#include <stdio.h>

void merge (int *arr, int low, int mid, int high, int *temp) {
    int start = low;
    int start2 = mid + 1;
    // if the left side is already less than the right size
    if (arr[mid] <= arr[start2]) 
	return;  	
    int temp_curr = low;
    while (start <= mid && start2 <= high) {
        if (arr[start] <= arr[start2]) {
            temp[temp_curr] = arr[start];
            start++;
        } else {
            temp[temp_curr] = arr[start2];
            start2++;
        }
        temp_curr++;
    }
    if (start == mid) 
        temp_curr = low;
	while (temp_curr < start2)
            arr[temp_curr] = temp[temp_curr++];
    else {
        while(start <= mid)
            temp[temp_curr] = arr[start++];
        temp_curr = low;
        while (temp_curr <= high)
            arr[temp_curr] = temp[temp_curr++];
    }	
}

void mergeSort(int *arr, int low, int high, int *temp) {
    if (high - low <= 1)
	return;
    int mid = low + (high - low) / 2;
    mergeSort(arr, low, mid - 1);
    mergeSort(arr, mid, high);
    merge(arr, low, mid, high, temp);

}

int main () {
    int input;
    while (scanf(%d", &input) != EOF) {
    }
}
