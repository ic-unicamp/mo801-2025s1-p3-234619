#include <stdio.h>

// image defs
#define image_size 512
#define image_depth 3

// convolution def
#define window_size 3 //do not change, hardcoded logic
#define filters 5

#define buffer_size (image_size * window_size)

float line_buffer[buffer_size];
float window[window_size * window_size];
float kernel[window_size * window_size] = {0.5, 0.5, 0.5,
                                           0.5, 0.5, 0.5,
                                           0.5, 0.5, 0.5};

float convolution(float window[], float kernel[])
{
    float result = window[0] * kernel[0] +
                   window[1] * kernel[1] +
                   window[2] * kernel[2] +
                   window[3] * kernel[3] +
                   window[4] * kernel[4] +
                   window[5] * kernel[5] +
                   window[6] * kernel[6] +
                   window[7] * kernel[7] +
                   window[8] * kernel[8];
    return result;
}

float image_pixel(int x, int y, int z)
{
    // Dummy image, if turned into an image,
    // will show a gradient from up left to
    // lower right.
    float result = x / 2 + y / 2;
    return result;
}

int main()
{
    // i,j,k are H,W and C respectively
    // f is filter no.
    // x,y are the kernel coordinates
    int f = 0, i = 0, j = 0, k = 0, x = 0, y = 0;

    int buffer_index = 0;
    int conv_index = 0;
    float conv_result = 0;

    //printf("buffer size: %d", buffer_size);

    for (f = 0; f < filters; f++)
    {
        for (k = 0; k < image_depth; k++)
        {
            for (i = 0; i < image_size - window_size; i++)
            {
                for (j = 0; j < image_size - window_size; j++)
                {
                    // the image_pixel func is separate as it simulates
                    // an image grabbed from outside memory
                    line_buffer[buffer_index] = image_pixel(i, j, k);

                    buffer_index++;
                    if (conv_index < image_size - window_size)
                    {
                        // there must be a better way to do this
                        window[0] = line_buffer[conv_index];
                        window[1] = line_buffer[conv_index + 1];
                        window[2] = line_buffer[conv_index + 2];

                        window[3] = line_buffer[conv_index + image_size];
                        window[4] = line_buffer[conv_index + image_size + 1];
                        window[5] = line_buffer[conv_index + image_size + 2];

                        window[6] = line_buffer[conv_index];
                        window[7] = line_buffer[conv_index + 2 * image_size + 1];
                        window[8] = line_buffer[conv_index + 2 * image_size + 2];

                        conv_result = convolution(window, kernel);
                        //printf("%f", conv_result);
                    }
                    conv_index++;

                    if (buffer_index > buffer_size)
                    buffer_index = 0;
                    //printf("f: %d, k: %d, i: %d, j: %d\n",f,k,i,j);
                }

                conv_index = 0;
            }
        }
    }
    return 0;
}