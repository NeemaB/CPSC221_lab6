#include <iostream>
#include <ctime>
#include <cstdlib>

int * x;
int comps=0;
int sum = 0 ;

void swap(int & a, int & b) {
	int tmp = a;
	a = b;
	b = tmp;
}

int randint(int a, int b) {
	return a + (rand() % (b - a + 1));
}

void quicksort(int a, int b) {
	if (a >= b) return;
	int p = randint(a,b); // pivot
	swap(x[a], x[p]);
	int m = a;
	int i;
	// in-place partition:
	for (i = a+1; i <= b; i++) {
		comps++ ;
		if (x[i] < x[a])
			swap(x[++m], x[i]);
	}
	swap(x[a],x[m]);
	quicksort(a, m-1);
	quicksort(m+1, b);
}

#define NN 1000

int main(int argc, char *argv[]) {
	srand(time(0));

	// change the following code
for(int k = 0 ; k < 100 ; k++){
	comps = 0 ;
	x = new int[NN];
	for (int i=0; i<NN; ++i) {
		x[i] = rand() % NN;
	}
	
	quicksort(0, NN-1);
	for (int i=0; i<NN; ++i) {
		std::cout << x[i] << " ";
	}
	std::cout << std::endl;

	quicksort(0, NN-1);
	// for (int i=0; i<NN; ++i) {
	// 	std::cout << x[i] << " ";
	// }
	sum = sum + comps ;
}
	std::cout << std::endl;
	std::cout << "# of computations:" << sum/100 ;

	delete[] x;
	return 0;
}
