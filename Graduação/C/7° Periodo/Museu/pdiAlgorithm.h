/*
 * pdiAlgorithm.h
 *
 *  Created on: 10/09/2012
 *      Author: wilfredo
 */

#ifndef PDIALGORITHM_H_
#define PDIALGORITHM_H_

unsigned char texDat1[400][400];
unsigned char texDat2[400][400];
unsigned char texDat3[400][400];
unsigned char texDat4[400][400];
unsigned char texDat5[400][400];
unsigned char texDat6[400][400];
unsigned char texDat7[400][400];
Image * img_ConvertGray(Image * origImg);
Image * img_Bin(Image * origImg, int num);
//Image * img_Blur(Image * origImg, int sizeMask);

//unsigned int * img_GetHistogram (Image * img);
//void printHistogramToConsole(Image * img);

#endif /* PDIALGORITHM_H_ */
