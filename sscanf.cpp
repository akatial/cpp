#include <stdio.h>

main() {
  int ret;
  char instr[] = "abc 123\t456\n789";
  char cout[4];
  int iout1;
  int iout2;
  int iout3;

  /* 文字列instrから各変数に変換して代入 */
  ret = sscanf( instr , "%3s%d%d%d" , cout
                           , &iout1 , &iout2 , &iout3 );
  if( ret == EOF ) {
    printf( "sscanfでエラー\n" );
    return -1;
  }

  /* 変換して代入された変数を表示 */
  printf( "cout=%s\n" , cout );/* abc */
  printf( "iout1=%d\n" , iout1 );/* 123 */
  printf( "iout2=%d\n" , iout2 );/* 456 */
  printf( "iout3=%d\n" , iout3 );/* 789 */
  printf( "ret=%d\n" , ret );/* 4(取り込んだ件数) */

  return 0;
}
