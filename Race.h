#define RACE_H
#ifdef RACE_H
class Race
{
private:
	std::string surname;
	std::string date;
	float duration;
	bool prize;

public:
	Race() :surname(""), date(""), duration(0), prize(0){}
	Race(std::string surname, std::string date, float duration, bool prize)
	{
		this->surname = surname;
		this->date = date;
		this->duration = duration;
		this->prize = prize;
	}
	std::string Getdate() {
		return date;
	}
	bool Getprize() {
		return prize;
	}
	void Input() {
		std::cout << "Введіть прізвище гонщика: ";
		std::cin >> surname;
		std::cout << "Введіть дату(у форматі XX.XX.XXXX): ";
		std::cin.ignore(256, '\n');
		std::cin >> date;
		std::cout << "Введіть тривалість заїзду: ";
		std::cin >> duration;
		std::cout << "Чи гонщик отримав приз(Так/Ні): ";
		std::string check;
		std::cin.ignore(256, '\n');
		std::cin >> check;
		while (check != "Так" && check != "так" && check != "Ні" && check != "ні") {
			std::cout << "Введіть Так/Ні: ";
			std::cin >> check;
		}
		if (check == "Так" || check == "так") {
			prize = true;
		}
		if (check == "Ні" || check == "ні") {
			prize = false;
		}
	}
	void fileOutput(const char* fileName)
	{
		std::ofstream ofs(fileName, std::ios::app);
		ofs << surname << ": " << date << ", " << "тривалість заїзду: " << duration << ", отримав приз: " << std::boolalpha << prize << std::endl;
	}
	std::string Getsurname() {
		return surname;
	}
};
void FindRace(Race* a,int n)
{
	std::cout << "Введіть потрібну дату(У форматі ХХ.ХХ.ХХХХ): ";
	std::string check;
	std::cin.ignore(256, '\n');
	std::cin >> check;
	int j = 0;
	for (int i = 0; i < n; i++) {
		if (a[i].Getdate() == check && a[i].Getprize() == true) {
			j++;
			std::cout << j << ". " << a[i].Getsurname() << std::endl;
			a[i].fileOutput("RaceFindResult.txt");
		}
	}
}
void raceShow()
{
	Race* a;
	std::cout << "Введіть кількість гонщиків: ";
	int n;
	std::cin >> n;
	a = new Race[n];
	for (int i = 0; i < n; i++) {
		a[i].Input();
	}
	std::cout << std::endl;
	FindRace(a, n);
}
#endif