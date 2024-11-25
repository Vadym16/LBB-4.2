#include <iostream>
#include <string>

using namespace std;

class Arr {
public:
	Arr() : size(0), codeError(0){}

	void set_arr(int num, const string& txt) {
		if (size < 100) {
			arr[size].num = num;
			arr[size].txt = txt;
			size++;
		}
	}

	string operator[](int num) {
		for (int i = 0; i < size; i++) {
			if (arr[i].num == num) {
				codeError = 0;
				return arr[i].txt;
			}
		}
		codeError = 1;
	}
	string operator()(int num) {
		return this->operator[](num);
	}

	friend istream& operator>>(istream& is, Arr& arr) {
		int num;
		string txt;
		is >> num >> txt;
		arr.set_arr(num, txt);
		return is;
	}
	friend ostream& operator<<(ostream& os, Arr& arr) {
		for (int i = 0; i < arr.size; i++) {
			os << arr.arr[i].num << " - " << arr.arr[i].txt << endl;
		}
		return os;
	}


private:
	struct para {
		int num;
		string txt;
	};

	para arr[100];
	int size;
	int codeError;
};

int main()
{
	setlocale(LC_ALL, "ukr");

	Arr ar;
	ar.set_arr(1, "один");
	ar.set_arr(2, "два");
	ar.set_arr(3, "три");
	ar.set_arr(4, "чотири");

	cout << "Масив: " << endl << ar;
	cout << "Введіть нові значення масиву: " << endl; cin >> ar;
	cout << "Масив з доданими елементами: " << endl << ar;

}



