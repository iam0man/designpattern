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
		std::cout << "������ ���ϴ�.";
	}
};

class FlyNoWay : public FlyBehavior
{
public:
	virtual void fly()
	{
		std::cout << "���� �� �� �����ϴ�.";
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
		std::cout << "�� ��";
	}
};

class Squeak : public QuackBehavior
{
public:
	virtual void quack() override
	{
		std::cout << "�������� ���";
	}
};


class Duck
{
public:
	FlyBehavior* pFlyBehavior;
	QuackBehavior* pQuackBehavior;

	void performQuack() { pQuackBehavior->quack(); }
	void swim() { std::cout << "������ �մϴ�."; }
	void display() { std::cout << "���� �̷��� ������ϴ�."; }
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