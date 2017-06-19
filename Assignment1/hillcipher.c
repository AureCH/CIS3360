//	Christian Helms
//	CIS 3360 
//	Assignment 1: HILL Cipher
//	6/15/2017

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MATSIZE 10
#define LINELEN 80
#define MAXSTRING 10000

void encrypt(char plainTxt[], int kmat[][MATSIZE], int n);
void pad(char text[], int n);

int main(int argc, char *argv[] )
{
	char keyfile[MAXSTRING], inputfile[MAXSTRING], outputfile[MAXSTRING];
	
	FILE* ifp = fopen(argv[1], "r");
	int i, j, n;
	
	fscanf(ifp, "%d", &n);
	int kmat[n][n];
	for (i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			fscanf(ifp, "%d", &kmat[i][j]);
		}
	}
	char plainTxt[MAXSTRING];
	fscanf(ifp, "%s", plainTxt);
	fclose(ifp);
	
	encrypt(plainTxt, kmat, n);
	return 0;
}

void encrypt(char plainTxt[], int kmat[][MATSIZE], int n)
{
	pad(plainTxt, n);
	
	int i =0;
	while (i < strlen(plainTxt))
	{
		int j, k;
		char cipherTxt[MATSIZE+1];
		
		for(j =0;j<n;j++)
		{
			int val =0;
			for(k=0;k<n;k++)
			{
				val = (val+ kmat[j][k]*(plainTxt[i+k] - 'a'))%26;
			}
			cipherTxt[j]= (char) ('a'+ value);
		}
		cipherTxt[n] = '\0';
		i +=n;
		
		printf("%s", cipherTxt);
	}
	printf("\n");
}

void pad(char text[], int n) {

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