
#include <iostream>
#include <cstring>
#include <fstream>
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

int get_file_size(char *filename)
{
    FILE *fp = fopen(filename, "rb");
    int size;
    if (fp == NULL) {
        printf("file open failed\n");
        return -1;
    }
    fseek(fp, 0, SEEK_END);
    size = ftell(fp);
    fclose(fp);
    return size;
}

void readTxt(string file)
{
    fstream infile; 
   // infile.open(file.data());   //将文件流对象与文件连接起来 
   // assert(infile.is_open());   //若失败,则输出错误消息,并终止程序运行 

    infile.open("C.txt", std::ios::app);
    if (!infile.is_open()) {
        printf("file openfile\n");
    }
    string s;
    while(getline(infile,s))
    {
        cout<<s<<endl;
    }
    infile.close();             //关闭文件输入流 
}

int main(int argc, char *argv[])
{
#if 0
    FILE *test;
    float buffer[] = {2.0, 3.0, 5.0};
    test = fopen("myfile.bin", "wb");
    fwrite(buffer, 1, sizeof(buffer), test);
    fclose(test);
    float readdata[3] = {0};
    test = fopen("myfile.bin", "rb");
    fread(readdata, 1, sizeof(readdata), test);
    printf("%f %f %f\n", readdata[0], readdata[1], readdata[2]);
#endif

    FILE *infile;
    fstream f_txt;
    char *srcbin = argv[1];
    int size = file_size(srcbin);
    unsigned char val[size];
    unsigned char data[size];
#if 0
    f_txt.open("C.txt", std::ios::app);
    if (!f_txt.is_open()) {
        printf("file openfile\n");
        return -1;
    }
    if ((infile = f4yyopen(srcbin, "rb")) == NULL) {
        printf("file open failed \n");
        exit(-1);
    }
#endif    
	readTxt("C.txt");
    //fwrite();
    //f_txt.close();
     
    return 0;
}

