
#ifndef _GEOMETRY_H
#define _GEOMETRY_H

typedef struct point{
    int x;
    int y;
}point;

void draw_circle(int x, int y, int r, int color);
void draw_line(int x1,int y1,int x2,int y2,int color);
void fb_disp_cross(int x, int y, unsigned int color);
void fb_disp_rectangle(int x, int y, int length, int width, int color);

#endif /* _GEOMETRY_H */

