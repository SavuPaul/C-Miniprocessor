#include <stdio.h>
#define MAX_OPERATIONS 9
#define SIZE 32

int main() {
    const int two_third_power = 8;
    unsigned int instr = 0, N = 0, cp1_instr = 0, cp2_instr = 0,
                first_1 = 0, first_2 = 0, first_3 = 0, nr_zero = 0,
                remaining2_zero = 0, remaining_zero = 0,
                op1 = 0, op2 = 0, i = 0, var1 = 0, var2 = 0,
                dim = 0, dim1 = 0, dim2 = 0, dim3 = 0, dim4 = 0;
    int nr_division1 = 0, nr_division2 = 0,
        divisions_allowed = 3, divisions_allowed2 = 2;
    char op[MAX_OPERATIONS];

    // reads the instruction
    scanf("%u", &instr);
    cp1_instr = instr;

    if (instr == 0) {
        printf("1 + 1\n");
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
        printf("%d ", N);
        remaining_zero = nr_zero - 3;

        // format 000 00 0--- or 000 00 00-- or 000 00 000- or 000 00 0000
        if (remaining_zero > 2) {
            printf("+ ");
            remaining2_zero = remaining_zero - 2;
            switch (remaining2_zero) {
                case 4:
                    printf("1\n");
                    break;
                case 3:
                    dim = 1 + (1 * first_1);
                    printf("%d\n", dim);
                    break;
                case 2:
                    dim = 1 + (1 * first_2 + 2 * first_1);
                    printf("%d\n", dim);
                    break;
                case 1:
                    dim = 1 + (1 * first_3 + 2 * first_2 + 4 * first_1);
                    printf("%d\n", dim);
                    break;
                default:
                    printf("1\n");
            }
        }

        // format: 000 00 ----
        if (remaining_zero == 2) {
            printf("+ ");
            cp2_instr = cp1_instr;
            while (cp2_instr != 0) {
                dim4 = dim3;
                dim3 = dim2;
                dim2 = dim1;
                dim1 = cp2_instr % 2;
                cp2_instr = cp2_instr / 2;
            }
            dim = (dim4 * 1 + dim3 * 2 + dim2 * 4 + dim1 * two_third_power) + 1;
            printf("%d\n", dim);
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
            if (op2 == 0) {
                printf("+ ");
            }
            if (op2 == 1) {
                printf("- ");
            }
            dim = (dim4 * 1 + dim3 * 2 + dim2 * 4 + dim1 * two_third_power) + 1;
            printf("%d\n", dim);
        }
    }

    // format 000 -- ----
    if (nr_zero == 3) {
        N = 1;
        printf("%d ", N);
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
            printf("+ ");
        }
        if (op1 == 0 && op2 == 1) {
            printf("- ");
        }
        if (op1 == 1 && op2 == 0) {
            printf("* ");
        }
        if (op1 == 1 && op2 == 1) {
            printf("/ ");
        }
        dim = (dim4 * 1 + dim3 * 2 + dim2 * 4 + dim1 * two_third_power) + 1;
        printf("%d\n", dim);
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
        printf("%u ", N);

        if (N == 1) {
            if (op1 == 0 && op2 == 0) {
                printf("+ ");
            }
            if (op1 == 0 && op2 == 1) {
                printf("- ");
            }
            if (op1 == 1 && op2 == 0) {
                printf("* ");
            }
            if (op1 == 1 && op2 == 1) {
                printf("/ ");
            }
            dim = (dim2 * 1 + dim1 * 2 + var2 * 4 + var1 * two_third_power) + 1;
            printf("%d\n", dim);
        }

        if (N == 2) {
            if (op1 == 0 && op2 == 0) {
                printf("+ ");
            }
            if (op1 == 0 && op2 == 1) {
                printf("- ");
            }
            if (op1 == 1 && op2 == 0) {
                printf("* ");
            }
            if (op1 == 1 && op2 == 1) {
                printf("/ ");
            }
            if (var1 == 0 && var2 == 0) {
                printf("+ ");
            }
            if (var1 == 0 && var2 == 1) {
                printf("- ");
            }
            if (var1 == 1 && var2 == 0) {
                printf("* ");
            }
            if (var1 == 1 && var2 == 1) {
                printf("/ ");
            }
            dim = (dim4 * 1 + dim3 * 2 + dim2 * 4 + dim1 * two_third_power) + 1;
            printf("%d\n", dim);
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
        printf("%u ", N);
        while (N != 0) {
            cp2_instr = cp1_instr;
            nr_division2 = nr_division1;
            while (cp2_instr != 0 && nr_division2 > divisions_allowed2) {
                op2 = op1;
                op1 = cp2_instr % 2;
                cp2_instr = cp2_instr / 2;
                nr_division2--;
            }
            N--;
            if (N != 0) {
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

        // prints the operations from the instruction
        for (int j = 0; j < i; j++) {
            printf("%c ", op[j]);
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
        dim = (dim1 * two_third_power + dim2 * 4 + dim3 * 2 + dim4 * 1) + 1;
        printf("%d\n", dim);
    }

    // if the instruction has exactly 32b
    if (nr_division1 == SIZE) {
        // forming N and printing it
        N = (first_3 * 1 + first_2 * 2 + first_1 * 4) + 1;
        printf("%u ", N);

        // memorising the codes for each operation in the variables op1, op2
        while (N != 0) {
            cp2_instr = cp1_instr;
            nr_division2 = nr_division1;
            while (cp2_instr != 0 && nr_division2 > divisions_allowed) {
                op2 = op1;
                op1 = cp2_instr % 2;
                cp2_instr = cp2_instr / 2;
                nr_division2--;
            }
            N--;
            if (N != 0) {
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

        // prints the operations from the instruction
        for (int j = 0; j < i; j++) {
            printf("%c ", op[j]);
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
        dim = (dim1 * two_third_power + dim2 * 4 + dim3 * 2 + dim4 * 1) + 1;
        printf("%d\n", dim);
    }

    return 0;
}
