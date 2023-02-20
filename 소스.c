#pragma warning(disable:4996)
#include <stdio.h>

void SnailArray(int, int[][10]);
void fillRow(int, int[][10], int*, int*, int*);
void fillCol(int, int[][10], int*, int*, int*);
void printArr(int, int[][10]);

int main()
{
	int arr[10][10] = {0, };
	int n=5;

	printf("달팽이 배열의 크기는? : ");
	scanf("%d", &n);

	SnailArray(n, arr);

	printArr(n, arr);

	return 0;
} 

void SnailArray(int n, int arr[][10])
{
	int x = 0, y = 0;
	int cnt = 1;
	int* px = &x, * py = &y;
	int* pcnt = &cnt;

	while (cnt<=n*n)
	{
		fillRow(n, arr, px, py, pcnt);
		if (cnt > n * n)
			break;
		fillCol(n, arr, px, py, pcnt);
	}
}

void fillRow(int n, int arr[][10], int* px, int* py, int* pcnt)
{
	static int row_dir = 1;
	
	do {
		if (arr[*px][*py] != 0)
			*px += row_dir;
		arr[*px][*py] = (*pcnt)++;
		*px += row_dir;
	} while ((0 <= *px < n) && (arr[*px][*py] == 0));
	*px -= row_dir;
	row_dir *= -1;
}

void fillCol(int n, int arr[][10], int* px, int* py, int* pcnt)
{
	static int col_dir = 1;

	do {
		if (arr[*px][*py] != 0)
			*py += col_dir;
		arr[*px][*py] = (*pcnt)++;
		*py += col_dir;
	} while (0 <= *py < n && arr[*px][*py] == 0);
	*px -= col_dir;
	col_dir *= -1;
}

void printArr(int n, int arr[][10])
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			printf("%2d ", arr[i][j]);
		printf("\n");
	}
}
