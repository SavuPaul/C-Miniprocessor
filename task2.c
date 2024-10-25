#include <stdio.h>
#include <math.h>
#define MAX_OPERATIONS 9
#define SIZE 32

int main() {
    // TASK 1

    const int two_third_power = 8;
    unsigned int instr = 0, N = 0, cp1_instr = 0, cp2_instr = 0,
                first_1 = 0, first_2 = 0, first_3 = 0, nr_zero = 0,
                remaining2_zero = 0, remaining_zero = 0,
                op1 = 0, op2 = 0, i = 0, var1 = 0, var2 = 0,
                Dim = 0, dim1 = 0, dim2 = 0, dim3 = 0, dim4 = 0,
                cp_N = 0;
    int nr_division1 = 0, nr_division2 = 0,
        divisions_allowed = 3, divisions_allowed2 = 2;
    char op[MAX_OPERATIONS];

    // reads the instruction
    scanf("%u", &instr);
    cp1_instr = instr;

    if (instr == 0) {
        N = 1;
        i = 0;
        op[i] = '+';
        i++;
        op[i] = '\0';
        Dim = 1;
        return 0;
    }

    // first 3 bits after the conversion to base 2
    while (instr > 0) {
        first_3 = first_2;
        first_2 = first_1;
        first_1 = instr % 2;
        instr = instr / 2;
        nr_division1++;
    }

    // how many zeros need to be added
    if (nr_division1 % SIZE != 0) {
        nr_zero = SIZE - nr_division1;
    }

    if (nr_zero > 3) {
        N = 1;
        remaining_zero = nr_zero - 3;

        // format 000 00 0--- or 000 00 00-- or 000 00 000- or 000 00 0000
        if (remaining_zero > 2) {
            i = 0;
            op[i] = '+';
            i++;
            op[i] = '\n';
            remaining2_zero = remaining_zero - 2;
            switch (remaining2_zero) {
                case 4:
                    Dim = 1;
                    break;
                case 3:
                    Dim = 1 + (1 * first_1);
                    break;
                case 2:
                    Dim = 1 + (1 * first_2 + 2 * first_1);
                    break;
                case 1:
                    Dim = 1 + (1 * first_3 + 2 * first_2 + 4 * first_1);
                    break;
                default:
                    break;
            }
        }

        // format: 000 00 ----
        if (remaining_zero == 2) {
            i = 0;
            op[i] = '+';
            i++;
            op[i] = '\n';
            cp2_instr = cp1_instr;
            while (cp2_instr != 0) {
                dim4 = dim3;
                dim3 = dim2;
                dim2 = dim1;
                dim1 = cp2_instr % 2;
                cp2_instr = cp2_instr / 2;
            }
            Dim = (dim4 * 1 + dim3 * 2 + dim2 * 4 + dim1 * two_third_power) + 1;
        }

        // format: 000 0- ----
        if (remaining_zero == 1) {
            cp2_instr = cp1_instr;
            while (cp2_instr != 0) {
                dim4 = dim3;
                dim3 = dim2;
                dim2 = dim1;
                dim1 = op2;
                op2 = cp2_instr % 2;
                cp2_instr = cp2_instr / 2;
            }
            i = 0;
            if (op2 == 0) {
                op[i] = '+';
                i++;
            }
            if (op2 == 1) {
                op[i] = '-';
                i++;
            }
            op[i] = '\0';
            Dim = (dim4 * 1 + dim3 * 2 + dim2 * 4 + dim1 * two_third_power) + 1;
        }
    }

    // format 000 -- ----
    if (nr_zero == 3) {
        N = 1;
        cp2_instr = cp1_instr;
        while (cp2_instr != 0) {
            dim4 = dim3;
            dim3 = dim2;
            dim2 = dim1;
            dim1 = op2;
            op2 = op1;
            op1 = cp2_instr % 2;
            cp2_instr = cp2_instr / 2;
        }
        if (op1 == 0 && op2 == 0) {
            op[i] = '+';
            i++;
        }
        if (op1 == 0 && op2 == 1) {
            op[i] = '-';
            i++;
        }
        if (op1 == 1 && op2 == 0) {
            op[i] = '*';
            i++;
        }
        if (op1 == 1 && op2 == 1) {
            op[i] = '/';
            i++;
        }
        op[i] = '\0';
        Dim = (dim4 * 1 + dim3 * 2 + dim2 * 4 + dim1 * two_third_power) + 1;
    }

    // format 00- -- ---- (first_1 = first_2 = 0)
    if (nr_zero == 2) {
        cp2_instr = cp1_instr;
        while (cp2_instr != 0) {
            dim4 = dim3;
            dim3 = dim2;
            dim2 = dim1;
            dim1 = var2;
            var2 = var1;
            var1 = op2;
            op2 = op1;
            op1 = first_3;
            first_3 = cp2_instr % 2;
            cp2_instr = cp2_instr / 2;
        }

        N = (first_3 * 1) + 1;

        if (N == 1) {
            i = 0;
            if (op1 == 0 && op2 == 0) {
                op[i] = '+';
                i++;
            }
            if (op1 == 0 && op2 == 1) {
                op[i] = '-';
                i++;
            }
            if (op1 == 1 && op2 == 0) {
                op[i] = '*';
                i++;
            }
            if (op1 == 1 && op2 == 1) {
                op[i] = '/';
                i++;
            }
            op[i] = '\0';
            Dim = (dim2 * 1 + dim1 * 2 + var2 * 4 + var1 * two_third_power) + 1;
        }

        if (N == 2) {
            i = 0;
            if (op1 == 0 && op2 == 0) {
                op[i] = '+';
                i++;
            }
            if (op1 == 0 && op2 == 1) {
                op[i] = '-';
                i++;
            }
            if (op1 == 1 && op2 == 0) {
                op[i] = '*';
                i++;
            }
            if (op1 == 1 && op2 == 1) {
                op[i] = '/';
                i++;
            }
            if (var1 == 0 && var2 == 0) {
                op[i] = '+';
                i++;
            }
            if (var1 == 0 && var2 == 1) {
                op[i] = '-';
                i++;
            }
            if (var1 == 1 && var2 == 0) {
                op[i] = '*';
                i++;
            }
            if (var1 == 1 && var2 == 1) {
                op[i] = '/';
                i++;
            }
            op[i] = '\0';
            Dim = (dim4 * 1 + dim3 * 2 + dim2 * 4 + dim1 * two_third_power) + 1;
        }
    }

    // format 0-- -- ----
    if (nr_zero == 1) {
        cp2_instr = cp1_instr;
        while (cp2_instr != 0) {
            first_3 = first_2;
            first_2 = cp2_instr % 2;
            cp2_instr = cp2_instr / 2;
        }
        N = (first_2 * 2 + first_3 * 1) + 1;
        cp_N = N;
        while (cp_N != 0) {
            cp2_instr = cp1_instr;
            nr_division2 = nr_division1;
            while (cp2_instr != 0 && nr_division2 > divisions_allowed2) {
                op2 = op1;
                op1 = cp2_instr % 2;
                cp2_instr = cp2_instr / 2;
                nr_division2--;
            }
            cp_N--;
            if (cp_N != 0) {
                divisions_allowed2 = divisions_allowed2 + 2;
            }
            if (op1 == 0 && op2 == 0) {
                op[i] = '+';
                i++;
            }
            if (op1 == 0 && op2 == 1) {
                op[i] = '-';
                i++;
            }
            if (op1 == 1 && op2 == 0) {
                op[i] = '*';
                i++;
            }
            if (op1 == 1 && op2 == 1) {
                op[i] = '/';
                i++;
            }
            op[i] = '\0';
        }

        // calculates and prints the dimension
        cp2_instr = cp1_instr;
        divisions_allowed2 = divisions_allowed2 + 2;
        nr_division2 = nr_division1;
        while (nr_division2 > divisions_allowed2) {
            dim4 = dim3;
            dim3 = dim2;
            dim2 = dim1;
            dim1 = cp2_instr % 2;
            cp2_instr = cp2_instr / 2;
            nr_division2--;
        }
        Dim = (dim1 * two_third_power + dim2 * 4 + dim3 * 2 + dim4 * 1) + 1;
    }

    // if the instruction has exactly 32b
    if (nr_division1 == SIZE) {
        // forming N and printing it
        N = (first_3 * 1 + first_2 * 2 + first_1 * 4) + 1;
        cp_N = N;

        // memorising the codes for each operation in the variables op1, op2
        while (cp_N != 0) {
            cp2_instr = cp1_instr;
            nr_division2 = nr_division1;
            while (cp2_instr != 0 && nr_division2 > divisions_allowed) {
                op2 = op1;
                op1 = cp2_instr % 2;
                cp2_instr = cp2_instr / 2;
                nr_division2--;
            }
            cp_N--;
            if (cp_N != 0) {
                divisions_allowed = divisions_allowed + 2;
            }
            if (op1 == 0 && op2 == 0) {
                op[i] = '+';
                i++;
            }
            if (op1 == 0 && op2 == 1) {
                op[i] = '-';
                i++;
            }
            if (op1 == 1 && op2 == 0) {
                op[i] = '*';
                i++;
            }
            if (op1 == 1 && op2 == 1) {
                op[i] = '/';
                i++;
            }
            op[i] = '\0';
        }

        // calculates and prints the dimension
        cp2_instr = cp1_instr;
        divisions_allowed = divisions_allowed + 2;
        nr_division2 = nr_division1;
        while (nr_division2 > divisions_allowed) {
            dim4 = dim3;
            dim3 = dim2;
            dim2 = dim1;
            dim1 = cp2_instr % 2;
            cp2_instr = cp2_instr / 2;
            nr_division2--;
        }
        Dim = (dim1 * two_third_power + dim2 * 4 + dim3 * 2 + dim4 * 1) + 1;
    }

    // N, op, Dim contain the results from task 1
    // TASK 2

    double numbers = 0, cp_numbers = 0;
    int group = 0, power = 0;
    const double formula = ((N + 1) * Dim) / 16.0;
    numbers = formula;
    if (numbers > floor(numbers)) {
        numbers = floor(numbers) + 1;
    }

    unsigned short nr[SIZE], ops[SIZE] = {0}, digit = 0, value = 0, rank = 0;
    int j = 0, result = 0;
    cp_numbers = numbers;
    while (numbers != 0) {
        scanf("%hu", &nr[j]);
        j++;
        numbers--;
    }

    // converting the numbers to binary and grouping bits based on Dim size
    // converting each group to decimal and memorising the number in an array
    const unsigned int index = 16 / Dim - 1;
    const double nmbrs = 16 / Dim * cp_numbers;
    unsigned int q = index;
    int ok = 1;
    for (int t = 0; t < j; t++) {
        if (ok == 0) {
            q = q + (2 * Dim - 1);
        }
        ok = 0;
        group = 0;
        rank = -1;
        value = 1;
        while (nr[t] != 0) {
            digit = nr[t] % 2;
            rank++;
            if (group < Dim) {
                if (digit == 1) {
                    value = 1;
                    for (int k = 0; k < rank; k++) {
                        value = 2 * value;
                    }
                    ops[q] = ops[q] + value;
                }
            } else {
                rank = 0;
                value = 1;
                q--;
                if (q == -1) {
                    return 0;
                }
                if (digit == 1) {
                    ops[q] = ops[q] + value;
                }
                group = 0;
            }
            group++;
            nr[t] = nr[t] / 2;
        }
    }

    // final result based on the 2 vectors (op, ops)
    result = ops[0];
    for (int t = 1, k = 0; t < nmbrs; t++, k++) {
        switch (op[k]) {
            case '+':
                result = result + ops[t];
                break;

            case '-':
                result = result - ops[t];
                break;

            case '*':
                result = result * ops[t];
                break;

            case '/':
                result = result / ops[t];
                break;
        }
    }

    printf("%d\n", result);
    return 0;
}
