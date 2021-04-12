#include <stdio.h>
#include "common.h"

/// <summary>
/// ヘッダを表示する関数
/// </summary>
void drawHeader(char* title) {
	printf("--------------------------------------------------\n");
	printf("- %s\n", title);
	printf("--------------------------------------------------\n");
}