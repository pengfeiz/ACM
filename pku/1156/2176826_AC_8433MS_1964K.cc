#include <stdio.h>

#define MAX 700

int map[MAX][MAX];
int rowMin[MAX], rowMax[MAX];

int main(int argc, char* argv[])
{
	int U, V, C, i, j, leftCol, rightCol, firstRow, lastRow, maxCol, res, oneLine, nowMin, nowMax, nowArea;
	scanf("%d %d %d", &U, &V, &C);
	for (i = 0; i < V; i++)
		for (j = 0; j < U; j++)
			scanf("%d", &map[i][j]);
	res = 0;
	for (leftCol = 0; leftCol < U; leftCol++)
	{
		maxCol = U - leftCol;
		if (maxCol > 100) maxCol = 100;
		if (maxCol * V <= res) break;
		for (i = 0; i < V; i++)
			rowMin[i] = rowMax[i] = map[i][leftCol];
		for (rightCol = leftCol; rightCol < U && rightCol - leftCol + 1 <= 100; rightCol++)
		{
			for (i = 0; i < V; i++)
			{
				if (map[i][rightCol] < rowMin[i]) rowMin[i] = map[i][rightCol];
				if (map[i][rightCol] > rowMax[i]) rowMax[i] = map[i][rightCol];
			}
			oneLine = rightCol - leftCol + 1;
			for (firstRow = 0; firstRow < V; firstRow++)
			{
				if (oneLine * (V - firstRow) <= res) break;
				nowMin = rowMin[firstRow];
				nowMax = rowMax[firstRow];
				nowArea = 0;
				for (lastRow = firstRow; lastRow < V; lastRow++)
				{
					if (rowMax[lastRow] - rowMin[lastRow] > C)
					{
						firstRow = lastRow;
						break;
					}
					if (rowMin[lastRow] < nowMin) nowMin = rowMin[lastRow];
					if (rowMax[lastRow] > nowMax) nowMax = rowMax[lastRow];
					if (nowMax - nowMin > C) break;
					nowArea += oneLine;
				}
				if (nowArea > res) res = nowArea;
			}
		}
	}
	printf("%d\n", res);
	return 0;
}