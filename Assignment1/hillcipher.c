//	Christian Helms
//	CIS 3360 
//	Assignment 1: HILL Cipher
//	6/15/2017

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MATSIZE 9
#define LINELEN 80
#define MAXSTRING 10000

void encrypt(char plainTxt[], int kmat[][MATSIZE], int n);
void pad(char text[], int n);


int main(int argc, char *argv[] )
{

	char keyfile[MAXSTRING], inputfile[MAXSTRING], outputfile[MAXSTRING];
//		printf("%d" "\n", __LINE__);
//		fflush(stdout);
	printf("Argv0 %s \n", argv[0]);
	printf("Argv1 %s \n", argv[1]);
	printf("Argv2 %s \n", argv[2]);
	fflush(stdout);
	FILE* ifp = fopen(argv[1], "r");
		if( ifp == NULL)
		{
			printf("bad file address");
			return 0;
		}

		printf("%d" "\n", __LINE__);
		fflush(stdout);
	int i, j, n, flen;
// Read in matrix size, then matrix	
	fscanf(ifp, "%d", &n);

	int kmat[n][n];
	for (i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{

			fscanf(ifp, "%d", &kmat[i][j]);
		}
	}
	fclose(ifp);
// open input file, dump into large array
	ifp = fopen(argv[2],"r");
		printf("%d" "\n", __LINE__);
		fflush(stdout);
// Segfaulting here 
	fscanf(ifp, "%s", inputfile);
	fclose(ifp);
		printf("%d" "\n", __LINE__);
		fflush(stdout);
//Print input file to console, at maximum width 80, newline break
	flen = strlen(inputfile);
	j=0;
	while (j<flen)	
	{
		for(i=0; i<LINELEN;i++)
		{
		printf("%c", inputfile[i]);
		}
		printf("\n");
		j++;
	}
// start encryption
	encrypt(inputfile, kmat, n);
	return 0;
}

void encrypt(char plainTxt[], int kmat[][MATSIZE], int n)
{
		printf("%d" "\n", __LINE__);
		fflush(stdout);
// Pad if necessary
	pad(plainTxt, n);
	
	int i =0;
//	iterate through entire file length, doing looped matrix multiplication
	while (i < strlen(plainTxt))
	{
		int j, k;
		char cipherTxt[n+1];
		
		for(j =0;j<n;j++)
		{
			int val =0;
			for(k=0;k<n;k++)
			{
// add check for commas/convert to lower here
				val = (val+ kmat[j][k]*(plainTxt[i+k] - 'a'))%26;
			}
			cipherTxt[j]= (char) ('a'+ val);
		}
		cipherTxt[n] = '\0';
		i +=n;
// Cipher console print here --		
		printf("%s", cipherTxt);
	}
	printf("\n");
}

void pad(char text[], int n) {
		printf("%d" "\n", __LINE__);
		fflush(stdout);

    // Calculate number of padding chars.
    int oldlen = strlen(text);
    int padding = (n - oldlen%n)%n;
    int newlen = oldlen + padding;

    // Go ahead and pad.
    int i;
    for (i=oldlen; i<newlen; i++)
        text[i] = 'x';
    text[newlen] = '\0';
}


