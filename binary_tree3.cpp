
#include  <stdio.h>
#include  <stdlib.h>
#include  <string.h>

#define  NO     1               /* 番号（入力・探索用）*/
#define  NAME   2               /* 氏名（入力・探索用）*/

/*--- メニュー ---*/
typedef enum {
  Term, Insert, Search, Delete, Print
} Menu;

/*--- 会員データ ---*/
typedef struct {
  int   no;                   /* 番号 */
  char  name[10];             /* 氏名（キー） */
} Data;

/*--- ノード ---*/
typedef struct __bnode {
  Data            data;           /* データ */
  struct __bnode  *left;          /* 左の子ノードへのポインタ */
  struct __bnode  *right;         /* 右の子ノードへのポインタ */
} BinNode;

/*--- データの氏名を比較 ---*/
int NameCmp(Data x, Data y)
{
  return (strcmp(x.name, y.name));
}

/*--- 一つのノードを動的に確保 ---*/
BinNode *AllocNode(void)
{
  return ((BinNode *)calloc(1, sizeof(BinNode)));
}

/*--- ノードの各メンバに値を設定 ----*/
void SetBinNode(BinNode *n, Data x, BinNode *left, BinNode *right)
{
  n->data  = x;                   /* データ */
  n->left  = left;                /* 左の子ノードへのポインタ */
  n->right = right;               /* 右の子ノードへのポインタ */
}

/*--- 氏名による探索 ---*/
BinNode *SearchNode(BinNode *p, Data x)
{
  int  cond;

  if (p == NULL)
    return (NULL);                                  /* 探索失敗 */
  else if ((cond = NameCmp(x, p->data)) == 0)
    return (p);                                     /* 探索成功 */
  else if (cond < 0)
    SearchNode(p->left,  x);                /* 左部分木から探索 */
  else
    SearchNode(p->right, x);                /* 右部分木から探索 */
}

/*--- ノードを挿入 ---*/
BinNode *InsertNode(BinNode *p, Data x)
{
  int  cond;

  if (p == NULL) {
    p = AllocNode();
    SetBinNode(p, x, NULL, NULL);
  } else if ((cond = NameCmp(x, p->data)) == 0)
    printf("【エラー】%sは既に登録されています。\n", x.name);
  else if (cond < 0)
    p->left  = InsertNode(p->left, x);
  else
    p->right = InsertNode(p->right, x);
  return (p);
}

/*--- ノードを削除 ---*/
int DeleteNode(BinNode **root, Data x)
{
  BinNode *next, *temp;
  BinNode **left;
  BinNode **p = root;

  while (1) {
    int cond;
    if (*p == NULL) {
      printf("【エラー】%sは登録されていません。\n", x.name);
      return (-1);        /* そのキーは存在しない */
    } else if ((cond = NameCmp(x, (*p)->data)) == 0)
      break;                          /* 探索成功 */
    else if (cond < 0)
      p = &((*p)->left);              /* 左部分木から探索 */
    else
      p = &((*p)->right);             /* 右部分木から探索 */
  }
  if ((*p)->left == NULL)
    next = (*p)->right;
  else {
    left = &((*p)->left);
    while ((*left)->right != NULL)
      left = &(*left)->right;
    next = *left;
    *left = (*left)->left;
    next->left  = (*p)->left;
    next->right = (*p)->right;
  }
  temp = *p;
  *p = next;
  free(temp);
  return (0);
}

/*--- データの番号と氏名を表示 ---*/
void PrintData(Data x)
{
  printf("番号：%d　氏名：%s\n", x.no, x.name);
}

/*--- 全ノードのデータを表示 ---*/
void PrintTree(BinNode *p)
{
  if (p != NULL) {
    PrintTree(p->left);
    PrintData(p->data);
    PrintTree(p->right);
  }
}

/*--- 全ノードを解放 ---*/
void FreeTree(BinNode *p)
{
  if (p != NULL) {
    FreeTree(p->left);
    FreeTree(p->right);
    free(p);
  }
}

/*--- データの入力 ---*/
Data Read(const char *message, int sw)
{
  Data  temp;

  printf("%sするデータを入力してください。\n", message);

  if (sw & NO)    { printf("番号：");   scanf("%d", &temp.no);  }
  if (sw & NAME)  { printf("名前：");   scanf("%s", temp.name); }

  return (temp);
}

/*--- メニュー選択 ---*/
Menu SelectMenu(void)
{
  int  ch;

  do {
    printf("\n(1)挿入  (2)探索  (3) 削除  (4)表示  (0)終了 ：");
    scanf("%d", &ch);
  } while (ch < Term  ||  ch > Print);
  return ((Menu)ch);
}

/*--- メイン関数 ---*/
int main(void)
{
  Menu     menu;
  BinNode  *root;

  root = NULL;
  do {
    Data  x;
    BinNode  *temp;

    switch (menu = SelectMenu()) {
    case Insert :  x = Read("挿入", NO | NAME);
      root = InsertNode(root, x); break;

    case Search :  x = Read("探索", NAME);
      if ((temp = SearchNode(root, x)) != NULL)
	PrintData(temp->data);
      break;

    case Delete :  x = Read("削除", NAME);
      if (DeleteNode(&root, x) != -1)
	printf("削除しました。\n");
      break;

    case Print  :  puts("【一覧表】");
      PrintTree(root);    break;
    }
  } while (menu != Term);

  FreeTree(root);

  return (0);
}
