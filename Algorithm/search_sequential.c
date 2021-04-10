//-----------------------------------------------------------------------------
// 線形探索法による探索アルゴリズム
//-----------------------------------------------------------------------------
#include <stdio.h>
#include "common.h"
#include "search.h"

// 配列のサイズ
#define SIZE 100

/// <summary>
/// 線形探索のメインの処理
/// </summary>
void search_sequential(void) {
  
  // 配列を準備
  const int NUMS[SIZE] = {
    15, 99, 20, 96, 32, 44,  7, 54, 61, 68,
     2, 24,  8, 72, 37,  6, 25, 98, 74, 52,
    56, 88, 11, 35, 18, 40, 31, 79, 26, 42,
    36, 73, 59, 67,  9, 76, 85, 92, 41, 14,
    86, 13, 27,  0, 94, 30, 84, 62, 87, 22,
    39, 89, 90, 80, 58, 38, 97, 23, 81, 50,
    91, 47, 53, 71, 55, 12, 82, 95, 63, 57,
    69,  1, 49, 77, 75,  3, 34, 46, 70, 43,
    64, 33, 16, 17, 48, 21, 10,  5, 60, 93,
    28, 29, 78, 65, 51, 66, 19, 45, 83,  4
  };

  int num = 0;

  // データ入力
  drawHeader("線形探索法アルゴリズム");
  printf("検索したい数値を入力してください:");
  scanf_s("%d", &num);

  // 数値を検索
  int foundIndex = search(num, NUMS, SIZE);

  if (foundIndex == -1) {
    printf("%dは見つかりませんでした。\n", num);
  }
  else {
    printf("%d は配列の %d番目 に見つかりました。\n", num, foundIndex);
  }
}

/// <summary>
/// 線形探索法によって配列「nums[size]」から指定された数値「num」を探し
/// 見つかった場所を返す、見つからなかった場合は-1を返す
/// </summary>
static int search(int num, int nums[], int size)
{
  for (int i = 0; i < size; ++i) {
    if (nums[i] == num) {
      return i;
    }
  }

  return -1;
}

