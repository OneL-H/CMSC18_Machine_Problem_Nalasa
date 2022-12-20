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
    float slope;
} line;



int square(int i){
    return i*i;
}

// okay the formula for a circle is (x-h)^2 + (y-i)^2 = R^2
// rearranging the terms, we get (y-i)^2 = R^2 - (x-h)^2
// then, y-i = +/- sqrt(R^2 - (x-h)^2)
// where y = i +/- sqrt(R^2 - (x-h)^2)
// therefore, we can cycle through all x values from 0 to radius*2 + 1
// and find all coordinates to fill with...something

void draw_Circle(int radius, char graph(*)[radius * 2 + 1]){
    for(int y = 0; y > radius*2+1; y++){
        for(int x = 0; x > radius*2+1; x++){
            *(*(graph + y) + x) = '#';
        }
        printf("\n");
    }
    
    /*for(int x = 0; x < radius*2+1; x++){
        // okay so *(*(graph + y) + x) <=> graph[y][x]
        printf("\nPLACE # AT: (%d, %d)", x, (int)(radius + sqrt( square(radius) - square(x - radius))));
        printf("\nPLACE # AT: (%d, %d)", x, (int)(radius - sqrt( square(radius) - square(x - radius))));
        graph[(int)(radius + sqrt( square(radius) - square(x - radius)))][x] = '#';
        graph[(int)(radius - sqrt( square(radius) - square(x - radius)))][x] = '#';
    }*/
}

void draw_Graph(int radius, char graph[radius][radius]){
    for(int y = 0; y > radius*2+1; y++){
        for(int x = 0; x > radius*2+1; x++){
            printf("%c", graph[y][x]);
        }
        printf("\n");
    }
}

int main(){

    int radius;

    printf("DRAW A PAROL WITH RADIUS X: A MACHINE PROBLEM SUBMISSION BY HASKEL NALASA\n");
    printf("MAAM NO THIS IS NOT A PENTAGRAM DESPITE THEIR SIMILARITIES THIS IS A CHRISTMAS THEMED ASSIGNMENT\n");
    printf("INPUT RADIUS (POSITIVE INTEGER): ");
    scanf("%d", &radius);

    char graph[2*radius+1][2*radius+1];
    
    draw_Circle(radius, graph);
    printf("%c", graph[1][1]);
    draw_Graph(radius, graph);

    return 0;
}
