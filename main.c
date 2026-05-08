#include "dsk6713.h"
#include <stdlib.h>
#include "image_data.h"

#define RES 128
#define SIZE (RES * RES)

// Align buffers to 8-byte boundaries for DSP efficiency
#pragma DATA_ALIGN(buffer_A, 8);
#pragma DATA_SECTION(buffer_A, ".img_data")
unsigned char buffer_A[SIZE];

#pragma DATA_ALIGN(buffer_B, 8);
#pragma DATA_SECTION(buffer_B, ".img_data")
unsigned char buffer_B[SIZE];

// Prototypes
void median_3x3(unsigned char *src, unsigned char *dst);
void sobel_edge(unsigned char *src, unsigned char *dst);

void main() {
    DSK6713_init();

    // STEP 1: Remove noise from original image
    median_3x3(image, buffer_B);

    // STEP 2: Detect edges from the cleaned image
    // Result will be in buffer_A
    sobel_edge(buffer_B, buffer_A);

    while(1);
}

void median_3x3(unsigned char *src, unsigned char *dst) {
    int i, j, k, m, n;
    unsigned char win[9], temp;
    for(i=1; i<RES-1; i++) {
        for(j=1; j<RES-1; j++) {
            k=0;
            for(m=-1; m<=1; m++)
                for(n=-1; n<=1; n++)
                    win[k++] = src[(i+m)*RES+(j+n)];
            // Bubble sort
            for(k=0; k<8; k++) {
                for(m=k+1; m<9; m++) {
                    if(win[k]>win[m]) { temp=win[k]; win[k]=win[m]; win[m]=temp; }
                }
            }
            dst[i*RES+j] = win[4];
        }
    }
}

void sobel_edge(unsigned char *src, unsigned char *dst) {
    int i, j, gx, gy, sum;
    for(i=1; i<RES-1; i++) {
        for(j=1; j<RES-1; j++) {
            gx = -src[(i-1)*RES+(j-1)] + src[(i-1)*RES+(j+1)]
                 -2*src[i*RES+(j-1)] + 2*src[i*RES+(j+1)]
                 -src[(i+1)*RES+(j-1)] + src[(i+1)*RES+(j+1)];
            gy = -src[(i-1)*RES+(j-1)] - 2*src[(i-1)*RES+j] - src[(i-1)*RES+(j+1)]
                 +src[(i+1)*RES+(j-1)] + 2*src[(i+1)*RES+j] + src[(i+1)*RES+(j+1)];
            sum = abs(gx) + abs(gy);
            dst[i*RES+j] = (sum > 255) ? 255 : (unsigned char)sum;
        }
    }
}
