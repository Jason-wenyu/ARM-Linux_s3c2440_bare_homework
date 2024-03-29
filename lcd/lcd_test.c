#include "geometry.h"
#include "font.h"
#include "lcd.h"
#include "framebuffer.h"

void lcd_test(void)
{
    unsigned int fb_base;
	int xres, yres, bpp;
	int x, y;
	unsigned char *p0;
	unsigned short *p;
	unsigned int *p2;
	int index;
	
	get_lcd_params(&fb_base, &xres, &yres, &bpp);
	fb_get_lcd_params();
	font_init();
	/* 往framebuffer中写数据 */
	if(bpp == 8)
	{
        /* 让LCD输出整屏的红色 */

		/* bpp: palette[12] */
		p0 = (unsigned char *)fb_base;
		for(x = 0; x < xres; x++)
		{
            for(y = 0; y < yres; y++)
            {
                *p0++ = 12
            }
		}
		
		/* palette[47] */
		p0 = (unsigned char *)fb_base;
		for (x = 0; x < xres; x++)
			for (y = 0; y < yres; y++)
				*p0++ = 47;

		/* palette[88] */
		p0 = (unsigned char *)fb_base;
		for (x = 0; x < xres; x++)
			for (y = 0; y < yres; y++)
				*p0++ = 88;

		/* palette[0] */
		p0 = (unsigned char *)fb_base;
		for (x = 0; x < xres; x++)
			for (y = 0; y < yres; y++)
				*p0++ = 0;
			
	}
	else if(bpp == 16)
	{
        /* 让LCD输出整屏的红色 */

		/* 565: 0xf800 */

		p = (unsigned short *)fb_base;
		for (x = 0; x < xres; x++)
			for (y = 0; y < yres; y++)
				*p++ = 0xf800;

		/* green */
		p = (unsigned short *)fb_base;
		for (x = 0; x < xres; x++)
			for (y = 0; y < yres; y++)
				*p++ = 0x7e0;

		/* blue */
		p = (unsigned short *)fb_base;
		for (x = 0; x < xres; x++)
			for (y = 0; y < yres; y++)
				*p++ = 0x1f;

		/* black */
		p = (unsigned short *)fb_base;
		for (x = 0; x < xres; x++)
			for (y = 0; y < yres; y++)
				*p++ = 0;
	}
	else if(bpp == 32)
	{
        /* 让LCD输出整屏的红色 */

		/* 0xRRGGBB */

		p2 = (unsigned int *)fb_base;
		for (x = 0; x < xres; x++)
			for (y = 0; y < yres; y++)
				*p2++ = 0xff0000;

		/* green */
		p2 = (unsigned int *)fb_base;
		for (x = 0; x < xres; x++)
			for (y = 0; y < yres; y++)
				*p2++ = 0x00ff00;

		/* blue */
		p2 = (unsigned int *)fb_base;
		for (x = 0; x < xres; x++)
			for (y = 0; y < yres; y++)
				*p2++ = 0x0000ff;

		/* black */
		p2 = (unsigned int *)fb_base;
		for (x = 0; x < xres; x++)
			for (y = 0; y < yres; y++)
				*p2++ = 0;
	}
		/* 画线 */
	draw_line(0, 0, xres - 1, 0, 0x23ff77);
	draw_line(xres - 1, 0, xres - 1, yres - 1, 0xffff);
	draw_line(0, yres - 1, xres - 1, yres - 1, 0xff00aa);
	draw_line(0, 0, 0, yres - 1, 0xff00ef);
	draw_line(0, 0, xres - 1, yres - 1, 0xff45);
	draw_line(xres - 1, 0, 0, yres - 1, 0xff0780);
	draw_line(50,50,100,50,0);

	/* 画圆 */
	draw_circle(xres/2, yres/2, yres/4, 0xff);

	/* 输出文字 */
	fb_print_string(200, 100, "LCD TEST", 0xff);
	/* return框显示 */
	fb_disp_rectangle(340,200,110,40,0xffffff);
	fb_print_string(350,215,"Return",0xffffff);
}
