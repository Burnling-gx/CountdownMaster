#ifndef GLOBALDATA_H
#define GLOBALDATA_H

#include <QVector>
#include <QColor>
#include <QFont>
#include <QRect>
#include <QJsonObject>
#include <QPalette>
#include "_event.h"

extern int screenWidth;
extern int screenHeight;

extern double leftFactor;
extern double topFactor;
extern double widthFactor;
extern double heightFactor;
extern double itemHeightFactor;

extern QVector<_Event> eventVector;

void init_functions();

#endif // GLOBALDATA_H
