#include <iostream>

using namespace std;

class Fruit
{
public:
    virtual void sayname() = 0;
};


class SourthBanana : public Fruit
{
public:
    void sayname()
    {
        cout<<"I am SourthBanana"<<endl;
    }
};

class SourthApple : public Fruit
{
public:
    void sayname()
    {
        cout<<"I an SouthApple"<<endl;
    }
};


class NorthBanana : public Fruit
{
public:
    void sayname()
    {
        cout<<"I am NorthBanana"<<endl;
    }
};

class NorthApple : public Fruit
{
public:
    void sayname()
    {
        cout<<"I am NorthApple"<<endl;
    }

};


class AbstractFactory
{
public:
    virtual Fruit *CreateBanana() = 0;
    virtual Fruit *CreateApple()  = 0;
};

class SourthFactory : public AbstractFactory
{
public:
    Fruit *CreateApple()
    {
        return new SourthApple;
    }
    Fruit *CreateBanana()
    {
        return new SourthBanana;
    }
};


class NorthFactory : public AbstractFactory
{
public:
    Fruit *CreateApple()
    {
        return new NorthApple;
    }
    Fruit *CreateBanana()
    {
        return new NorthBanana;
    }
};


int main()
{
    AbstractFactory *af ;
    Fruit *f;


    //生产南方的产品
    af = new SourthFactory;
    f  = af->CreateApple();
    f->sayname();
    f  = af->CreateBanana();
    f->sayname();
    delete af;
    delete f;


    //生产北方的产品
    af = new NorthFactory;
    f  = af->CreateApple();
    f->sayname();
    f  = af->CreateBanana();
    f->sayname();
    delete af;
    delete f;

    cout << "Hello world!" << endl;
    return 0;
}
