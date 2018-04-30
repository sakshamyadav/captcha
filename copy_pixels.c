#include <stdio.h>
#include "captcha.h"
//prototype for copy_pixels function
void copy_pixels(int height, int width, int pixels[height][width],
                 int start_row, int start_column, int copy_height, int copy_width,
                 int copy[copy_height][copy_width]);

void copy_pixels(int height, int width, int pixels[height][width],
                 int start_row, int start_column, int copy_height, int copy_width,
                 int copy[copy_height][copy_width]) {

//variable initialisation/declaration
	int row, column, i, j;
	int arr[height*width];  
	int counter=0;
	int counter2=0; 
//store bounding box pixels in one dimensional array 
	for(i = (copy_height+start_row-1); i>start_row-1; i--){
		for(j = start_column; j<(copy_width+start_column); j++){
			arr[counter] = pixels[i][j]; 
			counter = counter+1; 
		}
	}
//copy bounding box from arr to 2D array 'copy'
	for(row = (copy_height-1); row > -1; row-- ){
		for(column = 0; column< (copy_width); column++ ){
			copy[row][column] = arr[counter2]; 
			counter2 = counter2+1;
		}
	}
}
