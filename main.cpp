

#include <iostream>

using namespace std;

int result(int, int);
void main1();
void main2();
const int k = 2;

struct Point {
    int x, y;
};

int main(){

    main2();
    return 0;
}

void main1() {
    int z(0), b(50);//调用构造函数，等同于z = 50
    Point a;
    cout << "输入两个整数（以空格区分）：";
    cin >> a.x >> a.y;
    z = (a.x + a.y) * k;
    z = result(z, b);
    cout << "计算结果如下：" << endl;
    cout << "((" << a.x << "+" << a.y << ")*" << k << ")+" << b << "=" << z << endl;
}

int result(int a, int b) {
    return a + b;
}


void main2() {
    double *pDouble = new double[3];
    for (int i = 0; i < 3; i++) {
        cin >> *(pDouble + i);
    }

    for (int j = 0; j <3; j++) {
        cout<< *(pDouble+j) <<" ";
    }
    delete pDouble;
}




