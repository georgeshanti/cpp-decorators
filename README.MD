# C++ Decorators

Much like decorators in python, this library implements decorators in C++.

## Python code:

    def newDecorator(func):

        def inner(*args, **kwargs):
            # Code to execute before function
            func(*args, **kwargs)
            # Code to execute after function
        
        return inner
    
    @decorator1
    def decorated():
        # Function code block

## C++ code:

This decorator takes a function that takes an integer as argument ad returns an integer and returns a new function that accepts the same arguments and adds 2 to the result of the function passed.

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

Output:

    3
    5
    7

3 is the output of the function by itself

5 is the output of the function after decorated by NewDecorator

7 is the output of the decorated function once again decorated by NewDecorator

```
Note: The return type and argument type list must be passed to the Decorator base class as follows:

    class NewDecorator : public Decorator<ReturnType, ArgumentTypes>

If the function to be decorated as the defination as follows:

    int func(char, double, int);

Then the Decorator must be defined as follows:

    class NewDecorator : public Decorator<int, char, double, int>
```

```
Note: When passing a decorated object to another decorator it will apply the second decorator. This is achieved by overloading the copy constructor.

It will also apply the decorator when we assign a decorator to another one in it's declaration as follows:
    
    NewDecorator B = A;

If you wish to carry out a true copy then it mus be done after declaration as follows:

    NewDecorator B;
    B = A;
