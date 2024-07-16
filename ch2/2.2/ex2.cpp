#include <iostream>
using namespace std;

void print_vector(vector<int> a) {
	for (int el : a) cout << el << " ";
	cout << endl;
}

// Given array A[0:n] sort it by first finding the smallest element of A and exchanging it with
// A[0], then find the smallest element of A[1:n] end exchange it with A[1], etc.
void selection_sort(vector<int> &A) {
	int n = A.size();

	for (int i = 0; i < n-1; i++) {
		int min = 0;

		for (int j = i+1; i < n; i++) {
				if (A[j] < A[min]) {
					min = j;
				}
		}

		swap(A[min], A[i]);
		// print_vector(A);
	}
}

// NOTE
// Loop invariant: at iteration i A[0:i-1] is sorted.
// Selection sort only has to run for the first n-1 elements because at the very end 
// the algorithm has the task of sorting A[n-1:n-1] i.e. we do nothing because the subarray
// has one element.


int main() {
	vector<int> a = {8, 4, 2, 3};
	selection_sort(a);

	cout << "Result: ";
	print_vector(a);
	return 0;
}