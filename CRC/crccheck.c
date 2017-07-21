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
//	char crcmath[8][64] = {
	crclength = strlen(CRCpolynomial);
	int *crcpoly[crclength];
//	printf("\n%d\n", crclength);


	FILE* ifp = fopen(argv[2], "r");
		if(ifp == NULL)
			{
				printf("\nbad file address\n");
				return 0;
			}

	for(i=0; i<512; i++)
	{
		fscanf(ifp, "%c", &input[i]);
		if(input[i] == '\n')
			input[i] = '.';

	if(i%64 == 0 && i !=0)
	{
	printf("\n");
	printf("%c", input[i]);	
	}
	else
		printf("%c", input[i]);
	}
	printf("\n");
	fclose(ifp);
	
	if(strcmp(argv[1], "c") == 0)
	{
		//printf("\n c\n");
	}
	else if(strcmp(argv[1], "v") == 0)
	{
		//printf("\n v \n");
	}
	else
	printf("\n Invalid second parameter, enter c or v\n");


}
