// В задаче следует написать структуру данных, обрабатывающую команды push* и pop*.
//Формат входных данных.
//В первой строке количество команд n.n ≤ 1000000.
//Каждая команда задаётся как 2 целых числа : a b.
//a = 1 - push front
//a = 2 - pop front
//a = 3 - push back
//a = 4 - pop back
//Для очереди используются команды 2 и 3. Для дека используются все четыре команды.
//Если дана команда pop*, то число b - ожидаемое значение.Если команда pop вызвана для пустой структуры данных, то ожидается “ - 1”.
//Формат выходных данных.
//Требуется напечатать YES - если все ожидаемые значения совпали.Иначе, если хотя бы одно ожидание не оправдалось, то напечатать NO.

//1_1.Реализовать очередь с динамическим зацикленным буфером.
//Базовые структуры данных.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
//in
//3 3 44 3 50 2 44
//out
//YES
//in
//2 2 -1 3 10
//out
//YES
//in
//2 3 44 2 66
//out
//NO


#include <iostream>
using namespace std;
using std::cout;
using std::endl;

class Ochered { //добавление класса
private:
	int* buf = nullptr; //ссылка на выделяемый буфер
	int buf_size = 0; //размер буфера
	int begin = 0; //номер начала буфера
	int Ochered_size = 0; //размер 
	void realocation(int new_size) { //операция увеличения памяти (объяснить)
		int* new_buffer = new int[new_size];
		for (int i = 0; i < Ochered_size; i++) {
			new_buffer[i] = buf[(begin + i) % buf_size];
		}
		delete[] buf;
		buf = new_buffer;
		buf_size = new_size;
		begin = 0;
	}
public:
	bool empty() { return Ochered_size == 0; } //проверка что очередь пустая
	void push_back(int value) { //добавление в конец
		if (buf_size == Ochered_size) { //если размер надо увеличить его увеличиваем в 2 раза +5
			realocation(buf_size * 2 + 5);
		}
		buf[(begin + Ochered_size) % buf_size] = value; //потом записываем в конец value
		Ochered_size++; //увеличиваем размер на 1
	}
	int pop_front() {//удаление первого элемента
		int result = buf[begin];
		Ochered_size--;
		begin++;
		if (begin == buf_size) { begin = 0; }
		return result;
	}

	~Ochered() {}
};

int main() {
	Ochered t; // создание объекта класса
	int n;
	cin >> n; //считываем количество операций
	for (int i = 0; i < n; i++) { //циклом проходим по операциям
		int command, value;
		cin >> command >> value;
		if (command == 3) { //если 3 записываем в конец
			t.push_back(value);
		}
		else if (command == 2) {
			if (t.empty() && value != -1) {
				cout << "NO" << endl;
				return 0;
			}
			else if (t.empty() && value == -1) {
			}
			else if (t.pop_front() != value) {
				cout << "NO" << endl;
				return 0;
			}
		}

	}
	cout << "YES" << endl;
	return 0;
}