#pragma once
#include <QStandardItemModel>
#include <qlist.h>
#include "showresult.h"

struct Hitsuyo
{
	int cnt;
	int all;
	bool anime;
	bool repeat;
	int* weight;
	QString* content;
	bool mode;
	int seed;
	int time;
	int count;
	ShowResult* resultS;
};

int GetIndex(int[], int, int);
int GetIndexL(int [], int, int);
int GetIndexH(int[], int, int);