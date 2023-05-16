# Sosa4
Консольная реализация игры «Кто хочет стать миллионером», с возможностью выбора режима игры : 
1.	Обычный режим;
2.	Усложненный режим
3.	Бесконечный режим.
 
1. Режимы игры обычный и усложненный.
Обычный режим использует определенную базу вопросов, которые не являются особо сложными. 
Усложненный режим отличается от обычного лишь используемой базой вопрсов.
Игра начинается с краткого обьяснения правил игры.
«У вас есть 3 подсказки - Помощь зала, звонок другу, 50/50.
К тому же, за каждый правильный ответ вы получаете определенную сумму, забрать которую можно только в том случае, когда она является несгораемой.
Player_Name, должен предупредить, что в случае отказа от несграемой суммы и последующего неправильного ответа вы уходите ни с чем!»
 
После ввода имени и оглашения правил задается первый вопрос.
 
После того, как вопрос задан, игра предлагает взять подсказку. Подсказками являются: помощь зала, звонок другу, 50/50 .
 

Подсказки устроены таким образом, что друг знает ответ с вероятностью в 50%, зал выбирает правильный ответ с вероятностью в 25%, а 50/50 оставляет 2 варианта ответа, 1 из которых неправильный 
Чтобы выбрать ответ, нужно ввести соответствующую вашему варианту букву. В случае, если вариант ответа правильный, а сумма является несгораемой, игрок может покинуть игру с данной суммой, либо продолжить.
 
2. Режим игры бесконечный.
В данном режиме вопросы задаются до тех пор, пока не будет использована вся база вопросов, либо игрок не решит выйти, либо у игрока не кончатся жизни. Вопрос не может быть задан дважды, ведется учет заданных вопросов. Количество жизней игрока равно 3 единицам. Количество подсказок – по 1 использованию на каждую. Однако, в игре присутствует чит-код - 1029384756, дающий максимально возможное количество жизней и подсказок. Его необходимо вводить на этапе выбора дальнейшего действия 

 
Раздел 2 Описание программы
Код всей программы находится в ПРИЛОЖЕНИИ.
2.1 Отображение вопросов из файла.
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
Данная функция используется для обычного и сложного режимов игры. Она необходима для использования определенного файла, исходя из принимаемого аргумента – режима игры.

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
Функция, подобная предыдущей, однако принимает в себя номер вопроса, помимо режима игры. 
2.2 Вызов подсказок
void PomoshZala(string RightAnswer) {
	int n = random(1, 4);
	if (n == 1) cout<<"Зал выбрал ответ "<<RightAnswer << endl;
	if (n == 2) cout << "Зал выбрал ответ B" << endl;
	if (n == 3)  cout << "Зал выбрал ответ C" << endl;
	if (n == 4) cout << "Зал выбрал ответ D"<<endl;
}

Функция, необходимая для вызова подсказки «помощь зала». Выбирает случайную букву и выдает правильный ответ с вероятностью в 25%.

void Fifty(string RightAnswer) {
	string NotRightAnswer;
	if (RightAnswer == "A") NotRightAnswer = "B";
	if (RightAnswer == "B") NotRightAnswer = "A";
	if (RightAnswer == "C") NotRightAnswer = "D";
	if (RightAnswer == "D") NotRightAnswer = "C";
	cout << "Ответы " << RightAnswer << " и " <<NotRightAnswer <<endl;
}

Функция, необходимая для вызова подсказки «50\50». Принимая входящий аргумент – правильный ответ, формирует значение, соответствующее неправильному ответу. Затем, выводит на экран один правильный вариант и один неправильный.


void Zvonok(string RightAnswer) {
	cout << "Вы звоните другу" << endl <<"..." << endl << "..." << endl << "..."<<endl;
	int n = random(1, 2);
	if (n==1) cout << "Друг выбрал ответ " << RightAnswer << endl;
	else cout << "Друг не знает ответа" << endl;
	cout << "Звонок завершен" << endl;
}
Функция, необходимая для вызова подсказки «звонок другу». Принимает в качестве аргумента правильный ответ, и, с вероятностью в 50% выводит его, иначе, выводится надпись «друг не знает ответа».

	


 
2.3 Получение хода игрока
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
Посредством данной функции, программа предлагает использовать подсказку. В случае, если все подсказки не израсходованы. Именно в этой функции вызываются функции подсказок. 
 
2.4 Начало игры
cout << "Выберите режим игры." << endl<<"1.Обычный" << endl << "2.Усложненный" << endl << "3.Бесконечный" << endl;
	cin >> gamemode;
	if (gamemode == 3) {
		while (q != 2) {
			if (q == 1029384756) {
				health = 999;
				zvonok = 999;
				fifty = 999;
				pomosh = 999;}
			cout << "У вас " << health << " жизней"<<endl;
			QuNumber = 0;
			while (0 == 0) {
				QuNumber = random(1, FileSize*6-1);
				for (int i = 0;i < FileSize;i++) {
					if (mass1[i] == QuNumber) flag = 1;
				}
				if (QuNumber % 6 == 0 && flag != 1) {
					flag = 0;
					break;}
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
			cout << "Еще вопрос - 1, закончить - 2"<<endl;
			cin >> q;
		}
		return 0;
	}
	else if (gamemode == 1 || gamemode == 2) {
		cout << "Приветствую вас на нашей игре! Введите ваше имя: " << endl;
 
Начало игры, как и все последующие диалоги (вопросы), прописаны в функции main(). Поскольку каждый диалог является уникальный, в ходе ответов на вопросы которого вызываются остальные функции, формирующие целостность программы.
