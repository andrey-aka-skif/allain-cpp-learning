/*
* Alex Allain. Jumping into c++.
* Глава 8. Случайные числа и отладка
*
* 5. Напишите программу для игры в покер. Сдайте игроку пять карт,
* предоставьте возможность брать новые карты и определите комбинацию,
* которую ему удалось получить. Подумайте, насколько легко решить эту задачу.
* Какие проблемы могут возникнуть с отслеживанием карт, взятых из колоды?
* Сравните сложность этой задачи и задачи об игровом автомате.
*/

#include <iostream>
#define NOMINMAX
#include <Windows.h>
#include <string>

void run_poker_game();
void get_five_cards();
int get_rnd_value(int low, int high);
int get_uniq_rnd_card();
static bool check_uniq(int value);
std::string map_card_name(int card_number);
void show_player_cards();
void replace_card(int card_number_to_replace);
void show_result();
void add_card_to_discard(int card_number);
void sort_cards();

namespace CustomInput {
	static int int_cin() {
		int input = 0;
		std::cin >> input;

		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			throw std::runtime_error("Ошибка: введено не целое число");
		}

		return input;
	}
}

int main() {
	SetConsoleOutputCP(CP_UTF8);

	try
	{
		run_poker_game();
	}
	catch (const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
}

int card_1 = 0;
int card_2 = 0;
int card_3 = 0;
int card_4 = 0;
int card_5 = 0;

int discard_card_1 = 0;
int discard_card_2 = 0;
int discard_card_3 = 0;

int const MAX_REPLACE_COUNT = 3;

void run_poker_game() {
	srand(time(NULL));

	std::cout
		<< "Играем."
		<< std::endl
		<< "Вы получили карты (выберите номер карты от 1 до 5 для замены, но не более трех раз. 0 - сдать карты):"
		<< std::endl;

	get_five_cards();
	sort_cards();
	show_player_cards();

	int card_number_to_replace = 0;
	int replace_count = 0;

	while (true)
	{
		std::cout << "Заменить карту: ";

		try
		{
			card_number_to_replace = CustomInput::int_cin();
		}
		catch (const std::exception&)
		{
			std::cout << "Укажите номер карты целым числом" << std::endl;
			continue;
		}

		if (card_number_to_replace == 0) {
			std::cout << "Сдаем карты!" << std::endl;
			break;
		}

		if (card_number_to_replace < 0 || card_number_to_replace > 5) {
			std::cout << "Укажите правильный номер карты" << std::endl;
			continue;
		}

		replace_card(card_number_to_replace);
		sort_cards();

		std::cout << "Новые карты игрока:" << std::endl;
		show_player_cards();

		replace_count++;

		if (replace_count >= 3)
			break;
	}

	std::cout << "Результат:" << std::endl;
	show_result();
}

void get_five_cards()
{
	card_1 = get_uniq_rnd_card();
	card_2 = get_uniq_rnd_card();
	card_3 = get_uniq_rnd_card();
	card_4 = get_uniq_rnd_card();
	card_5 = get_uniq_rnd_card();
}

static int get_uniq_rnd_card() {
	int value = 0;

	while (!check_uniq(value))
	{
		value = get_rnd_value(1, 52);
	}

	return value;
}

static bool check_uniq(int value) {
	if (value == 0)
		return false;

	if (value == card_1)
		return false;
	if (value == card_2)
		return false;
	if (value == card_3)
		return false;
	if (value == card_4)
		return false;
	if (value == card_5)
		return false;

	if (value == discard_card_1)
		return false;
	if (value == discard_card_2)
		return false;
	if (value == discard_card_3)
		return false;

	return true;
}

static int get_rnd_value(int low, int high) {
	return rand() % (high - low + 1) + low;
}

static std::string map_card_name(int card_number) {
	// Проверяем, что индекс в диапазоне 1..52
	if (card_number < 1 || card_number > 52) {
		throw std::out_of_range("Карты с таким индексом не существует");
	}

	// Корректируем индекс под "внутреннюю" логику (0..51)
	int adjustedIndex = card_number - 1;

	// Масти (0-3)
	int suit = adjustedIndex / 13;
	// Достоинства (0-12)
	int rank = adjustedIndex % 13;

	std::string cardName;

	// Определяем достоинство
	switch (rank) {
	case 0:  cardName = "2"; break;
	case 1:  cardName = "3"; break;
	case 2:  cardName = "4"; break;
	case 3:  cardName = "5"; break;
	case 4:  cardName = "6"; break;
	case 5:  cardName = "7"; break;
	case 6:  cardName = "8"; break;
	case 7:  cardName = "9"; break;
	case 8:  cardName = "10"; break;
	case 9:  cardName = "Валет"; break;
	case 10: cardName = "Дама"; break;
	case 11: cardName = "Король"; break;
	case 12: cardName = "Туз"; break;
	}

	cardName += " ";

	// Определяем масть
	switch (suit) {
	case 0: cardName += "пик ♠"; break;
	case 1: cardName += "червей ♥"; break;
	case 2: cardName += "бубен ♦"; break;
	case 3: cardName += "треф ♣"; break;
	}

	return cardName;
}

static void show_player_cards() {
	std::cout << "1) " << map_card_name(card_1) << std::endl;
	std::cout << "2) " << map_card_name(card_2) << std::endl;
	std::cout << "3) " << map_card_name(card_3) << std::endl;
	std::cout << "4) " << map_card_name(card_4) << std::endl;
	std::cout << "5) " << map_card_name(card_5) << std::endl;
}

static void replace_card(int card_number_to_replace) {
	if (card_number_to_replace == 1) {
		add_card_to_discard(card_1);
		card_1 = get_uniq_rnd_card();
		return;
	}
	if (card_number_to_replace == 2) {
		add_card_to_discard(card_2);
		card_2 = get_uniq_rnd_card();
		return;
	}
	if (card_number_to_replace == 3) {
		add_card_to_discard(card_3);
		card_3 = get_uniq_rnd_card();
		return;
	}
	if (card_number_to_replace == 4) {
		add_card_to_discard(card_4);
		card_4 = get_uniq_rnd_card();
		return;
	}
	if (card_number_to_replace == 5) {
		add_card_to_discard(card_5);
		card_5 = get_uniq_rnd_card();
		return;
	}

	throw std::out_of_range("Карты с таким номером не существует");
}

static void add_card_to_discard(int card_number) {
	if (discard_card_1 == 0) {
		discard_card_1 = card_number;
		return;
	}
	if (discard_card_2 == 0) {
		discard_card_2 = card_number;
		return;
	}
	if (discard_card_3 == 0) {
		discard_card_3 = card_number;
		return;
	}

	throw std::out_of_range("Больше нельзя заменять карты");
}

static void sort_cards() {
	// Используем алгоритм сортировки вставками для пяти переменных
	// Шаг 1: Сортируем первые две карты
	if (card_1 > card_2) std::swap(card_1, card_2);
	// Шаг 2: Вставляем третью карту в отсортированную последовательность
	if (card_2 > card_3) std::swap(card_2, card_3);
	if (card_1 > card_2) std::swap(card_1, card_2);
	// Шаг 3: Вставляем четвертую карту
	if (card_3 > card_4) std::swap(card_3, card_4);
	if (card_2 > card_3) std::swap(card_2, card_3);
	if (card_1 > card_2) std::swap(card_1, card_2);
	// Шаг 4: Вставляем пятую карту
	if (card_4 > card_5) std::swap(card_4, card_5);
	if (card_3 > card_4) std::swap(card_3, card_4);
	if (card_2 > card_3) std::swap(card_2, card_3);
	if (card_1 > card_2) std::swap(card_1, card_2);
}

/**
 * Роял-флэш.
 *
 * \return
 */
static bool check_royal_flush() {
	// Роял-флэш – 10, J, Q, K, A одной масти

	// пики
	if (card_1 == 9 && card_2 == 10 && card_3 == 11 && card_4 == 12 && card_5 == 13)
		return true;
	// червы
	if (card_1 == 22 && card_2 == 23 && card_3 == 24 && card_4 == 25 && card_5 == 26)
		return true;
	// бубны
	if (card_1 == 35 && card_2 == 36 && card_3 == 37 && card_4 == 38 && card_5 == 39)
		return true;
	// трефы
	if (card_1 == 48 && card_2 == 49 && card_3 == 50 && card_4 == 51 && card_5 == 52)
		return true;

	return false;
}

/**
 * Стрит-флэш.
 *
 * \return
 */
static bool check_straight_flush() {
	// Стрит-флэш – 5 карт одной масти по порядку (например, 5-6-7-8-9 черви)

	if (card_1 > 1 && card_1 < 10) {
		if (card_2 == card_1 + 1 && card_3 == card_1 + 2 && card_4 == card_1 + 3 && card_5 == card_1 + 4)
			return true;
	}
	if (card_1 > 14 && card_1 < 22) {
		if (card_2 == card_1 + 1 && card_3 == card_1 + 2 && card_4 == card_1 + 3 && card_5 == card_1 + 4)
			return true;
	}
	if (card_1 > 27 && card_1 < 35) {
		if (card_2 == card_1 + 1 && card_3 == card_1 + 2 && card_4 == card_1 + 3 && card_5 == card_1 + 4)
			return true;
	}
	if (card_1 > 40 && card_1 < 48) {
		if (card_2 == card_1 + 1 && card_3 == card_1 + 2 && card_4 == card_1 + 3 && card_5 == card_1 + 4)
			return true;
	}

	return false;
}

/**
 * Каре.
 *
 * \return
 */
static bool check_four_of_a_kind() {
	// Каре – 4 карты одного достоинства (например, четыре дамы)

	int val1 = ((card_1 - 1) % 13) + 1;
	int val2 = ((card_2 - 1) % 13) + 1;
	int val3 = ((card_3 - 1) % 13) + 1;
	int val4 = ((card_4 - 1) % 13) + 1;
	int val5 = ((card_5 - 1) % 13) + 1;

	if (val1 == val2 && val2 == val3 && val3 == val4) return true;
	if (val1 == val2 && val2 == val3 && val3 == val5) return true;
	if (val1 == val2 && val2 == val4 && val4 == val5) return true;
	if (val1 == val3 && val3 == val4 && val4 == val5) return true;
	if (val2 == val3 && val3 == val4 && val4 == val5) return true;

	return false;
}

/**
 * Фулл-хаус.
 *
 * \return
 */
static bool check_full_house() {
	// Фулл-хаус – пара + тройка (например, два короля и три десятки)

	return false;
}

/**
 * Флэш.
 *
 * \return
 */
static bool check_flush() {
	// Флэш – 5 карт одной масти (не по порядку)

	return false;
}

/**
 * Стрит.
 *
 * \return
 */
static bool check_straight() {
	// Стрит – 5 карт по порядку, масти разные

	int val1 = ((card_1 - 1) % 13) + 1;
	int val2 = ((card_2 - 1) % 13) + 1;
	int val3 = ((card_3 - 1) % 13) + 1;
	int val4 = ((card_4 - 1) % 13) + 1;
	int val5 = ((card_5 - 1) % 13) + 1;

	// Проверяем: val1, val1+1, val1+2, val1+3, val1+4
	if (val2 == val1 + 1 && val3 == val1 + 2 && val4 == val1 + 3 && val5 == val1 + 4) {
		return true;
	}
	return false;
}

/**
 * Тройка.
 *
 * \return
 */
static bool check_three_of_a_kind() {
	// Тройка – 3 карты одного достоинства

	int val1 = ((card_1 - 1) % 13) + 1;
	int val2 = ((card_2 - 1) % 13) + 1;
	int val3 = ((card_3 - 1) % 13) + 1;
	int val4 = ((card_4 - 1) % 13) + 1;
	int val5 = ((card_5 - 1) % 13) + 1;

	// Проверяем все возможные комбинации трёх одинаковых значений
	return
		// Вариант 1: val1, val2, val3 равны
		(val1 == val2 && val2 == val3) ||

		// Вариант 2: val1, val2, val4 равны
		(val1 == val2 && val2 == val4) ||

		// Вариант 3: val1, val2, val5 равны
		(val1 == val2 && val2 == val5) ||

		// Вариант 4: val1, val3, val4 равны
		(val1 == val3 && val3 == val4) ||

		// Вариант 5: val1, val3, val5 равны
		(val1 == val3 && val3 == val5) ||

		// Вариант 6: val1, val4, val5 равны
		(val1 == val4 && val4 == val5) ||

		// Вариант 7: val2, val3, val4 равны
		(val2 == val3 && val3 == val4) ||

		// Вариант 8: val2, val3, val5 равны
		(val2 == val3 && val3 == val5) ||

		// Вариант 9: val2, val4, val5 равны
		(val2 == val4 && val4 == val5) ||

		// Вариант 10: val3, val4, val5 равны
		(val3 == val4 && val4 == val5);
}

/**
 * Две пары.
 *
 * \return
 */
static bool check_two_pair() {
	// Две пары – например, два туза и две восьмёрки

	int val1 = ((card_1 - 1) % 13) + 1;
	int val2 = ((card_2 - 1) % 13) + 1;
	int val3 = ((card_3 - 1) % 13) + 1;
	int val4 = ((card_4 - 1) % 13) + 1;
	int val5 = ((card_5 - 1) % 13) + 1;

	// Проверяем все возможные комбинации двух пар
	return
		// Вариант 1: val1 == val2 и val3 == val4 (остальные разные)
		(val1 == val2 && val3 == val4 && val1 != val3 && val1 != val5 && val3 != val5) ||

		// Вариант 2: val1 == val2 и val4 == val5
		(val1 == val2 && val4 == val5 && val1 != val3 && val1 != val4 && val3 != val4) ||

		// Вариант 3: val1 == val2 и val3 == val5
		(val1 == val2 && val3 == val5 && val1 != val3 && val1 != val4 && val3 != val4) ||

		// Вариант 4: val1 == val3 и val2 == val4
		(val1 == val3 && val2 == val4 && val1 != val2 && val1 != val5 && val2 != val5) ||

		// ... и так далее для всех возможных комбинаций
		(val1 == val3 && val2 == val5 && val1 != val2 && val1 != val4 && val2 != val4) ||

		(val1 == val4 && val2 == val3 && val1 != val2 && val1 != val5 && val2 != val5) ||

		(val1 == val4 && val2 == val5 && val1 != val2 && val1 != val3 && val2 != val3) ||

		(val1 == val5 && val2 == val3 && val1 != val2 && val1 != val4 && val2 != val4) ||

		(val1 == val5 && val2 == val4 && val1 != val2 && val1 != val3 && val2 != val3) ||

		(val2 == val3 && val4 == val5 && val1 != val2 && val1 != val4 && val2 != val4);
}

/**
 * Пара.
 *
 * \return
 */
static bool check_pair() {
	// Пара – две карты одного достоинства

	int val1 = ((card_1 - 1) % 13) + 1;
	int val2 = ((card_2 - 1) % 13) + 1;
	int val3 = ((card_3 - 1) % 13) + 1;
	int val4 = ((card_4 - 1) % 13) + 1;
	int val5 = ((card_5 - 1) % 13) + 1;

	return val1 == val2 || val1 == val3 || val1 == val4 || val1 == val5 ||
		val2 == val3 || val2 == val4 || val2 == val5 ||
		val3 == val4 || val3 == val5 ||
		val4 == val5;
}

void show_result() {
	sort_cards();

	if (check_royal_flush())
		std::cout << "Роял-флэш – 10, J, Q, K, A одной масти." << std::endl;
	else if (check_straight_flush())
		std::cout << "Стрит-флэш – 5 карт одной масти по порядку (например, 5-6-7-8-9 черви)." << std::endl;
	else if (check_four_of_a_kind())
		std::cout << "Каре – 4 карты одного достоинства (например, четыре дамы)." << std::endl;
	else if (check_full_house())
		std::cout << "Фулл-хаус – пара + тройка (например, два короля и три десятки)." << std::endl;
	else if (check_flush())
		std::cout << "Флэш – 5 карт одной масти (не по порядку)." << std::endl;
	else if (check_straight())
		std::cout << "Стрит – 5 карт по порядку, масти разные." << std::endl;
	else if (check_three_of_a_kind())
		std::cout << "Тройка – 3 карты одного достоинства." << std::endl;
	else if (check_two_pair())
		std::cout << "Две пары – например, два туза и две восьмёрки." << std::endl;
	else if (check_pair())
		std::cout << "Пара – две карты одного достоинства." << std::endl;
	else
		std::cout << "Победило казино" << std::endl;
}
