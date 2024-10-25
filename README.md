# Binary Instruction Interpretation Program

This program processes and interprets binary instructions based on two main tasks: extracting key information from a binary instruction format and performing operations based on grouped binary digits. Here’s an overview of each task:

## Table of Contents
1. [Task 1: Instruction Conversion and Interpretation](#task-1-instruction-conversion-and-interpretation)
2. [Task 2: Number Grouping and Operation Execution](#task-2-number-grouping-and-operation-execution)

---

### Task 1: Instruction Conversion and Interpretation

This task involves reading an instruction from the keyboard, converting it into binary, and interpreting its components as follows:
1. **Extracting Bits**: The instruction’s first 3 bits are stored in the variables `first_1`, `first_2`, and `first_3`. 
2. **Formatting to 32 Bits**: Since the instruction must be 32 bits long, if the converted binary number is shorter than 32 bits, additional `0`s are prefixed to reach the required length.
    - Depending on the number of leading zeroes needed, the instruction format may appear as:
        - `000 00 0000`, `000 00 000-`, `000 00 00--`, `000 00 0---`, `000 00 ----`, etc., where `-` indicates bits already part of the binary instruction.

3. **Interpreting the Instruction**:
    - The first 3 bits determine `N`, the number of operations to process.
    - For each `N` value:
      - **If `N = 1`**: Only one sign is indicated by the next 2 bits, which is then printed based on its binary code (00/01/10/11).
      - **If `N = 2`**: The next 4 bits are interpreted similarly, representing two signs.
      - **For `N > 2`**: Each set of 2 bits is interpreted as a sign and stored in the character vector `op`.

4. **Size Determination**: The next 4 bits indicate the operation size, calculated according to problem requirements. 
5. **Output**: The program displays `N`, the collected signs in the vector, and the determined size as it processes each case.

### Task 2: Number Grouping and Operation Execution

This task processes input numbers to perform operations in binary:
1. **Counting Required Numbers**: Based on a given formula, the required number of inputs is stored in `numbers`, which are read from the keyboard and stored in the vector `nr`.
2. **Binary Grouping and Conversion**:
    - In the first loop, each binary digit is divided by 2 to identify the current bit.
    - Bits are grouped into sets of size `Dim` (specified in the problem), and each group is converted from binary to decimal to obtain the actual numbers, which are stored in the `ops` vector.
3. **Operation Execution**:
    - A second loop pairs each consecutive number in `ops` with a corresponding sign from the `op` vector.
    - Using these pairs, the program calculates the final result by iterating through both vectors, applying the appropriate operators to each operand.

This program effectively interprets binary instructions and performs calculations based on grouped binary digits, providing clear outputs at each processing step.
