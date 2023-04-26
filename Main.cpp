#include <iostream>
#include <fstream>
#include <string>

bool print_file(std::string file_path) {
	static std::ifstream in;
	in.open(file_path);
	if (in.is_open()) {
		char sym;
		while (in.get(sym))
			std::cout << sym;
		std::cout << std::endl;
		in.close();
		return true;
	}
	in.close();
	return false;
}

bool insert_file(std::string file_path, std::string str, int position);

int main() {
	setlocale(LC_ALL, "Russian");
	int n;
	std::string path = "file.txt";


	// Класс fstream
	/*std::fstream file;	// Объект класса fstream, позволяющий одновременно записывать и считывать данные из файла
	file.open(path, std::ios::in | std::ios::app);	// открытие файла с режимами in и app

	if (file.is_open()) {
		std::cout << "Файл открыт.\n";
		// Добавление записи в файл
		std::cout << "Запись в файл.\nВведите строку -> ";
		std::string str;
		std::getline(std::cin, str);
		file << str << '\n';
		std::cout << "Запись добавлена в файл.\n";
		
		file.seekg(0, std::ios::beg);	// перемещение курсора для считывания данных в начало файла

		// Чтение из файла
		std::cout << "Содержимое файла:\n";
		char sym;
		while (file.get(sym))
			std::cout << sym;
	}
	else
		std::cout << "Ошибка открытия файла!\n";
	file.close();*/


	// Задание "Ввод в позицию файла"
	/*std::cout << "Содержимое файла:\n";
	print_file(path);

	std::cout << "Введите строку -> ";
	std::string substr;
	std::getline(std::cin, substr);
	std::cout << "Введите позицию -> ";
	std::cin >> n;

	if (insert_file(path, substr, n)) {
		std::cout << "Вставка выполнена успешною\n";
		std::cout << "Содержимое файла:\n";
		print_file(path);
		std::cout << std::endl;
	}
	else
		std::cout << "Ошибка выполнения функции!.\n\n";*/

	
	// Задача 1. Чтение даты из файла
	std::cout << "Задача 1.\nСодержимое файла:\n";
	std::string date_path = "date.txt";
	print_file(date_path);

	std::string date;
	std::ifstream in;
	in.open(date_path);
	if (in.is_open()) {
		char sym;
		while (in.get(sym))
			date += sym;
	}
	else
		std::cout << "Ошибка открытия файла!\n";
	in.close();

	unsigned int year_index = date.rfind('.') + 1;
	unsigned int month_index = date.find('.') + 1;

	unsigned int day = std::stoi(date.substr(0, month_index - 1));
	unsigned int month = std::stoi(date.substr(month_index, year_index - 1 - month_index));
	unsigned int year = std::stoi(date.substr(year_index));

	std::cout << "День:  " << day << std::endl;
	std::cout << "Месяц: " << month << std::endl;
	std::cout << "Год:   " << year << std::endl;

	return 0;
}

bool insert_file(std::string file_path, std::string str, int position) {
	std::string file_text;
	std::fstream file;
	file.open(file_path, std::ios::in);
	if (file.is_open()) {
		char sym;
		while (file.get(sym))
			file_text += sym;
	}
	else {
		file.close();
		return false;
	}
	file.close();

	file_text.insert(position, str);

	file.open(file_path, std::ios::out);
	if (file.is_open()) {
		file << file_text;
		file.close();
		return true;
	}
	file.close();
	return false;
}
