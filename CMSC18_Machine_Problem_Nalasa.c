// OKAY I JUST HAD A GOOD IDEA TODAY AND ITS TIME TO PUT IT TO USE
// REMEMBER THAT "DRAW A DUMB TRIANGLE WITH HEIGHT X".c 
// OKAY SO WHAT ABOUT "DRAW A PAROL WITH RADIUS X".c

// THIS IS: "DRAW A PAROL WITH RADIUS X".c by haskel nalasa 2022-06042

#include <stdio.h>
#include <math.h>

// geddit guys - none dimensional? not 0 dimensional because C wont let me do that?
typedef struct none_dimensional{
    int x;
    int y;
} point;

// defines a bunch of lines and points we'll use in a bit
typedef struct one_dimensional{
    point endpoint_1;
    point endpoint_2;
    float slope = (endpoint_1.y - endpoint_2.y) / (endpoint_1.x - endpoint_2.x);
} line;

int square(int i){
    return i*i;
}

int round_good(float f){
    printf("%ld <- %f -> %ld", floor(f), f, ceil(f));
    return ((f - floor(f)) < (ceil(f) - f)) ? floor(f) : ceil(f);
}

void draw_Graph(int radius, char graph[radius][radius]){
    for(int y = 0; y < radius*2+1; y++){
        printf("\n");
        for(int x = 0; x < radius*2+1; x++){
            printf("%c", graph[y][x]);
        }
    }
}

int main(){

    int radius;

    printf("DRAW A PAROL WITH RADIUS X: A MACHINE PROBLEM SUBMISSION BY HASKEL NALASA\n");
    printf(" NOT A PENTAGRAM DESPITE THEIR SIMILARITIES THIS IS A CHRISTMAS THEMED ASSIGNMENT\n");
    printf("NOTE: RESOLUTION IMPROVES WITH INCREASING RADII???");
    printf("INPUT RADIUS (POSITIVE INTEGER): ");
    scanf("%d", &radius);

    char graph[2*radius+1][2*radius+1];
    
    graph[0][1] = '3';
    printf("%c", graph[0][1]);
    
    for(int y = 0; y < radius*2+1; y++){
        for(int x = 0; x < radius*2+1; x++){
            graph[y][x] = '.';
        }
    }
    
    // okay the formula for a circle is (x-h)^2 + (y-i)^2 = R^2
    // rearranging the terms, we get (y-i)^2 = R^2 - (x-h)^2
    // then, y-i = +/- sqrt(R^2 - (x-h)^2)
    // where y = i +/- sqrt(R^2 - (x-h)^2)
    // therefore, we can cycle through all x values from 0 to radius*2 + 1
    // and find all coordinates to fill with...something

    for(int x = 0; x < radius*2+1; x++){
        // printf("\n(%d, %d)", x, (int)round(radius + sqrt(square(radius) - square(x-radius))));
        // printf("\n(%d, %d)", x, (int)round(radius - sqrt(square(radius) - square(x-radius))));
        graph[(int)round(radius + sqrt(square(radius) - square(x-radius)))][x] = '#';
        graph[(int)round(radius - sqrt(square(radius) - square(x-radius)))][x] = '#';
    }

    // swap the values for a second pass - literally the same thing lmao cause they're interchangable
    // makes the circle more "continuous" i guess?
    for(int y = 0; y < radius*2+1; y++){
        // printf("\n(%d, %d)", (int)round(radius + sqrt(square(radius) - square(y-radius))), y);
        // printf("\n(%d, %d)", (int)round(radius - sqrt(square(radius) - square(y-radius))), y);
        graph[y][(int)round(radius + sqrt(square(radius) - square(y-radius)))] = '#';
        graph[y][(int)round(radius - sqrt(square(radius) - square(y-radius)))]= '#';
    }
    
    for(int y = 0; y < radius*2+1; y++){
        printf("\n");
        for(int x = 0; x < radius*2+1; x++){
            printf("%c", graph[y][x]);
        }
    }

    point point_A, point_B, point_C, point_D, point_E;

    point_A.x = (int)round(radius * cos(18) + radius);
    point_A.y = (int)round(radius * sin(18) - radius);

    point_B.x = (int)round(radius * cos(90) + radius);
    point_B.y = (int)round(radius * sin(90) - radius);

    point_C.x = (int)round(radius * cos(162) + radius);
    point_C.y = (int)round(radius * sin(162) - radius);

    point_D.x = (int)round(radius * cos(234) + radius);
    point_D.y = (int)round(radius * sin(234) - radius);

    point_E.x = (int)round(radius * cos(306) + radius);
    point_E.y = (int)round(radius * sin(306) - radius);

    // endpoints of the star, 72 degrees apart, defined through pure math

    line segment_AC, segment_AD, segment_BD, segment_BE, segment_CE;

    segment_AC.endpoint_1 = point_A;
    segment_AC.endpoint_2 = point_C;
    
    segment_AD.endpoint_1 = point_A;
    segment_AD.endpoint_2 = point_D;

    segment_BD.endpoint_1 = point_B;
    segment_BD.endpoint_2 = point_D;

    segment_BE.endpoint_1 = point_B;
    segment_BE.endpoint_2 = point_E;

    segment_CE.endpoint_1 = point_C;
    segment_CE.endpoint_2 = point_E;

    return 0;
}