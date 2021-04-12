#include <stdio.h>
#include "search.h"

struct Section {
	char* title;
	void (*func)(void);
};

// 探索アルゴリズムセクション
struct Section SEARCH_SECTIONS[] = {
	{"線形探索法", search_sequential},
	{"線形探索法(番兵)", search_sequential_sentinel},
	{"二分探索法", search_binary},
};

// セクションの数
const int SECTION_COUNT = sizeof(SEARCH_SECTIONS) / sizeof(struct Section);

/// <summary>
/// エントリーポイント
/// </summary>
int main(void) {

	while (1) 
	{
		// セクションの選択
		int sectionIndex = 0;
		printf("セクション番号を選択してください\n\n");

		for (int i = 0; i < SECTION_COUNT; ++i) {
			printf("[%d] %s\n", i, SEARCH_SECTIONS[i].title);
		}

		scanf_s("%d", &sectionIndex);

		if (0 <= sectionIndex && sectionIndex < SECTION_COUNT) {
			SEARCH_SECTIONS[sectionIndex].func();
		}
		else {
			break;
		}
	}


	return 0;
}