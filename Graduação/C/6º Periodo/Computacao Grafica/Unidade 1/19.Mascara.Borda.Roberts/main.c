/*
 ============================================================================
 Name        : pdi.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "image.h"
#include "pdiAlgorithm.h"

int main(void) {
	//puts("!!!Hello World!!!"); /* prints !!!Hello World!!! */
	//Image *lenaImg = imgReadPPM("/Users/dri/Documents/UERN/Ensino/disciplinas/CG/codigospdi/pdi/pdi/images/lena-std.pnm");
    Image *lenaImg = imgReadPPM("C:/Users/Daniel/Downloads/Computacao_Grafica/19.Mascara.Borda.Roberts/lena-std.pnm");
	//imgWritePPM(lenaImg, "./images/lena256color.ppm");

	//Image *lenaImgGray = img_ConvertGray(lenaImg);
	//imgWritePPM(lenaImgGray, "/Users/dri/Documents/UERN/Ensino/disciplinas/CG/codigospdi/pdi/pdi/images/lena256Gray.ppm");
    
    //Image *lenaImgGray = img_ConvertGray(lenaImg);
    //imgWritePPM(lenaImgGray, "/Users/dri/Documents/UERN/Ensino/disciplinas/CG/codigospdi/pdi/pdi/images/foto256Gray.ppm");
    
    Image *lenaImgGray = img_Bin(lenaImg);
    imgWritePPM(lenaImgGray, "C:/Users/Daniel/Downloads/Computacao_Grafica/19.Mascara.Borda.Roberts/Resultado/foto256Bin.ppm");

	imgDestroy(lenaImg);
    imgDestroy(lenaImgGray);
	return EXIT_SUCCESS;
}
