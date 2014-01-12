#include "sorting.h"
#include <time.h>

void sorting::insertion_sort(array<int>& A) {
	int n = A.size();
	for (int k = 2; k <= n; k++) {
		int x = A[k];
		int i = k - 1;
		while (i >= 1 && x < A[i]) A[i + 1] = A[i], i--;
		A[i + 1] = x;
	}
}

void sorting::merge_sort(array<int>& A, int p, int r) {
	if (p < r - 1) {
		int q = (p + r) / 2;
		merge_sort(A, p, q);
		merge_sort(A, q, r);
		merge(A, p, q, r);
	}
}

void sorting::heap_sort(array<int>& A) {
	heapify(A);
	for (int j = A.size(); j > 1; j--) {
		swap(A, 1, j);
		sift_down(A, 1, j - 1);
	}
}

void sorting::counting_sort(array<int>& A) {
	int n = A.size(), low, high;
	low = high = A[1];
	for (int i = 2; i <= n; i++) {
		if (A[i] < low) low = A[i];
		if (A[i] > high) high = A[i];
	}
	array<int> B(1, n);
	array<int> C(low, high);
	for (int j = low; j <= high; j++) C[j] = 0;
	for (int i = 1; i <= n; i++) C[A[i]]++;
	for (int j = low + 1; j <= high; j++) C[j] += C[j - 1];
	for (int i = n; i > 0; i--) B[C[A[i]]--] = A[i];
	A = B; //(instead of return B)
}

void sorting::radix_sort(array<int>& A) {
	struct element { int bigkey; int key; };
	array<element> newA(1, A.size());
	for (int l = 1; l <= A.size(); l++)
		newA[l].bigkey = A[l], newA[l].key = 0;

	int n = newA.size(), basis = n, high = newA[1].bigkey;
	for (int i = 2; i <= n; i++) if (newA[i].bigkey > high) high = newA[i].bigkey;
	for (int k = 1; k <= high; k *= basis) {
		for (int j = 1; j <= n; j++) newA[j].key = (newA[j].bigkey / k) % basis;

		int low, high;
		low = high = newA[1].key;
		for (int i = 2; i <= n; i++) {
			if (newA[i].key < low) low = newA[i].key;
			if (newA[i].key > high) high = newA[i].key;
		}
		array<element> B(1, n);
		array<int> C(low, high);
		for (int j = low; j <= high; j++) C[j] = 0;
		for (int i = 1; i <= n; i++) C[newA[i].key]++;
		for (int j = low + 1; j <= high; j++) C[j] += C[j - 1];
		for (int i = n; i > 0; i--) B[C[newA[i].key]--] = newA[i];
		
		newA = B;
	}

	for (int l = 1; l <= A.size(); l++)
		A[l] = newA[l].bigkey;
}

void sorting::quick_sort(array<int>& A, int p, int r) {
	if (p < r - 1) {
		int i = partition(A, p, r, (rand() % (r - p)) + p);
		quick_sort(A, p, i);
		quick_sort(A, i + 1, r);
	}
}

void sorting::bubble_sort(array<int>& A) {
	for (int n = A.size(); n > 1; n--)
		for (int i = 1; i < n; i++)
			if (A[i] > A[i + 1])
				swap(A, i, i + 1);
}

//Helpers

void sorting::merge(array<int>& A, int p, int q, int r) {
	array<int> B(p, r - 1);
	int i, j;
	for (i = p; i < q; i++) B[i] = A[i];
	for (j = r; i < r; i++) B[--j] = A[i];
	i = p; j = r - 1;
	for (int k = p; k < r; k++) A[k] = (B[i] < B[j]) ? B[i++] : B[j--];
}

void sorting::sift_down(array<int>& A, int i, int j) {
	while (1) {
		int k = 2 * i;
		if (k > j) break;
		if (k < j && A[k + 1] < A[k]) k++;
		if (A[i] > A[k]) swap(A, i, k), i = k;
		else break;
	}
}

void sorting::heapify(array<int>& A) {
	int n = A.size();
	for (int i = n / 2; i > 0; i--) sift_down(A, i, n);
}

void sorting::swap(array<int>& A, int i, int k) {
	int tmp = A[i];
	A[i] = A[k];
	A[k] = tmp;
}

int sorting::partition(array<int>& A, int p, int r, int t) {
	int x = A[t];
	A[t] = A[p];
	int i = p;
	for (int j = p + 1; j < r; j++) if (A[j] < x) swap(A, ++i, j);
	A[p] = A[i]; A[i] = x;
	return i;
}

//Evaluating
auto sorting::evaluateAlgorithms(array<int>& A, int algorithmToPrintResult) -> std::vector<double> {
	vector<array<int>> copies = {A, A, A, A, A, A, A};

	std::vector<double> out(7);
	clock_t start, end;

	start = clock();
	sorting::insertion_sort(copies[0]);
	end = clock();
	out[0] = (end - start) / (CLOCKS_PER_SEC / 1000);

	start = clock();
	sorting::merge_sort(copies[1], 1, copies[1].size() + 1);
	end = clock();
	out[1] = (end - start) / (CLOCKS_PER_SEC / 1000);

	start = clock();
	sorting::heap_sort(copies[2]);
	end = clock();
	out[2] = (end - start) / (CLOCKS_PER_SEC / 1000);

	start = clock();
	sorting::counting_sort(copies[3]);
	end = clock();
	out[3] = (end - start) / (CLOCKS_PER_SEC / 1000);

	start = clock();
	sorting::radix_sort(copies[4]);
	end = clock();
	out[4] = (end - start) / (CLOCKS_PER_SEC / 1000);

	start = clock();
	sorting::quick_sort(copies[5], 1, copies[5].size() + 1);
	end = clock();
	out[5] = (end - start) / (CLOCKS_PER_SEC / 1000);

	start = clock();
	sorting::bubble_sort(copies[6]);
	end = clock();
	out[6] = (end - start) / (CLOCKS_PER_SEC / 1000);

	if (algorithmToPrintResult > 0) A = copies[algorithmToPrintResult - 1];
	return out;
}