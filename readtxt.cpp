#include <fstream>
#include <iostream>
#include <cstring>
#include <stdio.h>
#include <vector>
#include <dirent.h>
#include <sys/stat.h>
using namespace std;

int file_size(char *filename)
{
    struct stat statbuf;
    int ret;
    ret = stat(filename, &statbuf);
    if (ret != 0)
        return -1;
    return statbuf.st_size;
}

int main(int argc, char *argv[])
{
    //int f_size = file_size("C.txt");
    int f_size = 7341 * 2;
	unsigned char a[f_size];
    unsigned char data[f_size / 2];
    unsigned char tmp[2] = {0};
    
    char *srcbin = argv[1];
    cout << f_size << endl;

    FILE *infile;
    if ((infile = fopen(srcbin, "wb")) == NULL) {
        printf("file open failed \n");
        exit(-1);
    }
	ifstream in("C.txt");
	for (int i = 0; i <  f_size / 2; i++){
		in >> a[2 * i];
        if ((a[2 *i] >= 'A') && (a[2 * i] <= 'F')) {
            tmp[0] = a[2 * i] - 55;
        }

        if((a[2 * i] >= '0') && (a[2 * i] <= '9')) {
            tmp[0] = a[2 * i] - 0x30;
        }
        in >> a[2 * i + 1];
        if ((a[2 * i + 1] >= 'A') && (a[2 *i + 1] <= 'F')) {
            tmp[1] = a[2 *i + 1] - 55;
        }

        if((a[2 * i + 1] >= '0') && (a[2 * i + 1] <= '9')) {
            tmp[1] = a[2 * i + 1] - 0x30;
        }
        data[i] = tmp[0] * 0x10 + tmp[1];

    }
    fwrite(data, 1, sizeof(data), infile);
    in.close();
    fclose(infile);
}
