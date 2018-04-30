#include <stdio.h>
#include "captcha.h"
//main function starts here
int main(int argc, char *argv[]) {
    //declaration of integer and floating point variables 
    int number; 
    int height, width, start_row, start_column, box_width, box_height, holes;
    float horiBal, verBal, blackness, tallness, diagonal, density, holeFrac, horSym;
    float numBlack; 

    //checking valid argument entry in CLI
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <image-file>\n", argv[1]);
        return 1;
    }

    if (get_pbm_dimensions(argv[1], &height, &width) != 1) {
        return 1;
    }
    //declare pixels array
    int pixels[height][width];
    if (read_pbm(argv[1], height, width, pixels)) {
        //get bounding box function is called - determines properties of bounding box
        get_bounding_box(height, width, pixels, &start_row, &start_column, &box_height, &box_width);
        //box_pixels array declared
        int box_pixels[box_height][box_width];
        //copy_pixels function is called - copies bounding box into box_pixels array
        copy_pixels(height, width, pixels, start_row, start_column, box_height, box_width, box_pixels);
        //receive the value of each attribute from the functions written in partition.c 
        horiBal= get_horizontal_balance(box_height, box_width, box_pixels);
        verBal = get_vertical_balance(box_height, box_width, box_pixels);
        blackness = get_blackness(box_height, box_width, box_pixels);
        numBlack = black_count(box_height, box_width, box_pixels);
        tallness = get_tallness(box_height, box_width);
        diagonal = get_diagonal(box_height, box_width);
        density = get_density(box_height, box_width, box_pixels);
        holes = get_holes(box_height, box_width, box_pixels);
        holeFrac = get_holeFrac(box_height, box_width, box_pixels);
        horSym = get_hor_symmetry(box_height, box_width, box_pixels);
        //determines the number based on the attributes - the function get_number is written in partition.c 
        number = get_number(horiBal, verBal, blackness, numBlack, tallness, diagonal, density, holes, holeFrac, horSym, box_height, box_width);
        //prints the number which is predicted by my algorithm
        printf("%d", number);
        printf("\n");
}
    return 0;
}
