#include <iostream>
using namespace std;

int merge(vector<int> &A, int p, int q, int r) {
	int nl = q - p + 1; // length of A[p:q]
	int nr = r - q;  // length of A[q+1:r]

	vector<int> L(nl), R(nr); 

	for (int i=0;i<nl;i++) { // copy A[p:q] into L[0:nl-1]
		L[i] = A[p+i]; 
	}

	for (int j=0;j<nr;j++) { // copy A[q+1:r] into R[0:nr-1]
		R[j] = A[q+j+1];
	}

	int i = 0, j = 0, k = p;
	int inversions = 0;

	while (i < nl && j < nr) {
		if (L[i] <= R[j]) {
			A[k] = L[i];
			i++;
		} else {
			A[k] = R[j];
			j++;
			inversions++;
		}

		k++;
	}

	while (i < nl) {
		A[k] = L[i];
		i++;
		k++;
	}

	while (j < nr) {
		A[k] = R[j];
		j++;
		k++;
	}

	return inversions;
}

int merge_sort(vector<int> &a, int p, int r) {
	if (p < r) {
		int q = floor((p+r)/2); // Midpoint of A[p:r]

		int left = merge_sort(a, p, q); // recursively sort A[p:q]
		int right = merge_sort(a, q+1, r); // recursively sort A[q+1:r]

		// merge A[p:q] and A[q+1:r] into A[p:r]
		int inv = merge(a, p, q, r) + left + right; 
		return inv;
	} else {
		return 0;
	}
}

int main() {
	vector<int> A = {3, 2, 1};
	int a = 0, b = A.size();
	cout << "#inversions = " << merge_sort(A, a, b-1) << endl;

	for (int el : A) cout << el << " ";
	cout << endl;


	return 0;
}