// OKAY I JUST HAD A GOOD IDEA TODAY AND ITS TIME TO PUT IT TO USE
// REMEMBER THAT "DRAW A DUMB TRIANGLE WITH HEIGHT X".c 
// OKAY SO WHAT ABOUT "DRAW A PAROL WITH RADIUS X".c

// THIS IS: "DRAW A PAROL WITH RADIUS X".c by haskel nalasa 2022-06042

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
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

int radius; // global radius variable so i dont need to keep passing it

void draw_circle(char (*graph)[2*radius+1]);
void draw_Graph(int radius, char graph[2*radius+1][2*radius+1]);
void draw_line(line segment, char (*graph)[2*radius+1], char ch);
void set_slope(line *segment);
void draw_point(point *endpoint, char ch, char (*graph)[2*radius+1]);

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
            graph[y][x] = ' ';
        }
    }
    
    draw_circle(graph);

    // draw_Graph(radius, graph);

    point point_A, point_B, point_C, point_D, point_E;
    
    const int base_angle = 18;
    
    // maam. i dont know why THIS method works okay but if i put it in a for loop,
    // accessing it with points[i].x, the numbers all turn big for some reason
    // so when i try to feed it into other functions, i end up trying to access a cell in graph
    // that is out of bounds. weird C magic i dont know yet, i guess.
    
    point_A.x = (int)round(radius * cos(((base_angle) * pi) / 180) + radius);
    point_A.y = abs((int)round(radius * sin(((base_angle) * pi) / 180) - radius));
    // draw_point(&point_A, 'A', graph);
    
    point_B.x = (int)round(radius * cos(((1*72 + base_angle) * pi) / 180) + radius);
    point_B.y = abs((int)round(radius * sin(((1*72 + base_angle) * pi) / 180) - radius));
    // draw_point(&point_B, 'B', graph);

    point_C.x = (int)round(radius * cos(((2*72 + base_angle) * pi) / 180) + radius);
    point_C.y = abs((int)round(radius * sin(((2*72 + base_angle) * pi) / 180) - radius));
    // draw_point(&point_C, 'C', graph);

    point_D.x = (int)round(radius * cos(((3*72 + base_angle) * pi) / 180) + radius);
    point_D.y = abs((int)round(radius * sin(((3*72 + base_angle) * pi) / 180) - radius));
    // draw_point(&point_D, 'D', graph);

    point_E.x = (int)round(radius * cos(((4*72 + base_angle) * pi) / 180) + radius);
    point_E.y = abs((int)round(radius * sin(((4*72 + base_angle) * pi) / 180) - radius));
    // draw_point(&point_E, 'E', graph);
    
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
    
    // okay, so these are the endpoints of the star. we will basically do the same thing
    // with the circle but the formula is different this time.
    
    printf("\n(y+10)^{2}+(x-10)^{2}=100");
    draw_line(segment_AC, graph, '#');
    draw_line(segment_AD, graph, '#');
    draw_line(segment_BD, graph, '#');
    draw_line(segment_BE, graph, '#');
    draw_line(segment_CE, graph, '#');

    draw_Graph(radius, graph);

    return 0;
}

// okay the formula for a circle is (x-h)^2 + (y-i)^2 = R^2
// rearranging the terms, we get (y-i)^2 = R^2 - (x-h)^2
// then, y-i = +/- sqrt(R^2 - (x-h)^2)
// where y = i +/- sqrt(R^2 - (x-h)^2)
// therefore, we can cycle through all x values from 0 to radius*2 + 1
// and find all coordinates to fill with...something

void draw_circle(char (*graph)[2*radius+1]){
    for(int x = 0; x < radius*2+1; x++){
        *(*(graph + x) + (int)round(radius + sqrt(square(radius) - square(x-radius)))) = '#';
        *(*(graph + x) + (int)round(radius - sqrt(square(radius) - square(x-radius)))) = '#';
    }

    // swap the values for a second pass - literally the same thing lmao cause they're interchangable
    // makes the circle more "continuous" i guess?
    for(int y = 0; y < radius*2+1; y++){
        *(*(graph + (int)round(radius + sqrt(square(radius) - square(y-radius)))) + y) = '#';
        *(*(graph + (int)round(radius - sqrt(square(radius) - square(y-radius)))) + y) = '#';
    } // p.s. oh wow yeah that worked really well
}

    // since the slope has been predefined in the one-dimensional struct
    // we can use the "point-slope form" of a line: (y - y1) = m(x - x1)
    // rearranging to find y, we get: y = m(x - x1) + y1
    // for x, its a bit more complicated than the circle y - y1 = mx - mx1
    // mx = y - y1 + mx1 => x = (y - y1 + mx1) / m
    // idk maybe we'll use differenct endpoints for x1 and y1 maybe that will improve 
    // resolution

void draw_line(line segment, char (*graph)[2*radius+1], char ch){
    
    int increment_x = segment.endpoint_1.x < segment.endpoint_2.x ? 1 : -1;
    int increment_y = segment.endpoint_1.y < segment.endpoint_2.y ? 1 : -1;
    
    // pass 1: pass through the x values
    for(int x = segment.endpoint_1.x; x != segment.endpoint_2.x + increment_x; x+=increment_x){
        // printf("\n(%d, -%d)", x, (int)round(segment.slope*(start_x - x) + start_y));
        *(*(graph + x) + (int)round(segment.slope*(x - segment.endpoint_1.x) + segment.endpoint_1.y)) = ch;
    }
    
    
    // pass 2: pass through the y values
    if(segment.slope != 0){
        for(int y = segment.endpoint_1.y; y != segment.endpoint_2.y + increment_y; y+=increment_y){
            // printf("\n(%d, -%d)", (int)round((y - start_y + segment.slope*start_x) / segment.slope), y);
            *(*(graph + (int)round((y - segment.endpoint_1.y + segment.slope*segment.endpoint_1.x) / segment.slope)) + y) = ch;
        }
    } // one line is straight so we dont touch that.
}

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
    segment->slope = (((float)segment->endpoint_1.y - (float)segment->endpoint_2.y) / ((float)segment->endpoint_1.x - (float)segment->endpoint_2.x));
} // m = (y2 - y1) / (x2 - x1)

void draw_point(point *endpoint, char ch, char (*graph)[2*radius+1]){
    printf("\nchanging %c at (%d, %d) to %c", *(*(graph + endpoint->x) + endpoint->y), endpoint->x, endpoint->y, ch);
    // printf("\n(%d, %d)", endpoint.x, endpoint.y);
    *(*(graph + endpoint->x) + endpoint->y) = ch;
}