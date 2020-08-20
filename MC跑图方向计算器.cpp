#include <stdio.h>
#include <cmath>
#include <Windows.h>
#define Pi 3.141592653589793238f
using namespace std;

float degress(float a);
float direction(float* Des, float* Out);
void PrintDirectionInfo(float* Des, float* Out);

int main()
{
	system("title Minecraft跑图方向计算器");
	float Outset[2];
	float Destination[2];
	printf("输入终点坐标\n>>>");
	scanf_s("%f %f", &Destination[0], &Destination[1]);
FLAG:
	printf("\n输入起点坐标\n>>>");
	scanf_s("%f %f", &Outset[0], &Outset[1]);
	PrintDirectionInfo(&Destination[0], &Outset[0]);
	goto FLAG;
}

float direction(float* Des, float* Out)
{
	float h = Des[1] - Out[1];
	float l = Des[0] - Out[0];
	if (l == 0)
		return 0.0;
	//一般情况
	if (h > 0 and l > 0 || l > 0 and h < 0)
		return -90 + degress(atan(h / l));
	else if (l < 0 and h > 0 || l < 0 and h < 0)
		return 90 + degress(atan(h / l));
	//特殊情况
	else if (l > 0 and h == 0)
		return 0.0;
	else if (l == 0 and h > 0)
		return -90.0f;
	else if (l < 0 and h == 0)
		return 180.0f;
	else if (l == 0 and h < 0)
		return 90.0f;
}

float degress(float a) {
	//degress:弧度转角度
	//a:传入弧度
	return 180 * a / Pi;
}

void PrintDirectionInfo(float* Des, float* Out)
{
	float angle = direction(Des, Out);
	printf("——————————计算结果——————————\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
	printf("终点坐标:\tX:%.3lf\tZ:%.3lf\n", Des[0], Des[1]);
	printf("起点坐标:\tX:%.3lf\tZ:%.3lf\n\n", Out[0], Out[1]);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
	printf("方向角(y_rotation):");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
	printf("%.2lf\n", angle);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
	printf("传送命令:");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
	printf("\t/tp @s ~ ~ ~ %.2lf ~\n", angle);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	printf("————————————————————————");
}