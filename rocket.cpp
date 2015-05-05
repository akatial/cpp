//RocketSample.cpp
#include <iostream>
using namespace std;

class Rocket         //改良版ロケット
{
    int nenryo;      //燃料
    int sokudo;      //現在の速度
public:
    Rocket(int x);   //コンストラクタ
    void kasoku();   //加速を表す関数
};

//コンストラクタの定義
Rocket::Rocket(int x) : nenryo(x), sokudo(0){}

//加速を表す関数の定義
void Rocket::kasoku()
{
    if(nenryo >= 2){
        sokudo += 2;
        nenryo -= 2;
        cout<< "現在の燃料は" << nenryo << "です。" << endl;
        cout<< "現在の速度は" << sokudo << "です。" << endl;
    }
    else{
        cout << "燃料切れです。加速できません。漂流です。" <<endl;
    }
}

int main()
{
    cout << "ロケットをメモリ上につくります。燃料（整数）を入力してください。"<<endl;
    int n;       //ユーザの入力した値を格納する変数をひとつ用意しました。その名はnです。
    cin >> n;    //ユーザの入力した数字をnに代入しました。

    //nをコンストラクタに渡してロケットをつくります。
    Rocket ohtori(n); //これでnの値がコンストラクタの定義のxにコピーされ、
                      //コンストラクタの中身が実行され、nenryoの値がnの値に
                      //なったロケットohtori（鳳号）が生成されるわけです。
                      //このohtoriをオブジェクトなどとよぶのでした。
    cout<< "加速します。" <<endl;
    ohtori.kasoku();  //ohtoriに対してkasokuを使っています
    cout<< "また、加速します。" <<endl;
    ohtori.kasoku();  //ohtoriに対してkasokuを使っています
    cout<< "またまた、加速してみます。" <<endl;
    ohtori.kasoku();  //ohtoriに対してkasokuを使っています
    cout<< "鳳号の冒険は終わりました。" <<endl;
}
