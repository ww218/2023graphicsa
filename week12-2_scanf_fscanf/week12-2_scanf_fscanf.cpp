#include <stdio.h>
int main()
{
    FILE * fin = fopen("file.txt","r");///r:read

    char line[100];
    fscanf(fin,"%s",line);
    printf("�qfile.txtŪ��F: %s\n",line);

    fscanf(fin,"%s",line);
    printf("�qfile.txtŪ��F: %s\n",line);
}
