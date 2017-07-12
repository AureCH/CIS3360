//	Christian Helms
//	CIS 3360
//	Assignment 2 - CRC
//	7-11-2017

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>

#define CRCpolynomial "1010000001010011"



int main()//(int argc, char *argv[])
{
	int i =0, j, length,crclength;
		printf("%s", CRCpolynomial);
		fflush(stdout);
	crclength = strlen(CRCpolynomial);
	int *crcpoly[crclength];
	printf("\n%d\n", crclength);
	for(i=0; i< crclength; i++)
		{
			if(i == 0)
				printf("\n%d\n", __LINE__);
			crcpoly = atoi(CRCpolynomial);
//			crcpoly[crclength-i-1] = 1;//CRCpolynomial[i];
		} 
	printf("\nhere %d\n", __LINE__);
	fflush(stdout);
//	printf("\n%d\n", *crcpoly);

/*
	printf("hi\n");
	fflush(stdout);
	strcpy(crcpoly, CRCpolynomial);
	printf("%s", crcpoly);
	fflush(stdout);
*/	
//	FILE* ifp = fopen()
}
