int read_pbm(char filename[], int height, int width, int pixels[height][width]);
int get_pbm_dimensions(char filename[], int *height, int *width);
void print_image(int height, int width, int pixels[height][width]);
void get_bounding_box(int height, int width, int pixels[height][width],
                  int *start_row, int *start_column, int *box_height, int *box_width);
void copy_pixels(int height, int width, int pixels[height][width],
                 int start_row, int start_column, int copy_height, int copy_width,
                 int copy[copy_height][copy_width]);
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
int get_number(float horiBal, float verBal, float blackness, int numBlack, float tallness, float diagonal, float density, int holes, float holeFrac, float horSym, int height, int width);
