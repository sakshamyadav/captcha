#include <stdio.h>
#include "captcha.h"

//main function 
int main(int argc, char *argv[]) {
    int number; 
    int height, width, start_row, start_column, box_width, box_height, holes;
    float horiBal, verBal, blackness, tallness, diagonal, density, holeFrac, horSym;
    int numBlack;
    int captcha[4];


    if (argc < 2) {
        fprintf(stderr, "Usage: %s <image-file>\n", argv[0]);
        return 1;
    }

    if (get_pbm_dimensions(argv[1], &height, &width) != 1) {
        return 1;
    }

//refer to crack_digit.c for most of what is below

    int pixels[height][width];
    if (read_pbm(argv[1], height, width, pixels)) {

        //loop four times to read all four digits
        for(int i=0; i<4; i++){

            int partitioned_pixels[height][width];
            //partition function written in partition.c partitions the pbm file into 4 individual digits
            partition(height, width, pixels, partitioned_pixels); 

            get_bounding_box(height, width, partitioned_pixels, &start_row, &start_column, &box_height, &box_width);

            int box_pixels[box_height][box_width];
            copy_pixels(height, width, partitioned_pixels, start_row, start_column, box_height, box_width, box_pixels);

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

            number = get_number(horiBal, verBal, blackness, numBlack, tallness, diagonal, density, holes, holeFrac, horSym, box_height, box_width);
            //store the predicted number into captcha array 
            captcha[i] = number; 
            //clear the digit which has just been determined from the array pixels, i.e. turn all '1' to '0'
            clear_prev_partition(height, width, pixels, i);
    }
    
}
//loop through the captcha array four times to read it's contents, i.e. the four digit captcha
    for(int j = 0; j<4; j++){
        printf("%d", captcha[j]);
    }
    printf("\n");
    return 0;
}
