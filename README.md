# Generating Fixed-Point Lookup Tables

This repository contains C code for generating fixed-point lookup tables for the sine, cosine, and negative inverse tangent functions. The lookup tables are generated using floating-point arithmetic and then converted to fixed-point format.

## Usage

To use the code, simply run the `main` function of the program. This will generate three lookup tables for the sine, cosine, and negative inverse tangent functions, respectively. The lookup tables will be written to a C header file, which can be included in your C project.

The `generateLUT` function takes four arguments:

  void generateLUT(const char* name, int values, int fixedpoint_decimals, const char* file_name)

- `name`: A string containing the name of the lookup table.
- `values`: An integer specifying the number of values in the lookup table.
- `fixedpoint_decimals`: An integer specifying the number of decimal places in the fixed-point format. For example, a value of 16 would create a fixed-point format with 16 bits for the integer part and 16 bits for the fractional part.
- `file_name`: A string containing the name of the output file.

## Dependencies

The code requires the following C libraries:

- `stdio.h`
- `stdlib.h`
- `string.h`
- `stdint.h`
- `math.h`

## License

This code is released under the MIT License.  

