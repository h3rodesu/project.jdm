#include<iostream>
#include <iomanip>
#include<string>
#include<vector>
#include<memory>
#include<list>
#include <algorithm>
using namespace std;
class Car {
private:
	string carName;
	string carBrand;
	bool hasnewwheels = false;
	int ls;
	int weight;
	int wheel;
	string engine;
public:
	Car(string name, string brand, int power, int kg, int zacep, string dvig)
		:carBrand(brand), carName(name), engine(dvig), ls(power), weight(kg), wheel(zacep) {
	}

	virtual void ShowCar() {
		cout << " Бренд " << carBrand << " Машина " << carName << " Лошадиные силы: " << ls << endl;
		cout << " Двигатель: " << engine << " Вес: " << weight << "Зацеп колёс: " << wheel << endl;
	}

	void setLs(int nls) {
		ls = nls;
	}
	int getls() {
		return ls;
	}
	string getname() {
		return carName;
	}
	int getkg() {
		return weight;
	}
	int getwheel() {
		return wheel;
	}
	virtual ~Car() {}
};
using CarPtr = shared_ptr<Car>;
class Nissan : public Car {
public:
	Nissan(string carName, string carBrand, int power, int kg, int zacep, string dvig)
		:Car(carName, carBrand, power, kg, zacep, dvig) {
		//Здесь класс car вносит данные в свои переменные
	}
	~Nissan() {}
	using NissanPtr = shared_ptr<Nissan>;
};
class Toyota : public Car {
public:
	Toyota(string carName, string carBrand, int power, int kg, int zacep, string dvig)
		:Car(carName, carBrand, power, kg, zacep, dvig) {

	}
	~Toyota() {}
	using ToyotaPtr = shared_ptr<Toyota>;
};

class Mitsubishi : public Car {
public:
	Mitsubishi(string carName, string carBrand, int power, int kg, int zacep, string dvig)
		:Car(carName, carBrand, power, kg, zacep, dvig) {
	}
	~Mitsubishi() {}
};
using MitPtr = shared_ptr<Mitsubishi>;

class Shop {
private:
	string partName;
	int partHar;
	int partPrice;
public:
	Shop(string Pname, int har, int price) : partName(Pname), partHar(har), partPrice(price) {}

	void ShowShop() {
		cout << "Деталь: " << partName << " Характеристика: " << partHar << " Цена " << partPrice;
		cout << endl;
	}
	int gethar() {
		return partHar;
	}
	~Shop() {}
};
void ShowMyCars(const vector<CarPtr>& gar) {//Ампераснд и  const чтобы не копировать вектор
	for (auto it = gar.begin(); it != gar.end(); it++) {
		(*it)->ShowCar();
		cout << endl;
	}
}
using ShopPtr = shared_ptr<Shop>;

struct racer {
public:
	CarPtr carptr;
	int power;
};

enum Events {
	Dead,
	low,
	crash
};
void LaurelEvents() {
	Events event = static_cast<Events>(rand() % 3);
	switch (event) {
	case Dead: {
		cout << "Мимо вас проонесся полумертвый Лаурель, чуть не въехал в вас" << endl;
		break;
	}
	case low: {
		cout << "Мимо вас проонесся черный блестящий  Лаурель,говорят вчера намотался на столб" << endl;
		break;
	}
	case crash: {
		cout << "Мимо вас проонесся слишком низкий Лаурель ,улетел в кусты" << endl;
		break;
	}
	}
}

int main() {
	srand(time(0));
	setlocale(LC_ALL, "rus");


	vector<CarPtr>mygarrage;

	vector<CarPtr>CarShop;
	CarShop.push_back(make_shared<Toyota>("Mark II", "Toyota", 180, 1450, 70, "1JZ"));
	CarShop.push_back(make_shared<Nissan>("Silvia s13", "Nissan", 230, 1110, 30, "RB26DET"));
	CarShop.push_back(make_shared<Toyota>("Chaiser", "Toyota", 200, 1350, 80, "1.5JZ"));
	CarShop.push_back(make_shared<Nissan>("Skyline R32", "Nissan", 240, 1430, 80, "RB28DET"));
	CarShop.push_back(make_shared<Mitsubishi>("Lancer Evolution", "Mitsubishi", 220, 1410, 100, "4G63T MIVEC"));
	int choice = 0;
	cout << "Войти в магазин?" << endl;
	cin >> choice;
	if (choice == 1) {
		bool shopCar = true;
		while (shopCar) {
			cout << "Добро пожаловать в магазин" << endl;
			cout << "Доступные авто:" << endl;
			cout << endl;
			for (auto it = CarShop.begin(); it != CarShop.end(); it++) {
				(*it)->ShowCar();
				cout << endl;
			}
			int carChoice = 0;
			cout << "Выберите авто" << endl;
			std::cin >> carChoice;
			if (carChoice == 0) {
				cout << "Выход из магазинга" << endl;
				continue;
			}
			if (carChoice < 1 || carChoice>CarShop.size()) {
				cout << "Некорректный выбор,вы не в себе?" << endl;
				continue;
			}
			auto vybor = CarShop[carChoice - 1];
			cout << "Поздравляем с покупкой!" << endl;
			mygarrage.push_back(vybor);
			vybor->ShowCar();
			cout << endl;
			shopCar = false;
		}
	}
	else {

	}
	int garchoice = 0;
	cout << "Показать гараж-1" << endl;
	cin >> garchoice;
	if (garchoice == 1) {
		ShowMyCars(mygarrage);
	}
	vector<ShopPtr>TunShop;
	TunShop.push_back(make_shared<Shop>("Turbine", 70, 30000));
	TunShop.push_back(make_shared<Shop>("Intercooler", 50, 17000));
	TunShop.push_back(make_shared<Shop>("Nitro", 100, 50000));
	int tshopchoice = 0;
	cout << "Войти в тюнинг-ателье:1" << endl;
	cin >> tshopchoice;
	if (tshopchoice == 1) {
		cout << "Ассортимент" << endl;
		for (auto it = TunShop.begin(); it != TunShop.end(); it++) {
			(*it)->ShowShop();
		}
		int tunchoice = 0;
		cout << "Выберите деталь для покупки:" << endl;
		cin >> tunchoice;
		auto realchoice = TunShop[tunchoice - 1];
		if (realchoice != nullptr) {
			int newls = realchoice->gethar() + mygarrage[0]->getls();
			mygarrage[0]->setLs(newls);
		}
	}
	cout << "Деталь уставновлена успешно" << endl;
	ShowMyCars(mygarrage);
	int racechoice;
	cout << "Устроить гонку?" << endl;
	cin >> racechoice;
	if (racechoice == 1) {
		auto fbot = CarShop[rand() % CarShop.size()];
		auto sbot = CarShop[rand() % CarShop.size()];
		int playerchoice;
		cout << "Выберите авто" << endl;
		ShowMyCars(mygarrage);
		cin >> playerchoice;
		auto playercar = mygarrage[playerchoice - 1];
		cout << "Выбранное авто:" << playercar->getname() << endl;
		int trassa = (rand() % 2) + 1;
		int fbotpower = 0;
		int sbotpower = 0;
		int PlayerPower = 0;
		switch (trassa) {
		case 1: {	
			cout << "Спуск в горах,на старте стоят" << playercar->getname() <<
				' ' << fbot->getname() << " и " << sbot->getname() << endl;
			PlayerPower = playercar->getls() + playercar->getwheel();
			fbotpower = fbot->getls() + fbot->getwheel();
			sbotpower = sbot->getls() + sbot->getwheel();
			break;
		}
		case 2: {
			cout << "На светофоре стоят" << playercar->getname() <<
				' ' << fbot->getname() << " и " << sbot->getname() << endl;
			PlayerPower = playercar->getls() - (playercar->getkg() / 10);
			fbotpower = fbot->getls() - (fbot->getkg() / 10);
			sbotpower = sbot->getls() - (sbot->getkg() / 10);
			break;
		}
		}
		racer funit = { fbot, fbotpower };
		racer sunit{ sbot,sbotpower };
		racer player{ playercar,PlayerPower };
		int max = 0;
		string winner = " ";
		if (fbotpower > sbotpower) {
			max = fbotpower;
			winner = fbot->getname();
		}
		else {
			max = sbotpower;
			winner = sbot->getname();
		}
		if (max < PlayerPower) {
			winner = playercar->getname();
		}
		cout << "Победитель: " << winner << endl;
		LaurelEvents();

		// auto maxval = max(funit, sunit);
		//cout << maxval.carptr->getname() << endl;
	}
	system("Pause");
	return 0;
}