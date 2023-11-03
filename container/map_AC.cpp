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
因为函数用到了 Person类型，c+中变量是先定义后使用。
所以函数声明要放在类后面。
*/

void  isEmpty(map<int, Person> m);
void displayfor(map<int, Person> m);
void findElement(map<int, Person> m, int key);
int main() {
    map<int, Person> m;
    Person p1("张三",22);
    Person p2("李四", 33);
    Person p3("王五", 44);
    Person p4("阿牛", 55);
    Person p5("旺财", 66);
//pair<iterator, bool> insert( const pair<KEY_TYPE,VALUE_TYPE> &val );
    m.insert(pair<int, Person>(111, p1)); //插入元素
    m.insert(pair<int, Person>(222, p2));
    m.insert(pair<int, Person>(333, p3));
    isEmpty(m);
    cout << "map----m的元素为:" << endl;
    displayfor(m);

//size() 返回map中元素的个数 
    cout << "map中元素的个数 :" << m.size() << endl;

//max_size() 返回可以容纳的最大元素个数 
    cout << "map容纳的最大元素个数 " << m.max_size() << endl;

 map<int, Person> m1;
 map<int, Person>::iterator it1,it2;
//begin() 返回指向map头部的迭代器 
  it1 = m.begin();
//end() 返回指向map末尾的迭代器 
  it2 = m.end();
  cout << "---------------------" << endl;

//void insert( input_iterator start, input_iterator end );
  it1++;
  m1.insert(it1, it2);
  cout << "map----m1的元素为:" << endl;
  displayfor(m1);

  cout << "---------------------" << endl;
//swap() 交换两个map 
  cout << "交换两个map元素" << endl;
  m1.swap(m);
  cout << "map----m的元素为:" << endl;
  displayfor(m);
  displayfor(m1);

  cout << "---------------------" << endl;
/*
用insert函数插入数据，在数据的 插入上涉及到集合的唯一性这个概念，
即当map中有这个关键字时，insert操作是插入数据不了的，
但是用数组方式就不同了，它可以覆盖以前该关键字对 应的值
*/

  //用数组方式插入数据
  m[444] = p4;
  m[444] = p5; //p5覆盖了p4
  //采用用insert函数插入value_type数据
  m.insert(map<int, Person>::value_type(555, p5));
  cout << "map----m的元素为:" << endl;
  displayfor(m);

  map<int, Person>::iterator it3;
 m.find(555);

//使用find函数。
  it3 = m.find(888);
  if(it3!=m.end())
      cout << "找到了key=" <<888 << "元素" << endl;
  else
      cout << "没有找到key=" <<888<< "元素" << endl;


  cout << "---------------------" << endl;
//void erase( iterator pos );
  cout << "删除m第1个元素" << endl;
  it3 = m.begin();
  m.erase(it3);
  cout << "map----m的元素为:" << endl;
  displayfor(m);

//void clear();
// clear()函数删除map中的所有元素。
  m.clear();
  cout << "map----m的元素为:" << endl;
  displayfor(m);


    system("pause");
    return 0;
}
void  isEmpty(map<int, Person> m) 
{
    //empty() 如果map为空则返回true 
    if (m.empty())
        cout << "map为空" << endl;
    else
        cout << "map不为空" << endl;
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

//自己写一个find函数，本身想用本身的find的函数可以发现自己已经写了。
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
        cout << "找到了key="<<key<<"元素" << endl;
    else
    cout << "没有找到key=" << key << "元素" << endl;

}