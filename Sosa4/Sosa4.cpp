#include <iostream>
#include <string>
#include <fstream>
#include <Windows.h>
#include <random>
using namespace std;


int random(int low, int high) {
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> dist(low, high);
	return dist(gen);
}
ifstream file("C:\\Game.txt");
ifstream file_2("C:\\GameHard.txt");
string question(int gamemode) {
	string quest, A, B, C, D, RightAnswer,word;
	int n,k=0;
	if (gamemode == 1) {
		getline(file, quest);
		cout << quest << endl << endl;
		getline(file, A);
		cout << A << endl << endl;
		getline(file, B);
		cout << B << endl << endl;
		getline(file, C);
		cout << C << endl << endl;
		getline(file, D);
		cout << D << endl << endl;
		getline(file, RightAnswer);
		return RightAnswer;
	}
	if (gamemode == 2) {
		getline(file_2, quest);
		cout << quest << endl << endl;
		getline(file_2, A);
		cout << A << endl << endl;
		getline(file_2, B);
		cout << B << endl << endl;
		getline(file_2, C);
		cout << C << endl << endl;
		getline(file_2, D);
		cout << D << endl << endl;
		getline(file_2, RightAnswer);
		return RightAnswer;
	}	
	
}


string InfinityQuestion(int gamemode,int n) {
	string quest, A, B, C, D, RightAnswer, word;
	int k=0;
	if (gamemode == 3) {
		ifstream file_3("C:\\GameInfinity.txt");
		for (int i = 0;i <= 144; i++) {
			getline(file_3, quest);
			k++;
			if (k == n) {
				getline(file_3, quest);
				cout << quest << endl << endl;
				getline(file_3, A);
				cout << A << endl << endl;
				getline(file_3, B);
				cout << B << endl << endl;
				getline(file_3, C);
				cout << C << endl << endl;
				getline(file_3, D);
				cout << D << endl << endl;
				getline(file_3, RightAnswer);
				k = 0;
				file_3.close();
				return RightAnswer;
			}
		}
	}
}
void PomoshZala(string RightAnswer) {
	int n = random(1, 4);
	if (n == 1) cout<<"Зал выбрал ответ "<<RightAnswer << endl;
	if (n == 2) cout << "Зал выбрал ответ B" << endl;
	if (n == 3)  cout << "Зал выбрал ответ C" << endl;
	if (n == 4) cout << "Зал выбрал ответ D"<<endl;
}

void Fifty(string RightAnswer) {
	string NotRightAnswer;
	if (RightAnswer == "A") NotRightAnswer = "B";
	if (RightAnswer == "B") NotRightAnswer = "A";
	if (RightAnswer == "C") NotRightAnswer = "D";
	if (RightAnswer == "D") NotRightAnswer = "C";
	cout << "Ответы " << RightAnswer << " и " <<NotRightAnswer <<endl;
}

void Zvonok(string RightAnswer) {
	cout << "Вы звоните другу" << endl <<"..." << endl << "..." << endl << "..."<<endl;
	int n = random(1, 2);
	if (n==1) cout << "Друг выбрал ответ " << RightAnswer << endl;
	else cout << "Друг не знает ответа" << endl;
	cout << "Звонок завершен" << endl;
}

string help(string RightAnswer, int pomosh, int fifty, int zvonok) {
	string quest;
	cout << "Помощь зала - нажмите 1, 50/50 - нажмите 2, позвонить другу - нажмите 3" << endl;
	cin >> quest;
	if (quest == "1" && pomosh != 0) {
		PomoshZala(RightAnswer);
		pomosh -= 1;
	}
	else if (quest == "2" && fifty != 0) {
		Fifty(RightAnswer);
		fifty -= 1;
	}
	else if (quest == "3" && zvonok != 0) {
		Zvonok(RightAnswer);
		zvonok -= 1;
	}
	else {
		cout << "Шутим, значит? последний раз спрашиваю." << endl;
		cout << "Помощь зала - нажмите 1, 50/50 - нажмите 2, позвонить другу - нажмите 3" << endl;
		cin >> quest;
		if (quest == "1" && pomosh != 0) {
			PomoshZala(RightAnswer);
			pomosh -= 1;
		}
		else if (quest == "2" && fifty != 0) {
			Fifty(RightAnswer);
			fifty -= 1;
		}
		else if (quest == "3" && zvonok != 0) {
			Zvonok(RightAnswer);
			zvonok -= 1;
		}
	}
	string mass;
	mass += pomosh;
	mass += fifty;
	mass += zvonok;
	return mass;
}






int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	string name,quest,A,B,C,D,mass;
	int FileSize;
	FileSize = 24;
	int* mass1 = new int[FileSize]{};
	string RightAnswer;
	int gamemode,QuNumber,flag = 0,k=0, zvonok = 1, fifty = 1, pomosh = 1,q=0,health=3;
	cout << "Выберите режим игры." << endl<<"1.Обычный" << endl << "2.Усложненный" << endl << "3.Бесконечный" << endl;
	cin >> gamemode;
	if (gamemode == 3) {
		while (q != 2) {
			if (q == 1029384756) {
				health = 999;
				zvonok = 999;
				fifty = 999;
				pomosh = 999;
			}
			cout << "У вас " << health << " hp"<<endl;
			QuNumber = 0;
			while (0 == 0) {
				QuNumber = random(1, FileSize*6-1);
				for (int i = 0;i < FileSize;i++) {
					if (mass1[i] == QuNumber) flag = 1;
				}
				if (QuNumber % 6 == 0 && flag != 1) {
					flag = 0;
					break;
				}
				flag = 0;
			}
			mass1[k] = QuNumber;
			k++;
			flag = 0;
			RightAnswer = InfinityQuestion(gamemode,QuNumber);
			if (((pomosh + fifty + zvonok) != 0)) {
				cout << "Подсказку? Д/Н." << endl << endl;
				cin >> quest;
			}
			if ((quest == "д" || quest == "Д") && ((pomosh + fifty + zvonok) != 0)) {
				mass = help(RightAnswer, pomosh, fifty, zvonok);
				pomosh = mass[0];
				fifty = mass[1];
				zvonok = mass[2];
			}
			cout << "Выбирайте ответ." << endl;
			cin >> quest;
			if (quest == RightAnswer) cout << "И это правильный ответ!" << endl;
			else if (mass1[FileSize - 1] != 0) {
				cout << "Поздравляю. У меня кончились вопросы!";
				return 0;
			}
			else {
				cout << "Ответ неверный."<<endl;
				health--;
				if (health == 0) {
					cout << "У вас закончились жизни.";
					return 0;
				}
			}
			cout << "Еще вопрос - любая цифра, закончить - 2"<<endl;
			cin >> q;
		}
		return 0;
	}
	else if (gamemode == 1 || gamemode == 2) {
		cout << "Приветствую вас на нашей игре! Введите ваше имя: " << endl;
		cin>>name;
		cout << endl;
		cout << name << "? Прекрасное имя! Давайте обсудим правила." << endl << endl << "У вас есть 3 подсказки - Помощь зала, звонок другу, 50/50." << endl << endl << "К тому же, за каждый правильный ответ вы получаете определенную сумму, забрать которую можно только в том случае, когда она является несгораемой." << endl << endl;
		cout << name << ", должен предупредить, что в случае отказа от несгoраемой суммы и последующего неправильного ответа вы уходите ни с чем!" << endl << endl;
		cout << "Итак, перейдем к первому вопросу. Вы готовы?" << endl << endl;
		cin >> quest;
		cout << "Впрочем, неважно. Начинаем!" << endl;
		RightAnswer = question(gamemode);
		cout << "Долго думаете. Нужна ли вам помощь? Да или нет?" << endl << endl;
		cin >> quest;
		if (quest == "Да" || quest == "да") {
			mass = help(RightAnswer, pomosh, fifty, zvonok);
			pomosh = mass[0];
			fifty = mass[1];
			zvonok = mass[2];
		}

		cout << "Так какой же ответ?" << endl;
		cin >> quest;

		if (quest == RightAnswer) cout << "И это правильный ответ! Вы выиграли Автомобиль!" << endl << "Ладно,шучу, не автомобиль. Тем не менее, 1000 рублей теперь на вашем счету!" << endl;
		else {
			cout << "Ответ неверный. Не расстраивайтесь, повезет в любви. До свидания!";
			return 0;

		}
		///////////////////////////////////////////////////////////////////////
		cout << "Отличное начало! Приступаем к следующему вопросу! На его кону несгораемая сумма." << endl;

		RightAnswer = question(gamemode);
		cout << "Вы готовы ответить? Да/Нет?" << endl << endl;
		cin >> quest;
		if (quest == "Нет") {
			mass = help(RightAnswer, pomosh, fifty, zvonok);
			pomosh = mass[0];
			fifty = mass[1];
			zvonok = mass[2];
		}
		cout << "Выбирайте ответ." << endl;
		cin >> quest;

		if (quest == RightAnswer) cout << "И это правильный ответ!" << endl << "5000 рублей теперь на вашем счету! Вы можете забрать их и уйти домой," << endl << "а можете и дальше наслаждаться моей компанией." << endl;
		else {
			cout << "Ответ неверный. До свидания!";
			return 0;
		}
		cout << "Остаетесь - 1 или уходите - любое значение?" << endl;
		cin >> quest;
		if (quest != "1") {
			cout << "Жаль. Вот ваши 5 тысяч. Удачи!";
			return 0;
		}
		///////////////////////////////////////////////////////////////////////
		cout << "Ну и хорошо. Перейдем к третьему вопросу! Навострили ушки?" << endl;
		cin >> quest;

		RightAnswer = question(gamemode);
		cout << "Ответите сами? Да/Нет?" << endl << endl;
		cin >> quest;
		if (quest == "Нет" && ((pomosh + fifty + zvonok) != 0)) {
			mass = help(RightAnswer, pomosh, fifty, zvonok);
			pomosh = mass[0];
			fifty = mass[1];
			zvonok = mass[2];
		}
		else if (quest == "Нет" && ((pomosh + fifty + zvonok) == 0)) cout << "У Вас кончились подсказки.";
		cout << "Выбирайте ответ." << endl;
		cin >> quest;
		if (quest == RightAnswer) cout << "И это правильный ответ!" << endl << "25 000 рублей теперь на вашем счету!" << endl << endl;
		else {
			cout << "Ответ неверный. До новых встреч!";
			return 0;
		}
		cout << "И мы продолжаем с Вами же!";





		/////////////////////////////////////////////////////////////////////////////////

		cout << "Перейдем к четвертому вопросу!" << endl;
		cin >> quest;

		RightAnswer = question(gamemode);
		if (((pomosh + fifty + zvonok) != 0)) {
			cout << "Ответите сами? Да/Нет?" << endl << endl;
			cin >> quest;
		}
		if ((quest == "Нет" || quest == "нет") && ((pomosh + fifty + zvonok) != 0)) {
			mass = help(RightAnswer, pomosh, fifty, zvonok);
			pomosh = mass[0];
			fifty = mass[1];
			zvonok = mass[2];
		}
		cout << "Выбирайте ответ." << endl;
		cin >> quest;
		if (quest == RightAnswer) cout << "И это правильный ответ!" << endl << "Вы выиграли 100 000 рублей! Поздравляю." << endl << endl;
		else {
			cout << "Ответ неверный. До новых встреч!";
			return 0;
		}
		cout << "И мы продолжаем с Вами же!";


		//


		cout << "Перейдем к пятому вопросу!" << endl;
		cin >> quest;

		RightAnswer = question(gamemode);
		if (((pomosh + fifty + zvonok) != 0)) {
			cout << "Ответите сами? Да/Нет?" << endl << endl;
			cin >> quest;
		}
		if ((quest == "Нет" || quest == "нет") && ((pomosh + fifty + zvonok) != 0)) {
			mass = help(RightAnswer, pomosh, fifty, zvonok);
			pomosh = mass[0];
			fifty = mass[1];
			zvonok = mass[2];
		}
		cout << "Выбирайте ответ." << endl;
		cin >> quest;
		if (quest == RightAnswer) cout << "И это правильный ответ!" << endl << "250 000 рублей теперь у Вас в кармане! Следующий вопрос мы разыграем на несгораемую сумму!" << endl << endl;
		else {
			cout << "Ответ неверный. До новых встреч!";
			return 0;
		}
		cout << "И мы продолжаем с Вами же!";

		//


		cout << "Перейдем к шестому вопросу!" << endl;
		cin >> quest;

		RightAnswer = question(gamemode);
		if (((pomosh + fifty + zvonok) != 0)) {
			cout << "Ответите сами? Да/Нет?" << endl << endl;
			cin >> quest;
		}
		if ((quest == "Нет" || quest == "нет") && ((pomosh + fifty + zvonok) != 0)) {
			mass = help(RightAnswer, pomosh, fifty, zvonok);
			pomosh = mass[0];
			fifty = mass[1];
			zvonok = mass[2];
		}
		cout << "Выбирайте ответ." << endl;
		cin >> quest;
		if (quest == RightAnswer) cout << "И это правильный ответ!" << endl << "500 000 рублей теперь у Вас! Вы можете их забрать!" << endl << endl;
		else {
			cout << "Ответ неверный. До новых встреч!";
			return 0;
		}
		cout << "Остаетесь - 1 или уходите - любое значение?" << endl;
		cin >> quest;
		if (quest != "1") {
			cout << "Жаль. Ваш выигрыш будет выписан вам на выходе. Удачи!";
			return 0;
		}

		cout << "Правильно решение! И мы продолжаем с Вами же!";


		//

		cout << "Перейдем к седьмому вопросу!" << endl;
		cin >> quest;

		RightAnswer = question(gamemode);
		if (((pomosh + fifty + zvonok) != 0)) {
			cout << "Ответите сами? Да/Нет?" << endl << endl;
			cin >> quest;
		}
		if ((quest == "Нет" || quest == "нет") && ((pomosh + fifty + zvonok) != 0)) {
			mass = help(RightAnswer, pomosh, fifty, zvonok);
			pomosh = mass[0];
			fifty = mass[1];
			zvonok = mass[2];
		}
		cout << "Выбирайте ответ." << endl;
		cin >> quest;
		if (quest == RightAnswer) cout << "И это правильный ответ!" << endl << "750 000 рублей теперь на вашем счету!" << endl << endl;
		else {
			cout << "Ответ неверный. До новых встреч!";
			return 0;
		}
		cout << "И мы продолжаем с Вами же!";


		//

		cout << "Перейдем к восьмому вопросу!" << endl;
		cin >> quest;

		RightAnswer = question(gamemode);
		if (((pomosh + fifty + zvonok) != 0)) {
			cout << "Ответите сами? Да/Нет?" << endl << endl;
			cin >> quest;
		}
		if ((quest == "Нет" || quest == "нет") && ((pomosh + fifty + zvonok) != 0)) {
			mass = help(RightAnswer, pomosh, fifty, zvonok);
			pomosh = mass[0];
			fifty = mass[1];
			zvonok = mass[2];
		}
		cout << "Выбирайте ответ." << endl;
		cin >> quest;
		if (quest == RightAnswer) cout << "И это правильный ответ!" << endl << "1 000 000 рублей теперь на вашем счету! Это последня несгораемая сумма!" << endl << endl;
		else {
			cout << "Ответ неверный. До новых встреч!";
			return 0;
		}
		cout << "Остаетесь - 1 или уходите - любое значение?" << endl;
		cin >> quest;
		if (quest != "1") {
			cout << "Жаль. Ваш выигрыш будет выписан вам на выходе. Удачи!";
			return 0;
		}
	
		cout << "И мы продолжаем с Вами же!";


		//

		cout << "Перейдем к девятому вопросу!" << endl;
		cin >> quest;

		RightAnswer = question(gamemode);
		if (((pomosh + fifty + zvonok) != 0)) {
			cout << "Ответите сами? Да/Нет?" << endl << endl;
			cin >> quest;
		}
		if ((quest == "Нет" || quest == "нет") && ((pomosh + fifty + zvonok) != 0)) {
			mass = help(RightAnswer, pomosh, fifty, zvonok);
			pomosh = mass[0];
			fifty = mass[1];
			zvonok = mass[2];
		}
		cout << "Выбирайте ответ." << endl;
		cin >> quest;
		if (quest == RightAnswer) cout << "И это правильный ответ!" << endl << "1 500 000 рублей у Вас!" << endl << endl;
		else {
			cout << "Ответ неверный. До новых встреч!";
			return 0;
		}
		cout << "И мы продолжаем с Вами же!";




		//
		cout << "Итак! Барабанная дробь! Переходим к десятому вопросу!" << endl;
		cin >> quest;

		RightAnswer = question(gamemode);
		if (((pomosh + fifty + zvonok) != 0)) {
			cout << "Ответите сами? Да/Нет?" << endl << endl;
			cin >> quest;
		}
		if ((quest == "Нет" || quest == "нет") && ((pomosh + fifty + zvonok) != 0)) {
			mass = help(RightAnswer, pomosh, fifty, zvonok);
			pomosh = mass[0];
			fifty = mass[1];
			zvonok = mass[2];
		}
		cout << "Выбирайте ответ." << endl;
		cin >> quest;
		if (quest == RightAnswer) cout << "И это правильный ответ!" << endl << "2 000 000 рублей теперь на вашем счету!" << endl << endl;
		else {
			cout << "Ответ неверный. До новых встреч!";
			return 0;
		}
		cout << "Мэрлин, да Вы чертов гений! Надеюсь, эти деньги пойдут на благое дело! Всего Вам хорошего.";






	}
	else {
		cout << "Неверное значение.";
		return 0;
	}
	file.close();
	file_2.close();

}
