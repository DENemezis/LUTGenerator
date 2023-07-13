#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <math.h>

#define M_PIf 3.14159265358979323846f // Define the value of pi as a float constant

void generateLUT(const char* name, int values, int fixedpoint_decimals, const char* file_name)
{
    char fp_output[50000] = { 0 }; // Initialize a buffer to store the output as a string

    const char* fp_comment = "//fixed point in 16.16f format\n"; // Define a comment to indicate the fixed point format used in the output

    // SINE
    strcat(fp_output, fp_comment); // Add the fixed point format comment to the output string
    strcat(fp_output, "const int32_t "); // Add the type of the lookup table to the output string
    strcat(fp_output, name); // Add the name of the lookup table to the output string
    strcat(fp_output, "_sin_LUT["); // Add the suffix for the sine lookup table to the output string
    char str_values[10];
    sprintf(str_values, "%d", values); // Convert the number of values to a string
    strcat(fp_output, str_values); // Add the number of values to the output string
    strcat(fp_output, "]=\n{\n"); // Close the array declaration and start a new line

    for (int i = 0; i < values; i++)
    {
        float a = sinf(2 * M_PIf * (i / (float)values)); // Calculate the sine of the current angle using the float sine function
        a = a * (1 << fixedpoint_decimals); // Convert the sine value to fixed point format by multiplying by 2^16
        int32_t fixed_a = (int32_t)roundf(a); // Round the fixed point value to the nearest integer

        char str_fixed_a[20];
        sprintf(str_fixed_a, "%d", fixed_a); // Convert the fixed point value to a string
        strcat(fp_output, str_fixed_a); // Add the fixed point value to the output string
        strcat(fp_output, ","); // Add a comma to separate the values in the array

        if (i % 8 == 7) // Add a new line every 8 values to improve readability
        {
            strcat(fp_output, "\n");
        }
    }

    strcat(fp_output, "};\n\n"); // Close the array declaration and add an extra line break


    // COSINE
    strcat(fp_output, fp_comment); // Add the fixed point format comment to the output string
    strcat(fp_output, "const int32_t "); // Add the type of the lookup table to the output string
    strcat(fp_output, name); // Add the name of the lookup table to the output string
    strcat(fp_output, "_cos_LUT["); // Add the suffix for the cosine lookup table to the output string
    strcat(fp_output, str_values); // Add the number of values to the output string
    strcat(fp_output, "]=\n{\n"); // Close the array declaration and start a new line

    for (int i = 0; i < values; i++)
    {
        float a = cosf(2 * M_PIf * (i / (float)values)); // Calculate the cosine of the current angle using the float cosine function
        a = a * (1 << fixedpoint_decimals); // Convert the cosine value to fixed point format by multiplying by 2^16
        int32_t fixed_a = (int32_t)roundf(a); // Round the fixed point value to the nearest integer

        char str_fixed_a[20];
        sprintf(str_fixed_a, "%d", fixed_a); // Convert the fixed point value to a string
        strcat(fp_output, str_fixed_a); // Add the fixed point value to the output string
        strcat(fp_output, ","); // Add a comma to separate the values in the array

        if (i % 8 == 7) // Add a new line every 8 values to improve readability
        {
            strcat(fp_output, "\n");
        }
    }

    strcat(fp_output, "};\n\n"); // Close the array declaration and add an extra line break


    // NEGATIVE INVERSE TANGENT
    strcat(fp_output, fp_comment); // Add the fixed point format comment to the output string
    strcat(fp_output, "const int32_t "); // Add the type of the lookup table to the output string
    strcat(fp_output, name); // Add the name of the lookup table to the output string
    strcat(fp_output, "_aTan_LUT["); // Add the suffix for the negative inverse tangentlookup table to the output string
    strcat(fp_output, str_values); // Add the number of values to the output string
    strcat(fp_output, "]=\n{\n"); // Close the array declaration and start a new line

    for (int i = 0; i < values; i++)
    {
        float a = atanf(-1 / (i / (float)values)); // Calculate the negative inverse tangent of the current value using the float arctangent function
        a = a * (1 << fixedpoint_decimals); // Convert the negative inverse tangent value to fixed point format by multiplying by 2^16
        int32_t fixed_a = (int32_t)roundf(a); // Round the fixed point value to the nearest integer

        char str_fixed_a[20];
        sprintf(str_fixed_a, "%d", fixed_a); // Convert the fixed point value to a string
        strcat(fp_output, str_fixed_a); // Add the fixed point value to the output string
        strcat(fp_output, ","); // Add a comma to separate the values in the array

        if (i % 8 == 7) // Add a new line every 8 values to improve readability
        {
            strcat(fp_output, "\n");
        }
    }

    strcat(fp_output, "};\n\n"); // Close the array declaration and add an extra line break

    // Write the output string to a file
    FILE* fp = fopen(file_name, "w"); // Open the output file for writing
    if (fp == NULL) // Check if the file was opened successfully
    {
        printf("Error: Unable to open file %s for writing.\n", file_name);
        return;
    }

    fwrite(fp_output, sizeof(char), strlen(fp_output), fp); // Write the output string to the file

    fclose(fp); // Close the file
}

int main()
{
    const char* name = "myLookupTable"; // Name of the lookup table
    int values = 1024; // Number of values in the lookup table
    int fixedpoint_decimals = 16; // Number of decimal places in the fixed point format
    const char* file_name = "myLookupTable.h"; // Name of the output file
    
    generateLUT(name, values, fixedpoint_decimals, file_name); // Generate and write the lookup tables to files

    printf("Lookup tables generated successfully!\n");

    return 0;
}
