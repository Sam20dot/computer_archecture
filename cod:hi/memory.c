#include <stdio.h>
#include <stdlib.h>
#include <stdint.h> // For uint64_t to hold absolute 64-bit numbers

int global_var = 100;

void print_binary_64(uint64_t num) {
    for (int i = 63; i >= 0; i--) {
        uint64_t bit = (num >> i) & 1;
        printf("%llu", (unsigned long long)bit);
        if (i % 8 == 0 && i != 0) printf(" "); // Space every byte for clarity
    }
}

int main() {
    int local_stack_var = 50;
    int *heap_var = (int*)malloc(sizeof(int));

    // 1. Establish the Absolute Theoretical Theoretical Boundaries of 2^64
    uint64_t absolute_min = 0x0ULL;
    uint64_t absolute_max = 0xFFFFFFFFFFFFFFFFULL; // 2^64 - 1

    printf("====================================================================================\n");
    printf("THEORETICAL 64-BIT MEMORY ARCHITECTURE MAP ($2^{64}$ Bytes)\n");
    printf("====================================================================================\n");
    
    printf("Absolute Minimum Address (0):\n");
    printf("Hex: 0x%016llx\n", (unsigned long long)absolute_min);
    printf("Bin: "); print_binary_64(absolute_min); printf("\n\n");

    printf("Absolute Maximum Address ($2^{64} - 1$):\n");
    printf("Hex: 0x%016llx\n", (unsigned long long)absolute_max);
    printf("Bin: "); print_binary_64(absolute_max); printf("\n");
    printf("====================================================================================\n\n");

    // 2. Print Active Operational Occupations (Where your code actually lands)
    printf("====================================================================================\n");
    printf("ACTUAL RUNTIME OCCUPATIONS WITHIN THE RUNNING APPLICATION\n");
    printf("====================================================================================\n");

    // Code Segment
    uint64_t code_addr = (uint64_t)main;
    printf("1. Code Segment Occupation (Instructions/Text):\n");
    printf("   Hex: 0x%016llx | Pointer Name: main()\n", (unsigned long long)code_addr);
    printf("   Bin: "); print_binary_64(code_addr); printf("\n\n");

    // Global Data Segment
    uint64_t global_addr = (uint64_t)&global_var;
    printf("2. Data Segment Occupation (Global Static Storage):\n");
    printf("   Hex: 0x%016llx | Pointer Name: &global_var\n", (unsigned long long)global_addr);
    printf("   Bin: "); print_binary_64(global_addr); printf("\n\n");

    // Heap Segment
    uint64_t heap_addr = (uint64_t)heap_var;
    printf("3. Heap Segment Occupation (Dynamic Runtime Allocation):\n");
    printf("   Hex: 0x%016llx | Pointer Name: heap_var\n", (unsigned long long)heap_addr);
    printf("   Bin: "); print_binary_64(heap_addr); printf("\n\n");

    // Stack Segment
    uint64_t stack_addr = (uint64_t)&local_stack_var;
    printf("4. Stack Segment Occupation (Local Function Context):\n");
    printf("   Hex: 0x%016llx | Pointer Name: &local_stack_var\n", (unsigned long long)stack_addr);
    printf("   Bin: "); print_binary_64(stack_addr); printf("\n");
    printf("====================================================================================\n");

    free(heap_var);
    return 0;
}
