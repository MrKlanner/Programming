// Sortings.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int Asm_shaker_sort(int* arr, int N);
int C_shaker_sort(int * arr, int N);
void show_mass(int *arr, int N);

int main()
{
	srand(time(NULL));
	int N;
	cout << "Enter the number of elements -> ";
	cin >> N;
	int *arr1 = new int[N];
	int *arr2 = new int[N];
	//cout << "Enter the array:" << endl;
	//for (int i = 0; i < N; i++)
	//cin >> arr[i];
	//--------------------------------------------------------------------------------
	cout << "\nBest array:\n";
	for (int i = 0; i < N; i++)
	{
		arr1[i] = i + 1;
		arr2[i] = arr1[i];
	}
	cout << "Asm_shaker_sort time: " << Asm_shaker_sort(arr1, N) << endl;
	cout << "C++_shaker_sort time: " << C_shaker_sort(arr2, N) << endl;
	//---------------------------------------------------------------------------------
	cout << "\nRandom array:\n"; 
	for (int i = 0; i < N; i++)
	{
		arr1[i] = rand() % 100;
		arr2[i] = arr1[i];
	}
	/*for (int i = 0; i < N; i++)
	{
		cout << arr[i] << ' ';
	}
	cout << '\n';*/
	cout << "Asm_shaker_sort time: " << Asm_shaker_sort(arr1, N) << endl;
	//show_mass(arr, N);
	cout << "C++_shaker_sort time: " << C_shaker_sort(arr2, N) << endl;
	//show_mass(arr, N);
	/*for (int i = 0; i < N; i++)
	{
		cout << arr[i] << ' ';
	}*/
	//---------------------------------------------------------------------------------
	cout << "\nBad array:\n";
	for (int i = 0; i < N; i++)
	{
		arr1[i] = N - i;
		arr2[i] = arr1[i];
	}
	cout << "Asm_shaker_sort time: " << Asm_shaker_sort(arr1, N) << endl;
	cout << "C++_shaker_sort time: " << C_shaker_sort(arr2, N) << endl;
	system("pause");
	return 0;
}

int Asm_shaker_sort(int* arr, int N)
{
	unsigned int t = clock();
	__asm
	{
		pushad
		mov esi, -1
		mov ebx, N //const
		mov ecx, N
		shr ecx, 1 //ecx = len/2 (const)
		mov eax, arr
		cycle:
			mov edx, -1 //для начала cycle с 0
			inc esi //начинаем с 0
			cmp esi, ecx //если счётчик равен len/2, то выходим из ф-ции
			je exit1
			cycle1:
				inc edx
				push ebx
				sub ebx, esi
				dec ebx
				cmp edx, ebx
				je cycle2
				pop ebx
			subcycle1 :
				mov edi, [eax + edx * 4]
				cmp edi, [eax + edx * 4 + 4]
			jbe cycle1; // A[i] <= A[i+1], subcycle1
						 // cmp esi, right-1
						 //je out_cycle
				push edi
				mov edi, [eax + edx * 4 + 4]
				mov [eax + edx * 4], edi
				pop edi
				mov [eax + edx * 4 + 4], edi
			jmp subcycle1

			cycle2:
				pop ebx
				mov edx, ebx //для проверки сначала
				sub edx, esi
				sub edx, 1
				inc edx
			subcycle2:
				dec edx //начинаем с ebx - 2 - esi 
					cmp edx, esi
				jbe cycle // edx <= esi, 
					mov edi, [eax + edx * 4]
					cmp edi, [eax + edx * 4 - 4]
				jae subcycle2 //A[i-1] >= A[i], subsycle2
					push edi
					mov edi, [eax + edx * 4 - 4]
					mov[eax + edx * 4], edi
					pop edi
					mov[eax + edx * 4 - 4], edi
				jmp subcycle2;

			exit1 : popad
	}
	t = clock() - t;
	return t;
}

int C_shaker_sort(int * array, int size)
{
	unsigned int t = clock();
	for (int i = 0; i < size / 2; i++) {
		bool swapped = false;
		for (int j = i; j < size - i - 1; j++) { //one way
			if (array[j] < array[j + 1]) {
				int tmp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = tmp;
				swapped = true;
			}
		}
		for (int j = size - 2 - i; j > i; j--) { //and back
			if (array[j] > array[j - 1]) {
				int tmp = array[j];
				array[j] = array[j - 1];
				array[j - 1] = tmp;
				swapped = true;
			}
		}
		if (!swapped) break; //block (break if no element was swapped - the array is sorted)
	}
	t = clock() - t;
	return t;
}

void show_mass(int *arr, int N)
{
	cout << '\n[' << ' ';
	for (int i = 0; i < N; i++)
	{
		cout << arr[i] << ' ';
	}
	cout << ']' << endl;
}