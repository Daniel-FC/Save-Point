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
	int matriz[imgGetHeight(origImg)][imgGetWidth(origImg)], tam=3, TAM=49, vetor[TAM], cont;
	
    int x, y, z, w;
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

        	for(z=x-tam, cont=0; z<=x+tam; z++){
        		
        	    for(w=y-tam; w<=y+tam; w++){
        		
		            red = imgGetPixelRed(origImg, z, w);
		            green = imgGetPixelGreen(origImg, z, w);
		            blue = imgGetPixelBlue(origImg, z, w);
		            gray = validColor(0.21*red + 0.71*green + 0.07*blue);
		            cont++;
					vetor[cont]=gray;     		
        		
				}	
        		
			}
			for(z=0; z<TAM; z++){
				
				for(w=0; w<TAM; w++){
				
					if(vetor[z]<vetor[w]){
						
						cont=vetor[z];
						vetor[z]=vetor[w];
						vetor[w]=cont;
						
					}		

				}

			}
			matriz[y][x]=vetor[(TAM+1)/2];

        }
    }
    
    for (y = 0; y < imgGetHeight(origImg); y++)
    {
        for (x = 0; x < imgGetWidth(origImg); x++)
        {
        	
			if(x!=0 && x!=1 && x!=2 && x!=(imgGetWidth(origImg)-1) && x!=(imgGetWidth(origImg)-2) && x!=(imgGetWidth(origImg)-3) &&
			   y!=0 && y!=1 && y!=2 && y!=(imgGetHeight(origImg)-1) && y!=(imgGetHeight(origImg)-2) && y!=(imgGetHeight(origImg)-3)){
				
				gray=matriz[y][x];
				
			}
        	
			imgSetPixel(rImg, x, y, gray, gray, gray);
    
        }
    }
    
    return rImg;
}
