#include <iostream>
#include <string>
using namespace std;

struct Item {
	int inventoryNumber;
	char group;

	union {
		struct {
			char material[20];
			double weight;
		};
		struct {
			double height;
			double width;
			double depth;
		};
	};
};

void PrintItem(const Item& item) {
	if (item.group == 'A') {
		cout << "Инвентарный номер: " << item.inventoryNumber << endl;
		cout << "Группа: " << item.group << endl;
		cout << "Материал: " << item.material << endl;
		cout << "Вес: " << item.weight << endl;
	}
	else {
		cout << "Инвентарный номер: " << item.inventoryNumber << endl;
		cout << "Группа: " << item.group << endl;
		cout << "Высота: " << item.height << endl;
		cout << "Ширина: " << item.width << endl;
		cout << "глубина: " << item.depth << endl;
	}
}

Item items[5];

int main()
{
	setlocale(LC_ALL, "ru");

	//for (int i = 0; i < 5; i++) {
	//	cout << "Введите информацию об изделии n" << i + 1 << endl;
	//	cout << "Инвентарный номер: ";
	//	cin >> items[i].inventoryNumber;
	//	cout << "Группа (A/B): ";
	//	cin >> items[i].group;

	//	if (items[i].group == 'A') {
	//		cout << "Материал (wood/plastic): ";
	//		cin >> items[i].material;
	//		//gets_s(items[i].material, 255);
	//		//cin.getline(items[i].material, 255);
	//		//strcpy_s(items[1].material,"wood");
	//		cout << "Вес: ";
	//		cin >> items[i].weight;
	//	}
	//	else if (items[i].group == 'B') {
	//		cout << "Высота: ";
	//		cin >> items[i].height;
	//		cout << "Ширина: ";
	//		cin >> items[i].width;
	//		cout << "Глубина: ";
	//		cin >> items[i].depth;
	//	}
	//}

	items[0].inventoryNumber = 5;
	items[0].group = 'A';
	strcpy_s(items[0].material, "wood");
	items[0].weight = 28;

	items[1].inventoryNumber = 4;
	items[1].group = 'A';
	strcpy_s(items[1].material, "plastic");
	items[1].weight = 120;

	items[2].inventoryNumber = 3;
	items[2].group = 'B';
	items[2].height = 14;
	items[2].width = 63;
	items[2].depth = 8;

	items[3].inventoryNumber = 2;
	items[3].group = 'A';
	strcpy_s(items[3].material, "wood");
	items[3].weight = 54;

	items[4].inventoryNumber = 1;
	items[4].group = 'A';
	strcpy_s(items[4].material, "wood");
	items[4].weight = 47;

	float maxWeight;
	cout << "Введите максимальный вес изделия: ";
	cin >> maxWeight;

	cout << "Список изделий группы A, изготовленных из дерева "
		<< "и имеющих вес не более " << maxWeight << ":" << endl << endl;

	string wood = "wood";
	for (int i = 0; i < 5; ++i) {
		if (items[i].group == 'A' && items[i].material == wood && items[i].weight <= maxWeight) {
			PrintItem(items[i]);
			cout << endl;
		}
	}

	return 0;
}
