//-----------------------------------------------------------------------------
// 二分探索法による探索アルゴリズム
// 2分探索法は検索対象の配列が昇順や降順で並んでいる事が前提となる。
// 
//-----------------------------------------------------------------------------
#include <stdio.h>
#include "common.h"
#include "search.h"

// 配列のサイズ
#define SIZE 100

/// <summary>
/// 探索
/// </summary>
static int search(int num, const int nums[], int size)
{
  int s = 0;        // 始点
  int e = SIZE - 1; // 終点

  // 二分探索法による数値探索
  return binary_search(num, nums, s, e);
}

/// <summary>
/// 二分探索法による探索
/// </summary>
/// <param name="num">探す数</param>
/// <param name="nums">数値配列(昇順)</param>
/// <param name="s">始点</param>
/// <param name="e">終点</param>
/// <returns>見つかった位置(index)、見つからなければ-1</returns>
static int binary_search(int num, const int nums[], int s, int e) 
{
  // 始点と終点が入れ替わっていたら見つからなかったということ
  if (e < s) return -1;

  // 中央のIndexを求める
  int c = (s + e) / 2;

  // 一致するものが見つかったらその場所を返す
  if (nums[c] == num) {
    return c;
  }

  // 探しているもの数が右側にある場合は、開始位置を変えて再探索
  if (nums[c] < num) {
    return binary_search(num, nums, c + 1, e);
  }

  // 探しているもの数が左側にある場合は、終了位置を変えて再探索
  if (num < nums[c]) {
    return binary_search(num, nums, s, c - 1);
  }
}

/// <summary>
/// メインの処理
/// </summary>
void search_binary(void) {

  // 配列を準備
  const int NUMS[SIZE] = {
     0,  1,  2,  3,  4,  5,  6,  7,  8,  9,
    10, 11, 12, 13, 14, 15, 16, 17, 18, 19,
    20, 21, 22, 23, 24, 25, 26, 27, 28, 29,
    30, 31, 32, 33, 34, 35, 36, 37, 38, 39,
    40, 41, 42, 43, 44, 45, 46, 47, 48, 49,
    50, 51, 52, 53, 54, 55, 56, 57, 58, 59,
    60, 61, 62, 63, 64, 65, 66, 67, 68, 69,
    70, 71, 72, 73, 74, 75, 76, 77, 78, 79,
    80, 81, 82, 83, 84, 85, 86, 87, 88, 89,
    90, 91, 92, 93, 94, 95, 96, 97, 98, 99
  };

  int num = 0;

  // データ入力
  drawHeader("二分探索法アルゴリズム");
  printf("検索したい数値を入力してください:");
  scanf_s("%d", &num);

  // 数値を検索
  int foundIndex = search(num, NUMS, SIZE);

  if (foundIndex == -1) {
    printf("%dは見つかりませんでした。\n", num);
  }
  else {
    printf("%d は nums[%d] に見つかりました。\n", num, foundIndex);
  }
}