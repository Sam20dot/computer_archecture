#include <fcntl.h>
#include <unistd.h>

int main(void) {
    // 1. Ask kernel to open/create a file (returns FD 3)
    int fd = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd < 0) return 1;

    // 2. Unbuffered direct write to the file descriptor
    write(fd, "Hello Kernel!\n", 14);

    // 3. Close the file descriptor
    close(fd);

    return 0;
}
