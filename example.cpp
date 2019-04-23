#include "decorator.hpp"
#include <iostream>

class NewDecorator : public Decorator<int,int>{
	public:
		NewDecorator():Decorator(){};
		NewDecorator(decorateeFunc dF):Decorator(dF){};
		NewDecorator(Decorator &D):Decorator(D){};
		int operator () (int a){
			return decoratee(a)+2;
		}
};

class NewDecorator1 : public Decorator<int,int>{
	public:
		NewDecorator1():Decorator(){};
		NewDecorator1(decorateeFunc dF):Decorator(dF){};
		NewDecorator1(Decorator &D):Decorator(D){};
		int operator () (int a){
			return decoratee(a)+3;
		}
};

int t(int a){
	return a;
}

int main(){
	NewDecorator A(t);
	NewDecorator1 B(A);
	std::cout<<t(3)<<std::endl<<A(3)<<std::endl<<B(3)<<std::endl;
	return 0;
}