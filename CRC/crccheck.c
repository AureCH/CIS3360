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



int main(int argc, char *argv[])
{
	int i =0, j, length,crclength,c;
//	char input[64][8];
	char itest;
	char input[512] = { [0 ... 511] = '.'};
		printf("%s", CRCpolynomial);
		fflush(stdout);
	crclength = strlen(CRCpolynomial);
	int *crcpoly[crclength];
	printf("\n%d\n", crclength);


	FILE* ifp = fopen(argv[2], "r");
		if(ifp == NULL)
			{
				printf("\nbad file address\n");
				return 0;
			}

	for(i=0; i<512; i++)
	{
		fscanf(ifp, "%c", &input[i]);	
/*		fscanf(ifp, "%c", &itest);
		if(itest == "\n")
		
		else
		{
		input[i] = itest;
		}
		*/
	}

/*	while((c= fgetc(ifp)) != EOF)
	{
		for(j=0; j<8;j++)
		{
			for(i=0; i<64; i++)
			{
				if (c == "\n")
					break;
				else
					input[i][j] = c;
			}
		}
	}
*/
/*	for(i=0; i< crclength; i++)
		{
			if(i == 0)
				printf("\n%d\n", __LINE__);
			crcpoly = atoi(CRCpolynomial);
//			crcpoly[crclength-i-1] = 1;//CRCpolynomial[i];
		} 
*/
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
