#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <set>


using namespace std;

struct Words{
	char word[50];

};

void createGroups(int n, Words* Array, int N) {
	char* temp1;
	char* temp2;
	int numberWords=0; //количество "нужных" слов 
	bool result = false;


	for (int i = 0; i < N; i++) { //считаем количество слов с нужными параметрами (у которых символов достаточно для создания группы)
		if (strlen(Array[i].word) >= n) {
			numberWords++;
		}
	}
	
	Words* TempArray = new Words[numberWords];

	for (int i=0 , j = 0; i < N; i++) { //записываем во временный массив слова с нужными характеристиками (у которых символов достаточно для создания группы)
		if (strlen(Array[i].word) >= n) {
			TempArray[j] = Array[i];
			j++;
		}
	}
	

	Words* TempOfTemp = new Words[numberWords];
	for (int i = 0; i < numberWords-1; i++) { //находим и убираем  слова у которых одинаковые первые буквы  в массиве и удаляем дубликаты 
		temp1 = TempArray[i].word;
		for (int j = i+1; j < numberWords; j++) {
			temp2 = TempArray[j].word;
			for (int k = 0; k < n; k++) {
				if (temp1[k] == temp2[k]) { //если одинаковые первые буквы 
					result = true;
					/*cout << endl << temp1[k] <<" "<< temp2[k];*/
				}
				else { //если разные 
					result = false;
					/*cout << endl << temp1[k] << "?" << temp2[k];*/
					break;
				}
			}
			if (result) { //удаляем элемент-дубликат если они  одинаковые 
				/*cout << endl<<temp1<<i<<" " << "delete: " <<temp2<<j<< endl;*/
				i--;
				for (int a = 0; a < numberWords; a++) { //записываем данные во временный массив 
					TempOfTemp[a] = TempArray[a];
					
				}
				numberWords--;
				TempArray = new Words[numberWords];

				for (int a = 0, b = 0; a <= numberWords; a++) { // возвращаем данные без одинаковых элементов в старый массив
					if (a == j) a++;
					TempArray[b] = TempOfTemp[a];
					b++;
				}

				
			}
		}
	}
	delete[]TempOfTemp;

	cout << endl<<"Возможные группы:"<<endl;
	for (int i = 0; i < numberWords; i++) {
		cout << TempArray[i].word << "/ ";
	}
	cout << endl;
	string String1;
	string String2;

	cout << endl;
	for (int i = 0; i < numberWords; i++) {
		temp1 = TempArray[i].word;
		String1 = temp1;
		cout << "____________________________________________" << endl;
		cout << i + 1 << "Group:" <<String1.substr(0,n)  << endl;
		for (int j = 0; j < N; j++) { //сравниваем группы и слова в массиве 
			temp2 = Array[j].word;
			String2 = temp2;
			if ((String1.substr(0, n) == String2.substr(0, n)) && (String1.substr(0, n) != String2) ) { //если основа слова совпадает c группой,выводим слово 
				cout << temp2 << endl;
				if (temp1 == temp2) {
					cout << "hui" << endl;
				}
			}


		}
	}
	delete[]TempArray;
	
}

void sortStr(Words *Array, int N) {
	int code;
	for (int n = 1; n < N; n++) { //сортируем данные по алфавиту 
		for (int m = 0; m < N - n; m++) {
			code = strcmp(Array[m + 1].word, Array[m].word);
			if (code < 0) {
				swap(Array[m], Array[m + 1]);
			}
		}
	}

	

	cout << "По какому кол-ву символов хотите найти сходства?" << endl;
	int choice;
	cin >> choice;
	createGroups(choice,Array,N);
	
}




int workwithFile() {
	string mainStr;
	fstream file; //создаем файл 
	string fileName = "file.txt"; // переменная хранит назваие файла 
	file.open(fileName, fstream::in | fstream::out | fstream::app);

	if (!file.is_open()) {
		cout << "Ошибка открытия файла!" << endl;
		return 0;
	}
	else {
		cout << "Файл открыт!" << endl;
		string str;
		int i = 0;
		while (!file.eof()) {  //пока файл открыт 
			file >> str; //без этого цикл будет вечный 
		    i++; //считаем количество слов/символов
		}
		file.close();
		file.open(fileName, fstream::in | fstream::out | fstream::app);
		Words* Array = new Words[i];
		i = 0;
		while (!file.eof()) {  //пока не конец файла 
			file >> Array[i].word; //записываем в массив структур
			i++;
		}
		
		
		sortStr(Array,i);
	}


	file.close();
}



int main() {
	int choice = 0;
	bool temp = true;
	setlocale(LC_ALL, "rus");
	do {
		workwithFile();
		cout << "Хотите продолжить?(1-да 2-нет)" << endl;
		
		cin >> choice;
		if (choice == 1) {
			temp = true;
		}
		else if (choice == 2) {
			temp = false;
		}

	} while (temp);

}