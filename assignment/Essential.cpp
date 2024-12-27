#include <iostream>
using namespace std;

class Animal
{
public:
	virtual void MakeSound() const = 0;
	virtual ~Animal() = default;
};

class Dog : public Animal
{ 
public:
	void MakeSound() const override
	{
		cout << "bark!!\n";
	}
};

class Cat : public Animal
{
public:
	void MakeSound() const override
	{
		cout << "Meeow!!\n";
	}
};

class Cow : public Animal
{
public:
	void MakeSound() const override
	{
		cout << "Moo!!\n";
	}
};

int main()
{
	Animal* animal[3];

	animal[0] = new Dog;
	animal[1] = new Cat;
	animal[2] = new Cow;

	for (auto a : animal)
	{
		a->MakeSound();
	}

	for (auto a : animal)
	{
		delete a;
	}
}