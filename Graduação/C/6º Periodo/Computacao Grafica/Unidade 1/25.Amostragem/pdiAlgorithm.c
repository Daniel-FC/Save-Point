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
            
            
            if ((gray >= 0)&(gray <= 15))
 				gray=15;
            if ((gray >= 16)&(gray <= 30))
 				gray=30;
            if ((gray >= 31)&(gray <= 45))
  				gray=45;   				
            if ((gray >= 46)&(gray <= 60))
  				gray=60;   				
            if ((gray >= 61)&(gray <= 75))
  				gray=75;   				
            if ((gray >= 76)&(gray <= 90))
  				gray=90; 
            if ((gray >= 91)&(gray <= 105))
 				gray=105;
            if ((gray >= 106)&(gray <= 120))
 				gray=120;
            if ((gray >= 121)&(gray <= 135))
  				gray=135;   				
            if ((gray >= 136)&(gray <= 150))
  				gray=150;   				
            if ((gray >= 151)&(gray <= 165))
  				gray=165;   				
            if ((gray >= 166)&(gray <= 180))
  				gray=180;
            if ((gray >= 181)&(gray <= 195))
 				gray=195;
            if ((gray >= 196)&(gray <= 210))
 				gray=210;
            if ((gray >= 211)&(gray <= 224))
  				gray=224;   				
            if ((gray >= 226)&(gray <= 240))
  				gray=240;   				
            if ((gray >= 240)&(gray <= 255))
  				gray=255;   								                 
            
            //imgSetPixel(rImg, x, y, red, green, blue);
            imgSetPixel(rImg, x, y, gray, gray, gray);
        }
    }
    
    return rImg;
}
