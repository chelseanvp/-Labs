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
	int numberWords=0; //���������� "������" ���� 
	bool result = false;


	for (int i = 0; i < N; i++) { //������� ���������� ���� � ������� ����������� (� ������� �������� ���������� ��� �������� ������)
		if (strlen(Array[i].word) >= n) {
			numberWords++;
		}
	}
	
	Words* TempArray = new Words[numberWords];

	for (int i=0 , j = 0; i < N; i++) { //���������� �� ��������� ������ ����� � ������� ���������������� (� ������� �������� ���������� ��� �������� ������)
		if (strlen(Array[i].word) >= n) {
			TempArray[j] = Array[i];
			j++;
		}
	}
	

	Words* TempOfTemp = new Words[numberWords];
	for (int i = 0; i < numberWords-1; i++) { //������� � �������  ����� � ������� ���������� ������ �����  � ������� � ������� ��������� 
		temp1 = TempArray[i].word;
		for (int j = i+1; j < numberWords; j++) {
			temp2 = TempArray[j].word;
			for (int k = 0; k < n; k++) {
				if (temp1[k] == temp2[k]) { //���� ���������� ������ ����� 
					result = true;
					/*cout << endl << temp1[k] <<" "<< temp2[k];*/
				}
				else { //���� ������ 
					result = false;
					/*cout << endl << temp1[k] << "?" << temp2[k];*/
					break;
				}
			}
			if (result) { //������� �������-�������� ���� ���  ���������� 
				/*cout << endl<<temp1<<i<<" " << "delete: " <<temp2<<j<< endl;*/
				i--;
				for (int a = 0; a < numberWords; a++) { //���������� ������ �� ��������� ������ 
					TempOfTemp[a] = TempArray[a];
					
				}
				numberWords--;
				TempArray = new Words[numberWords];

				for (int a = 0, b = 0; a <= numberWords; a++) { // ���������� ������ ��� ���������� ��������� � ������ ������
					if (a == j) a++;
					TempArray[b] = TempOfTemp[a];
					b++;
				}

				
			}
		}
	}
	delete[]TempOfTemp;

	cout << endl<<"��������� ������:"<<endl;
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
		for (int j = 0; j < N; j++) { //���������� ������ � ����� � ������� 
			temp2 = Array[j].word;
			String2 = temp2;
			if ((String1.substr(0, n) == String2.substr(0, n)) && (String1.substr(0, n) != String2) ) { //���� ������ ����� ��������� c �������,������� ����� 
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
	for (int n = 1; n < N; n++) { //��������� ������ �� �������� 
		for (int m = 0; m < N - n; m++) {
			code = strcmp(Array[m + 1].word, Array[m].word);
			if (code < 0) {
				swap(Array[m], Array[m + 1]);
			}
		}
	}

	

	cout << "�� ������ ���-�� �������� ������ ����� ��������?" << endl;
	int choice;
	cin >> choice;
	createGroups(choice,Array,N);
	
}




int workwithFile() {
	string mainStr;
	fstream file; //������� ���� 
	string fileName = "file.txt"; // ���������� ������ ������� ����� 
	file.open(fileName, fstream::in | fstream::out | fstream::app);

	if (!file.is_open()) {
		cout << "������ �������� �����!" << endl;
		return 0;
	}
	else {
		cout << "���� ������!" << endl;
		string str;
		int i = 0;
		while (!file.eof()) {  //���� ���� ������ 
			file >> str; //��� ����� ���� ����� ������ 
		    i++; //������� ���������� ����/��������
		}
		file.close();
		file.open(fileName, fstream::in | fstream::out | fstream::app);
		Words* Array = new Words[i];
		i = 0;
		while (!file.eof()) {  //���� �� ����� ����� 
			file >> Array[i].word; //���������� � ������ ��������
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
		cout << "������ ����������?(1-�� 2-���)" << endl;
		
		cin >> choice;
		if (choice == 1) {
			temp = true;
		}
		else if (choice == 2) {
			temp = false;
		}

	} while (temp);

}