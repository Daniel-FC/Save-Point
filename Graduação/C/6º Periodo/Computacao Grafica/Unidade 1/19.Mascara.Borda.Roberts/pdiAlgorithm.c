#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "image.h"
#include <math.h>

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
	
	int matriz[imgGetHeight(origImg)][imgGetWidth(origImg)];
	int tam=1, TAM=9, soma1, soma2, cont, vetor1[TAM], vetor2[TAM];

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
			matriz[y][x]=gray;	
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
					vetor1[cont]=gray; 
					vetor2[cont]=gray;
					cont++;     		
        		
				}
					
			}
			for(z=0; z<TAM; z++){
				
				if(z==0){
					
					vetor1[z]=vetor1[z]*0;
					vetor2[z]=vetor2[z]*(-1);
					
				}
				if(z==1){
					
					vetor1[z]=vetor1[z]*0;
					vetor2[z]=vetor2[z]*0;
					
				}
				if(z==2){
					
					vetor1[z]=vetor1[z]*(-1);
					vetor2[z]=vetor2[z]*0;
					
				}				
				if(z==3){
					
					vetor1[z]=vetor1[z]*0;
					vetor2[z]=vetor2[z]*0;
					
				}				
				if(z==4){
					
					vetor1[z]=vetor1[z]*1;
					vetor2[z]=vetor2[z]*1;
					
				}				
				if(z==5){
					
					vetor1[z]=vetor1[z]*0;
					vetor2[z]=vetor2[z]*0;
					
				}				
				if(z==6){
					
					vetor1[z]=vetor1[z]*0;
					vetor2[z]=vetor2[z]*0;
					
				}				
				if(z==7){
					
					vetor1[z]=vetor1[z]*0;
					vetor2[z]=vetor2[z]*0;
					
				}									
				if(z==8){
					
					vetor1[z]=vetor1[z]*0;
					vetor2[z]=vetor2[z]*0;
					
				}
							
			}
			for(z=0, soma1=0, soma2=0; z<TAM; z++){
			
				soma1=soma1+vetor1[z];
				soma2=soma2+vetor2[z];
			
			}
			soma1=pow(soma1, 2);
			soma2=pow(soma2, 2);
			cont=soma1+soma2;
			sqrt(cont);					
			matriz[y][x]=cont;

		}
	}

    for (y = 0; y < imgGetHeight(origImg); y++){
    	
        for (x = 0; x < imgGetWidth(origImg); x++){

			gray=matriz[y][x];
			
			imgSetPixel(rImg, x, y, gray, gray, gray);

        }
    }	
	
    return rImg;
}
