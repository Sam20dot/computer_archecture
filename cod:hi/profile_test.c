#include <stdio.h>
#include <unistd.h>

#define COMPUTE_LIMIT 500000000  // Adjust if your CPU is ultra-fast
#define SYS_CALL_LIMIT 500000    // Number of kernel writes

int main() {
    printf("🚀 Starting 3-Second Profiling Experiment...\n");

    // ==========================================
    // PART 1: GENERATING USER CPU TIME (~1.0s)
    // ==========================================
    // This loop stays entirely in User Space doing pure math.
    volatile unsigned long long counter = 0;
    for (unsigned long long i = 0; i < COMPUTE_LIMIT; i++) {
        counter += i ^ 0x55; 
    }

    // ==========================================
    // PART 2: GENERATING SYSTEM CPU TIME (~1.0s)
    // ==========================================
    // Opening a dummy null device to blast system writes to the kernel.
    FILE *dev_null = fopen("/dev/null", "w");
    if (dev_null != NULL) {
        for (int i = 0; i < SYS_CALL_LIMIT; i++) {
            // fprintf forces a context switch into Kernel Mode
            fprintf(dev_null, "%d", i); 
        }
        fclose(dev_null);
    }

    // ==========================================
    // PART 3: GENERATING WAITING/REAL TIME (~1.0s)
    // ==========================================
    // This tells the OS to put our thread to sleep for exactly 1 second.
    // The CPU drops to 0% usage here, but the wall-clock keeps ticking.
    sleep(1); 

    printf("🏁 Experiment Finished!\n");
    return 0;
}
