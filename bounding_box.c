//Created by Saksham Yadav
//prints a PBM image file 

#include <stdio.h>
#include "captcha.h"
//get_bounding_box prototype
void get_bounding_box(int height, int width, int pixels[height][width],
                  int *start_row, int *start_column, int *box_height, int *box_width);

void get_bounding_box(int height, int width, int pixels[height][width],
                  int *start_row, int *start_column, int *box_height, int *box_width){
//variable initialisation/declaration
int minRight, minLeft, minUp, minDown;
int i, j, k, l, m, n, p, q; 
minUp = 0;
minDown = height - 1; 
minLeft = width-1; 
minRight = 0; 

//determine minimum distance from top of bounding box
for(i=0; i < width; i++){
	for(j=height-1; j > -1; j--){
		if(pixels[j][i] == 1){
			if(j > minUp){
				minUp = j; 
			}
		}		
	}
}

//determine minimum distance from bottom of bounding box
for(k=0; k < width; k++){
	for(l=0; l < height; l++){
		if(pixels[l][k] == 1){
			if(l < minDown){
				minDown = l; 
			}
		}
	}
}

//determine minimum distance from left of bounding box
for(m=0; m< height; m++){
	for(n=0; n<width; n++){
		if(pixels[m][n] == 1){
			if(n<minLeft){
				minLeft = n; 
			}
		}
	}
}

//determine minimum distance from right of bounding box
for(p=0; p<height; p++){
	for(q=width-1; q>-1; q--){
		if(pixels[p][q] == 1){
			if(q>minRight){
				minRight = q; 
			}
		}
	}
}
//store necessary bounding box information in memory
*box_height = minUp - minDown +1; 
*box_width = minRight - minLeft +1;
*start_column = minLeft; 
*start_row = minDown; 

}