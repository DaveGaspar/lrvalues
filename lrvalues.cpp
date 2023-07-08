#include <iostream>

class A{
	public:
		int m_a;
		A(){
			std::cout << "call default constructor" << std::endl;
		}
		A(int a):m_a(a){
			std::cout << "call parametrized constructor" << std::endl;
		}
		~A(){
			std::cout << "call destructor" << std::endl;
		}
		A(const A& obj){
			std::cout << "call copy constructor" << std::endl;
			this->m_a = obj.m_a;
		}

		A operator +(const A& obj){
			A temp(*this);
			temp.m_a += obj.m_a;
			return temp;
		} 
};

// void print(A obj){
// 	std::cout << "print lvalue " << obj.m_a << std::endl;
// }

// void print(A& obj){
// 	std::cout << "print lvalue reference " << obj.m_a << std::endl;
// }

void print(const A& obj){
	std::cout << "print const lvalue reference " << obj.m_a << std::endl;
}

// void print(A&& obj){
// 	std::cout << "print rvalue reference " << obj.m_a << std::endl;
// }

void print(const A&& obj){
	std::cout << "print const rvalue reference " << obj.m_a << std::endl;
}

int main()
{
	A a(5);
	A b(7);
	print(a);
	print(a+b);

	return 0;
}
