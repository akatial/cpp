#include "stdafx.h"
#include <windows.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

/*!
	@brief ゲームの局面を表現する型

	便宜上以下の局面を二進数で100000001000001000と表現する

	    | | |
	  | | | | |
	| | | | | | |
 
 */
typedef DWORD32 BOARD;

const int BOARD_SIZE = (3+1+5+1+7+1);

const int SENTE = 1; //! 先手番
const int GOTE = 0;  //! 後手番
const int CHILD_NODE_MAX = 128;
const int MAX_NODE_PATH = 128;

/*!
	@brief 各局面の評価値保存用変数
 */
struct node_t{
	//! この局面で手番を持っている側から見た評価値
	double value;
	//! この局面の評価回数
	int    count;
}gBoardNode[1<<(BOARD_SIZE+1)];;

/*!
	@brief 0～1の乱数を生成
	@return 乱数
 */
double random()
{
	return (double)rand() / ((double)RAND_MAX + 1.0);
}

/*!
	@brief 局面を出力
	@param[in] board 局面
 */
void printBoard(BOARD board)
{
	for ( int i = 0; i < 18; i++) {
		if ( board & (1 << i) ){
			printf("x");
		}else{
			printf("o");
		}
	}
	printf("\n");
}

/*!
	@brief 1手指すことで、推移可能な局面をリストアップ
	@param[in] root 現在の局面
	@param[out] childNode 遷移可能な局面
	@return 遷移可能な局面数
 */
int legalMove(BOARD root, BOARD childNode[])
{
	int size = 0;
	for (int i = 0; i < BOARD_SIZE; i++){
		BOARD action = 0x1 << i;
		while(1){
			if (action & root){
				break;
			}
			childNode[size++] = root | action;
			action = action | action << 1;
		}
	}
	return size;
}

/*!
	@brief 盤面を初期化
	@param[out] pBorad 盤面のポインタ
 */
void initBorad(BOARD *pBorad)
{
	*pBorad = 0 | (0x1 << 3) | (0x1 << (3+1+5)) | (0x1 <<(3+1+5+1+7));

}

/*!
	@brief モンテカルロシミュレートを実行
	@param[in] node 開始時点のボードの状態
	@param[in] turn 先手番/後手番(Negamaxにしてるから常に先手番として呼んでいる)
	@return    勝者
 */
int monte(BOARD node, int turn)
{
	BOARD childNode[CHILD_NODE_MAX];

	while(1){
		int size = legalMove(node, childNode);
		if (size == 0){
			return turn;
		}else{
			node = childNode[(int)(random() * size)];
			turn = 1 - turn;
		}
	}
}

/*!
	@breif UCB1を用いてモンテカルロシミュレートする開始局面を選択する
	@param[in] root 現在の局面
	@return モンテカルロする局面
 */
BOARD descendByUCB1(BOARD root)
{
	BOARD nextPhase[CHILD_NODE_MAX];
	int totalCount = 0;

	int size = legalMove(root, nextPhase);
	for ( int i = 0; i < size; i++ ){
		if ( gBoardNode[nextPhase[i]].count == 0){
			return (BOARD)nextPhase[i];
		}
		totalCount += gBoardNode[nextPhase[i]].count;
	}
	double bestValue = -1.0; // -INFINITY
	BOARD bestPhase = 0;
	for ( int i = 0; i < size; i++ ){
		double value = (1.0 - gBoardNode[nextPhase[i]].value/gBoardNode[nextPhase[i]].count) + 
			           sqrt((2*log((double)totalCount))/(gBoardNode[nextPhase[i]].count));
		if (bestValue < value){
			bestValue = value;
			bestPhase = nextPhase[i];
		}
	}
	return bestPhase;
}

/*!
	ノードの評価値をパスを上りながら更新していく
	@param[in] path 更新するノードのパス
	@paran[in] len pathの長さ
	@paran[in] 更新値
 */
void updateNode(BOARD path[], int len, double value)
{
	for (int i = len-1; i >= 0; i-- ){
		gBoardNode[path[i]].value += value;
		gBoardNode[path[i]].count += 1;
		value = 1.0 - value;
	}
}

/*!
	@brief UCTによるプレイシーケンス
	@param[in] root 開始局面
 */
void playOne(BOARD root)
{
	BOARD path[MAX_NODE_PATH];
	int index = 0;
	BOARD nextPhase = root;
	path[index++] = nextPhase;
	while(gBoardNode[nextPhase].count != 0){
		nextPhase = descendByUCB1(path[index-1]);
		if (nextPhase == 0){
			break;
		}
		path[index++] = nextPhase;
	}
	nextPhase = path[index-1];
	int winner = monte(nextPhase, SENTE);
	updateNode(path, index, (double)winner);

}

/*!
	@brief qsort用比較関数
	@param[in] p1 比較ノードの局面(BOARD*型)
	@param[in] p1 比較ノードの局面(BOARD*型)
	@return 比較結果
 */
int compare(const void *p1, const void *p2)
{

	int v1 = *(BOARD*)p1;
	int v2 = *(BOARD*)p2;
	double v = gBoardNode[v1].value / gBoardNode[v1].count - gBoardNode[v2].value / gBoardNode[v2].count;
	if (v < 0){
		return -1;
	}else if (v == 0){
		return 0;
	}else{
		return 1;
	}
}


int _tmain(int argc, _TCHAR* argv[])
{

	BOARD board;
	initBorad(&board);
	const int N_TEST = 1000000; //!試験回数
	for ( int i = 0; i < N_TEST; i++ ){
		playOne(board);
	}

	BOARD nextPhase[CHILD_NODE_MAX];
	int size = legalMove(board, nextPhase);
	printf("=========result=====\n");
	qsort(nextPhase, size, sizeof(BOARD), compare);
	for (int i = 0; i < size; i++ ){
		printBoard(nextPhase[i]);
		printf("%lf[%4d]\n", 1-gBoardNode[nextPhase[i]].value / gBoardNode[nextPhase[i]].count,
		                     gBoardNode[nextPhase[i]].count);
	}
	getchar();
	return 0;
}
