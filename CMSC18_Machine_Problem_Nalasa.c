// OKAY I JUST HAD A GOOD IDEA TODAY AND ITS TIME TO PUT IT TO USE
// REMEMBER THAT "DRAW A DUMB TRIANGLE WITH HEIGHT X".c 
// OKAY SO WHAT ABOUT "DRAW A PAROL WITH RADIUS X".c

// THIS IS: "DRAW A PAROL WITH RADIUS X".c by haskel nalasa 2022-06042

#include <stdio.h>
#include <math.h>
#define pi 3.141592654

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

int radius;

void draw_Graph(int radius, char graph[2*radius+1][2*radius+1]){
    int y, x;
    for(y = 0; y<(2*radius+1); ++y){
        printf("\n");
        for(x = 0; x < radius*2+1; x++){
            printf("%c", graph[x][y]);
        }
    }
}

void set_slope(line *segment){
    segment->slope = (float)((segment->endpoint_1.y - segment->endpoint_2.y) / (segment->endpoint_1.x - segment->endpoint_2.x));
}

void draw_point(point endpoint, char ch, char graph [2*radius+1][2*radius+1]){
    // printf("\nchanging %c at (%d, %d) to %c", graph[endpoint.y][endpoint.x], endpoint.x, endpoint.y, ch);
    printf("\n(%d, %d)", endpoint.x, endpoint.y);
    // graph[endpoint.y][endpoint.x] = ch;
}


int main(){
    
    printf("DRAW A PAROL WITH RADIUS X: A MACHINE PROBLEM SUBMISSION BY HASKEL NALASA\n");
    printf("(NOT A PENTAGRAM)\n");
    printf("NOTE: RESOLUTION IMPROVES WITH INCREASING RADII???\n");
    printf("USE LARGE SCREEN OR COPY-PASTE TO NOTEPAD WITH ZOOM OUT\n");
    printf("INPUT RADIUS (POSITIVE INTEGER): ");
    scanf("%d", &radius);

    char graph[2*radius+1][2*radius+1];
    
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
    } // p.s. oh wow yeah that worked really well
    
    draw_Graph(radius, graph);
    
    // uhh maam the reason these functions are all here is because i dont know how to pass
    // by reference with a two-dimensional array

    point point_A, point_B, point_C, point_D, point_E;
    
    const int base_angle = 18;
    
    point points[5] = {point_A, point_B, point_C, point_D, point_E};
    char letters[5] = {'A', 'B', 'C', 'D', 'E'};
    for(int i = 0; i < 5; i++){
        points[i].x = (int)round(radius * cos(((i*72 + base_angle) * pi) / 180) + radius);
        points[i].y = (int)round(radius * sin(((i*72 + base_angle) * pi) / 180) + radius);
        printf("\n%c (%d, %d)", letters[i], points[i].x, points[i].y);
    }
    /*for(int i = 0; i < 5; i++){
        draw_point(points[i], letters[i], graph);
    }*/
    
    
    // draw_Graph(radius, graph);

    // endpoints of the star, 72 degrees apart, defined through pure math
    // source: trust me bro i learned this in math20

    line segment_AC, segment_AD, segment_BD, segment_BE, segment_CE;

    segment_AC.endpoint_1 = point_A;
    segment_AC.endpoint_2 = point_C;
    set_slope(&segment_AC);
    
    segment_AD.endpoint_1 = point_A;
    segment_AD.endpoint_2 = point_D;
    set_slope(&segment_AD);

    segment_BD.endpoint_1 = point_B;
    segment_BD.endpoint_2 = point_D;
    set_slope(&segment_BD);

    segment_BE.endpoint_1 = point_B;
    segment_BE.endpoint_2 = point_E;
    set_slope(&segment_BE);

    segment_CE.endpoint_1 = point_C;
    segment_CE.endpoint_2 = point_E;
    set_slope(&segment_CE);
    
    line segments[5] = {segment_AC, segment_AD, segment_BE, segment_CE, segment_BD};
    /*
    for(int i = 0; i < 5; i++){
        draw_line(segments[i], );
    }
    */
    // okay, so these are the endpoints of the star. we will basically do the same thing
    // with the circle but the formula is different this time.
    
    // since the slope has been predefined in the one-dimensional struct
    // we can use the "point-slope form" of a line: (y - y1) = m(x - x1)
    // rearranging to find y, we get: y = m(x - x1) + y1
    // for x, its a bit more complicated than the circle y - y1 = mx - mx1
    // mx = y - y1 + mx1 => x = (y - y1 + mx1) / m
    // idk maybe we'll use differenct endpoints for x1 and y1 maybe that will improve 
    // resolution


    return 0;
}