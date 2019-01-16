/****************************************************************************
 * dwt_test_main/dwt_test_main.c
 *
 *
 *  Copyright (c) 2014, Rafat Hussain
 *  Copyright (c) 2016, Holger Nahrstaedt
 *  Copyright (c) 2019, Sony Semiconductor Solutions Co.
 *  All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 *   1.  Redistributions of source code must retain the above copyright notice,
 *       this list of conditions and the following disclaimer.
 *
 *   2.  Redistributions in binary form must reproduce the above copyright notice,
 *       this list of conditions and the following disclaimer 
 * 	     in the documentation and/or other materials provided with the distribution.
 *
 *   3.  The name of the author may not be used to endorse or promote products derived
 *       from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS
 * OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY
 * AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER
 * IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT
 * OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 ****************************************************************************/

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <sdk/config.h>
#include <stdio.h>

#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "wavelib.h"


/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * hello_main
 ****************************************************************************/

double absmax(double *array, int N) {
	double max;
	int i;

	max = 0.0;
	for (i = 0; i < N; ++i) {
		if (fabs(array[i]) >= max) {
			max = fabs(array[i]);
		}
	}

	return max;
}

double temp[1200];
char line_buf[1024];

#ifdef CONFIG_BUILD_KERNEL
int main(int argc, FAR char *argv[])
#else
int dwt_test_main(int argc, char *argv[])
#endif
{
	wave_object obj;
	wt_object wt;
	double *inp,*out,*diff;
	int N, i,J;

	FILE *ifp;

	char *name = "db4";
	obj = wave_init(name);// Initialize the wavelet

	ifp = fopen("/mnt/sd0/signal.txt", "r");
	i = 0;
	if (!ifp) {
		printf("Cannot Open File");
		exit(100);
	}
	while (!feof(ifp)) {
    fgets(line_buf, 1024, ifp);
		// fscanf(ifp, "%lf \n", &temp[i]);
		sscanf(line_buf, "%lf \n", &temp[i]);
		i++;
	}
	N = 256;

	inp = (double*)malloc(sizeof(double)* N);
	out = (double*)malloc(sizeof(double)* N);
	diff = (double*)malloc(sizeof(double)* N);
	//wmean = mean(temp, N);

	for (i = 0; i < N; ++i) {
		inp[i] = temp[i];
		//printf("%g \n",inp[i]);
	}
	J = 3;

	wt = wt_init(obj, "dwt", N, J);// Initialize the wavelet transform object
	setDWTExtension(wt, "sym");// Options are "per" and "sym". Symmetric is the default option
	setWTConv(wt, "direct");
	
	dwt(wt, inp);// Perform DWT
	//DWT output can be accessed using wt->output vector. Use wt_summary to find out how to extract appx and detail coefficients
	
	for (i = 0; i < wt->outlength; ++i) {
		// printf("%g ",wt->output[i]);
		printf("%f ",wt->output[i]);
	}
	
	idwt(wt, out);// Perform IDWT (if needed)
	// Test Reconstruction
	for (i = 0; i < wt->siglength; ++i) {
		diff[i] = out[i] - inp[i];
	}
	
	printf("\n MAX %g \n", absmax(diff, wt->siglength)); // If Reconstruction succeeded then the output should be a small value.
	
	wt_summary(wt);// Prints the full summary.
	wave_free(obj);
	wt_free(wt);

	free(inp);
	free(out);
	free(diff);
	return 0;
}

