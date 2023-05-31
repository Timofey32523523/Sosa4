Консольная реализация игры «Кто хочет стать миллионером», с возможностью выбора режима игры (рис. 1.2.1): 
1.	Обычный режим;
2.	Усложненный режим
3.	Бесконечный режим.

 ![image](https://github.com/Timofey32523523/Sosa4/assets/133767460/62a101eb-23e8-451d-a0ec-28f69c733900)
Рисунок 1.2.1 – Выбор режима игры «Кто хочет стать миллионером?»
1.2.1 Режимы игры обычный и усложненный.
Обычный режим использует определенную базу вопросов, которые не являются особо сложными. 
Усложненный режим отличается от обычного лишь используемой базой вопросов.
Игра начинается с краткого объяснения правил игры.
«У вас есть 3 подсказки - Помощь зала, звонок другу, 50/50.
К тому же, за каждый правильный ответ вы получаете определенную сумму, забрать которую можно только в том случае, когда она является несгораемой.
Player_Name, должен предупредить, что в случае отказа от несгораемой суммы и последующего неправильного ответа вы уходите ни с чем! »
 ![image](https://github.com/Timofey32523523/Sosa4/assets/133767460/1dad04a7-983d-41f1-b047-f5228d8f8f93)

Рисунок 1.2.2 – Ввод имени пользователя и озвучивание правил игры
После ввода имени и оглашения правил задается первый вопрос (рис. 1.2.3).
 ![image](https://github.com/Timofey32523523/Sosa4/assets/133767460/8b6954f1-f296-4a19-acb0-028a7dfed8c6)

Рисунок 1.2.3 – Первый вопрос
	После того, как вопрос задан, игра предлагает взять подсказку. Подсказками являются: помощь зала, звонок другу, 50/50 (рис. 1.2.4, 1.2.5, 1.2.6 соответственно).
 ![image](https://github.com/Timofey32523523/Sosa4/assets/133767460/c6fb2de1-3192-44b6-b7a0-0bc3fc9be5ea)

Рисунок 1.2.4 – Помощь зала
 ![image](https://github.com/Timofey32523523/Sosa4/assets/133767460/50a38a33-9f6d-4527-8888-414d754d3f5b)

Рисунок 1.2.5 – Пятьдесят на пятьдесят
 ![image](https://github.com/Timofey32523523/Sosa4/assets/133767460/5deef244-e437-435e-837f-a0b1d7b13d4c)

Рисунок 1.2.6 – Звонок другу

Подсказки устроены таким образом, что друг знает ответ с вероятностью в 50%, зал выбирает правильный ответ с вероятностью в 25%, а 50/50 оставляет 2 варианта ответа, 1 из которых неправильный 
Чтобы выбрать ответ, нужно ввести соответствующую вашему варианту букву. В случае, если вариант ответа правильный, а сумма является несгораемой, игрок может покинуть игру с данной суммой, либо продолжить. (рис. 1.2.7).
 ![image](https://github.com/Timofey32523523/Sosa4/assets/133767460/a35f5657-a3be-4fc6-801f-ffba29950b73)

Рисунок 1.2.7 – Выбор ответа и варианты продолжения
Конец игры будет выглядеть следующим образом (рис. 1.2.8 и рис. 1.2.9):
Игрок победил, ответив правильно на все вопросы
 ![image](https://github.com/Timofey32523523/Sosa4/assets/133767460/e27d3c73-cb48-480d-b9a3-7a959ea6cdbf)

Рисунок 1.2.8 – Игрок победил
Игрок выбрал неправильный ответ.
 ![image](https://github.com/Timofey32523523/Sosa4/assets/133767460/bca4823b-1a70-45da-aaa0-8bd8a7357303)

Рисунок 1.2.9 –  Игрок проиграл
1.2.2 Режим игры бесконечный.
В данном режиме вопросы задаются до тех пор, пока не будет использована вся база вопросов, либо игрок не решит выйти, либо у игрока не кончатся жизни. Вопрос не может быть задан дважды, ведется учет заданных вопросов. Количество жизней игрока равно 3 единицам. Количество подсказок – по 1 использованию на каждую. Однако, в игре присутствует чит-код - 1029384756, дающий максимально возможное количество жизней и подсказок. Его необходимо вводить на этапе выбора дальнейшего действия (рис 1.2.10)
 ![image](https://github.com/Timofey32523523/Sosa4/assets/133767460/9a2c0450-92e6-464d-9d5e-70c12acc8acd)

Рисунок 1.2.10 – Ввод чит-кода
