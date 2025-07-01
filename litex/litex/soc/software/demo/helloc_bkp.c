#include <stdio.h>
#include "csr.h"
#define image_size 128
#define window_size 3

double accumulator = 0;
float window[window_size][window_size];
float image_patch[window_size][window_size];
int count = 0;

int helloc(){
	int i=0, j=0, x=0, y=0;
	int imax =0, jmax=0;
	printf("Filling the matrices\n");
			for(x=0; x< window_size; x++){
				for(y=0; y<window_size; y++){
					window[x][y] = 0.5;
					image_patch[x][y] = 0.8;
				}
			}

	printf("Started the convolution for a %dx%d image\n", image_size, image_size);	

	for (i=0; i<image_size - window_size; i++){
		for (j=0; j<image_size - window_size; j++){
			for(x=0; x< window_size; x++){
				for(y=0; y<window_size; y++){
					
					window[x][y] = image_patch[x][y] * (j+x);
					adder_a_write(count);
					adder_b_write(1);
					count = adder_result_read();
				}
			}
			//printf("x=%d, y=%d",i, j);
			accumulator = 0;
		}
	}
	printf("convolution finished!\n Required %d steps\n", count);
	printf("\n!strfinished\n");
	return 0;
}
