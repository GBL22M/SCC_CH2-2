#include <iostream>
#include <cstdlib>
#include <ctime>
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
	~Dog()
	{
		cout << "dog die\n";
		//delete this;
	}
};

class Cat : public Animal
{
public:
	void MakeSound() const override
	{
		cout << "Meeow!!\n";
	}
	~Cat()
	{
		cout << "Cat die\n";
		//delete this;
	}
};

class Cow : public Animal
{
public:
	void MakeSound() const override
	{
		cout << "Moo!!\n";
	}
	~Cow()
	{
		cout << "Cow die\n";
		//delete this;
	}
};


class Zoo
{
public:
	Zoo()
		:animalCount(0)		
	{
		for (int i = 0; i < 10; ++i)
			animals[i] = nullptr;

		cout << "동물원 개장\n";
	}
	~Zoo()
	{
		for (int i = 0; i < animalCount; ++i)
		{
			delete animals[i];
		}
		animalCount = 0;
	}

	void AddAnimal(Animal* animal)
	{
		animals[animalCount] = animal;		
		animalCount++;
	}

	void PerformActions()
	{
		for (int i = 0; i < animalCount; ++i)
		{
			animals[i]->MakeSound();
		}
	}

private:
	Animal* animals[10];
	int animalCount;
};

Animal* CreateRandomAnimal()
{	
	int randomNum = rand() % 3;
	
 	Animal* animal = nullptr;
	if (randomNum == 0)
	{
		animal = new Dog;
	}
	if (randomNum == 1)
	{
		animal = new Cat;
	}
	if (randomNum == 2)
	{
		animal = new Cow;
	}

	return animal;
}

int main()
{
	srand(static_cast<unsigned int>(time(0)));
	
	Zoo zoo;

	int num;
	cout << "10보다 작은 숫자를 입력하세요: ";
	cin >> num;

	while(num > 10)	
	{
		cout << "다시 입력하세요: ";
		cin >> num;
	}
	cout << num << " 마리 동물이 추가됩니다.\n";

	for (int i = 0; i < num; ++i)
	{		
		zoo.AddAnimal(CreateRandomAnimal());
	}	

	zoo.PerformActions();

	cout << "\n동물원 폐장\n";
}