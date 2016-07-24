#include <iostream>
#include <algorithm>
#include <iterator>
#include <iomanip>
#include <cstring>

using namespace std;

int result(int, int);

void main1();

void main2();

const int k = 2;

struct Point {
    int x, y;
};


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
        cout << "请输入一个数字" << endl;
        cin >> *(pDouble + i);
    }

    for (int j = 0; j < 3; j++) {
        cout << *(pDouble + j) << " ";
    }
    delete pDouble;
}

void constTest() {
    int *p1 = new int(5);
    int *&p2 = p1;

    //  int * * p3 = &p1;

    const int y = 58; //常量，不能改变值
    const int *p = &y;//指向常量的指针
//    * p =  2;

    cout << *p << endl;
    cout << p << endl;
    cout << &p << endl;
    cout << y << endl;
    cout << &y << endl;
}

//1.6

bool compare(int a, int b) {

    return a > b;
}

void coutArray() {
    double a[4] = {1.1, 4.4, 3.3, 2.2}, b[4];
    // 数组复制到流中输出  p1:开始位置，p2： 结束位置 p3：输出流
    cout << "数组a" << endl;
    copy(a, a + 4, ostream_iterator<double>(cout, " "));

    cout << endl;
    cout << "逆向输出数组a" << endl;
    reverse_copy(a, a + 4, ostream_iterator<double>(cout, " "));
    cout << endl;

    //复制到数组b p1:开始位置，p2： 结束位置 p3，数组开始
    copy(a, a + 4, b);
    //输出数组b
    cout << "数组a" << endl;
    copy(b, b + 4, ostream_iterator<double>(cout, " "));
    cout << endl;
    /* for (int i = 0; i < 4; ++i) {
         cout << b[i] << endl;
     }*/

    //对数组a进行排序
    sort(a, a + 4); //默认升序排序
//    sort(a,a+4,compare) 降序排序 ,自己实现
    //    sort(a, a + 4, greater<double>()); // less<数据类型>()//从小到大排序 greater<数据类型>()//从大到小排序
    cout << "升序输出a" << endl;
    copy(a, a + 4, ostream_iterator<double>(cout, " "));
    cout << endl;

    cout << "逆向copy数组a到b" << endl;
    reverse_copy(a, a + 4, b);
    copy(b, b + 4, ostream_iterator<double>(cout, " "));
    cout << endl;


    double a1[4] = {1.1, 3.3, 2.2, 4.4};
    double *x = find(a1, a1 + 4, 4.4);

    //x的地址超出a1地址范围就是没有找到
    cout << (x == a1 + 3) << endl;
    if (x == a1 + 4) {
        cout << "没有找到值为4.4的元素" << endl;
    } else {
        cout << "有值为" << *x << "的数组元素" << endl;
    }
    delete x;


    //double i 每加一，内存地址增加8个字节 double类型8个字节，64位
    for (int i = 0; i < 4; ++i) {
        cout << "a1+" << i << " = " << a1 + i << "    value = " << a1[i] << endl;
    }
    cout << "x = " << x << "    *x = " << *x << endl;

    // char char1[] = "ab";
    char char2[] = {'a', 'b'};
    //todo 两者有区别，前者可直接cout输出值，后者会有乱码，不知道是什么。
    //todo 2016-07-17 01:00 ,发现是因为char2[] 没有 \0 不会截止， char1长度为3
    cout << char2 << endl;

    //    cout << sizeof(int)  << endl;  //sizeof 计算内存中占用字节数
    //通过sizeof 可计算数组长度
    /* for(int i=0;i< sizeof(char1)/ sizeof(char1[0]);i++){
         cout<<char1[i]<<" ";
     }*/

    /* string str = "str";
     str.~string();*/

}

void charCopy() {
    char a[11] = "wearehere!", b[11];

    cout << " sizeof(a) / sizeof(a[0]) = " << sizeof(a) / sizeof(a[0]) << endl;
    cout << "strlen(a) = " << strlen(a) << endl; // strlen() 属于<cstring> 中，strlen 遇到\0 会结束，并且不计算结束符
    copy(a, a + 11, b);
    cout << b << "sizeof(b) / sizeof(b[0]) = " << sizeof(b) / sizeof(b[0]) << endl;

    reverse_copy(a, a + 10, b);

    cout << b << endl;
    for (int i = 0; i < 11; ++i) {
        cout << b[i] << endl;
    }

}

//1.10 输出符操控定义
void coutOperFun() {
    cout.precision(10);
    const double PI = 13.141592;
    cout << PI << endl;
    cout << setprecision(0) << PI << endl;
}

void exercises1() {
    int num;
    int &ref = num;
    ref = ref + 100;
    num = num + 50;
}

void exercises2() {
    int x = 58, y = 98;
    const int *p = &x;
    cout << p << endl;
    cout << *p << endl;
    // *p=65;
    p = &y;
    cout << p << endl;
    cout << *p << endl;
}

void expercises3() {
    int x = 58, y = 98, z = 55;
    int *const p = &x;
    cout << *p << "   " << p << endl;
    *p = 56;
    cout << *p << "   " << p << endl;
//    p= &y;//  p是常量指针，不能作为左值
    cout << z << endl;
    z = *p;
    cout << z << endl;
}

/**
 * 分别用ASCII码形式输出 65 和 66
 */
void expercises4_1() {
    int char1 = 55, char2 = 56;
    cout << char(char1) << endl;
    cout << char(char2) << endl;

}

/**
 * 编写一个为int型变量分配100个整型量空间的程序
 */
void expercises4_2() {
    int *pint = new int[100];
}

/**
 * 接收输入的15个float 值，并计算最小值和这些值的和
 */
void expercises4_3() {
    float *pfloat = new float[15];
    float sum = 0.0f;
    //<limits> 头文件中，获取float 最大值,或者 min =0.0f, 当i=0时，把输入的值赋给min
    float min = numeric_limits<float>::max();

    cout << "请输入15个Float型数字" << endl;
    for (int i = 0; i < 15; ++i) {
        cin >> *(pfloat + i);
        sum += *(pfloat + i);
        if (min > *(pfloat + i)) {
            min = *(pfloat + i);
        }
    }
    cout << "15个float 数字中最小的是：" << min << ", 15个数字的和是：" << sum << endl;
//    int length = sizeof(pfloat)/ sizeof(pfloat[0]);
}

/**
 * 找出数组中4的位置，在将数组a复制给数组b,然后将数组a的内容反转在找出4的位置，
 * 最后分别输出数组a和b的内容
 */
void expercises4_4() {
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8}, b[8];
    int *p = find(a, a + 8, 4);
    if (p == a + 8) {
        cout << "没有找到值为4的数组元素" << endl;
    } else {
        cout << "找到了值为" << *p << "的数组元素" << endl;
    }
    copy(a, a + 8, b);
    reverse(a, a + 8);
    p = find(a, a + 8, 4);
    if (p == a + 8) {
        cout << "没有找到值为4的数组元素" << endl;
    } else {
        cout << "找到了值为" << *p << "的数组元素" << endl;
    }
    copy(a, a + 8, ostream_iterator<int>(cout)); //ostream_iterator 在 <iterator>
    cout<<endl;
    copy(b, b + 8, ostream_iterator<int>(cout));
}

int main() {
    // int num;//不初始化，值是不确定的， static 时默认值是0
    // cout << num << endl;


    //constTest();
    //1.6
    //coutArray();
    //1.9
    //charCopy();
    //1.10
    //coutOperFun();
//    expercises4_2();
//    expercises4_3();

    expercises4_4();
    return 0;


}

