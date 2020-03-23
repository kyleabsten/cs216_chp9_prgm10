/*
Programmer Name: Kyle Absten
Date: 03/17/2020
Description:  This program is for CS216. It is chapter 9, problem 10.  It will create two identical arrays of 8 integers.
It will display the elements of the first array, and then sort it in ascending order using a bubble sort.  
It will print the values after each step.


It will then display the elements of the sedond array.  It will then sort the second array in ascending order using a selection sort.
It will print the values after each step.
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int const arraySize = 8; //Constant Int; size of arrays
int array1[arraySize], array2[arraySize]; //Two arrays of ints; set to arraySize

void buildArrays(int[], int[], int); //Function prototype; takes three arguments; two int arrays and an int; returns void
void printArrayValues(int[], int); //Function prototype; takes two arguments; an array of ints and an int; returns void
void bubbleSortArray(int[], int);  //Function prototype; takes two arguments; an array of ints and an int; returns void
void selectionSortArray(int[], int);  //Function prototype; takes two arguments; an array of ints and an int; returns void

int main() { //Main func call

	buildArrays(array1, array2, arraySize);  //Calls the build arrays function

	printArrayValues(array1, arraySize);  //Calls the printArrayValues function; passing array1 and arraysize as arguments
	cout << endl;
	bubbleSortArray(array1, arraySize);  //Calls bubbleSortArray function; passing array1 and arraysize as arguments
	cout << endl;
	printArrayValues(array2, arraySize);  //Calls the printArrayValues function; using array2 and arraysize as arguments
	cout << endl;
	selectionSortArray(array2, arraySize);  //Calls selectionSortArray function; passing array1 and arraysize as arguments
	return 0;
}

void buildArrays(int firstArray[], int secondArray[], int numOfElements) { //Function; takes two int arrays and an int; returns void
	unsigned seed;  //Seed for random number generator
	seed = time(0);  //Seed based on time
	srand(seed);  //Feeding seed to random

	for (int index = 0; index < numOfElements; index++) { //Loop through indexes of arrays
		int randomInt = rand();  //Genereate random int
		firstArray[index] = randomInt;  //Assign randomInt to index of array1
		secondArray[index] = randomInt;  //Assign same randomInt to index of array2

	}
}

void printArrayValues(int givenArray[], int numOfElements) {  //Function; takes an int array and an int; returns void
	for (int index = 0; index < numOfElements; index++) {  //Loop through indexes of array
		cout << givenArray[index] << " "; // Print value at current index
	}
	cout << endl;
}

void bubbleSortArray(int givenArray[], int numOfElements) {  //Function; takes an int array and an int; returns void
	int temp;  //Int; temp holding for swapping value
	bool didSwap;  //Boolean; did a swap happen or not
	do {
		didSwap = false;  //Set did swap to false
		for (int index = 0; index < numOfElements - 1; index++) {  //Loop thorugh indexes of array
			if (givenArray[index] > givenArray[index + 1]) { //If value at index is less than value at next index
				temp = givenArray[index];  //Set temp to store value at current index
				givenArray[index] = givenArray[index + 1];  //Set current index value to next index value
				givenArray[index + 1] = temp;  //Set next index value to temp
				didSwap = true;  //Set didSwap flag to true; a swap happened
			}
		}printArrayValues(givenArray, numOfElements); //Call print arrayValues with current array
	} while (didSwap); //Loop as long as a swap occured
}

void selectionSortArray(int givenArray[], int numOfElements) { //Function; takes an int array and an int; returns void
	int currentIndex, minIndex, minValue;  //Ints; stores current index, index of min value and min value
	
	for (currentIndex = 0; currentIndex < numOfElements - 1; currentIndex++) { //Outer loop; loop through array indexes
		minIndex = currentIndex; //minIndex set to Current index; if a lower value isn't found, this value stays
		minValue = givenArray[currentIndex];  //minValue set to value at  current index; if a lower value isn't found, this value stays
		for (int index = currentIndex + 1; index < numOfElements; index++) { //Inner Loop through arrays indexes
			if (givenArray[index] < minValue) { //Compare value at each index to see if its smaller than current minValue
				minValue = givenArray[index]; //If a lower value is found, set minValue to it
				minIndex = index; //If a lower value is found, set minIndex to it's index
			}
		}
		givenArray[minIndex] = givenArray[currentIndex];  //Set old index new min value of outer loop to current index; swap
		givenArray[currentIndex] = minValue; //Set current index to new minValue found in inner loop
		printArrayValues(givenArray, arraySize); //Call printArrayValues passing currentArray and arraySize
	}
}