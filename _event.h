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

    // bool shadow_enabled;
    // int shadow_offset_x;
    // int shadow_offset_y;
    // int shadow_blur_radius;
    // QColor shadow_color;

    QString otherStylesheet;
    int eventId;

    void initializeDefaults();
    void parseJsonObject(const QJsonObject&);

    _Event();
    _Event(const QJsonObject&, int);
};

#endif // _EVENT_H
