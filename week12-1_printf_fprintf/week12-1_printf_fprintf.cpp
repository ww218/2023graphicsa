#include <stdio.h>
int main()
{///檔案指標fout= 開檔案("檔名","用什麼模式")
    FILE * fout = fopen("file.txt","w");///w:write
    printf("Hello World!\n");
    fprintf(fout,"Hello World!在桌面!");
}
