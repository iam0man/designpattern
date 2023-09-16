#include <iostream>

class FlyBehavior
{
public:
	virtual void fly() {};
};

class FlyWithWings : public FlyBehavior
{
public:
	virtual void fly()
	{
		std::cout << "날개로 납니다.";
	}
};

class FlyNoWay : public FlyBehavior
{
public:
	virtual void fly()
	{
		std::cout << "저는 날 수 없습니다.";
	}
};

class QuackBehavior
{
public:
	virtual void quack() {};
};

class Quack : public QuackBehavior
{
public:
	virtual void quack() override
	{
		std::cout << "꽥 꽥";
	}
};

class Squeak : public QuackBehavior
{
public:
	virtual void quack() override
	{
		std::cout << "고무오리의 삑삑";
	}
};


class Duck
{
public:
	FlyBehavior* pFlyBehavior;
	QuackBehavior* pQuackBehavior;

	void performQuack() { pQuackBehavior->quack(); }
	void swim() { std::cout << "수영을 합니다."; }
	void display() { std::cout << "저는 이렇게 생겼습니다."; }
	void performFly() { pFlyBehavior->fly(); };

	void SetFlyBehavior(FlyBehavior* pf)
	{
		pFlyBehavior = pf;
	}
	void SetQuackBehavior(QuackBehavior* pq)
	{
		pQuackBehavior = pq;
	}
};

class MallardDuck : public Duck
{
public:
	MallardDuck()
	{
		pQuackBehavior = new Quack();
		pFlyBehavior = new FlyWithWings();
	}
};

int main()
{
	Duck* mallard = new MallardDuck;

	mallard->performQuack();
	mallard->performFly();

	mallard->SetFlyBehavior(new FlyNoWay());
	mallard->performFly();

}