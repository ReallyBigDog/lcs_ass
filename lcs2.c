#include <stdio.h>
#include <stdlib.h>

int max(int x, int y) {
	if (x > y) {
		return x;
	}
	return y;
}

void print_array(int *arr, int size){
	for (int i=0; i<size; i++){
		printf("%d ",arr[i]);
	}
	printf("\n");
}

int lcs2(int *a, int n, int *b, int m) {
	//write your code here
	int **lcs_arr = malloc(sizeof(int*) * (n + 1));
	for (int i = 0; i < n + 1; i++) {
		lcs_arr[i] = malloc(sizeof(int) * (m + 1));
		lcs_arr[i][0] = 0;
	}
	for (int i = 0; i < m + 1; i++) {
		lcs_arr[0][i] = 0;
	}

	for (int i = 1; i < n + 1; i++) {
		for (int j = 1; j < m + 1; j++) {
			if (a[i - 1] == b[j - 1]) {
				lcs_arr[i][j] = lcs_arr[i - 1][j - 1] + 1;
			}
			else {
				lcs_arr[i][j] = max(lcs_arr[i][j - 1], lcs_arr[i - 1][j]);
			}
		}
	}

	int lcs = lcs_arr[n][m];

	for (int i = 0; i < n + 1; i++) {
		free(lcs_arr[i]);
	}

	return lcs;
}

int main() {
	int n, m;

	printf("Enter value of n: ");
	fflush(stdout);
	scanf("%d", &n);

	int * a = malloc(n*sizeof(int));
	printf("Enter %d values for array a, separated by spaces:\n", n);
	fflush(stdout);
	for (int i=0; i < n; i++){
		scanf("%d", &a[i]);
	}

	printf("Enter value of m: ");
	fflush(stdout);
	scanf("%d", &m);

	int * b = malloc(m*sizeof(int));
	printf("Enter %d values for array b:\n", m);
	fflush(stdout);
	for (int i=0; i < m; i++){
		scanf("%d", &b[i]);
	}

	printf("Input sequences are:\n");
	print_array(a, n);
	print_array(b, m);
	fflush(stdout);

	int lcs = lcs2(a, n, b, m);
	printf("LCS = %d\n",lcs);

	return 0;
}
