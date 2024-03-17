#ifndef EVENTWIDGET_H
#define EVENTWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QGraphicsDropShadowEffect>

#include "_event.h"

class EventWidget : public QWidget
{
    Q_OBJECT
public:
    explicit EventWidget(QWidget *parent = nullptr);

    _Event event;

    QString eventName;
    QString eventDate;
    int countdown;

    void setEventName(QString);
    void setEventDate(QString);
    void setEvent(_Event);

    void updateEventCountdown();
private:
    QLabel *label_eventName;
    QLabel *label_eventCountdown;
    QWidget *eventWidget;



signals:

};

#endif // EVENTWIDGET_H
