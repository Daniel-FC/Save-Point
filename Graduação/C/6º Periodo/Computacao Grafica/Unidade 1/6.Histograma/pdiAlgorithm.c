#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "image.h"
#include <string.h>

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
	FILE *log, *tot;
	int vetor[256], l, c;
    int x, y;
    unsigned char red, green, blue, gray;
    Image *rImg = imgCreate(imgGetWidth(origImg), imgGetHeight(origImg));
    
    if (rImg == NULL)
        return NULL;
        
    for(l=0; l<256; l++)
    	vetor[l]=0;
 
    for (y = 0; y < imgGetHeight(origImg); y++)
    {
        for (x = 0; x < imgGetWidth(origImg); x++)
        {
            red = imgGetPixelRed(origImg, x, y);
            green = imgGetPixelGreen(origImg, x, y);
            blue = imgGetPixelBlue(origImg, x, y);
            
            gray = validColor(0.21*red + 0.71*green + 0.07*blue);
            
   			vetor[gray]++;    
            
            //imgSetPixel(rImg, x, y, red, green, blue);
            //imgSetPixel(rImg, x, y, gray, gray, gray);
        }
    }
    
    log=fopen("Resultado.txt", "w");
    tot=fopen("Resultado.xls", "w");
    for(l=0; l<256; l++){
		
    	fprintf(log, "(%i):\t", l);
    	fprintf(tot, "(%i):\t%i\n", l, vetor[l]);
    	for(c=0; c<vetor[l]; c++){
    	
    		fprintf(log, "x");
    	
    	}
    	fprintf(log, "\n");
    	
	}

    return rImg;
}
