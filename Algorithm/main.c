#include <stdio.h>
#include "search.h"

struct Section {
	char* title;
	void (*func)(void);
};

// �T���A���S���Y���Z�N�V����
struct Section SEARCH_SECTIONS[] = {
	{"���`�T���@", search_sequential},
	{"���`�T���@(�ԕ�)", search_sequential_sentinel},
};

// �Z�N�V�����̐�
const int SECTION_COUNT = sizeof(SEARCH_SECTIONS) / sizeof(struct Section);

/// <summary>
/// �G���g���[�|�C���g
/// </summary>
int main(void) {

	// �Z�N�V�����̑I��
	int sectionIndex = 0;
	printf("�Z�N�V�����ԍ���I�����Ă�������\n\n");

	for (int i = 0; i < SECTION_COUNT; ++i) {
		printf("[%d] %s\n", i, SEARCH_SECTIONS[i].title);
	}

	scanf_s("%d", &sectionIndex);

	if (0 <= sectionIndex && sectionIndex < SECTION_COUNT) {
		SEARCH_SECTIONS[sectionIndex].func();
	}

	return 0;
}