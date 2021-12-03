#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
using namespace std;

int* CreateArray(int ArraySize) {
	int* Array_Pointer;
	Array_Pointer = new int[ArraySize];
	cout << "Enter " << ArraySize << " integers:\n";
	for (int i = 0; i < ArraySize; i++)
		cin >> Array_Pointer[i];
	return Array_Pointer;
}

int NewArraySize(int* ArrayA, int SizeA, int* ArrayB, int SizeB) {
	int New_Size = SizeA;
	bool flag;
	for (int i = 0; i < SizeA; i++) {
		flag = false;
		for (int j = 0; j < SizeB; j++) {
			if (ArrayA[i] == ArrayB[j]) {
				flag = true;
				break;
			}
		}
		if (flag == false)
			New_Size++;
	}
	return New_Size;
}

int* New_Array(int* ArrayA, int SizeA, int* ArrayB, int SizeB, int New_Size) {
	int* Array_Pointer, Index_End_ArrayA = 0;
	bool flag;
	Array_Pointer = new int[New_Size];
	for (int i = 0; i < SizeA; i++)
		Array_Pointer[i] = ArrayA[i];
	delete[]ArrayA;
	for (int i = 0; i < SizeB; i++) {
		flag = false;
		for (int j = 0; j < SizeA; j++) {
			if (ArrayB[i] == Array_Pointer[j]) {
				flag = true;
				break;
			}
		}
		if (flag == false) {
			Array_Pointer[SizeA + Index_End_ArrayA] = ArrayB[i];
			Index_End_ArrayA++;
		}
	}
	delete[]ArrayB;
	return Array_Pointer;
}

int* OrgenizeArray(int* Array_Pointer, int Array_size) {
	int* RandomArr = new int[Array_size],temp;
	for (int i = 0; i < Array_size; i++)
	{
		RandomArr[i] = Array_Pointer[i]
	}
	for (int i = 1; i < Array_size; i++) {
		if (RandomArr[i - 1] > RandomArr[i]) {
			temp = RandomArr[i];
			RandomArr[i] = RandomArr[i - 1];
			RandomArr[i - 1] = temp;
			i = 0;
		}
	}
	return RandomArr;
}

int main() {
	int* ArrayA, * ArrayB, SizeA = 3, SizeB = 3, newsize, * NewPointer, ** Array;
	ArrayA = CreateArray(SizeA);
	ArrayB = CreateArray(SizeB);
	newsize = NewArraySize(ArrayA, SizeA, ArrayB, SizeB);
	NewPointer = New_Array(ArrayA, SizeA, ArrayB, SizeB, newsize);
	Array = &NewPointer;
	OrgenizeArray(Array, newsize);
	for (int i = 0; i < newsize; i++)
	{
		cin >> NewPointer[i];
	}
	delete[] NewPointer;
	return 0;
}