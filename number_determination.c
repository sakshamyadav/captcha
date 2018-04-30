#include <stdio.h>
#include "captcha.h"
    //function to determine the number based on attributes
int get_number(float horiBal, float verBal, float blackness, int numBlack, float tallness, float diagonal, float density, int holes, float holeFrac, float horSym, int height, int width);

int get_number(float horiBal, float verBal, float blackness, int numBlack, float tallness, float diagonal, float density, int holes, float holeFrac, float horSym, int height, int width){

    int number; 
    if(holeFrac<=0.0113){
        if(verBal<=0.5489){
            if(horiBal<=0.5277){
                if(density<=0.3465){
                    if(horiBal<=0.5004){
                        if(width<=44.5){
                            if(horSym<=0.7459){
                                if(verBal<=0.4783){
                                    number = 1;
                                }
                                else{
                                    number = 5;
                                }
                            }
                            else{
                                number = 1;
                            }
                        }
                        else{
                            number = 5;
                        }
                    }
                    else if(diagonal<= 58.5961){
                        if(blackness <= 0.3371){
                            if(blackness<=0.2856){
                                if(density <= 0.2736){
                                    number = 7;
                                }
                                else if(diagonal<=55.3598){
                                    number = 2; 
                                }
                                else{
                                    number = 5;
                                }
                            }
                            else if(width<=30){
                                number = 1;
                            }
                            else{
                                number = 3;
                            }
                        }
                        else{
                            number = 5;
                        }
                    }
                    else{
                        number = 2;
                    }
                }
                else if(horSym<=1.0063){
                    if(blackness <= 0.4854){
                        if(tallness <= 1.7963){
                            if(blackness <= 0.4566){
                                if(verBal <= 0.4536){
                                    number = 5; 
                                }
                                else if(horiBal <= 0.5233){
                                    if(numBlack <= 568.5){
                                        if(density <= 0.3661){
                                            if(tallness <= 1.369){
                                                number = 3;
                                            }
                                            else{
                                                number = 2;
                                            }
                                        }
                                        else if(tallness <= 1.7596){
                                            if(width <= 23.5){
                                                number = 2;
                                            }
                                            else if(density <= 0.3707){
                                                if(diagonal <= 55.9163){
                                                    number = 1;
                                                }
                                                else{
                                                    number = 2;
                                                }
                                            }
                                            else{
                                                number = 1;
                                            }
                                        }
                                        else{
                                            number = 5;
                                        }
                                    }
                                    else if(tallness <= 1.3033){
                                        if(horSym <= 0.9703){
                                            number = 5;
                                        }
                                        else{
                                            number = 1;
                                        }
                                    }
                                    else if(width <= 36.5){
                                        if(height <= 50.5){
                                            number = 2; 
                                        }
                                        else if(verBal <= 0.4926){
                                            number = 2;
                                        }
                                        else if(height <= 53.0){
                                            number = 1;
                                        }
                                        else{
                                            number = 2;
                                        }
                                    }
                                    else{
                                        number = 5; 
                                    }
                                }
                                else{
                                    number = 5;
                                }
                            }
                            else{
                                number = 1;
                            }
                        }
                        else{
                            number = 1;
                        }
                    }
                    else if(height <= 38.0){
                        number = 3;
                    }
                    else if(verBal <= 0.4481){
                        number = 2;
                    }
                    else{
                        number = 5;
                    }
                }
                else if(verBal <= 0.5142){
                    number = 5;
                }
                else if(horSym <= 1.2031){
                    if(horiBal <= 0.509){
                        if(horiBal <= 0.4966){
                            if(blackness <= 0.3574){
                                number = 7;
                            }
                            else if(horiBal <= 0.4759){
                                number = 5;
                            }
                            else{
                                number = 1;
                            }
                        }
                        else{
                            number = 2;
                        }
                    }
                    else if(horiBal <= 0.5245){
                        number = 3;
                    }
                    else{
                        number = 1;
                    }
                }
                else if(numBlack <= 417.0){
                    number = 7;
                }
                else if(blackness <= 0.385){
                    if(tallness <= 1.5031){
                        number = 7;
                    }
                    else{
                        number = 5;
                    }
                }
                else{
                    number = 5;
                }
            }
            else if(width <= 27.5){
                if(density <= 0.5256){
                    if(tallness <= 1.9297){
                        if(horiBal <= 0.5688){
                            if(density <= 0.3635){
                                if(height <= 47.0){
                                    if(blackness <= 0.2799){
                                        number = 1;
                                    }
                                    else if(horiBal <= 0.5613){
                                        number = 2;
                                    }
                                    else if(tallness <= 1.7061){
                                        number = 1;
                                    }
                                    else{
                                        number = 2;
                                    }
                                }
                                else{
                                    number = 1;
                                }
                            }
                            else if(numBlack <= 491.5){
                                if(horSym <= 1.2348){
                                    number = 3;
                                }
                                else{
                                    number = 5;
                                }
                            }
                            else if(diagonal <= 52.6548){
                                number = 1;
                            }
                            else if(horiBal <= 0.5418){
                                number = 5;
                            }
                            else{
                                number = 2;
                            }
                        }
                        else if(horSym <= 0.841){
                            number = 1;
                        }
                        else if(width <= 25.5){
                            number = 1;
                        }
                        else if(numBlack <= 301.5){
                            number = 5;
                        }
                        else if(density <= 0.4452){
                            number = 3;
                        }
                        else{
                            number = 1;
                        }
                    }
                    else if(numBlack <= 559.5){
                        if(density <= 0.43){
                            number =1;
                        }
                        else if(blackness <= 0.4514){
                            number = 3;
                        }
                        else{
                            number = 1;
                        }
                    }
                    else if(horiBal <= 0.5403){
                        number = 2;
                    }
                    else{
                        number = 1;
                    }
                }
                else{
                    number = 3;
                }
            }
            else if(horSym <= 0.8466){
                if(horiBal <= 0.5942){
                    if(tallness <= 1.6228){
                        if(density <= 0.4569){
                            if(diagonal <= 58.4151){
                                if(verBal <= 0.445){
                                    number = 5;
                                }
                                else if(diagonal <= 57.326){
                                    if(horiBal <= 0.5588){
                                        if(diagonal <= 54.8026){
                                            if(diagonal <= 52.0185){
                                                if(blackness <= 0.3643){
                                                    number =2;
                                                }
                                                else{
                                                    number =3;
                                                }
                                            }
                                            else{
                                                number = 5;
                                            }
                                        }
                                        else{
                                            number = 2;
                                        }
                                    }
                                    else{
                                        number = 2;
                                    }
                                }
                                else if(verBal <= 0.4759){
                                    number = 3;
                                }
                                else{
                                    number = 5;
                                }
                            }
                            else if(horiBal <= 0.5387){
                                if(verBal <= 0.4689){
                                    number = 3;
                                }
                                else{
                                    number = 2;
                                }
                            }
                            else{
                                number = 2;
                            }
                        }
                        else if(verBal <= 0.4608){
                            number = 5;
                        }
                        else if(tallness <= 1.318){
                            number = 3;
                        }
                        else if(horSym <= 0.8094){
                            number = 2;
                        }
                        else{
                            number = 1;
                        }
                    }
                    else if(horiBal <= 0.5495){
                        number = 1;
                    }
                    else{
                        number = 3; 
                    }
                }
                else if(horSym <= 0.824){
                    if(horSym <= 0.6745){
                        if(horSym <= 0.5617){
                            number = 3;
                        }
                        else{
                            number = 1;
                        }
                    }
                    else if(height <= 46.0){
                        number = 3;
                    }
                    else if(numBlack <= 673.5){
                        if(horiBal <= 0.6551){
                            number =2; 
                        }
                        else{
                            number = 3;
                        }
                    }
                    else if(horSym <= 0.7055){
                        number = 2;
                    }
                    else{
                        number = 3;
                    }
                }
                else{
                    number = 1;
                }
            }
            else if(density <= 0.4256){
                if(horiBal <= 0.5732){
                    if(verBal <= 0.4805){
                        if(horiBal <= 0.5326){
                            number = 1;
                        }
                        else{
                            number = 5; 
                        }
                    }
                    else if(horSym <= 0.9863){
                        number = 2; 
                    }
                    else if(verBal <= 0.5138){
                        if(numBlack <= 624.5){
                            if(horSym <= 1.0236){
                                if(verBal <= 0.4902){
                                    number = 5; 
                                }
                                else if(horSym <= 1.0016){
                                    number = 2;
                                }
                                else if(horSym <= 1.009){
                                    number = 3; 
                                }
                                else{
                                    number = 2; 
                                }
                            }
                            else if(numBlack <= 497.0){
                                number = 3;
                            }
                            else{
                                number = 5; 
                            }
                        }
                        else{
                            number = 2;
                        }
                    }
                    else if(diagonal <= 60.44){
                        if(diagonal <= 56.5198){
                            if(tallness <= 1.5092){
                                number = 3; 
                            }
                            else if(numBlack <= 434.5){
                                number = 2;
                            }
                            else if(verBal <= 0.526){
                                number = 5;
                            }
                            else if(numBlack <= 500.5){
                                number = 3;
                            }
                            else{
                                number = 7;
                            }
                        }
                        else if(height <= 51.0){
                            number = 2; 
                        }
                        else{
                            number = 3;
                        }
                    }
                    else if(numBlack <= 908.5){
                        number = 7; 
                    }
                    else{
                        number = 3; 
                    }
                }
                else if(height <= 47.5){
                    if(width <= 28.5){
                        if(blackness <= 0.365){
                            number = 1;
                        }
                        else if(numBlack <= 507.5){
                            number = 3; 
                        }
                        else{
                            number = 5; 
                        }
                    }
                    else if(diagonal <= 45.7755){
                        number = 5; 
                    }
                    else{
                        number = 3; 
                    }
                }
                else if(tallness <= 1.5303){
                    number = 2; 
                }
                else if(numBlack <= 637.5){
                    if(horSym <= 1.0869){
                        number = 3; 
                    }
                    else if(height <= 50.5){
                        number = 2; 
                    }
                    else{
                        number = 3; 
                    }
                }
                else if(height <= 54.5){
                    number = 1; 
                }
                else{
                    number = 7; 
                }
            }
            else if(verBal <= 0.5394){
                if(horiBal <= 0.5313){
                    if(horSym <= 1.0597){
                        number = 2; 
                    }
                    else{
                        number = 5; 
                    }
                }
                else if(horSym <= 1.1816){
                    if(numBlack <= 1009.0){
                        if(verBal <= 0.4837){
                            if(horiBal <= 0.5801){
                                number = 5;
                            }
                            else{
                                number = 3; 
                            }
                        }
                        else if(horiBal <= 0.5365){
                            if(horiBal <= 0.5348){
                                number = 3; 
                            }
                            else{
                                number = 5; 
                            }
                        }
                        else{
                            number = 3; 
                        }
                    }
                    else{
                        number = 5; 
                    }
                }
                else{
                    number = 2;
                }
            }
            else if(numBlack <= 882.0){
                number = 5; 
            }
            else{
                number = 2; 
            }
        }
        else if(blackness <= 0.4342){
            if(horSym <= 1.1622){
                number = 2; 
            }
            else if(verBal <= 0.5647){
                if(horSym <= 1.4811){
                    number = 7; 
                }
                else if(tallness <= 1.8958){
                    number = 5; 
                }
                else{
                    number = 7; 
                }
            }
            else{
                number = 7; 
            }
        }
        else if(tallness <= 1.6854){
            number = 3; 
        }
        else if(numBlack <= 425.0){
            number = 1; 
        }
        else if(verBal <= 0.5614){
            number = 2; 
        }
        else{
            number = 7; 
        }
    }
    else if(holeFrac <= 0.1016){
        if(horiBal <= 0.5084){
            if(density <= 0.4303){
                number = 4; 
            }
            else if(horiBal <= 0.4821){
                if(holeFrac <= 0.0515){
                    number = 4; 
                }
                else if(holeFrac <= 0.0874){
                    number = 6; 
                }
                else if(density <= 0.6017){
                    if(density <= 0.4756){
                        number = 4; 
                    }
                    else if(horSym <= 1.0903){
                        number = 6; 
                    }
                    else{
                        number = 9; 
                    }
                }
                else{
                    number = 8; 
                }
            }
            else if(horSym <= 0.9627){
                if(density <= 0.6498){
                    if(horiBal <= 0.4876){
                        number = 8; 
                    }
                    else if(blackness <= 0.4901){
                        number = 4; 
                    }
                    else if(holeFrac <= 0.0624){
                        if(width <= 34.5){
                            number = 4; 
                        }
                        else{
                            number = 6; 
                        }
                    }
                    else{
                        number = 6; 
                    }
                }
                else{
                    number = 9; 
                } 
            }
            else if(blackness <= 0.6436){
                number = 9; 
            }
            else{
                number = 6; 
            }
        }
        else if(horSym <= 0.8967){
            if(density <= 0.549){
                if(tallness <= 0.9884){
                    number = 9; 
                }
                else if(height <= 53.5){
                    number = 4; 
                }
                else if(horiBal <= 0.5466){
                    number = 8; 
                }
                else{
                    number = 4; 
                }
            }
            else if(holeFrac <= 0.0714){
                if(holeFrac <= 0.0527){
                    number = 4; 
                }
                else if(diagonal <= 60.2576){
                    number = 9; 
                }
                else{
                    number = 4; 
                }
            }
            else{
                number = 8; 
            }
        }
        else if(holeFrac <= 0.06){
            if(tallness <= 1.0701){
                number = 9; 
            }
            else{
                number = 4; 
            }
        }
        else if(numBlack <= 516.0){
            number = 4; 
        }
        else if(holes <= 1.5){
            number = 9; 
        }
        else if(width <= 35.5){
            number = 8; 
        }
        else{
            number = 9; 
        }
    }
    else if(holes <= 1.5){
        if(holeFrac <= 0.229){
            if(horiBal <= 0.5128){
                if(blackness <= 0.5445){
                    if(horSym <= 1.2249){
                        if(horiBal <= 0.4934){
                            if(tallness <= 1.2985){
                                if(horSym <= 0.8299){
                                    number = 9; 
                                }
                                else{
                                    number = 6; 
                                }
                            }
                            else{
                                number = 6; 
                            }
                        }
                        else if(verBal <= 0.5039){
                            if(height <= 40.5){
                                number = 0; 
                            }
                            else{
                                number = 6; 
                            }
                        }
                        else{
                            number = 9; 
                        }
                    }
                    else{
                        number = 9; 
                    }
                }
                else{
                    number = 0; 
                }
            }
            else if(density <= 0.5887){
                if(blackness <= 0.3093){
                    number = 4; 
                }
                else if(holeFrac <= 0.1148){
                    if(width <= 30.0){
                        number = 4; 
                    }
                    else{
                        number = 9; 
                    }
                }
                else{
                    number = 9; 
                }
            }
            else if(height <= 49.5){
                number = 0; 
            }
            else{
                number = 9; 
            }
        }
        else if(horiBal <= 0.538){
            number = 0; 
        }
        else{
            number = 9; 
        }
    }
    else if(holes <= 2.5){
        if(horSym <= 0.6506){
            number = 6; 
        }
        else if(holeFrac <= 0.2878){
            if(holeFrac <= 0.1968){
                if(holeFrac <= 0.1403){
                    if(blackness <= 0.4185){
                        if(horiBal <= 0.4919){
                            number = 6; 
                        }
                        else{
                            number = 9; 
                        }
                    }
                    else if(horSym <= 1.1177){
                        if(numBlack <= 789.0){
                            if(numBlack <= 755.0){
                                number = 8; 
                            }
                            else{
                                number = 0; 
                            }
                        }
                        else{
                            number = 8; 
                        }
                    }
                    else{
                        number = 0; 
                    }
                }
                else if(numBlack <= 677.0){
                    if(horiBal <= 0.4804){
                        if(holeFrac <= 0.1681){
                            number = 6; 
                        }
                        else{
                            number = 9; 
                        }
                    }
                    else if(blackness <= 0.3844){
                        number = 9; 
                    }
                    else if(diagonal <= 53.6563){
                        number = 8; 
                    }
                    else{
                        number = 0; 
                    }
                }
                else if(height <= 55.5){
                    number = 0; 
                }
                else{
                    number = 8; 
                }
            }
            else if(tallness <= 1.0762){
                if(tallness <= 1.0286){
                    number = 8; 
                }
                else{
                    number = 0; 
                }
            }
            else{
                number = 8; 
            }
        }
        else if(width <= 28.5){
            if(tallness <= 1.4258){
                number = 0; 
            }
            else{
                number = 8; 
            }
        }
        else if(horiBal <= 0.5371){
            number = 0; 
        }
        else{
            number = 8; 
        }
    }
    else if(density <= 0.4965){
        if(verBal <= 0.5252){
            if(holeFrac <= 0.396){
                number = 8; 
            }
            else{
                number =0; 
            }
        }
        else if(numBlack <= 384.5){
            number = 4; 
        }
        else{
            number = 0; 
        }
    }
    else if(holeFrac <= 0.1254){
        number = 8; 
    }
    else if(verBal <= 0.4854){
        if(width <= 33.0){
            number = 8; 
        }
        else{
            number = 0; 
        }
    }
    else{
        number = 0; 
    }


    return number; 
}

