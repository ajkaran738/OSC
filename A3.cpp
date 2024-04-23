#include <iostream>
#include <unistd.h>
#include <cstring>
#include <sys/types.h>

using namespace std;

int main() {
    int fd1[2], fd2[2];
    char str1[] = "Hello Child Process from Parent Process";
    char str2[] = "Hello Parent Process from Child Process";

    if (pipe(fd1) == -1 || pipe(fd2) == -1) {
        perror("Pipe Failed");
        return 1;
    }

    pid_t pid = fork();

    if (pid < 0) {
        perror("Fork Failed");
        return 1;
    }

    if (pid > 0) {
        close(fd1[0]);
        write(fd1[1], str1, strlen(str1) + 1);
        close(fd1[1]);

        close(fd2[1]);
        char buffer[100];
        ssize_t nbytes = read(fd2[0], buffer, sizeof(buffer));
        if (nbytes >= 0) {
            buffer[nbytes] = '\0';
            cout << buffer << endl;
        }
        close(fd2[0]);
    } else {
        close(fd1[1]);
        char buffer[100];
        ssize_t nbytes = read(fd1[0], buffer, sizeof(buffer));
        if (nbytes >= 0) {
            buffer[nbytes] = '\0';
            cout << buffer << endl;
        }
        close(fd1[0]);

        close(fd2[0]);
        write(fd2[1], str2, strlen(str2) + 1);
        close(fd2[1]);
    }

    return 0;
}
