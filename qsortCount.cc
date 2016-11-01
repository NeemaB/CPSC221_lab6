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

int qc(int n){
	if(n <= 1){
		return 0;
	}else{
		int p = randint(0, n-1);
		return (n-1) + qc(p) + qc(n - 1 - p);
	}
}

int qc_ave(int n){
	if(n <= 1) return 0;
	float sum = 0.0;
	for(int m = 1; m <= n; m++){
		sum += (n-1) + qc_ave(m-1) + qc_ave(n-m);
	}
	return sum / n;
}

		

#define NN 10

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
	// for (int i=0; i<NN; ++i) {
	// 	std::cout << x[i] << " ";
	// }
	sum = sum + comps ;
}
	int comps_qc = qc(NN);
	int comps_qc_ave = qc_ave(NN);

	std::cout << std::endl;
	std::cout << "# of computations: " << sum/100 << std::endl ;
	
	std::cout << "# of computations for qc on array[NN]: " << comps_qc << std::endl ;
	std::cout << "# of computations for qc_ave on array[NN]: " << comps_qc_ave << std::endl;

	delete[] x;
	return 0;
}
