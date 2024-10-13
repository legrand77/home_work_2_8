#include <iostream>

class Fraction
{
private:
	int numerator_;
	int denominator_;

public:
	Fraction(int numerator, int denominator)
	{
		numerator_ = numerator;
		denominator_ = denominator;
	}
	void Print() { std::cout << numerator_ << "/" << denominator_; };// вывод значения дроби в консоль

	Fraction reduction(Fraction(*e))// код сокращения дроби
	{
		for (int i = 2; i <= (abs(e->numerator_) >= abs(e->denominator_) ? abs(e->numerator_): abs(e->denominator_)); i++)
		{
			   bool x = true;
			   while (x)
			   {
				   if (e->numerator_ % i == 0 && e->denominator_ % i == 0)
				   {
					   bool x = true;
					   e->numerator_ /= i;
					   e->denominator_ /= i;
				   }
				   else x = false;
                }
		}
	 return Fraction(*e);
	}
		Fraction operator+(Fraction other)// перегрузка оператора +
	    {
		Fraction  tmp ((other.denominator_* numerator_ + denominator_ * other.numerator_),(denominator_ * other.denominator_));
		return reduction(&tmp);
	    }

		Fraction operator-(Fraction other)//перегрузка оператора -
		{
			Fraction  tmp((other.denominator_ * numerator_ - denominator_ * other.numerator_), (denominator_ * other.denominator_));
			return reduction(&tmp);
		}

		Fraction operator*(Fraction other)//перегрузка оператора *
		{
			Fraction  tmp((numerator_ * other.numerator_), (denominator_ * other.denominator_));
			return reduction(&tmp);
		}

		Fraction operator/(Fraction other)//перегрузка оператора /
		{
			Fraction  tmp((numerator_* other.denominator_), (denominator_ * other.numerator_));
			
			return reduction(&tmp);
		}

		Fraction& operator++() {numerator_ += denominator_; return *this; }//перегрузка оператора  преинкремент ++

		Fraction& operator--() {numerator_ -= denominator_; return *this; }//перегрузка оператора преинкремент --

		Fraction operator++(int)//перегрузка оператора постинкремент ++

		{
			Fraction temp = *this;
			++(*this);
			return temp;
		}

		Fraction operator--(int)//перегрузка оператора постинкремент --
		{
			Fraction temp = *this;
			--(*this);
			return temp;
		}
};

int main() 
{
	setlocale(LC_ALL, "Russian");
	system("chcp 1251");
	int f_1_1, f_1_2, f_2_1, f_2_2;
	
	std::cout << "Введите числитель дроби 1: ";
	std::cin >> f_1_1;
	std::cout << "Введите знаменатель дроби 1: ";
	std::cin >> f_1_2;
	std::cout << "Введите числитель дроби 2: ";
	std::cin >> f_2_1;
	std::cout << "Введите знаменатель дроби 2: ";
	std::cin >> f_2_2;
	Fraction f1(f_1_1, f_1_2);
	Fraction f2(f_2_1, f_2_2);

	f1.Print();std::cout << " + "; f2.Print();std::cout << " = ";(f1 + f2).Print();std::cout << std::endl;
	f1.Print(); std::cout << " - "; f2.Print(); std::cout << " = "; (f1 - f2).Print(); std::cout << std::endl;
	f1.Print(); std::cout << " * "; f2.Print(); std::cout << " = "; (f1 * f2).Print(); std::cout << std::endl;
	f1.Print(); std::cout << " / "; f2.Print(); std::cout << " = "; (f1 / f2).Print(); std::cout << std::endl;
	std::cout << "++"; f1.Print(); std::cout << " * "; f2.Print(); std::cout << " = "; (++f1 * f2).Print(); std::cout << std::endl;
	std::cout << "Значение дроби 1 = "; (f1).Print();  std::cout << std::endl;
	f1.Print();std::cout << "--"; std::cout << " * "; f2.Print(); std::cout << " = "; (f1-- * f2).Print(); std::cout << std::endl;
	std::cout << "Значение дроби 1 = "; (f1).Print();  std::cout << std::endl;
}