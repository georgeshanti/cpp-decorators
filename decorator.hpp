#ifndef _DECORATOR_H_
#define _DECORATOR_H_

template<class returnType, class... argumentTypes>
class Decorator{
    protected:
    public:
        typedef returnType (*decorateeFunc)(argumentTypes...);
        Decorator<returnType,argumentTypes...>* _decorateeObj;
        decorateeFunc _decorateeFunc;

        void operator=(const Decorator &D ) {
            _decorateeObj = D._decorateeObj;
            _decorateeFunc = D._decorateeFunc;
        }

        Decorator(){
            _decorateeFunc = 0;
            _decorateeObj = 0;
        }

        Decorator(decorateeFunc dF){
            _decorateeFunc = dF;
            _decorateeObj = 0;
        }

        Decorator(Decorator<returnType,argumentTypes...> &D){
            _decorateeFunc = 0;
            _decorateeObj = &D;
        }

        returnType decoratee(argumentTypes... a){
            if(_decorateeFunc)
                return (*_decorateeFunc)(a...);
            else
                return (*_decorateeObj)(a...);
        }
        
        virtual returnType operator()(argumentTypes... a){
            return _decorateeFunc(a...);
        };
};

#endif