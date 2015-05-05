#include <iostream>
//目的値
#define FIGURE 11

int main(void)
{
  //前もってソートしておく
  int test[10]={1,2,3,4,5,6,7,8,9,10};

  //配列の要素数を取得
  int number=sizeof(test)/sizeof(int);
  //最小の添字
  int min=0;
  //最大の添字
  int max=number-1;
  //中央の要素番号
  int mid;

  //最大値と最小値が一致するまでループ
  while(min <= max)
    {
      mid=(min+max)/2;

      //まず一致するか比較
    if(test[mid]==FIGURE){
      std::cout << "見つかりました" << std::endl;
      return 0;
    }else if(test[mid]<FIGURE){
      //目的値が中央値よりも上なら、最小値を中央値の一つ上に設定
      min=mid+1;

    }else if(test[mid]>FIGURE){
      //目的値が中央値よりも下なら、最大値を中央値の一つ下に設定
      max=mid-1;
    }
  }

  std::cout << "見つかりませんでした" << std::endl;

  return 0;
}
