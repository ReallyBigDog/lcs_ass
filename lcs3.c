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

int lcs3(int *a, int n,  int *b, int m, int *c, int l) {
	//write your code here
	int ***lcs_arr = malloc(sizeof(int**) * (n + 1));
	for (int i = 0; i < n + 1; i++) {
		lcs_arr[i] = malloc(sizeof(int*) * (m + 1));
		for (int j = 0; j < m + 1; j++) {
			lcs_arr[i][j] = malloc(sizeof(int) * (l + 1));
			lcs_arr[i][j][0] = 0;
		}
		for (int k = 0; k < l + 1; k++) {
			lcs_arr[i][0][k] = 0;
		}
	}
	for (int j = 0; j < m + 1; j++) {
		for (int k = 0; k < l + 1; k++) {
			lcs_arr[0][j][k] = 0;
		}
	}

	for (int i = 1; i < n + 1; i++) {
		for (int j = 1; j < m + 1; j++) {
			for (int k = 1; k < l + 1; k++) {
				if (a[i - 1] == b[j - 1] && b[j - 1] == c[k - 1]) {
					lcs_arr[i][j][k] = lcs_arr[i - 1][j - 1][k - 1] + 1;
				}
				else {
					lcs_arr[i][j][k] = max(max(lcs_arr[i][j][k - 1], lcs_arr[i][j - 1][k]), lcs_arr[i - 1][j][k]);
				}
			}
		}
	}

	int lcs = lcs_arr[n][m][l];

	for (int i = 0; i < n + 1; i++) {
		for (int j = 0; j < m + 1; j++) {
			free(lcs_arr[i][j]);
		}
	}

	return lcs;
}

int main() {
	int n, m, l;

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

	printf("Enter value of l: ");
	fflush(stdout);
	scanf("%d", &l);

	int * c = malloc(l*sizeof(int));
	printf("Enter %d values for array b:\n", l);
	fflush(stdout);
	for (int i=0; i < l; i++){
		scanf("%d", &c[i]);
	}

	printf("Input sequences are:\n");
	print_array(a, n);
	print_array(b, m);
	print_array(c, l);
	fflush(stdout);

	int lcs = lcs3(a, n, b, m, c, l);
	printf("LCS = %d\n",lcs);

	return 0;
}
