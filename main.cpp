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
    int z(0), b(50);//���ù��캯������ͬ��z = 50
    Point a;
    cout << "���������������Կո����֣���";
    cin >> a.x >> a.y;
    z = (a.x + a.y) * k;
    z = result(z, b);
    cout << "���������£�" << endl;
    cout << "((" << a.x << "+" << a.y << ")*" << k << ")+" << b << "=" << z << endl;
}

int result(int a, int b) {
    return a + b;
}


void main2() {
    double *pDouble = new double[3];
    for (int i = 0; i < 3; i++) {
        cout << "������һ������" << endl;
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

    const int y = 58; //���������ܸı�ֵ
    const int *p = &y;//ָ������ָ��
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
    // ���鸴�Ƶ��������  p1:��ʼλ�ã�p2�� ����λ�� p3�������
    cout << "����a" << endl;
    copy(a, a + 4, ostream_iterator<double>(cout, " "));

    cout << endl;
    cout << "�����������a" << endl;
    reverse_copy(a, a + 4, ostream_iterator<double>(cout, " "));
    cout << endl;

    //���Ƶ�����b p1:��ʼλ�ã�p2�� ����λ�� p3�����鿪ʼ
    copy(a, a + 4, b);
    //�������b
    cout << "����a" << endl;
    copy(b, b + 4, ostream_iterator<double>(cout, " "));
    cout << endl;
    /* for (int i = 0; i < 4; ++i) {
         cout << b[i] << endl;
     }*/

    //������a��������
    sort(a, a + 4); //Ĭ����������
//    sort(a,a+4,compare) �������� ,�Լ�ʵ��
    //    sort(a, a + 4, greater<double>()); // less<��������>()//��С�������� greater<��������>()//�Ӵ�С����
    cout << "�������a" << endl;
    copy(a, a + 4, ostream_iterator<double>(cout, " "));
    cout << endl;

    cout << "����copy����a��b" << endl;
    reverse_copy(a, a + 4, b);
    copy(b, b + 4, ostream_iterator<double>(cout, " "));
    cout << endl;


    double a1[4] = {1.1, 3.3, 2.2, 4.4};
    double *x = find(a1, a1 + 4, 4.4);

    //x�ĵ�ַ����a1��ַ��Χ����û���ҵ�
    cout << (x == a1 + 3) << endl;
    if (x == a1 + 4) {
        cout << "û���ҵ�ֵΪ4.4��Ԫ��" << endl;
    } else {
        cout << "��ֵΪ" << *x << "������Ԫ��" << endl;
    }
    delete x;


    //double i ÿ��һ���ڴ��ַ����8���ֽ� double����8���ֽڣ�64λ
    for (int i = 0; i < 4; ++i) {
        cout << "a1+" << i << " = " << a1 + i << "    value = " << a1[i] << endl;
    }
    cout << "x = " << x << "    *x = " << *x << endl;

    // char char1[] = "ab";
    char char2[] = {'a', 'b'};
    //todo ����������ǰ�߿�ֱ��cout���ֵ�����߻������룬��֪����ʲô��
    //todo 2016-07-17 01:00 ,��������Ϊchar2[] û�� \0 �����ֹ�� char1����Ϊ3
    cout << char2 << endl;

    //    cout << sizeof(int)  << endl;  //sizeof �����ڴ���ռ���ֽ���
    //ͨ��sizeof �ɼ������鳤��
    /* for(int i=0;i< sizeof(char1)/ sizeof(char1[0]);i++){
         cout<<char1[i]<<" ";
     }*/

    /* string str = "str";
     str.~string();*/

}

void charCopy() {
    char a[11] = "wearehere!", b[11];

    cout << " sizeof(a) / sizeof(a[0]) = " << sizeof(a) / sizeof(a[0]) << endl;
    cout << "strlen(a) = " << strlen(a) << endl; // strlen() ����<cstring> �У�strlen ����\0 ����������Ҳ����������
    copy(a, a + 11, b);
    cout << b << "sizeof(b) / sizeof(b[0]) = " << sizeof(b) / sizeof(b[0]) << endl;

    reverse_copy(a, a + 10, b);

    cout << b << endl;
    for (int i = 0; i < 11; ++i) {
        cout << b[i] << endl;
    }

}

//1.10 ������ٿض���
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
//    p= &y;//  p�ǳ���ָ�룬������Ϊ��ֵ
    cout << z << endl;
    z = *p;
    cout << z << endl;
}

/**
 * �ֱ���ASCII����ʽ��� 65 �� 66
 */
void expercises4_1() {
    int char1 = 55, char2 = 56;
    cout << char(char1) << endl;
    cout << char(char2) << endl;

}

/**
 * ��дһ��Ϊint�ͱ�������100���������ռ�ĳ���
 */
void expercises4_2() {
    int *pint = new int[100];
}

/**
 * ���������15��float ֵ����������Сֵ����Щֵ�ĺ�
 */
void expercises4_3() {
    float *pfloat = new float[15];
    float sum = 0.0f;
    //<limits> ͷ�ļ��У���ȡfloat ���ֵ,���� min =0.0f, ��i=0ʱ���������ֵ����min
    float min = numeric_limits<float>::max();

    cout << "������15��Float������" << endl;
    for (int i = 0; i < 15; ++i) {
        cin >> *(pfloat + i);
        sum += *(pfloat + i);
        if (min > *(pfloat + i)) {
            min = *(pfloat + i);
        }
    }
    cout << "15��float ��������С���ǣ�" << min << ", 15�����ֵĺ��ǣ�" << sum << endl;
//    int length = sizeof(pfloat)/ sizeof(pfloat[0]);
}

/**
 * �ҳ�������4��λ�ã��ڽ�����a���Ƹ�����b,Ȼ������a�����ݷ�ת���ҳ�4��λ�ã�
 * ���ֱ��������a��b������
 */
void expercises4_4() {
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8}, b[8];
    int *p = find(a, a + 8, 4);
    if (p == a + 8) {
        cout << "û���ҵ�ֵΪ4������Ԫ��" << endl;
    } else {
        cout << "�ҵ���ֵΪ" << *p << "������Ԫ��" << endl;
    }
    copy(a, a + 8, b);
    reverse(a, a + 8);
    p = find(a, a + 8, 4);
    if (p == a + 8) {
        cout << "û���ҵ�ֵΪ4������Ԫ��" << endl;
    } else {
        cout << "�ҵ���ֵΪ" << *p << "������Ԫ��" << endl;
    }
    copy(a, a + 8, ostream_iterator<int>(cout)); //ostream_iterator �� <iterator>
    cout<<endl;
    copy(b, b + 8, ostream_iterator<int>(cout));
}

int main() {
    // int num;//����ʼ����ֵ�ǲ�ȷ���ģ� static ʱĬ��ֵ��0
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

