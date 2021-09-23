//1.Построить систему классов для описания плоских геометрических фигур: круга, квадрата, прямоугольника. 
//Предусмотреть методы для создания объектов, перемещения на плоскости, изменения размеров и вращения на заданный угол. 
//2.Написать программу, демонстрирующую работу с этими классами. 
//Программа должна содержать меню, позволяющее осуществить проверку всех методов классов. 

#include <iostream>

using namespace std;

//Описывает общую геометрическую фигуру
class AbstractFigure
{
protected:

    double alpha = 0; //Угол поворота
    double x = 0; //Координата на плоскости по иксу
    double y = 0; //Координата на плоскости по игрику

    //Выводит всю информацию о фигуре
    virtual void GetInfo() = 0;

    //Меняет координаты фигуры
    virtual void MovingOnPlane(double& x, double& y) = 0;

    //Меняет размер фигуры
    virtual void Resize(double* sizes) = 0;

    //Вращает фигуру на заданный угол
    virtual void Rotation(double& alpha) = 0;
};

//Описывает квадрат
class Square : protected AbstractFigure
{
private:

    double side = 1; //Сторона квадрата

public:

    //Конструктор класса Square
    Square(double& side)
    {
        this->side = side;
    }

    //Выводит всю информацию о квадрате
    void GetInfo() override
    {
        cout << "\n\tSquare:\n\t\tLength = " << side << "\n\t\tCoordinates:\n\t\t\tx = " << x
            << "\n\t\t\ty = " << y << "\n\t\tAngle of inclination = " << alpha;
    }

    //Меняет координаты квадрата 
    void MovingOnPlane(double& x, double& y) override
    {
        this->x = x;
        this->y = y;
    }

    //Меняет размер квадрата
    void Resize(double* sizes) override
    {
        side = sizes[0];
    }

    //Вращает квадрат на заданный угол
    void Rotation(double& alpha) override
    {
        this->alpha = alpha;
    }
};

//Описывает прямоугольник
class Rectangle : protected AbstractFigure
{
private:

    double firstSide = 1; //Первая сторона прямоугольника
    double secondSide = 1; //Вторая сторона прямоугольника

public:

    //Конструктор класса Rectangle
    Rectangle(double& firstSide, double& secondSide)
    {
        this->firstSide = firstSide;
        this->secondSide = secondSide;
    }

    //Выводит всю информацию о прямоугольнике
    void GetInfo() override
    {
        cout << "\n\tRectangle:\n\t\tLength = " << firstSide << "\n\t\tWidth = " << secondSide
            << "\n\t\tCoordinates:\n\t\t\tx = " << x << "\n\t\t\ty = " << y
            << "\n\t\tAngle of inclination = " << alpha;
    }

    //Меняет координаты прямоугольника 
    void MovingOnPlane(double& x, double& y) override
    {
        this->x = x;
        this->y = y;
    }

    //Меняет размер прямоугольника
    void Resize(double* sizes) override
    {
        firstSide = sizes[0];
        secondSide = sizes[1];
    }

    //Вращает прямоугольник на заданный угол
    void Rotation(double& alpha) override
    {
        this->alpha = alpha;
    }
};

//Описывает круг
class Circle : protected AbstractFigure
{
private:

    double radius; //Радиус круга
    double circumference; //Длина окружности

public:

    //Конструктор класса Circle
    Circle(double& centerX, double& centerY, double& radius)
    {
        x = centerX;
        y = centerY;
        this->radius = radius;
        circumference = 2 * 3.14 * this->radius;
        circumference = int(circumference * 100 + 0.5) / 100.0;
    }

    //Выводит всю информацию о круге
    void GetInfo() override
    {
        cout << "\n\tCircle:\n\t\tCircumference = " << circumference << "\n\t\tCoordinates:\n\t\t\tx = "
            << x << "\n\t\t\ty = " << y << "\n\t\tAngle of inclination = " << alpha;
    }

    //Меняет координаты круга 
    void MovingOnPlane(double& x, double& y) override
    {
        this->x = x;
        this->y = y;
    }

    //Меняет размер круга
    void Resize(double* size) override
    {
        radius = size[0];
        circumference = 2 * 3.14 * radius;
        circumference = int(circumference * 100 + 0.5) / 100.0;
    }

    //Вращает прямоугольник на заданный угол
    void Rotation(double& alpha) override
    {
        this->alpha = alpha;
    }
};

//Реализует вывод на консоль
class DrawInConsole
{
private:

    //Создаёт объект класса Square и возвращает информацию о созданном объекте
    Square CreateSquare()
    {
        cout << "\nEnter the size of the square: ";
        cin >> squareSide;

        Square square = Square(squareSide);

        cout << "\nInformation about created shape:";
        return square;
    }

    //Создаёт объект класса Rectangle и возвращает информацию о созданном объекте
    Rectangle CreateRectangle()
    {
        cout << "\nEnter the size of the rectangle:\nLength = ";
        cin >> rectanglenLength;
        cout << "Width = ";
        cin >> rectangleWidth;

        Rectangle rectangle = Rectangle(rectanglenLength, rectangleWidth);

        cout << "\nInformation about created shape:";
        return rectangle;
    }

    //Создаёт объект класса Circle и возвращает информацию о созданном объекте
    Circle CreateCircle()
    {
        cout << "\nEnter the coordinates of the circle:\nCoordinate of the center by X = ";
        cin >> circle_X;
        cout << "Coordinate of the center by Y = ";
        cin >> circle_Y;
        cout << "Enter the radius of the circle: ";
        cin >> circleRadius;

        Circle circle = Circle(circle_X, circle_Y, circleRadius);

        cout << "\nInformation about created shape:";
        return circle;
    }

public:

    double circle_X; //Координата круга по иксу
    double circle_Y; //Координата круга по игрик
    double circleRadius; //Радиус круга
    double rectanglenLength; //Длина прямоугольника
    double rectangleWidth; //Ширина прямоугольника
    double squareSide; //Сторона квадрата

    //Метод реализующий вывод информации о фигурах в консоль
    void Draw()
    {
        int number = -1; //Хранит ввод пользователя

        cout << "Welcome to my program! What u want to do? Press the number:\n";
        cout << "1 - Create square\n2 - Create rectangle\n3 - Create circle";
        cout << "\nYour choice: ";
        cin >> number;

        switch (number)
        {
        case 1:
        {
            Square mySquare = CreateSquare();
            mySquare.GetInfo();
            cout << "\n\nWhat do you want to do next?\n\t";
            cout << "1 - Change the size of the square\n\t";
            cout << "2 - Change the coordinates of the square\n\t";
            cout << "3 - Rotate the square to the specified angle";
            int firstInput = -1;
            cout << "\nYour choice: ";
            cin >> firstInput;
            switch (firstInput)
            {
            case 1:
            {
                cout << "\n\tEnter the new size of the square: ";
                double size[1];
                cin >> size[0];
                mySquare.Resize(size);
                cout << "\nUpdated information about the created shape:";
                mySquare.GetInfo();
                break;
            }
            case 2:
            {
                cout << "\n\tEnter the new coordinates of the square:\n\t\tEnter x = ";
                double x = -1, y = -1;
                cin >> x;
                cout << "\t\tEnter y = ";
                cin >> y;
                mySquare.MovingOnPlane(x, y);
                cout << "\nUpdated information about the created shape:";
                mySquare.GetInfo();
                break;
            }
            case 3:
            {
                cout << "\n\tEnter the angle: ";
                double angle = -1;
                cin >> angle;
                mySquare.Rotation(angle);
                cout << "\nUpdated information about the created shape:";
                mySquare.GetInfo();
                break;
            }
            default:
            {
                cout << "\nU enetered the wrong number!";
                break;
            }
            }
            break;
        }

        case 2:
        {
            Rectangle myRectangle = CreateRectangle();
            myRectangle.GetInfo();
            cout << "\n\nWhat do you want to do next?\n\t";
            cout << "1 - Change the size of the rectangle\n\t";
            cout << "2 - Change the coordinates of the rectangle\n\t";
            cout << "3 - Rotate the rectangle to the specified angle";
            int secondInput = -1;
            cout << "\nYour choice: ";
            cin >> secondInput;
            switch (secondInput)
            {
            case 1:
            {
                cout << "\n\tEnter the new size of the rectangle:\n\tLength = ";
                double size[2];
                cin >> size[0];
                cout << "\tWidth = ";
                cin >> size[1];
                myRectangle.Resize(size);
                cout << "\nUpdated information about the created shape:";
                myRectangle.GetInfo();
                break;
            }
            case 2:
            {
                cout << "\n\tEnter the new coordinates of the rectangle:\n\t\tEnter x = ";
                double x = -1, y = -1;
                cin >> x;
                cout << "\t\tEnter y = ";
                cin >> y;
                myRectangle.MovingOnPlane(x, y);
                cout << "\nUpdated information about the created shape:";
                myRectangle.GetInfo();
                break;
            }
            case 3:
            {
                cout << "\n\tEnter the angle: ";
                double angle = -1;
                cin >> angle;
                myRectangle.Rotation(angle);
                cout << "\nUpdated information about the created shape:";
                myRectangle.GetInfo();
                break;
            }
            default:
            {
                cout << "\nU enetered the wrong number!";
                break;
            }
            }
            break;
        }

        case 3:
        {
            Circle myCircle = CreateCircle();
            myCircle.GetInfo();
            cout << "\n\nWhat do you want to do next?\n\t";
            cout << "1 - Change the circumference of the circle\n\t";
            cout << "2 - Change the coordinates of the circle\n\t";
            cout << "3 - Rotate the circle to the specified angle";
            int thirdInput = -1;
            cout << "\nYour choice: ";
            cin >> thirdInput;
            switch (thirdInput)
            {
            case 1:
            {
                cout << "\n\tEnter the new radius of the circle:\n\tRadius = ";
                double size[1];
                cin >> size[0];
                myCircle.Resize(size);
                cout << "\nUpdated information about the created shape:";
                myCircle.GetInfo();
                break;
            }
            case 2:
            {
                cout << "\n\tEnter the new coordinates of the circle:\n\t\tEnter x = ";
                double x = -1, y = -1;
                cin >> x;
                cout << "\t\tEnter y = ";
                cin >> y;
                myCircle.MovingOnPlane(x, y);
                cout << "\nUpdated information about the created shape:";
                myCircle.GetInfo();
                break;
            }
            case 3:
            {
                cout << "\n\tEnter the angle: ";
                double angle = -1;
                cin >> angle;
                myCircle.Rotation(angle);
                cout << "\nUpdated information about the created shape:";
                myCircle.GetInfo();
                break;
            }
            default:
            {
                cout << "\nU enetered the wrong number!";
                break;
            }
            }
            break;
        }
        default:
        {
            cout << "\nU enetered the wrong number!";
            break;
        }
        }
    }
};

int main()
{
    DrawInConsole draw = DrawInConsole(); //Объект класса DrawInConsole
    draw.Draw(); //Вызов метода вывода информации в консоль

    return 0;
}