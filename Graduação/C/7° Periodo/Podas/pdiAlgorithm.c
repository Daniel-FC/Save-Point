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

Image * img_Bin(Image * origImg){
     
    int x, y, l; 
    unsigned char red, green, blue, gray;
    Image *rImg = imgCreate(imgGetWidth(origImg), imgGetHeight(origImg));
    
    int x0[imgGetWidth(origImg)][imgGetHeight(origImg)];
    int x1[imgGetWidth(origImg)][imgGetHeight(origImg)];
    int x2[imgGetWidth(origImg)][imgGetHeight(origImg)];
    int x3[imgGetWidth(origImg)][imgGetHeight(origImg)];
    int x4[imgGetWidth(origImg)][imgGetHeight(origImg)];
    
    if (rImg == NULL)
        return NULL;
 
 	//Atribuição X0
    for (y = 0; y < imgGetHeight(origImg); y++){
    	
        for (x = 0; x < imgGetWidth(origImg); x++){
             
            red = imgGetPixelRed(origImg, x, y);
            green = imgGetPixelGreen(origImg, x, y);
            blue = imgGetPixelBlue(origImg, x, y);
            gray = validColor(0.21*red + 0.71*green + 0.07*blue);
            x0[y][x] = gray;
            x1[y][x] = gray;
            x2[y][x] = gray;

        }
         
    }
	
 	//Atribuição X1
 	for (l = 0; l < 3; l++){

    	for (y = 1; y < imgGetHeight(origImg)-1; y++){   		

        	for (x = 1; x < imgGetWidth(origImg)-1; x++){
			
				if(x2[y][x]==0 && x2[y][x-1]==0 && x2[y][x+1]==252 && x2[y-1][x]==252 && x2[y-1][x+1]==252 && x2[y+1][x]==252 && x2[y+1][x+1]==252)
					x1[y][x]=252;
				if(x2[y][x]==0 && x2[y][x-1]==252 && x2[y][x+1]==252 && x2[y-1][x]==0 && x2[y+1][x]==252 && x2[y+1][x-1]==252 && x2[y+1][x+1]==252)
					x1[y][x]=252;
				if(x2[y][x]==0 && x2[y][x-1]==252 && x2[y][x+1]==0 && x2[y-1][x]==252 && x2[y-1][x-1]==252 && x2[y+1][x]==252 && x2[y+1][x-1]==252)
					x1[y][x]=252;	
				if(x2[y][x]==0 && x2[y][x-1]==252 && x2[y][x+1]==252 && x2[y-1][x]==252 && x2[y-1][x-1]==252 && x2[y-1][x+1]==252 && x2[y+1][x]==0)
					x1[y][x]=252;
				
				if(x2[y-1][x-1]==0 && x2[y-1][x]==252 && x2[y-1][x+1]==252 && x2[y][x-1]==252 && x2[y][x]==0 && x2[y][x+1]==252 && x2[y+1][x-1]==252 && x2[y+1][x]==252 && x2[y+1][x+1]==252)
					x1[y][x]=252;
				if(x2[y-1][x-1]==252 && x2[y-1][x]==252 && x2[y-1][x+1]==0 && x2[y][x-1]==252 && x2[y][x]==0 && x2[y][x+1]==252 && x2[y+1][x-1]==252 && x2[y+1][x]==252 && x2[y+1][x+1]==252)
					x1[y][x]=252;
				if(x2[y-1][x-1]==252 && x2[y-1][x]==252 && x2[y-1][x+1]==252 && x2[y][x-1]==252 && x2[y][x]==0 && x2[y][x+1]==252 && x2[y+1][x-1]==252 && x2[y+1][x]==252 && x2[y+1][x+1]==0)
					x1[y][x]=252;
				if(x2[y-1][x-1]==252 && x2[y-1][x]==252 && x2[y-1][x+1]==252 && x2[y][x-1]==252 && x2[y][x]==0 && x2[y][x+1]==252 && x2[y+1][x-1]==0 && x2[y+1][x]==252 && x2[y+1][x+1]==252)
					x1[y][x]=252;
			
			}
			
        }

	    for (y = 0; y < imgGetHeight(origImg); y++){
	    			
	    	for (x = 0; x < imgGetWidth(origImg); x++)
	    		x2[y][x]=x1[y][x];
				
	    }  
         
    }
	
	for (y = 0; y < imgGetHeight(origImg); y++){
	    			
	    for (x = 0; x < imgGetWidth(origImg); x++){
	    	
			x2[y][x]=252;
			x3[y][x]=x1[y][x];
	    	
	    }
	    				
	}     
    	
    //Atribuição X2
    for (y = 1; y < imgGetHeight(origImg)-1; y++){
    
    	for (x = 1; x < imgGetWidth(origImg)-1; x++){
    		
			if(x2[y][x]==0 && x3[y][x-1]==0 && x3[y][x+1]==252 && x3[y-1][x]==252 && x3[y-1][x+1]==252 && x3[y+1][x]==252 && x3[y+1][x+1]==252)
				x2[y][x]=0;
			if(x3[y][x]==0 && x3[y][x-1]==252 && x3[y][x+1]==252 && x3[y-1][x]==0 && x3[y+1][x]==252 && x3[y+1][x-1]==252 && x3[y+1][x+1]==252)
				x2[y][x]=0;
			if(x3[y][x]==0 && x3[y][x-1]==252 && x3[y][x+1]==0 && x3[y-1][x]==252 && x3[y-1][x-1]==252 && x3[y+1][x]==252 && x3[y+1][x-1]==252)
				x2[y][x]=0;	
			if(x3[y][x]==0 && x3[y][x-1]==252 && x3[y][x+1]==252 && x3[y-1][x]==252 && x3[y-1][x-1]==252 && x3[y-1][x+1]==252 && x3[y+1][x]==0)
				x2[y][x]=0;
			
			if(x3[y-1][x-1]==0 && x3[y-1][x]==252 && x3[y-1][x+1]==252 && x3[y][x-1]==252 && x3[y][x]==0 && x3[y][x+1]==252 && x3[y+1][x-1]==252 && x3[y+1][x]==252 && x3[y+1][x+1]==252)
				x2[y][x]=0;
			if(x3[y-1][x-1]==252 && x3[y-1][x]==252 && x3[y-1][x+1]==0 && x3[y][x-1]==252 && x3[y][x]==0 && x3[y][x+1]==252 && x3[y+1][x-1]==252 && x3[y+1][x]==252 && x3[y+1][x+1]==252)
				x2[y][x]=0;
			if(x3[y-1][x-1]==252 && x3[y-1][x]==252 && x3[y-1][x+1]==252 && x3[y][x-1]==252 && x3[y][x]==0 && x3[y][x+1]==252 && x3[y+1][x-1]==252 && x3[y+1][x]==252 && x3[y+1][x+1]==0)
				x2[y][x]=0;
			if(x3[y-1][x-1]==252 && x3[y-1][x]==252 && x3[y-1][x+1]==252 && x3[y][x-1]==252 && x3[y][x]==0 && x3[y][x+1]==252 && x3[y+1][x-1]==0 && x3[y+1][x]==252 && x3[y+1][x+1]==252)
				x2[y][x]=0;    		
    		
		}
		
	}
	
    for (y = 0; y < imgGetHeight(origImg); y++){
    
    	for (x = 0; x < imgGetWidth(origImg); x++){
    		
    		x3[y][x]=x2[y][x];
    		x4[y][x]=x2[y][x];
    		
    	}
				
	}

    //Atribuição X3
    for (l = 0; l < 3; l++){
    	
		for (y = 0; y < imgGetHeight(origImg); y++){
			
			for (x = 0; x < imgGetWidth(origImg); x++)
				x4[y][x]=x3[y][x];
				
		} 
		
	    for (y = 1; y < imgGetHeight(origImg)-1; y++){
	    
	    	for (x = 1; x < imgGetWidth(origImg)-1; x++){
	    		
	    		if(x4[y][x]==0){
	    			
	    			x3[y-1][x-1]=0;
	    			x3[y-1][x]=0;
	    			x3[y-1][x+1]=0;
	    			x3[y][x-1]=0;
	    			x3[y][x+1]=0;
	    			x3[y+1][x-1]=0;
	    			x3[y+1][x]=0;
	    			x3[y+1][x+1]=0;
	    			
	    		}
	    		
			}
			
		}
		for (y = 0; y < imgGetHeight(origImg); y++){
			
	    	for (x = 0; x < imgGetWidth(origImg); x++){
	    		
	    		if(x0[y][x]==252)
	    			x3[y][x]=252;
	    			
			}
			
		}
	
	}

	//Atribuição X4
	for (y = 0; y < imgGetHeight(origImg); y++){
			
		for (x = 0; x < imgGetWidth(origImg); x++){
			
			x4[y][x]=252;
			if(x1[y][x]==0 || x3[y][x]==0)
				x4[y][x]=0;
			
		}
				
	}

    //Saida
    for(y = 0; y < imgGetHeight(origImg); y++){
    
    	for (x = 0; x < imgGetWidth(origImg); x++)
    		imgSetPixel(rImg, x, y, x4[y][x], x4[y][x], x4[y][x]);	
         
    }
    
    return rImg;
    
}
