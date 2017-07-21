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
	char crcmath[8][64] = {
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
		if(input[i] == '\n')
			input[i] = '.';
//			printf("no bueno spaces");	
/*		fscanf(ifp, "%c", &itest);
		if(itest == "\n")
		
		else
		{
		input[i] = itest;
		}
		*/
	if(i%64 == 0)
	{
	printf("\n");
	printf("%c", input[i]);	
	}
	else
		printf("%c", input[i]);
	}
	printf("\n");
	fclose(ifp);
}
