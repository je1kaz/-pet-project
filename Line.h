#define LINE_H
#ifdef LINE_H

class LinePoints
{
private:
	double coordinateStartX_, coordinateEndX_;
	double coordinateStartY_, coordinateEndY_;
	class Coordinates
	{
	private:
		double* abscissa_;
		double* ordinate_;
		int size_;
		std::string color_;
	public:
		Coordinates() : abscissa_(nullptr), ordinate_(nullptr), size_(0), color_("black") {}
		Coordinates(double* abscissa, double* ordinate, int size) : abscissa_(abscissa), ordinate_(ordinate), size_(size), color_("black") {}
		friend Coordinates CreateLine(double start, double end, double startValue, double endValue);
		void output(const char* name)
		{
			std::cout << name << ": " << std::endl;
			std::cout << "Color:" << color_ << std::endl;
			if (abscissa_ == nullptr || ordinate_ == nullptr)
			{
				return;
			}
			for (int i = 0; i < size_; i++)
			{
				std::cout << "Y(" << abscissa_[i] << ") = " << ordinate_[i] << std::endl;
			}
		}
		void fileOutput(const char* fileName, const char* dataName)
		{
			if (abscissa_ == nullptr || ordinate_ == nullptr)
			{
				return;
			}
			std::ofstream ofs(fileName);
			ofs << dataName << ": " << std::endl;
			ofs << "Color:" << color_ << std::endl;
			for (int i = 0; i < size_; i++)
			{
				ofs << "Y(" << abscissa_[i] << ") = " << ordinate_[i] << std::endl;
			}
		}
		
	};
	Coordinates createLine(double start, double end, double startValue, double endValue)
	{
		int size = int((end - start) * 100) + 1;
		double* coordinatesAbscissa = new double[size];
		double* coordinatesOrdinate = new double[size];
		coordinatesAbscissa[0] = start;
		coordinatesAbscissa[size - 1] = end;
		coordinatesOrdinate[0] = startValue;
		coordinatesOrdinate[size - 1] = endValue;
		for (int i = 1; i < size - 1; i++)
		{
			coordinatesAbscissa[i] = coordinatesAbscissa[i - 1] + 0.01;
			coordinatesOrdinate[i] = (coordinatesAbscissa[i] - start) * (endValue - startValue) / (end - start) + startValue;
		}
		Coordinates current(coordinatesAbscissa, coordinatesOrdinate, size);
		return current;

	}
public:
	LinePoints() : coordinateStartX_(0), coordinateStartY_(0), coordinateEndX_(0), coordinateEndY_(0) {}
	LinePoints(double coordinateStartX, double coordinateStartY, double coordinateEndX, double coordinateEndY)
	{
		coordinateStartX_ = coordinateStartX;
		coordinateStartY_ = coordinateStartY;
		coordinateEndX_ = coordinateEndX;
		coordinateEndY_ = coordinateEndY;
	}
	LinePoints(LinePoints& line)
	{
		coordinateStartX_ = line.coordinateStartX_;
		coordinateStartY_ = line.coordinateStartY_;
		coordinateEndX_ = line.coordinateEndX_;
		coordinateEndY_ = line.coordinateEndY_;
	}
	void operator < (LinePoints& linePoints)
	{
		Coordinates Line;
		if (coordinateStartX_ == linePoints.coordinateStartX_)
		{
			std::cout << "Помилка.Задані лінії не є функцією!" << std::endl;
			return;
		}
		if (coordinateStartX_ > linePoints.coordinateStartX_)
		{
			Line = createLine(linePoints.coordinateStartX_, coordinateStartX_, linePoints.coordinateStartY_, coordinateStartY_);
			Line.output("StartLine");
			Line.fileOutput("ResultStart.txt", "StartLine");
		}
		else
		{
			Line = createLine(coordinateStartX_, linePoints.coordinateStartX_, coordinateStartY_, linePoints.coordinateStartY_);
			Line.output("StartLine");
			Line.fileOutput("ResultStart.txt", "StartLine");
		}
		if (coordinateEndX_ == linePoints.coordinateEndX_)
		{
			std::cout << "Помилка.Задані лінії не є функцією!" << std::endl;
			return;
		}
		if (coordinateEndX_ > linePoints.coordinateEndX_)
		{
			Line = createLine(linePoints.coordinateEndX_, coordinateEndX_, linePoints.coordinateEndY_, coordinateEndY_);
			Line.output("EndLine");
			Line.fileOutput("ResultEndLine.txt", "EndLine");
		}
		else
		{
			Line = createLine(coordinateEndX_, linePoints.coordinateEndX_, coordinateEndY_, linePoints.coordinateEndY_);
			Line.output("EndLine");
			Line.fileOutput("ResultEndLine.txt", "EndLine");
		}
	}
};
void lineShow()
{
	std::cout << "Введіть координати початку першої прямої (x y): ";
	double startX, startY;
	std::cin >> startX;
	std::cin >> startY;
	std::cout << "Введіть координати кінця першої прямої (x y): ";
	double endX, endY;
	std::cin >> endX;
	std::cin >> endY;
	LinePoints a(startX, startY, endX, endY);
	std::cout << "Введіть координати початку другої прямої (x y): ";
	std::cin >> startX;
	std::cin >> startY;
	std::cout << "Введіть координати кінця другої прямої (x y): ";
	std::cin >> endX;
	std::cin >> endY;
	LinePoints b(startX, startY, endX, endY);
	a < b;
}
#endif