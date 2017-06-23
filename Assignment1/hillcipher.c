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
char *pad(char text[], int n);
void print(char plainTxt[]);


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

	printf("Key Matrix:\n \n");
	int kmat[n][n];
	for (i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{

			fscanf(ifp, "%d", &kmat[i][j]);
			printf("%d ", kmat[i][j]);
		}
		printf("\n");
	}
	fclose(ifp);
// open input file, dump into large array
	ifp = fopen(argv[2],"r");
//		printf("%d" "\n", __LINE__);
//		fflush(stdout);
	int iChar;
	i=0;
// Convert & Strip rather than dump into large array.
	while((iChar = getc(ifp)) !=EOF)
	{
		if(isalpha(iChar))
			inputfile[i++] = tolower(iChar);
	}
	inputfile[i] = '\0';
//	fscanf(ifp, "%s", inputfile);
	fclose(ifp);
//		printf("%d" "\n", __LINE__);
//		fflush(stdout);
//	printf("Strlen of Input file: %d \n", strlen(inputfile));
//	printf("Array size of input file: %d \n", sizeof(inputfile));

// This is causing seg fault... not entirely sure why.
//Print input file to console, at maximum width 80, newline break
/*flen = strlen(inputfile)-1;
	j=0;
	int ccount=0;
	while (j<flen)	
	{
		for(i=0; i<LINELEN;i++)
		{
		printf("%c", inputfile[ccount]);
		ccount++;
		}
		printf("\n");
		j++;
	}
*/
//	printf("%s\n", inputfile);
// start encryption
	encrypt(inputfile, kmat, n);

//	flen = strlen(inputfile);
//	j=0;
//	int ccount =0;
//	printf("%d \n", flen);
/*	while(j=flen)
	{
		for(i=0; i<LINELEN;i++)
		{
			//printf("%c", inputfile[ccount]);
			ccount++;
		}
		printf("\n");
		j++;
	}
*/
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
	
	print(plainTxt);
	printf("CipherText:\n\n");
	char cipherTxt[n+1];
	int i =0;
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
			cipherTxt[j]= (char) ('a'+ val);
		}
		cipherTxt[n] = '\0';
		i +=n;
// Cipher console print here --		
	printf("%s", cipherTxt);
	}
	printf("\n\n");
	int linecount, charCount;
	i =0;
//	printf("\n%d\n", i);
	int lines = strlen(cipherTxt)/LINELEN;
/*
	while(cipherTxt[i] != cipherTxt[strlen(cipherTxt)])
	{
	for(linecount =0; linecount < lines-10; linecount++)
		{
		for(charCount =0; charCount < LINELEN; charCount++)
			{	
			printf("%c", cipherTxt[i++]);
			}
		if(charCount == 80)
			printf("\n");
		}
	}
*/
	printf("\n");

	printf("\n");


}

char *pad(char text[], int n) {
//		printf("%d" "\n", __LINE__);
//		fflush(stdout);

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
	printf("\nPlainText:\n\n");
	int lines;
	lines = strlen(plainTxt)/LINELEN;
//	printf("%d %d\n", lines-10, __LINE__);
//	printf("%d\n", lines);

	while(plainTxt[i] != '\0')
	{
	for(linecount =0; linecount < lines-10; linecount++)
		{
		for(charCount =0; charCount < LINELEN; charCount++)
			{	
			printf("%c", plainTxt[i++]);
			}
		if(charCount == 80)
			printf("\n");
//	printf("\n");
		}
	//printf("%d", i);
	}	









}
