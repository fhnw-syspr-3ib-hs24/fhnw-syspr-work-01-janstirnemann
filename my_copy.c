#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>


int main(int argc, char *argv[]){
    size_t n = 32; // Buffer size
    char buf[n];
    // read
    int readFileDescriptor = open(argv[1], O_RDONLY);

    //write
    int fileDescriptor = open(argv[2], O_WRONLY| O_CREAT | O_TRUNC | O_APPEND, S_IRUSR | S_IWUSR);


    ssize_t r = read(readFileDescriptor, buf, 32);
    ssize_t w = write(fileDescriptor, buf, r);
    // read the whole text with buffer
    while ( r > 0){
        //write(STDOUT_FILENO, buf, r);
        r = read(readFileDescriptor, buf, n);
        w = write(fileDescriptor, buf, n);
    }
    return 0;
}