#include "sorting.h"
#include <iostream>

using std::cin; 
using std::cout;
using std::endl;

int main(int argc, char ** argv) {
	cout << "-------------------------------------------------" << endl;
	cout << "SortingAlgorithms - Christian Diller - 12.01.2014" << endl;
	cout << "-------------------------------------------------" << endl;
	cout << "This program evaluates 7 sorting algorithms as described in " << endl << " T. Hagerup, Vorlesungsskript Informatik 3:" << endl;
	cout << "insertion_sort(1), merge_sort(2), heap_sort(3), counting_sort(4), " << endl << " radix_sort(5), quick_sort(6), bubble_sort(7)" << endl;
	cout << "Enter the length n of the integer sequence (with randoms in [1, n]): ";
	int n;
	cin >> n;
	cout << "Building the sequence ..." << endl;
	std::vector<int> sequence(n);
	for(int i = 0; i < n; i++) sequence[i] = rand() % n + 1;
	cout << "Which algorithm should print its result? (0 = do not print a result): ";
	int c;
	cin >> c;
	cout << "Evaluating algorithms ..." << endl << endl;
	sorting::array<int> sequenceArr(sequence);
	std::vector<double> result = sorting::evaluateAlgorithms(sequenceArr, c);
	if (c != 0) {
		cout << "Your sequence has been sorted: " << endl;
		for (int k = 1; k <= sequenceArr.size(); k++) cout << sequenceArr[k] << " ";
		cout << endl << endl;
	}
	cout << "Results of the evaluation: " << endl;
	cout << "-------------------------------------------------------------------------------" << endl;
	cout << " #\tAlgorithm              Time(ms)            Compared to insertion_sort" << endl;
	cout << "-------------------------------------------------------------------------------" << endl;
	cout << "(1)\tinsertion_sort\t\t" << result[0] << "\t\t\t" << result[0] / result[0] * 100.0 << "%" << endl;
	cout << "(2)\tmerge_sort\t\t" << result[1] << "\t\t\t" << result[1] / result[0] * 100.0 << "%" << endl;
	cout << "(3)\theap_sort\t\t" << result[2] << "\t\t\t" << result[2] / result[0] * 100.0 << "%" << endl;
	cout << "(4)\tcounting_sort\t\t" << result[3] << "\t\t\t" << result[3] / result[0] * 100.0 << "%" << endl;
	cout << "(5)\tradix_sort\t\t" << result[4] << "\t\t\t" << result[4] / result[0] * 100.0 << "%" << endl;
	cout << "(6)\tquick_sort\t\t" << result[5] << "\t\t\t" << result[5] / result[0] * 100.0 << "%" << endl;
	cout << "(7)\tbubble_sort\t\t" << result[6] << "\t\t\t" << result[6] / result[0] * 100.0 << "%" << endl;

	getchar(); getchar();
}
