#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "../header/denoise.h"

int main() {
	// gcc -Wall -I../header -L../Bin denoisetest.c -o denoise -ldenoiselib -lwavelib -lm
	double *inp,*oup;
	int i,N;
	FILE *ifp,*ofp;
	double temp[2400];

	char *wname = "sym8";
	char *method = "dwt";
	char *ext = "sym";
	char *thresh = "soft";

	ifp = fopen("noisyheavisine.txt", "r");
	i = 0;
	if (!ifp) {
	    printf("Cannot Open File");
	    exit(100);
	}

	while (!feof(ifp)) {
	    fscanf(ifp, "%lf \n", &temp[i]);
	    i++;
	}

	fclose(ifp);

	N = i;

	inp = (double*)malloc(sizeof(double)* N);
	oup = (double*)malloc(sizeof(double)* N);

	for(i = 0; i < N;++i) {
		inp[i] = temp[i];
	}

	//visushrink(inp,N,wname,method,ext,thresh,oup);
	sureshrink(inp,N,J,wname,method,ext,thresh,oup);

	ofp = fopen("denoiseds.txt", "w");

	for(i = 0; i < N;++i) {
		fprintf(ofp,"%g \n",oup[i]);
	}

	fclose(ofp);

	free(inp);
	free(oup);
	return 0;
}
