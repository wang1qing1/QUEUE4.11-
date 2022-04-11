#include<stdio.h>
int main()
{
	int arr[1000][1000] = { 0 };
	int n = 0, m = 0, k = 0;
	scanf_s("%d%d%d", &n, &m, &k);
	while (m--)
	{
		int i=0, j = 0;
		scanf_s("%d%d", &i, &j);
		arr[i - 1][j - 1] = 3;
	}
	while (k--)
	{
		int i = 0, j = 0;
		scanf_s("%d%d", &i, &j);
		arr[i - 1][j - 1] = 4;
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (arr[i][j] == 4)
			{
				int a = 0, b = 0, c = 0, d = 0;
				i - 2 < 0 ? a = 0 : a = i-2;
				j - 2 < 0 ? b = 0 : b = j-2;
				i + 2 > n-1 ? c = n-1 : c = i+2;
				j + 2 > n-1 ? d = n-1 : d = j+2;
				for (a; a <= c; a++)
				{
					for (b; b <= d; b++)
					{
						if (arr[a][b] == 0)
						{
							arr[a][b] = 1;
						}
					}
				}
			}
			if (arr[i][j] == 3)
			{
				int a = 0, b = 0, c = 0, d = 0;
				i - 2 < 0 ? a = 0 : a = i - 2;
				j - 2 < 0 ? b = 0 : b = j - 2;
				i + 2 > n - 1 ? c = n - 1 : c = i + 2;
				j + 2 > n - 1 ? d = n - 1 : d = j + 2;
				for (a; a <= c; a++)
				{
					if (arr[a][j] == 0)
					{
						arr[a][j] = 1;
					}
				}
				for (b; b <= d; b++)
				{
					if (arr[i][b] == 0)
					{
						arr[i][b] = 1;
					}
				}
				if (i - 1 >= 0 && j - 1 >= 0 && arr[i - 1][j - 1] == 0)
					arr[i - 1][j - 1] = 1;
				if (i - 1 >= 0 && j + 1 <= n - 1 && arr[i - 1][j + 1] == 0)
					arr[i - 1][j + 1] = 1;
				if (i + 1 <= n - 1 && j - 1 >= 0 && arr[i + 1][j - 1] == 0)
					arr[i + 1][j - 1] = 1;
				if (i + 1 <= n - 1 && j + 1 <= n - 1 && arr[i + 1][j + 1] == 0)
					arr[i + 1][j + 1] = 1;

			}
		}
	}
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (arr[i][j] == 0)
			{
				count++;
			}
		}
	}
	printf("%d", count);
	return 0;
}