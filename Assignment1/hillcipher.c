//Christian Helms
//	CIS 3360 
//	Assignment 1: HILL Cipher
//	6/15/2017

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MATSIZE 5
#define LINELEN 80
#define MAXSTRING 10000

void encrypt(char plainTxt[], int kmat[][MATSIZE], int n);
//void encrypt(char plainTxt[], int **kmat, int n);
char *pad(char text[], int n);
void print(char plainTxt[]);


int main(int argc, char *argv[] )
{

	char keyfile[MAXSTRING], inputfile[MAXSTRING], outputfile[MAXSTRING];
	FILE* ifp = fopen(argv[1], "r");
		if( ifp == NULL)
		{
			printf("bad file address");
			return 0;
		}

	int i, j, n, flen;
// Read in matrix size, then matrix	
	fscanf(ifp, "%d", &n);

	printf("\nKey Matrix:\n \n");
	int kmat[n][n];
	for (i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{

			fscanf(ifp, "%d", &kmat[i][j]);
			printf("%d", kmat[i][j]);
//prevent extra spaces in matrix that cause diff issues	
			if(j!=n-1)
				printf(" ");
		}
		printf("\n");
	}
	fclose(ifp);
// open input file, dump into large array
	ifp = fopen(argv[2],"r");
	int iChar;
	i=0;
// Convert & Strip rather than dump into large array.
	while((iChar = getc(ifp)) !=EOF)
	{
		if(isalpha(iChar))
			inputfile[i++] = tolower(iChar);
	}
	inputfile[i] = '\0';
	fclose(ifp);

// start encryption
	encrypt(inputfile, kmat, n);

	return 0;
}

void encrypt(char plainTxt[], int kmat[][MATSIZE], int n)
{
//		printf("%d" "\n", __LINE__);
//		fflush(stdout);
// Pad if necessary
	plainTxt = pad(plainTxt, n);
	int lcount=0;
	int ccount;
	char buff[LINELEN];
	int flen =0;
	
	flen = strlen(plainTxt);
	char cText[flen];
	print(plainTxt);
	printf("\nCipherText:\n\n");
	char cipherTxt[n+1];
	int i =0, z=0;
//	iterate through entire file length, doing looped matrix multiplication
	while (i < strlen(plainTxt))
	{
		int j, k;
//		char cipherTxt[n+1];
		
		for(j =0;j<n;j++)
		{
			int val =0;
			for(k=0;k<n;k++)
			{

				val = (val+ kmat[j][k]*(plainTxt[i+k] - 'a'))%26;
			}
			cText[z++] = (char) ('a' + val);
			cipherTxt[j]= (char) ('a'+ val);

		}
		cipherTxt[n] = '\0';
		i +=n;

// Cipher console print here --
	
	printf("%s", cipherTxt);
	if (z%80== 0)
		printf("\n");
	}
	printf("\n");	
}

char *pad(char text[], int n) {

    // Calculate number of padding chars.
    int oldlen = strlen(text);
    int padding = (n - oldlen%n)%n;
    int newlen = oldlen + padding;

    // Go ahead and pad.
    int i;
    for (i=oldlen; i<newlen; i++)
        text[i] = 'x';
    text[newlen] = '\0';
	return text;
}

void print(char plainTxt[])
{
	char buffer[80];
	int linecount, charCount,i =0;
	printf("\n\nPlaintext:\n\n");
	int lines;
	lines = strlen(plainTxt)/LINELEN;

	while(plainTxt[i] != '\0')
	{
	for(linecount =0; linecount < lines-10; linecount++)
		{
		for(charCount =0; charCount < LINELEN; charCount++)
			{
				if(plainTxt[i] == '\0')
				{
					printf("\n");
					break;	
				}
			printf("%c", plainTxt[i++]);
			}
		if(charCount == 80)
			printf("\n");
		}
	}	
}
