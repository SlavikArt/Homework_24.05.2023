#include <iostream>
using namespace std;

/*
Фабричный метод (Factory Method) — порождающий шаблон проектирования, предоставляющий подклассам интерфейс для создания экземпляров некоторого класса.
В момент создания наследники могут определить, какой класс инстанциировать. Иными словами, фабрика делегирует создание объектов наследникам родительского класса.
Это позволяет использовать в коде программы не специфические классы, а манипулировать абстрактными объектами на более высоком уровне.
Фабричный метод  определяет интерфейс для создания объекта, но оставляет подклассам решение о том, какой класс инстанциировать.

Применимость
-  	классу заранее неизвестно, объекты каких подклассов ему нужно создавать.
-  	класс спроектирован так, чтобы объекты, которые он создаёт, специфицировались подклассами.
-  	класс делегирует свои обязанности одному из нескольких вспомогательных подклассов, и планируется локализовать знание о том, какой класс принимает эти обязанности на себя.

Достоинство
Фабричные методы избавляют проектировщика от необходимости встраивать в код зависящие от приложения классы. Код имеет дело только с интерфейсом
класса Product, поэтому он может работать с любыми определенными пользователями классами конкретных продуктов.
Недостаток
Потенциальный недостаток фабричного метода состоит в том, что клиентам, возможно, придется создавать подкласс класса Creator для создания лишь одного объекта ConcreteProduct.
*/

//продукт (House) определяет интерфейс объектов, создаваемых фабричным методом
class House abstract
{
};

// Конкретный продукт реализует интерфейс Product (в нашем случае, House)
class PanelHouse : public House
{
public:
	PanelHouse()
	{
		cout << "Panel house built\n";
	}
};

// Конкретный продукт реализует интерфейс Product (в нашем случае, House)
class WoodHouse : public House
{
public:
	WoodHouse()
	{
		cout << "Wooden house built\n";
	}
};

class BrickHouse : public House
{
public:
	BrickHouse()
	{
		cout << "Brick house built\n";
	}
};

class FoamBlockHouse : public House
{
public:
	FoamBlockHouse()
	{
		cout << "Foam block house built\n";
	}
};


// Creator объявляет фабричный метод, возвращающий объект типа Product.
// абстрактный класс строительной компании
class Developer abstract
{
	// фабричный метод
public:
	virtual House* Create() = 0;
};

// конкретный создатель замещает фабричный метод, возвращающий объект ConcreteProduct.
// строит панельные дома
class PanelDeveloper : public Developer
{
public:
	House* Create() override
	{
		return new PanelHouse;
	}
};

// конкретный создатель замещает фабричный метод, возвращающий объект ConcreteProduct.
// строит деревянные дома
class WoodDeveloper : public Developer
{
public:
	House* Create() override
	{
		return new WoodHouse;
	}
};

class BrickDeveloper : public Developer
{
public:
	House* Create() override
	{
		return new BrickHouse;
	}
};

class FoamBlockDeveloper : public Developer
{
public:
	House* Create() override
	{
		return new FoamBlockHouse;
	}
};

// Паттерн позволяет использовать в клиентском коде программы не специфические классы, а манипулировать абстрактными объектами на более высоком уровне.
House* Client(Developer* pDev)
{
	return pDev->Create();
}

int main()
{
	Developer* pDev = new PanelDeveloper();  // создали объект создателя панельных домов
	House* pHouse = Client(pDev);  // передали создателя в функцию Client и записали созданный дом в pHouse
	delete pHouse;
	delete pDev;

	pDev = new WoodDeveloper(); // теперь pDev уже "смотрит" на создателя деревянных домов
	pHouse = Client(pDev);  // передали создателя в функцию Client и записали созданный дом в pHouse
	delete pHouse;
	delete pDev;

	pDev = new BrickDeveloper();
	pHouse = Client(pDev);
	delete pHouse;
	delete pDev;

	pDev = new FoamBlockDeveloper();
	pHouse = Client(pDev);
	delete pHouse;
	delete pDev;
}
