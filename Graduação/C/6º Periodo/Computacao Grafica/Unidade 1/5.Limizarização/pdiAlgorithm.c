#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "image.h"

unsigned char validColor(int c)
{
	if (c < 0) return 0;
	if (c > 255) return 255;

	return ((unsigned char) c);
}

Image * img_ConvertGray(Image * origImg)
{
	int x, y;
	unsigned char red, green, blue, gray;
	Image *rImg = imgCreate(imgGetWidth(origImg), imgGetHeight(origImg));

	if (rImg == NULL)
			return NULL;

	for (y = 0; y < imgGetHeight(origImg); y++)
			{
				for (x = 0; x < imgGetWidth(origImg); x++)
				{
					red = imgGetPixelRed(origImg, x, y);
					green = imgGetPixelGreen(origImg, x, y);
					blue = imgGetPixelBlue(origImg, x, y);

					gray = validColor(0.21*red + 0.71*green + 0.07*blue);
                    
                    

					imgSetPixel(rImg, x, y, gray, gray, gray);
				}
			}

	return rImg;
}

Image * img_Bin(Image * origImg)
{
    int x, y;
    unsigned char red, green, blue, gray;
    Image *rImg = imgCreate(imgGetWidth(origImg), imgGetHeight(origImg));
    
    if (rImg == NULL)
        return NULL;
    
    for (y = 0; y < imgGetHeight(origImg); y++)
    {
        for (x = 0; x < imgGetWidth(origImg); x++)
        {
            red = imgGetPixelRed(origImg, x, y);
            green = imgGetPixelGreen(origImg, x, y);
            blue = imgGetPixelBlue(origImg, x, y);
            
            gray = validColor(0.21*red + 0.71*green + 0.07*blue);
            
            
            if ((gray >= 0)&(gray <= 50))
 				gray=25;
            if ((gray >= 51)&(gray <= 100))
 				gray=75;
             if ((gray >= 101)&(gray <= 150))
  				gray=125;   				
            if ((gray >= 151)&(gray <= 200))
  				gray=175;   				
            if ((gray >= 201)&(gray <= 250))
  				gray=225;   				
            if ((gray >= 251)&(gray <= 255))
  				gray=253;                 
            
            //imgSetPixel(rImg, x, y, red, green, blue);
            imgSetPixel(rImg, x, y, gray, gray, gray);
        }
    }
    
    return rImg;
}
