#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int findWay(char **matrix, int x, int y, int *xy)
{
	matrix[x][y] = '#';
	if(x == xy[0]-1 && y == xy[1]-1)
	{
		matrix[x][y] = 'O';
		return 1;
	}
	else
	{
		if(x+1 < xy[0] && matrix[x+1][y] == '.' && findWay(matrix,x+1,y,xy))
		{
			matrix[x][y] = 'v';
			return 1;
		}
		if(x-1 >= 0 && matrix[x-1][y] == '.' && findWay(matrix,x-1,y,xy))
		{
			matrix[x][y] = '^';
			return 1;
		}
		if(y+1 < xy[1] && matrix[x][y+1] == '.' && findWay(matrix,x,y+1,xy))
		{
			matrix[x][y] = '>';
			return 1;
		}
		if(y-1 >= 0 && matrix[x][y-1] == '.' && findWay(matrix,x,y-1,xy))
		{
			matrix[x][y] = '<';
			return 1;
		}
		matrix[x][y] = '.';
		return 0;
	}
}

int main()
{
	int xy[2], i, j;
	char **matrix;
	scanf("%d%d", &xy[0], &xy[1]);
	matrix = (char**)malloc(sizeof(char*)*xy[0]);

	for (i = 0; i < xy[0]; i++)
		matrix[i] = (char*)malloc(sizeof(char)*xy[1]);

	for (i = 0; i < xy[0]; i++)
		for (j = 0; j < xy[1]; ++j)
			scanf(" %c", &matrix[i][j]);

	findWay(matrix,0,0,xy);

	for (i = 0; i < xy[0]; i++)
	{
		for (j = 0; j < xy[1]; j++)
			printf("%c", matrix[i][j]);
		printf("\n");
	}

	for (i = 0; i < xy[0]; i++)
		free(matrix[i]);
	free(matrix);
	return 0;
}