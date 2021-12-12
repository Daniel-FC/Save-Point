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

Image * img_Bin(Image * origImg) {
	
	int matriz[imgGetHeight(origImg)][imgGetWidth(origImg)], tam=1, TAM=9, soma, cont, vetor[TAM];
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
        		
        			vetor[cont]=gray;
        			cont++;
        		
				}
					
			}
			/*for(z=0, cont=0; z<TAM; z++){
				
				if( ((vetor[4]-vetor[2])<10 || (vetor[2]-vetor[4])<10) && ((vetor[4]-vetor[6])<10 || (vetor[6]-vetor[4])<10) ){

					if(z!=2 && z!=4 && z!=6){
					
						if((vetor[4]-vetor[z])>10 ||(vetor[z]-vetor[4])>10)
							cont++;							
						
					}
		
				}

			}*/
			//if(cont==6){
				
				for(z=0, soma=0; z<TAM; z++){
					
		            if(z==2 || z==4 || z==6)
						soma=(vetor[z]*2)+soma;
					else
						soma=(vetor[z]*(-1))+soma;					
					
				}
				matriz[y][x]=soma;
				
			//}
			//else{
				
				//matriz[y][x]=vetor[4];
				
			//}

		}
	
	}	
	
    for (y = 0; y < imgGetHeight(origImg); y++)
    {
        for (x = 0; x < imgGetWidth(origImg); x++)
        {
        	
			if(x!=0 && x!=(imgGetWidth(origImg)-1) && 
			   y!=0 && y!=(imgGetHeight(origImg)-1)){
				
				gray=matriz[y][x];
				
			}
        	
			imgSetPixel(rImg, x, y, gray, gray, gray);
    
        }
    }	
	
    return rImg;
}
