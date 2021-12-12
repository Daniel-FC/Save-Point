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

	//Image *lenaImg = imgReadPPM("./Entradas/entrada1.pnm");
	//Image *lenaImg = imgReadPPM("./Entradas/entrada2.pnm");
	Image *lenaImg = imgReadPPM("./Entradas/entrada3.pnm");

    Image *lenaImgGray = img_Bin(lenaImg);
    imgWritePPM(lenaImgGray, "./Saida/saida.ppm");

	imgDestroy(lenaImg);
    imgDestroy(lenaImgGray);
	return EXIT_SUCCESS;
	
}
