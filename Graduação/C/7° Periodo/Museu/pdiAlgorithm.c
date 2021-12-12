#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "image.h"

unsigned char texDat1[400][400];
unsigned char texDat2[400][400];
unsigned char texDat3[400][400];
unsigned char texDat4[400][400];
unsigned char texDat5[400][400];
unsigned char texDat6[400][400];
unsigned char texDat7[400][400];

unsigned char validColor(int c)
{
	if (c < 0) return 0;
	if (c > 255) return 255;

	return ((unsigned char) c);
}

Image * img_ConvertGray(Image * origImg){
	int x, y;
	unsigned char red, green, blue, gray;
	Image *rImg = imgCreate(imgGetWidth(origImg), imgGetHeight(origImg));

	if (rImg == NULL)
			return NULL;

	for (y = 0; y < imgGetHeight(origImg); y++){
		
		for (x = 0; x < imgGetWidth(origImg); x++){
			red = imgGetPixelRed(origImg, x, y);
			green = imgGetPixelGreen(origImg, x, y);
			blue = imgGetPixelBlue(origImg, x, y);

			gray = validColor(0.21*red + 0.71*green + 0.07*blue);
            
			imgSetPixel(rImg, x, y, gray, gray, gray);
		}
		
	}

	return rImg;
}

Image * img_Bin(Image * origImg, int num){
	
    int x, y;
    unsigned char red, green, blue, gray;
    Image *rImg = imgCreate(imgGetWidth(origImg), imgGetHeight(origImg));
    
    if (rImg == NULL)
        return NULL;

    for (y = 0; y < imgGetHeight(origImg); y++){
    	
        for (x = 0; x < imgGetWidth(origImg); x++){
        	
            red = imgGetPixelRed(origImg, x, y);
            green = imgGetPixelGreen(origImg, x, y);
            blue = imgGetPixelBlue(origImg, x, y);
            gray = validColor(0.21*red + 0.71*green + 0.07*blue);
            if(num==1)
   				texDat1[y][x] = gray;
            if(num==2)
   				texDat2[y][x] = gray;   				
            if(num==3)
   				texDat3[y][x] = gray;
            if(num==4)
   				texDat4[y][x] = gray;
            if(num==5)
   				texDat5[y][x] = gray;
            if(num==6)
   				texDat6[y][x] = gray;
            if(num==7)
   				texDat7[y][x] = gray;				  				   				   			      				
   			imgSetPixel(rImg, x, y, gray, gray, gray);
            
        }
        
    }
    
    return rImg;
}
