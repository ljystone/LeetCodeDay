// NiuKeT01.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"


#include <stdio.h>

main()
{
	FILE * fp;
	int i, a[6] = { 1,2,3,4,5,6 }, k;
	fp = fopen("data.dat", "w+");
	for (i = 0; i < 6; i++)
	{
		fseek(fp, 0L, 0);
		fprintf(fp, "%d\n", a[i]);
		rewind(fp);
		fscanf(fp, "%d", &k);
	}
	fclose(fp);
	printf("%d\n", k);
}