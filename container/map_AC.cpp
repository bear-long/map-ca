#include<iostream>
#include<string>
#include<map>
#include<algorithm>
using  namespace std;

class Person{
 private:
     string name;
     int  age;
public:
    Person(string name,int  age) {
        this->name = name;
        this->age = age;
    }
    Person() {

    }

    void print() {
        cout << "name:" << name << " " << "age:" << age << endl;
 }
};

/*
��Ϊ�����õ��� Person���ͣ�c+�б������ȶ����ʹ�á�
���Ժ�������Ҫ��������档
*/

void  isEmpty(map<int, Person> m);
void displayfor(map<int, Person> m);
void findElement(map<int, Person> m, int key);
int main() {
    map<int, Person> m;
    Person p1("����",22);
    Person p2("����", 33);
    Person p3("����", 44);
    Person p4("��ţ", 55);
    Person p5("����", 66);
//pair<iterator, bool> insert( const pair<KEY_TYPE,VALUE_TYPE> &val );
    m.insert(pair<int, Person>(111, p1)); //����Ԫ��
    m.insert(pair<int, Person>(222, p2));
    m.insert(pair<int, Person>(333, p3));
    isEmpty(m);
    cout << "map----m��Ԫ��Ϊ:" << endl;
    displayfor(m);

//size() ����map��Ԫ�صĸ��� 
    cout << "map��Ԫ�صĸ��� :" << m.size() << endl;

//max_size() ���ؿ������ɵ����Ԫ�ظ��� 
    cout << "map���ɵ����Ԫ�ظ��� " << m.max_size() << endl;

 map<int, Person> m1;
 map<int, Person>::iterator it1,it2;
//begin() ����ָ��mapͷ���ĵ����� 
  it1 = m.begin();
//end() ����ָ��mapĩβ�ĵ����� 
  it2 = m.end();
  cout << "---------------------" << endl;

//void insert( input_iterator start, input_iterator end );
  it1++;
  m1.insert(it1, it2);
  cout << "map----m1��Ԫ��Ϊ:" << endl;
  displayfor(m1);

  cout << "---------------------" << endl;
//swap() ��������map 
  cout << "��������mapԪ��" << endl;
  m1.swap(m);
  cout << "map----m��Ԫ��Ϊ:" << endl;
  displayfor(m);
  displayfor(m1);

  cout << "---------------------" << endl;
/*
��insert�����������ݣ������ݵ� �������漰�����ϵ�Ψһ��������
����map��������ؼ���ʱ��insert�����ǲ������ݲ��˵ģ�
���������鷽ʽ�Ͳ�ͬ�ˣ������Ը�����ǰ�ùؼ��ֶ� Ӧ��ֵ
*/

  //�����鷽ʽ��������
  m[444] = p4;
  m[444] = p5; //p5������p4
  //������insert��������value_type����
  m.insert(map<int, Person>::value_type(555, p5));
  cout << "map----m��Ԫ��Ϊ:" << endl;
  displayfor(m);

  map<int, Person>::iterator it3;
 m.find(555);

//ʹ��find������
  it3 = m.find(888);
  if(it3!=m.end())
      cout << "�ҵ���key=" <<888 << "Ԫ��" << endl;
  else
      cout << "û���ҵ�key=" <<888<< "Ԫ��" << endl;


  cout << "---------------------" << endl;
//void erase( iterator pos );
  cout << "ɾ��m��1��Ԫ��" << endl;
  it3 = m.begin();
  m.erase(it3);
  cout << "map----m��Ԫ��Ϊ:" << endl;
  displayfor(m);

//void clear();
// clear()����ɾ��map�е�����Ԫ�ء�
  m.clear();
  cout << "map----m��Ԫ��Ϊ:" << endl;
  displayfor(m);


    system("pause");
    return 0;
}
void  isEmpty(map<int, Person> m) 
{
    //empty() ���mapΪ���򷵻�true 
    if (m.empty())
        cout << "mapΪ��" << endl;
    else
        cout << "map��Ϊ��" << endl;
}


void displayfor(map<int, Person> m)
{
    map<int, Person>::iterator it;
    it = m.begin();
    while (it != m.end()) {
        cout<<"id:" << it->first << "-----";
        it->second.print();
        it++;
    }
}

//�Լ�дһ��find�������������ñ����find�ĺ������Է����Լ��Ѿ�д�ˡ�
void findElement(map<int, Person> m,int key) {
    // iterator find( const KEY_TYPE &key );
    map<int, Person>::iterator it = m.begin();
    int flag = 0;
    while (it != m.end()) {
        if (it->first == key)
        {
            flag = 1;
            break;
        }
        it++;
    }
    if(flag==1)
        cout << "�ҵ���key="<<key<<"Ԫ��" << endl;
    else
    cout << "û���ҵ�key=" << key << "Ԫ��" << endl;

}