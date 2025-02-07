#pragma once

using namespace std;

void bubbleSort(int array[], int size);
void selectionSort(int array[], int size);
void insertionSort(int array[], int size);
void merge(int array[], int leftIndex, int midIndex, int rightIndex);
void mergeSort(int array[], int leftIndex, int rightIndex);
int pivot(int array[], int leftIndex, int rightIndex);
void quickSort(int array[], int leftIndex, int rightIndex);