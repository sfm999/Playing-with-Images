#include <stdio.h>
#include <math.h>

#define SIZE 15

void print_map(int map[SIZE][SIZE], int laser_y);
void populate_map(int map[SIZE][SIZE]);

void rotate_clockwise(int map[SIZE][SIZE]);
void rotate_anticlockwise(int map[SIZE][SIZE]);

void transpose(int map[SIZE][SIZE]);
void reflect(int map[SIZE][SIZE]);


int main(void)
{
	// Create and populate the map.
	int map[SIZE][SIZE];
	populate_map(map);
	
	
	// Print initial map pre rotation.
	print_map(map, 7);
	// Rotate map.
	rotate_clockwise(map);
	// Print map again to show rotation.
	printf("\nRotated by 90 clockwise: \n");
	print_map(map, 7);
	
	
	printf("\nRotated by 180 anti-clockwise to make it 90 anti clockwise from original position: \n");
	rotate_anticlockwise(map);
	rotate_anticlockwise(map);
	print_map(map, 7);
	
	
	return 0;
}

void rotate_clockwise(int map[SIZE][SIZE])
{
	transpose(map);
	reflect(map);
}

void rotate_anticlockwise(int map[SIZE][SIZE])
{
	reflect(map);
	transpose(map);
}


/*
	What the following to functions do is present an alternative method to rotating a 2d array. It is a zero extra space method,
	and has a time complexity of O(M) where M is the number of cells in the matrix. It has 0(1) Space complexity as we only use
	one data structure and no others.
*/

// Transpose side-by-side elements shifting them to their opposite positions.
// Same as grabbing an image from the bottom left and effectively flipping it using the top right corner as the pivot point.
// If this was an image, its quadrants would be effectively in reverse of their previous orientation.
void transpose(int map[SIZE][SIZE])
{
	int i;
	int j;
	for(i = 0; i < SIZE; i++)
	{
		for(j = 0; j < i; j++) 
		{
			int temp = map[i][j];
			map[i][j] = map[j][i];
			map[j][i] = temp;
		}
	}
}

// Reflect will effectively rearrange opposing column values from each line (e.g. if array is 0 1 2 3 then 0 and 3 will be swapped).
// If the width of the array (length of a row) is odd then for example the array was 0 1 2, we'd just swap 0 and 2 and leave 1.
// If the width is even, then we reverse to 0 1 2 3 and 0 and 3 being swapped, then 1 and 2 being swapped.
// This repeats for the rows i to N-1.
void reflect(int map[SIZE][SIZE])
{
	int i = 0;
	while(i < SIZE)
	{
		int j = 0;
		while(j < SIZE / 2)
		{
			int temp = map[i][j];
			map[i][j] = map[i][SIZE - j - 1];
			map[i][SIZE - j - 1] = temp;
			++j;
		}
		++i;
	}
}

// Simple method to just populate the map.
void populate_map(int map[SIZE][SIZE])
{
	int counter = 0;
	int i = 0;
	while(i < SIZE)
	{
		int j = 0;
		while(j < SIZE)
		{
			map[i][j] = ++counter;
			++j;
		}
		++i;
	}
	
}

// Print the map.
void print_map(int map[SIZE][SIZE], int laser_y)
{
	int i = 0;
	while(i < SIZE)
	{
		if(i == laser_y)
		{
			printf("> ");
		}else{
			printf("  ");
		}
		
		int j = 0;
		while(j < SIZE)
		{
			printf("%5d", map[i][j]);
			j++;
		}
		printf("\n");
		i++;		
	}
}
