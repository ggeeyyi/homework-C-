#include<iostream>
#include<string>

using namespace std;

class MyClass
{
public:
	MyClass(const string stu) :m_str(stu)
	{

	}
	void print(const string text)
	{
		cout << text << m_str << endl << endl;
	}

	//减除指定字符串
	void MyClass::sub(const string stu1);
	//字符串相加
	MyClass operator +(const MyClass&c1){

		this->m_str = this->m_str + c1.m_str;
		return m_str;
	}
	//方法差不多，最好还是写个函数来做相减
	MyClass operator -(const MyClass&stu1){
		int pos = this->m_str.find(stu1.m_str);
		int n = stu1.m_str.size();
		this->m_str = this->m_str.erase(pos, n);
		return m_str;
	}
	~MyClass(){}
private:
	string m_str;
};

void MyClass::sub(const string stu1)
{
	int pos = m_str.find(stu1);//查找到指定字符串
	int n = stu1.size();//获取大小
	m_str = m_str.erase(pos, n);//相减
}

int main()
{
	MyClass s1("123"), s2("456");

	string text = "相加=";
	s1 = s1 + s2;//字符串相加
	s1.print(text); 

	text = "相减=";
	s1.sub("23");//减除指定字符串
	s1.print(text);

	s1 = s1 - s2;//字符串相减
	s1.print(text);
	system("pause");
}


