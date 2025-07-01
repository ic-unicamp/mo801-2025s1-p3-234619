import numpy as np
import numbers

def to_verilog_fixed_q16_16(var_name, value):
    fixed_val = int(round(value * 65536))  # Convert to Q16.16
    hex_val = f"{fixed_val & 0xFFFFFFFF:08X}"  # 32-bit hex, zero-padded
    return f"wire [31:0] {var_name} = 32'h{hex_val}; // {value} in Q16.16"

def generate_weights(input):
    weights_number = 9
    
    if isinstance(input, np.ndarray):
        weight_list = list(np.ravel(input))
    elif isinstance(input, list):
        weight_list = input
    elif isinstance(input, numbers.Number):
        weight_list = [input] * weights_number
    else:
        print("Input type is not recognized.")
        return 0

    for (index, value) in enumerate(weight_list):
        var_name = f'reg{index}'
        verilog_line  = to_verilog_fixed_q16_16(var_name, value)
        print(verilog_line)