#ifndef _EVENT_H
#define _EVENT_H

#include <QJsonObject>
#include <QJsonParseError>

#include <QColor>
#include <QFont>
#include <QString>

class _Event{

public:
    QString eventName;
    QString eventDate;

    QColor color_eventName;
    QColor color_eventCountdown;

    QColor backgroundColor;

    QFont font_eventName;
    QFont font_eventCountdown;

    QString widget_border;

    bool bold_eventName;
    bool bold_eventCountdown;

    int eventId;

    void initializeDefaults();
    void parseJsonObject(const QJsonObject&);

    _Event();
    _Event(const QJsonObject&, int);
};

#endif // _EVENT_H
