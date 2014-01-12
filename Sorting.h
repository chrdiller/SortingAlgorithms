#include <vector>

using std::vector;

namespace sorting {
	template<typename T>
	class array {
	private:
		vector<T> data;
		int offset = 1;
	public:
		array(vector<T> inData) : data(inData) {}
		array(int begin, int end) {
			offset = begin;
			data = vector<T>((vector<T>::size_type)(end - begin + 1));
		}

		int size() {
			return data.size();
		}

		T& array<T>::operator[](int i) {
			return data[i-offset];
		}
	};

	void insertion_sort(array<int>& A);
	void merge_sort(array<int>& A, int p, int r);
	void heap_sort(array<int>& A);
	void counting_sort(array<int>& A);
	void radix_sort(array<int>& A);
	void quick_sort(array<int>& A, int p, int r);
	void bubble_sort(array<int>& A);

	//Helpers

	void merge(array<int>& A, int p, int q, int r);
	void sift_down(array<int>& A, int i, int j);
	void heapify(array<int>& A);
	void swap(array<int>& A, int i, int k);
	int partition(array<int>& A, int p, int r, int t);

	//Evaluating
	std::vector<double> evaluateAlgorithms(array<int>& A, int algorithmToPrintResult);
}