#include <iostream>

void merge(int arr[], int start_pos, int mid_pos, int end_pos) {
  // get the size of first and second array
  int first_arr_length = mid_pos - start_pos + 1;
  int second_arr_length = end_pos - mid_pos;

  // create first and second array
  int first_arr[first_arr_length];
  int second_arr[second_arr_length];

  // copy the values of input arr to first and second array
  for (int i = 0; i < first_arr_length; i++) {
    first_arr[i] = arr[start_pos + i];
  }
  for (int i = 0; i < second_arr_length; i++) {
    second_arr[i] = arr[mid_pos + 1 + i];
  }

  // initialize the pointers that keep track of progress
  int first_arr_position = 0;
  int second_arr_position = 0;
  int merged_arr_start_pos = start_pos;

  // merge first and second array until one of the pointers hit the end
  while (first_arr_position < first_arr_length &&
         second_arr_position < second_arr_length) {
    if (first_arr[first_arr_position] <= second_arr[second_arr_position]) {
      arr[merged_arr_start_pos] = first_arr[first_arr_position];
      first_arr_position++;
    } else {
      arr[merged_arr_start_pos] = second_arr[second_arr_position];
      second_arr_position++;
    }
    merged_arr_start_pos++;
  }

  // copy the remaining elements of first array (if any) to the merged array
  while (first_arr_position < first_arr_length) {
    arr[merged_arr_start_pos] = first_arr[first_arr_position];
    first_arr_position++;
    merged_arr_start_pos++;
  }

  // copy the remaining elements of second array (if any) to the merged array
  while (second_arr_position < second_arr_length) {
    arr[merged_arr_start_pos] = second_arr[second_arr_position];
    second_arr_position++;
    merged_arr_start_pos++;
  }
}

void mergeSort(int arr[], int start_pos, int end_pos) {
  // base case: end_pos will keep getting smaller until it's same as the
  // start_pos
  if (start_pos >= end_pos) {
    return;
  }
  int mid_pos = start_pos + (end_pos - start_pos) / 2;
  mergeSort(arr, start_pos, mid_pos);
  mergeSort(arr, mid_pos + 1, end_pos);
  merge(arr, start_pos, mid_pos, end_pos);
}

void printArray(int A[], int size) {
  for (int i = 0; i < size; i++) std::cout << A[i] << " ";
  std::cout << std::endl;
}

int main() {
  int input_arr[] = {6, 5, 12, 10, 9, 1, 30, -3};
  int input_arr_size = sizeof(input_arr) / sizeof(input_arr[0]);
  mergeSort(input_arr, 0, input_arr_size - 1);
  printArray(input_arr, input_arr_size);
  return 0;
}
