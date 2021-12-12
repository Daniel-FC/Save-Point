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
	int matriz[imgGetHeight(origImg)][imgGetWidth(origImg)], tam=2, TAM=25;
	
    int x, y, z, w, soma;
    unsigned char red, green, blue, gray;
    Image *rImg = imgCreate(imgGetWidth(origImg), imgGetHeight(origImg));
    
    if (rImg == NULL)
        return NULL;
        
    for (y = 0; y < imgGetHeight(origImg); y++)
    {
        for (x = 0; x < imgGetWidth(origImg); x++)
        {
		
		    red = imgGetPixelRed(origImg, y, x);
		    green = imgGetPixelGreen(origImg, y, x);
		    blue = imgGetPixelBlue(origImg, y, x);
			gray = validColor(0.21*red + 0.71*green + 0.07*blue);		
			imgSetPixel(rImg, x, y, gray, gray, gray);		
		
		}
	}
    
    for (y = tam; y < imgGetHeight(origImg)-tam; y++)
    {
        for (x = tam; x < imgGetWidth(origImg)-tam; x++)
        {

        	for(z=x-tam, soma=0; z<=x+tam; z++){
        		
        	    for(w=y-tam; w<=y+tam; w++){
        		
		            red = imgGetPixelRed(origImg, z, w);
		            green = imgGetPixelGreen(origImg, z, w);
		            blue = imgGetPixelBlue(origImg, z, w);
		            gray = validColor(0.21*red + 0.71*green + 0.07*blue);
					soma=soma+gray;

				}	
        		
			}
			matriz[y][x]=soma/TAM;

        }
    }
    
    for (y = 0; y < imgGetHeight(origImg); y++)
    {
        for (x = 0; x < imgGetWidth(origImg); x++)
        {
        	
			if(x!=0 && x!=1 && x!=(imgGetWidth(origImg)-1) && x!=(imgGetWidth(origImg)-2) &&
			   y!=0 && y!=1 && y!=(imgGetHeight(origImg)-1) && y!=(imgGetHeight(origImg)-2)){
				
				gray=matriz[y][x];
				
			}
        	
			imgSetPixel(rImg, x, y, gray, gray, gray);
    
        }
    }

    return rImg;
}
