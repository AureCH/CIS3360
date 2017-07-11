//Christian Helms
//	CIS 3360 
//	Assignment 1: HILL Cipher
//	6/15/2017

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MATSIZE2 2
#define MATSIZE3 3
#define MATSIZE4 4
#define MATSIZE5 5
#define MATSIZE6 6
#define MATSIZE7 7
#define MATSIZE8 8
#define MATSIZE9 9
#define MATSIZE 10
#define LINELEN 80
#define MAXSTRING 10000

void encrypt2(char plainTxt[], int kmat[][MATSIZE2], int n);
void encrypt3(char plainTxt[], int kmat[][MATSIZE3], int n);
void encrypt4(char plainTxt[], int kmat[][MATSIZE4], int n);
void encrypt5(char plainTxt[], int kmat[][MATSIZE5], int n);
void encrypt6(char plainTxt[], int kmat[][MATSIZE6], int n);
void encrypt7(char plainTxt[], int kmat[][MATSIZE7], int n);
void encrypt8(char plainTxt[], int kmat[][MATSIZE8], int n);
void encrypt9(char plainTxt[], int kmat[][MATSIZE9], int n);
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

	printf("\nKey Matrix:\n\n");
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
	switch(n)
	{
		case 2: 
			encrypt2(inputfile, kmat, n);
			break;
		case 3:
			encrypt3(inputfile, kmat, n);
			break;
		case 4:
			encrypt4(inputfile, kmat, n);
			break;
		case 5:
			encrypt5(inputfile, kmat, n);
			break;
		case 6:
			encrypt6(inputfile, kmat, n);
			break;
		case 7:
			encrypt7(inputfile, kmat, n);
			break;
		case 8:
			encrypt8(inputfile, kmat, n);
			break;
		case 9:
			encrypt9(inputfile, kmat, n);
			break;
	}
//	encrypt(inputfile, kmat, n);

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
			printf("%c", cipherTxt[j]);
			if(z%80 ==0)
			printf("\n");

		}
		cipherTxt[n] = '\0';
		i +=n;

// Cipher console print here --
	
//	printf("%s", cipherTxt);
//	if (z%80== 0)
//		printf("\n");
	}
	printf("\n");	
}

void encrypt2(char plainTxt[], int kmat[][MATSIZE2], int n)
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
			printf("%c", cipherTxt[j]);
			if(z%80 ==0)
			printf("\n");

		}
		cipherTxt[n] = '\0';
		i +=n;

// Cipher console print here --
	
//	printf("%s", cipherTxt);
//	if (z%80== 0)
//		printf("\n");
	}
	printf("\n");	
}
void encrypt3(char plainTxt[], int kmat[][MATSIZE3], int n)
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
			printf("%c", cipherTxt[j]);
			if(z%80 ==0)
			printf("\n");

		}
		cipherTxt[n] = '\0';
		i +=n;

// Cipher console print here --
	
//	printf("%s", cipherTxt);
//	if (z%80== 0)
//		printf("\n");
	}
	printf("\n");	
}
void encrypt4(char plainTxt[], int kmat[][MATSIZE4], int n)
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
			printf("%c", cipherTxt[j]);
			if(z%80 ==0)
			printf("\n");

		}
		cipherTxt[n] = '\0';
		i +=n;

// Cipher console print here --
	
//	printf("%s", cipherTxt);
//	if (z%80== 0)
//		printf("\n");
	}
	printf("\n");	
}
void encrypt5(char plainTxt[], int kmat[][MATSIZE5], int n)
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
			printf("%c", cipherTxt[j]);
			if(z%80 ==0)
			printf("\n");

		}
		cipherTxt[n] = '\0';
		i +=n;

// Cipher console print here --
	
//	printf("%s", cipherTxt);
//	if (z%80== 0)
//		printf("\n");
	}
	printf("\n");	
}
void encrypt6(char plainTxt[], int kmat[][MATSIZE6], int n)
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
			printf("%c", cipherTxt[j]);
			if(z%80 ==0)
			printf("\n");

		}
		cipherTxt[n] = '\0';
		i +=n;

// Cipher console print here --
	
//	printf("%s", cipherTxt);
//	if (z%80== 0)
//		printf("\n");
	}
	printf("\n");	
}
void encrypt7(char plainTxt[], int kmat[][MATSIZE7], int n)
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
			printf("%c", cipherTxt[j]);
			if(z%80 ==0)
			printf("\n");

		}
		cipherTxt[n] = '\0';
		i +=n;

// Cipher console print here --
	
//	printf("%s", cipherTxt);
//	if (z%80== 0)
//		printf("\n");
	}
	printf("\n");	
}
void encrypt8(char plainTxt[], int kmat[][MATSIZE8], int n)
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
			printf("%c", cipherTxt[j]);
			if(z%80 ==0)
			printf("\n");

		}
		cipherTxt[n] = '\0';
		i +=n;

// Cipher console print here --
	
//	printf("%s", cipherTxt);
//	if (z%80== 0)
//		printf("\n");
	}
	printf("\n");	
}
void encrypt9(char plainTxt[], int kmat[][MATSIZE9], int n)
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
			printf("%c", cipherTxt[j]);
			if(z%80 ==0)
			printf("\n");

		}
		cipherTxt[n] = '\0';
		i +=n;

// Cipher console print here --
	
//	printf("%s", cipherTxt);
//	if (z%80== 0)
//		printf("\n");
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
	for(linecount =0; linecount < 1; linecount++)
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

