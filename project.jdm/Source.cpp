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
		cout << "Модель:" << carName << "\nМарка:" << carBrand << "\nМощность:" << ls << " Лошадиных сил" << "\nВес:" << kg << " Килограмм" <<"\nЗацеп"<<wheel << endl;
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
void light(vector<car>& lightest) {
	car* morelight = &lightest[0];
	for (int i = 0; i < lightest.size(); i++) {
		if (lightest[i].getkg() < morelight->getkg()) {
			morelight = &lightest[i];
		}
	}
	cout <<"Самая лёгкая машина: "<< morelight->getname();
}
class doublyListNode {
private:
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
			cout << "--------------------------" << endl;
			current = current->next;
		}
	}
	void leader() {
		Node* current=head;
		Node* fastestNode = head;
		while (current == nullptr) {
			cout << "Машина не выбрана" << endl;
			return;
		}
		while(current!=nullptr){
			if (current->carptr->getls() > fastestNode->carptr->getls()) {
				fastestNode=current;
			}
			current = current->next;
		}
		cout << "Самая мощная машина" << fastestNode->carptr->getname();

	}
	void lightest() {
		Node* current = head;
		Node* light = head;
		while (current == nullptr) {
			cout << "Машина не вырбрана" << endl;
			return;
		}
		while (current != nullptr) {
			if (current->carptr->getkg() < light->carptr->getkg()) {
				light = current;
			}
			current = current->next;
		}
		cout << "Самая легкая машина: " << light->carptr->getname() << endl;
	}
};
int main() {
	srand(time(0));
	setlocale(LC_ALL, "rus");
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
		cout << "Выберете машину 1-3 или выйдите-0" << endl;
		cin >> choice;
		if (choice == 1) {
			mark.show();
			cout << endl;
			int swap = 0;
			int limit = 280;
			if (mark.getls() < limit) {
				cout << "Достпуен свап на 2jz.Замена?" << endl;
				cin >> swap;
				if (swap == 1) {
					mark.setLs();
					cout << "Двигатель свапнут!Текущие характеристики:" << endl;
					mark.show();
				}
				else if (choice == 2 || mark.getls() > limit || mark.getls() == limit) {

				}
				if (mark.getwheelstatus() == false) {
					int wheelchoice = 0;
					int wheellimit = 100;
					cout << "Доступна замены резины на резину с большим зацепом.Заменить?" << endl;
					cin >> wheelchoice;
					if (wheelchoice == 1) {
						mark.setwheel();
						mark.setwhellstatus();
						cout << "Резина заменена!Текущие характеристики:" << endl;
						mark.show();
					}
					else if (wheelchoice == 2 || mark.setwheel() > limit || mark.setwheel() == limit) {

					}
				}
			}
		}
		else if (choice == 2) {
			silvia.show();
			int limit = 310;
			int swap = 0;
			if (silvia.getls() < limit) {
				cout << "Доступен свап на SR20DET.Замена?" << endl;
				cin >> swap;
				if (swap == 1) {
					silvia.setLs();
					cout << "Замена проведена успешно!Текущие характеристики:" << endl;
					silvia.show();
				}
				else if (swap == 2 || silvia.getls() > limit) {

				}
				int wheelchoice = 0;
				cout << "Доступна замена резины на резину с большим зацепом!Замена?" << endl;
				cin >> wheelchoice;
				if (wheelchoice == 1 && silvia.getwheelstatus() == false) {
					silvia.setwheel();
					silvia.setwhellstatus();
					cout << "Замена прошла успешно!Текущий статус:" << endl;
					silvia.show();
				}
				else if (wheelchoice == 2 || silvia.getwheelstatus() == true) {

				}
			}
		}
		else if (choice == 3) {
			skyline.show();
			int limit = 340;
			int swap = 0;
			if (skyline.getls() < limit) {
				cout << "Доступен свап на RB26DETT.Замена?" << endl;
				cin >> swap;
				if (swap == 1) {
					skyline.setLs();
					cout << "Текущие характеристики:" << endl;
					skyline.show();
				}
			}
			else if (swap == 2 || skyline.getls() > limit || skyline.getls() == limit) {

			}
			int wheellimit = 100;
			int wheelchoice = 0;
			if (skyline.getwheel() < wheellimit && skyline.getwheelstatus() == false) {
				cout << "Доступна замена шин на шины с большим зацепом.Замена?" << endl;
				cin >> wheelchoice;
				if (wheelchoice == 1) {
					skyline.setwheel();
					skyline.setwhellstatus();
					cout << "Замена прошла успешна!Текущие характеристики:" << endl;
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
	int trassa = rand() % 3 + 1;
	int race = 0;
	cout << "Устроить гонку?" << endl;
	cin >> race;
	if (race == 1) {
		car* racerone = nullptr;
		car* racertwo = nullptr;
		car* racerthree = nullptr;
		int max = 0;
		double maxf = 0;
		car* winner;
		int racechoice = 0;
		cout << "Кто на первой полосе?" << endl;
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
		cout << "Кто на второй полосе?" << endl;
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
		cout << "Кто на третьей полосе?" << endl;
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
			cout << "На светофоре встали" << racerone->getname() << " , " << racertwo->getname() << "и" << racerthree->getname() << endl;
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
				cout << "Победитель " << winner->getname() << endl;
			}
		}
		else if (trassa == 2) {
			cout << "На спуске с горы стоят:" << racerone->getname() << " , " << racertwo->getname() << "и" << racerthree->getname() << endl;
			if (racerone->getls() < racertwo->getls()) {
				max = racerone->getls();
				winner = racerone;
			}
			else {
				max = racertwo->getls();
				winner = racertwo;
			}
			if (max < racerthree->getls()) {
				cout << "Победитель " << winner->getname() << endl;
			}
			else {
				cout << "Победитель " << racerthree->getname() << endl;
			}
			vector<vector<string>>laurel_events = {
						{"полумертвый ","Лаурель ","чуть не въехал"},
						{"черный блестящий ","Лаурель ",",говорят вчера намотался на столб"},
						{"слишком низкий ","Лаурель ",",улетел в кусты"}
			};
			int random_laurel = rand() % 3;
			cout << "Во время гонки мимо прнесся "
				<< laurel_events[random_laurel][0]
				<< laurel_events[random_laurel][1]
				<< laurel_events[random_laurel][2]<< endl;
		}
		else if (trassa == 3) {
			cout << "Гонка по трассе после дождя,на старте стоят: " << racerone->getname() << " , " << racertwo->getname() << "и" << racerthree->getname() << endl;
			if (racerone->getls() * racerone->getwheel() > racertwo->getls() * racertwo->getwheel()) {
				max = racerone->getls() * racerone->getwheel();
				winner = racerone;
			}
			else {
				max = racertwo->getls() * racertwo->getwheel();
				winner = racertwo;
			}
			if (max > racerthree->getls() * racerthree->getwheel()) {
				cout << "Победил " << winner->getname() << endl;
			}
			else {
				cout << "Победил" << racerthree->getname() << endl;
			}
		}
	}
	string det1name = "Турбина";
	int det1_price = 30000;
	int det1_har = 50;
	string det2name = "Интеркуллер";
	int det2_price = 25000;
	int det2_har = 30;
	string det3name = "Спойлер";
	int det3_price = 8000;
	int det3_har = 0;
	int tunchoice;
	cout << "Введите деталь для покупки" << endl;
	cin >> tunchoice;
	vector<vector<string>>tuning;
	tuning.push_back({ det1name, to_string(det1_price),"+" + to_string(det1_har) + "ls"});
	tuning.push_back({ det2name, to_string(det2_price), "+" + to_string(det2_har) + "ls"});
	tuning.push_back({ det3name, to_string(det3_price),"+" + to_string(det3_har) + "ls"});
	if (tunchoice >= 1 && tunchoice <= 3) {
		int ind = tunchoice - 1;
			cout << "Деталь:"<<tuning[ind][0]
				<<"Стоимость:"<< tuning[ind][1]
				<<"Харакетристики:"<<tuning[ind][2] << endl;
	}
	mygarage.leader();
	cout << endl;
	mygarage.lightest();
	system("Pause");
	return 0;
}