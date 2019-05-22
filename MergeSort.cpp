#include <iostream>
using namespace std;

void Snapshot(int * A, int r) {
	for (int i = 0; i < r; i++)
		cout << A[i] << ";";
}
void Merge(int *A, int p, int q, int r) {
	int* L = new int[q - p + 1], *R = new int[r - q];

	for (int i = 0; i < (q - p + 1); i++)
		L[i] = A[p + i];
	for (int j = 0; j < (r - q); j++)
		R[j] = A[q + j + 1];

	int i = 0, j = 0, k = p;
	for (; (i < (q - p + 1)) && (j < (r - q)); k++) {
		if (L[i] <= R[j]) {
			A[k] = L[i]; i++;
		} else {
			A[k] = R[j]; j++;
		}
	}
	for (; i < (q - p + 1); i++, k++)
		A[k] = L[i];
	for (; j < (r - q); j++, k++)
		A[k] = R[j];
	delete[] L, R;
}
void MergeSort(int *A, int p, int r) {
	if (p < r) {
		int q = p + (r - p) / 2; // middle
		MergeSort(A, p, q); // first-half
		MergeSort(A, q + 1, r); //second-half
		Merge(A, p, q, r); // merge all together
	}
}
int main(int argc, char **argv) {
	int arraySize;

	cin >> arraySize;
	int* Sequence = new int[arraySize];

	for (int i = 0; i < arraySize; i++)
		cin >> Sequence[i];

	MergeSort(Sequence, 0, arraySize - 1);
	Snapshot(Sequence, arraySize); // for printing

	delete[] Sequence;
}