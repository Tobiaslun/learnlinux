#include "ch2.h"
int main()
{
	FILE *fp=fdopen(1,"w+");
	fprintf(fp,"%s\n","hello!");
	fclose(fp);
}
