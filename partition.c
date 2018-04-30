#include <stdio.h>
#include "captcha.h"
//declare prototypes
void partition(int height, int width, int pixels[height][width], int partitioned_pixels[height][width]);
void clear_prev_partition(int height, int width, int pixels[height][width], int counter);

void partition(int height, int width, int pixels[height][width], int partitioned_pixels[height][width]){
//declare variables
	int row, col; 
	int startCol; 
	int endCol; 
	int i,j;
	int zeroCounter;
//determine starting column of digit to be examined
	for(col = 0; col<width; col++){
		for(row=height-1; row>-1; row--){
			if(pixels[row][col] == 1){
				startCol = col; 
				col = width;
				row = -1;
				break;
			}
		}
	}

//determine last column of digit to be examined
	for(i = startCol; i<width; i++){
		zeroCounter = 0;
		for(j= height-1; j>-1; j--){
			if(pixels[j][i] == 0){
				zeroCounter = zeroCounter+1;
			}
			if(i == 199 && pixels[j][i] == 1){
				endCol = width; 
				i = width; 
				break; 
			}
		}	
		if(zeroCounter == height){
			endCol = i;
			i = width;
			break;
		}
	}

	//copy pixels of digit to be examined in array partitioned_pixels
		for(int c = 0; c<width; c++){
			for(int x= height-1; x>-1; x--){
				if(c<endCol){ 
					partitioned_pixels[x][c] = pixels[x][c]; 
				}
				else{
					partitioned_pixels[x][c] = 0; 
				}
			}
		}
}

//prototype for function responsible for clearing previously examined digits
void clear_prev_partition(int height, int width, int pixels[height][width], int counter){
//initialise variables
	int row, col; 
	int startCol; 
	int endCol; 
	int i,j;
	int zeroCounter;
//same subsection as the partition function 
	for(col = 0; col<width; col++){
		for(row=height-1; row>-1; row--){
			if(pixels[row][col] == 1){
				startCol = col; 
				col = width;
				row = -1;
				break;
			}
		}
	}

	for(i = startCol; i<width; i++){
		zeroCounter = 0;
		for(j= height-1; j>-1; j--){
			if(pixels[j][i] == 0){
				zeroCounter = zeroCounter+1;
			}
		}	
		if(zeroCounter == height){
			endCol = i;
			i = width;
			break;
		}
	}
//only clear previous partitions if the digits being examined are not the last digit (i.e. 4th digit)
	if(counter != 3){
		for(int c = 0; c<width; c++){
			for(int x= height-1; x>-1; x--){
				if(c<endCol){ 
					pixels[x][c] = 0; 
				}
			}
		}
	}

}