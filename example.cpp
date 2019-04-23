#include "decorator.hpp"
#include <iostream>

class NewDecorator : public Decorator<int,int>{
	public:
		NewDecorator():Decorator(){};
		NewDecorator(decorateeFunc dF):Decorator(dF){};
		NewDecorator(NewDecorator &D):Decorator(D){};
		int operator () (int a){
			return decoratee(a)+2;
		}
};

int t(int a){
	return a;
}

int main(){
	NewDecorator A(t);
	NewDecorator B(A);
	std::cout<<t(3)<<std::endl<<A(3)<<std::endl<<B(3)<<std::endl;
	return 0;
}