#include<iostream>
#include <iomanip>
#include<string>
#include<vector>
using namespace std;
void dvig(int power) {
	;
}

class car {
private:
	string carName;
	string carBrand;
	bool hasnewwheels = false;
	int ls;
	int kg;
	int wheel;
public:
	car(string name, string brand, int power, int weight,int zacep) {
		carName = name;
		carBrand = brand;
		ls = power;
		kg = weight;
	 wheel=zacep;
	}
	void show() {
		std::cout << "Модель:" << carName << "\nМарка:" << carBrand << "\nМощность:" << ls << " Лошадиных сил" << "\nВес:" << kg << " Килограмм" <<"\nЗацеп"<<wheel << endl;
	}
	void setLs(int value = 100) {
		ls = ls + value;
		kg = kg + value;
	}
	int getls() {
		return ls;
	}
	string getname() {
		return carName;
	}
	int getkg() {
		return kg;
	}
	int setwheel(int value = 100) {
		int temp = 100-wheel/2;
		wheel = temp+wheel;	
		return wheel;
	}
	int getwheel(){
		return wheel;
	}
	bool getwheelstatus() {
		return hasnewwheels;
	}
	bool setwhellstatus() {
		return hasnewwheels = true;
	}
};
class Nissan : public car {
public:
	Nissan(string carName, string carBrand, int ls, int weight,int zacep)
		:car(carName,carBrand,ls,weight,zacep) {
//Здесь класс car вносит данные в свои переменные
}
};
class Toyota : public car {
public:
	Toyota(string carName, string carBrand, int ls, int weight,int zacep)
		:car(carName, carBrand, ls, weight,zacep) {

	}
};
class doublyListNode {
public:
	struct Node {
		car* carptr;
		Node* next;
		Node* prev;
		Node(car* machine) : carptr(machine), next(nullptr), prev(nullptr) {}
	};
public:
	Node* head;
	Node* tail;
	doublyListNode() :head(nullptr), tail(nullptr) {}
	void insertAtEnd(car* machine) {
		Node* newNode = new Node(machine);
		if (head==nullptr) {
			head = newNode;
			tail = newNode;
		}
		else {
				tail->next = newNode;
			newNode->prev = tail;
			tail = newNode;
		}
	}
	void insertAtHead(car* machine) {
		Node* newNode = new Node(machine);
		if (head == nullptr) {
			head = newNode;
		}
		else {
			newNode->next = head;
			head->prev = newNode;
			head = newNode;
		}
	}
	void printGarage() {
		Node* current = head;
		while (current != nullptr) {
			current->carptr->show();
			std::cout << "--------------------------" << endl;
			current = current->next;
		}
	}
	void leader() {
		Node* current=head;
		Node* fastestNode = head;
		while (current == nullptr) {
			std::cout << "Машина не выбрана" << endl;
			return;
		}
		while(current!=nullptr){
			if (current->carptr->getls() > fastestNode->carptr->getls()) {
				fastestNode=current;
			}
			current = current->next;
		}
		std::cout << "Самая мощная машина" << fastestNode->carptr->getname();

	}
	void lightest() {
		Node* current = head;
		Node* light = head;
		while (current == nullptr) {
			std::cout << "Машина не выбрана" << endl;
			return;
		}
		while (current != nullptr) {
			if (current->carptr->getkg() < light->carptr->getkg()) {
				light = current;
			}
			current = current->next;
		}
		std::cout << "Самая легкая машина: " << light->carptr->getname() << endl;
	}

	Node* getCarNode(int choice) {
		Node* current = head;
		int count = 1;
		while (current != nullptr) {
			if (count == choice) {
				return current;
		}
			count++;
			current = current->next;
		}

	}
};
struct Part {//"Коробка" с грузом (деталями)
	string partName;
	int partCost;
	int partBoost;
	Part(string name, int cost, int bonus) : partName(name), partCost(cost), partBoost(bonus) {}
};
	class tuningShop {//Класс магазина
	private:
		struct shopNode {
			shopNode* next;
			shopNode* prev;
			Part* partptr;
			shopNode(Part* ptr) : partptr(ptr), next(nullptr),prev(nullptr) {}
		};
	public:
		shopNode* head = nullptr;

//Функция добавления запчастей в конец списка(с конца списка)
	
		void addToEnd(Part*detail) {
			shopNode* newNode = new shopNode(detail);//new т.к. создается потеницально новый объект, 
			//detail-временая переменная для пердачи данных в partptr;
			shopNode* current = head;
				if (head == nullptr) {
					head = newNode;
				}
				else {
					while (current->next != nullptr) {
						current=current->next;
					}
						current->next=newNode;
						newNode->prev = current;
					}
			}

		//Функция для вывода магазина
		void showShop() { 
			shopNode* current = head;
			int index = 1;
			if (head == nullptr) {
				std::cout << "На полках пусто" << endl;
				return;
			}
			while (current!= nullptr) {
				std::cout << index << "." << "Деталь:" << current->partptr->partName << " Стоимость: " << current->partptr->partCost << "Эффект от детали:" << current->partptr->partBoost << endl;
				std::cout << endl;	
				std::cout << setfill('-') << setw(20)<<endl;
				current = current->next;
				index++;
			}
		}

		//Сверение выбора игрока с деталью из магазина 

		Part*getPartPtr(int menuIndex) {
			int count = 1;
			shopNode* current = head;//Имеет тип shopNode
			while (current	!= nullptr) {
				if (menuIndex == count) {
					return current->partptr;
				}
				count++;
				current = current->next;
		}
			return nullptr;
		}
	};
int main() {
	srand(time(0));
	setlocale(LC_ALL, "rus");
	doublyListNode::Node* activeCarNode = nullptr;
	Nissan silvia("Silvia s13", "Nissan", 240, 1110, 30);
	Nissan skyline("Skyline", "Nissan", 240, 1430, 35);
	Toyota mark("Mark II", "Toyota", 180, 1450, 70);
	doublyListNode mygarage;
	mygarage.insertAtEnd(&silvia);
	mygarage.insertAtEnd(&skyline);
	mygarage.insertAtHead(&mark);
	mygarage.printGarage();
	int choice = 0;
	bool shop = true;
	while (shop) {
		std::cout << "Выберете машину 1-3 или выйдите-0" << endl;
		cin >> choice;
		if (choice == 1) {
		 activeCarNode = mygarage.getCarNode(choice);
			mark.show();
			std::cout << endl;
			int swap = 0;
			int limit = 280;
			if (mark.getls() < limit) {
				std::cout << "Достпуен свап на 2jz.Замена?" << endl;
				cin >> swap;
				if (swap == 1) {
					mark.setLs();
					std::cout << "Двигатель свапнут!Текущие характеристики:" << endl;
					mark.show();
				}
				else if (choice == 2 || mark.getls() > limit || mark.getls() == limit) {

				}
				if (mark.getwheelstatus() == false) {
					int wheelchoice = 0;
					int wheellimit = 100;
					std::cout << "Доступна замены резины на резину с большим зацепом.Заменить?" << endl;
					cin >> wheelchoice;
					if (wheelchoice == 1) {
						mark.setwheel();
						mark.setwhellstatus();
						std::cout << "Резина заменена!Текущие характеристики:" << endl;
						mark.show();
					}
					else if (wheelchoice == 2 || mark.setwheel() > limit || mark.setwheel() == limit) {

					}
				}
			}
		}
		else if (choice == 2) {
			activeCarNode = mygarage.getCarNode(choice);
			silvia.show();
			int limit = 310;
			int swap = 0;
			if (silvia.getls() < limit) {
				std::cout << "Доступен свап на SR20DET.Замена?" << endl;
				cin >> swap;
				if (swap == 1) {
					silvia.setLs();
					std::cout << "Замена проведена успешно!Текущие характеристики:" << endl;
					silvia.show();
				}
				else if (swap == 2 || silvia.getls() > limit) {

				}
				int wheelchoice = 0;
				std::cout << "Доступна замена резины на резину с большим зацепом!Замена?" << endl;
				cin >> wheelchoice;
				if (wheelchoice == 1 && silvia.getwheelstatus() == false) {
					silvia.setwheel();
					silvia.setwhellstatus();
					std::cout << "Замена прошла успешно!Текущий статус:" << endl;
					silvia.show();
				}
				else if (wheelchoice == 2 || silvia.getwheelstatus() == true) {

				}
			}
		}
		else if (choice == 3) {
			activeCarNode = mygarage.getCarNode(choice);
			skyline.show();
			int limit = 340;
			int swap = 0;
			if (skyline.getls() < limit) {
				std::cout << "Доступен свап на RB26DETT.Замена?" << endl;
				cin >> swap;
				if (swap == 1) {
					skyline.setLs();
					std::cout << "Текущие характеристики:" << endl;
					skyline.show();
				}
			}
			else if (swap == 2 || skyline.getls() > limit || skyline.getls() == limit) {

			}
			int wheellimit = 100;
			int wheelchoice = 0;
			if (skyline.getwheel() < wheellimit && skyline.getwheelstatus() == false) {
				std::cout << "Доступна замена шин на шины с большим зацепом.Замена?" << endl;
				cin >> wheelchoice;
				if (wheelchoice == 1) {
					skyline.setwheel();
					skyline.setwhellstatus();
					std::cout << "Замена прошла успешна!Текущие характеристики:" << endl;
					skyline.show();
				}
				else if (wheelchoice == 2 || skyline.getwheel() > wheellimit || skyline.getwheel() == wheellimit) {

				}
			}
		}
		else if (choice == 0) {
			shop = false;
		}
	}

	Part turbine("Турбина", 30000, 70);
	Part intercooler("Интеркуллер", 25000, 50);
	Part spoiler("Спойлер", 8000, 0);

	tuningShop magaz;
	magaz.addToEnd(&turbine);
	magaz.addToEnd(&intercooler);
	magaz.addToEnd(&spoiler);
	int choicenext = 0;
	std::cout << "Войти в магазин?" << endl;
	cin>> choicenext;
	if (choicenext == 1) {
		magaz.showShop();
		int tunchoice = 0;
		std::cout << "Введите номер детали для покупки" << endl;
		cin >> tunchoice;
		Part* chosenPart = magaz.getPartPtr(tunchoice);
		if (chosenPart != nullptr) {
			activeCarNode->carptr->setLs(chosenPart->partBoost);
			std::cout << "Деталь успешно установлена" << endl;
			std::cout << "Текущие характеристики:" << endl;
			activeCarNode->carptr->show();
		}
		else {
			std::cout << "Такая деталь отсутсвует" << endl;
		}
	}
	int trassa = rand() % 3 + 1;
	int race = 0;
	std::cout << "Устроить гонку?" << endl;
	cin >> race;
	if (race == 1) {
		car* racerone = nullptr;
		car* racertwo = nullptr;
		car* racerthree = nullptr;
		int max = 0;
		double maxf = 0;
		car* winner;
		int racechoice = 0;
		std::cout << "Кто на первой полосе?" << endl;
		cin >> racechoice;
		if (racechoice == 1) {
			racerone = &mark;
		}
		else if (racechoice == 2) {
			racerone = &silvia;
		}
		else if (racechoice == 3) {
			racerone = &skyline;
		}
		int racechoicesec = 0;
		std::cout << "Кто на второй полосе?" << endl;
		cin >> racechoicesec;
		if (racechoicesec == 1) {
			racertwo = &mark;
		}
		else if (racechoicesec == 2) {
			racertwo = &silvia;
		}
		else if (racechoicesec == 3) {
			racertwo = &skyline;
		}
		int racerchoicethree = 0;
		std::cout << "Кто на третьей полосе?" << endl;
		cin >> racerchoicethree;
		if (racerchoicethree == 1) {
			racerthree = &mark;
		}
		else if (racerchoicethree == 2) {
			racerthree = &silvia;
		}
		else if (racerchoicethree == 3) {
			racerthree = &skyline;
		}
		if (trassa == 1 ) {
			std::cout << "На светофоре встали" << racerone->getname() << " , " << racertwo->getname() << "и" << racerthree->getname() << endl;
			if ((double)racerone->getls() / (double)racerone->getkg() > (double)racertwo->getls() / (double)racertwo->getkg()) {
				maxf = (double)racerone->getls() / (double)racerone->getkg();
				winner = racerone;
			}
			else {
				maxf = (double)racertwo->getls() / (double)racertwo->getkg();
				winner = racertwo;
			}
			if (maxf < (double)racerthree->getls() / (double)racerthree->getkg()) {
				winner = racerthree;
			}
			else {
				std::cout << "Победитель " << winner->getname() << endl;
			}
		}
		else if (trassa == 2) {
			std::cout << "На спуске с горы стоят:" << racerone->getname() << " , " << racertwo->getname() << "и" << racerthree->getname() << endl;
			if (racerone->getls() < racertwo->getls()) {
				max = racerone->getls();
				winner = racerone;
			}
			else {
				max = racertwo->getls();
				winner = racertwo;
			}
			if (max < racerthree->getls()) {
				std::cout << "Победитель " << winner->getname() << endl;
			}
			else {
				std::cout << "Победитель " << racerthree->getname() << endl;
			}
			vector<vector<string>>laurel_events = {
						{"полумертвый ","Лаурель ","чуть не въехал"},
						{"черный блестящий ","Лаурель ",",говорят вчера намотался на столб"},
						{"слишком низкий ","Лаурель ",",улетел в кусты"}
			};
			int random_laurel = rand() % 3;
			std::cout << "Во время гонки мимо прнесся "
				<< laurel_events[random_laurel][0]
				<< laurel_events[random_laurel][1]
				<< laurel_events[random_laurel][2]<< endl;
		}
		else if (trassa == 3) {
			std::cout << "Гонка по трассе после дождя,на старте стоят: " << racerone->getname() << " , " << racertwo->getname() << "и" << racerthree->getname() << endl;
			if (racerone->getls() * racerone->getwheel() > racertwo->getls() * racertwo->getwheel()) {
				max = racerone->getls() * racerone->getwheel();
				winner = racerone;
			}
			else {
				max = racertwo->getls() * racertwo->getwheel();
				winner = racertwo;
			}
			if (max > racerthree->getls() * racerthree->getwheel()) {
				std::cout << "Победил " << winner->getname() << endl;
			}
			else {
				std::cout << "Победил" << racerthree->getname() << endl;
			}
		}
	}
	mygarage.leader();
	std::cout << endl;
	mygarage.lightest();
	system("Pause");
	return 0;
}