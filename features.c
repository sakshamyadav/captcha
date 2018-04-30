#include <stdio.h>
#include "captcha.h"
#include <math.h>
//all necessary prototypes declared -> to determine attributes
float get_horizontal_balance(int height, int width, int pixels[height][width]);
float get_vertical_balance(int height, int width, int pixels[height][width]);
float get_blackness(int height, int width, int pixels[height][width]);
int black_count(int height, int width, int pixels[height][width]);
float get_tallness(int height, int width);
float get_diagonal(int height, int width); 
float get_density(int height, int width, int pixels[height][width]);
int get_holes(int height, int width, int pixels[height][width]);
float get_holeFrac(int height, int width, int pixels[height][width]); 
float get_hor_symmetry(int height, int width, int pixels[height][width]);

//function responsible for determining horizontal balance
float get_horizontal_balance(int height, int width, int pixels[height][width]){

	float colSum=0;
	float blackPix=0; 
	float horizontalBalance;  

	int row, col;

	for(row = (height-1); row>-1; row--){ 
		for(col = 0; col<width; col++){
			if(pixels[row][col] == 1){
				colSum = colSum + col; 
				blackPix = blackPix+1;
			}
		}
	}

	horizontalBalance = (colSum/blackPix+0.5)/width;
	horizontalBalance = roundf(horizontalBalance*1000000.0f)/1000000.0f; 

	return horizontalBalance; 

}
//function responsible for determining vertical balance
float get_vertical_balance(int height, int width, int pixels[height][width]){
	float rowSum=0; 
	float blackPix=0; 
	float verticalBalance; 

	int row, col; 

	for(row = (height-1); row>-1; row--){ 
		for(col = 0; col<width; col++){
			if(pixels[row][col] == 1){
				rowSum = rowSum + row; 
				blackPix = blackPix+1;
			}
		}
	}

	verticalBalance = (rowSum/blackPix+0.5)/height;

	verticalBalance = roundf(verticalBalance*1000000.0f)/1000000.0f;
	return verticalBalance; 

}
//function responsible for determining blackness 
float get_blackness(int height, int width, int pixels[height][width]){
	float product = height*width; 
	int row,col; 
	float blackCount=0;
	float blackness; 

	for(row = (height-1); row>-1; row--){ 
		for(col = 0; col<width; col++){
			if(pixels[row][col] == 1){
				blackCount = blackCount + 1; 
			}
		}
	}

	blackness = blackCount/product; 
	blackness = roundf(blackness*1000000.0f)/1000000.0f;


	return blackness; 

}
//function responsible for determining number of pixels
int black_count(int height, int width, int pixels[height][width]){
	int numBlack = 0; 
	int row, col; 

	for(row = (height-1); row>-1; row--){ 
		for(col = 0; col<width; col++){
			if(pixels[row][col] == 1){
				numBlack = numBlack + 1; 
			}
		}
	}

	return numBlack; 
}
//function responsible for determining tallness
float get_tallness(int height, int width){
	float heightfloat = (float)height;
	float widthfloat = (float)width; 
	float tallness = heightfloat/widthfloat;

	tallness = roundf(tallness*1000000.0f)/1000000.0f;

	return tallness; 
}
//function responsible for determining diagonal distance of bounding box
float get_diagonal(int height, int width){
	float heightfloat = (float)height;
	float widthfloat = (float)width; 

	float hSquare, wSquare, diag; 

	hSquare = pow(heightfloat, 2); 
	wSquare = pow(widthfloat, 2);

	diag = sqrt(hSquare+wSquare);
	diag = roundf(diag*1000000.0f)/1000000.0f;

	return diag; 

}
//function responsible for determining density of digit
float get_density(int height, int width, int pixels[height][width]){
	float numBlack = 0; 
	int row, col; 
	float density; 
	float heightfloat = (float)height;
	float widthfloat = (float)width; 

	for(row = (height-1); row>-1; row--){ 
		for(col = 0; col<width; col++){
			if(pixels[row][col] == 1){
				numBlack = numBlack + 1; 
			}
		}
	}

	density = numBlack/(heightfloat*widthfloat);
	density = roundf(density*1000000.0f)/1000000.0f;

	return density; 
}
//function responsible for determining number of holes in digit
int get_holes(int height, int width, int pixels[height][width]){
	int row, col; 
	int i,j;
	int k,l; 
	int holeCount =0;
	int m,n;
	int a,s;
	int f,g; 
	int x,c;

	for(row = height-1; row>-1; row--){
		for(col =0; col<width; col++){
			if((row==height-1 || col==0 || col==width-1 || row==0) && (pixels[row][col]==0)){
				pixels[row][col] = 3; 
			}
		}
	}

	for(i = height-2; i>0; i--){
		for(j = 1; j < width-1; j++){
			if((pixels[i][j] == 0 && (pixels[i+1][j] == 3 || pixels[i][j+1] == 3 || pixels[i][j-1] == 3 || pixels[i-1][j] == 3))){
				pixels[i][j] = 3;
			}
		}
	}

	for(m = 1; m<height-2; m++){
		for(n = 1; n < width-1; n++){
			if((pixels[m][n] == 0 && (pixels[m+1][n] == 3 || pixels[m][n+1] == 3 || pixels[m][n-1] == 3 || pixels[m-1][n] == 3))){
				pixels[m][n] = 3;
			}
		}
	}

	for(a = 1; a<height-2; a++){
		for(s = width-1; s > 1; s--){
			if((pixels[a][s] == 0 && (pixels[a+1][s] == 3 || pixels[a][s+1] == 3 || pixels[a][s-1] == 3 || pixels[a-1][s] == 3))){
				pixels[a][s] = 3;
			}
		}
	}

	for(f = height-2; f>0; f--){
		for(g = width-1; g > 1; g--){
			if((pixels[f][g] == 0 && (pixels[f+1][g] == 3 || pixels[f][g+1] == 3 || pixels[f][g-1] == 3 || pixels[f-1][g] == 3))){
				pixels[f][g] = 3;
			}
		}
	}


	for(x = height-1; x>-1; x--){
		for(c =0; c<width; c++){
			if(pixels[x][c] == 0){
				while(pixels[x][c] != 1){
					x--; 
				}
				if(pixels[x][c] == 1){
					holeCount = holeCount+1; 
					x=x-2;
					break; 
				}
			}
		}
	}


	return holeCount; 
}
//function responsible for determining ratio of hole pixels to area of bounding box
float get_holeFrac(int height, int width, int pixels[height][width]){ 

	int row, col; 
	int i,j;
	int k,l; 
	float whiteCount =0;
	int m,n;
	int a,s;
	int f,g; 
	int x,c;
	float heightfloat = (float)height;
	float widthfloat = (float)width; 
	float holeFrac; 

	for(row = height-1; row>-1; row--){
		for(col =0; col<width; col++){
			if((row==height-1 || col==0 || col==width-1 || row==0) && (pixels[row][col]==0)){
				pixels[row][col] = 3; 
			}
		}
	}

	for(i = height-2; i>0; i--){
		for(j = 1; j < width-1; j++){
			if((pixels[i][j] == 0 && (pixels[i+1][j] == 3 || pixels[i][j+1] == 3 || pixels[i][j-1] == 3 || pixels[i-1][j] == 3))){
				pixels[i][j] = 3;
			}
		}
	}

	for(m = 1; m<height-2; m++){
		for(n = 1; n < width-1; n++){
			if((pixels[m][n] == 0 && (pixels[m+1][n] == 3 || pixels[m][n+1] == 3 || pixels[m][n-1] == 3 || pixels[m-1][n] == 3))){
				pixels[m][n] = 3;
			}
		}
	}

	for(a = 1; a<height-2; a++){
		for(s = width-1; s > 1; s--){
			if((pixels[a][s] == 0 && (pixels[a+1][s] == 3 || pixels[a][s+1] == 3 || pixels[a][s-1] == 3 || pixels[a-1][s] == 3))){
				pixels[a][s] = 3;
			}
		}
	}

	for(f = height-2; f>0; f--){
		for(g = width-1; g > 1; g--){
			if((pixels[f][g] == 0 && (pixels[f+1][g] == 3 || pixels[f][g+1] == 3 || pixels[f][g-1] == 3 || pixels[f-1][g] == 3))){
				pixels[f][g] = 3;
			}
		}
	}

	for(x = height-1; x>-1; x--){
		for(c =0; c<width; c++){
			if(pixels[x][c] == 0){
				whiteCount = whiteCount +1; 
			}
		}
	}

	holeFrac = whiteCount/(heightfloat*widthfloat);
holeFrac = roundf(holeFrac*1000000.0f)/1000000.0f;

	return holeFrac; 

}
//function responsible for determining horizontal symmetry
float get_hor_symmetry(int height, int width, int pixels[height][width]){
	int row, col; 
	float topHalf=0; 
	float bottomHalf=0;
	float horSym;  

	for(row = (height-1); row>-1; row--){ 
		for(col = 0; col<width; col++){
			if(row>(height/2) && pixels[row][col] == 1){
				topHalf = topHalf+1; 
			}
			else if(pixels[row][col] == 1){
				bottomHalf = bottomHalf +1; 
			}
		}
	}

	horSym = topHalf/bottomHalf; 
	horSym = roundf(horSym*1000000.0f)/1000000.0f;

	return horSym;

}



