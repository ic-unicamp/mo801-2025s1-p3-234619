module hardware_conv (
    input  wire [31:0] in0,
    input  wire [31:0] in1,
    input  wire [31:0] in2,
    input  wire [31:0] in3,
    input  wire [31:0] in4,
    input  wire [31:0] in5,
    input  wire [31:0] in6,
    input  wire [31:0] in7,
    input  wire [31:0] in8,
    output reg  [31:0] out
);

    // Fixed-point constants in Q16.16 format
    // For example: 1.0 = 1 << 16 = 65536
    // You can customize these
    wire [31:0] reg0 = 32'd65536 * 1; // 1.0
    wire [31:0] reg1 = 32'd65536 * 2; // 2.0
    wire [31:0] reg2 = 32'd65536 * 3; // 3.0
    wire [31:0] reg3 = 32'd65536 * 4; // 4.0
    wire [31:0] reg4 = 32'd65536 * 5; // 5.0
    wire [31:0] reg5 = 32'd65536 * 6; // 6.0
    wire [31:0] reg6 = 32'd65536 * 7; // 7.0
    wire [31:0] reg7 = 32'd65536 * 8; // 8.0
    wire [31:0] reg8 = 32'd65536 * 9; // 9.0

    // Multiply inputs and weights → Q32.32
    wire [63:0] prod0 = in0 * reg0;
    wire [63:0] prod1 = in1 * reg1;
    wire [63:0] prod2 = in2 * reg2;
    wire [63:0] prod3 = in3 * reg3;
    wire [63:0] prod4 = in4 * reg4;
    wire [63:0] prod5 = in5 * reg5;
    wire [63:0] prod6 = in6 * reg6;
    wire [63:0] prod7 = in7 * reg7;
    wire [63:0] prod8 = in8 * reg8;

    wire [63:0] sum = prod0 + prod1 + prod2 + prod3 + prod4 +
                      prod5 + prod6 + prod7 + prod8;

    // Convert back to Q16.16 (shift right by 16)
    always @(*) begin
        out = sum[47:16]; // Truncate to 32-bit Q16.16 result
    end

endmodule
