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
	FILE *log;
	int l, total=0, teste, TAM=256;
	double vetor[TAM];
    int x, y, vet[TAM];
    unsigned char red, green, blue, gray;
    Image *rImg = imgCreate(imgGetWidth(origImg), imgGetHeight(origImg));
    
    if (rImg == NULL)
        return NULL;

    for(l=0; l<TAM; l++)
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
        
        }
    }

    for(l=0; l<TAM; l++)
    	total=total+vetor[l];

   for(l=0; l<TAM; l++)
    	vetor[l]=100*vetor[l]/total/100;

   for(l=0; l<TAM; l++){
   		
   		if(l!=0)
   			vetor[l]=vetor[l]+vetor[l-1];
   	
   }

	for(l=0; l<TAM; l++)
		vetor[l]=round(vetor[l]*(TAM-1));
	
  	for (y = 0; y < imgGetHeight(origImg); y++)
    {
        for (x = 0; x < imgGetWidth(origImg); x++)
        {

   			gray=vetor[gray];    
            imgSetPixel(rImg, x, y, gray, gray, gray);
            
        }
    }

    log=fopen("Resultado.xls", "w");
    for(l=0; l<TAM; l++){
    	
    	vet[l]=vetor[l];
    	fprintf(log, "(%i):\t%i\n", l, vet[l]);
    	
	}
    	
    return rImg;
}
