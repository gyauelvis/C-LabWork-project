#include <stdio.h>

float areaOfCircle(float radius)
{
    float area = 3.142 * radius * radius;
    return area;
}

float areaOfRectangle(float width, float length)
{
    float area = width * length;
    return area;
}
float areaOfTriangle(float height, float base)
{
    float area = 0.5 * height * base;
    return area;
}
float areaOfSquare(float width)
{
    float area = width * width;
    return area;
}
int main()
{
    float areaOfFigure1 = (areaOfCircle(4) / 2) + areaOfRectangle(8, 12);
    printf("Shape1\n contains a circle and rectangle and \nThe area is \t%.2f\n", areaOfFigure1);
    float areaOfFigure2 = (areaOfRectangle(13, 8) + areaOfTriangle(6, 8));
    printf("\nShape2\n contains a triangle and rectangle and \nThe area is \t%.2f\n", areaOfFigure2);
    float areaOfFigure3 = (areaOfRectangle(11, 4) + areaOfSquare(5));
    printf("\nShape3\n contains a square and rectangle and \nThe area is \t%.2f\n", areaOfFigure3);
    float areaOfFigure4 = (areaOfTriangle(8, 7) + areaOfCircle(4) / 2);
    printf("\nShape4\n contains a circle and triangle and \nThe area is \t%.2f \n", areaOfFigure4);
    float areaOfFigure5 = (areaOfTriangle(4, 7) + areaOfSquare(7));
    printf("\nShape5\n contains a square and triangle and \nThe area \t%.2f \n", areaOfFigure5);
    float areaOfFigure6 = (areaOfSquare(6) + areaOfRectangle(12, 6));
    printf("\nShape6\n contains a square and rectangle and \nThe area  \t%.2f \n", areaOfFigure6);

    return 0;
}