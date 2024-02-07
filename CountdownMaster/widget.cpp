#include "widget.h"
#include "ui_widget.h"
#include "globaldata.h"
#include "eventwidget.h"

#include <QScreen>
#include <QGuiApplication>
#include <QRect>
#include <QApplication>
#include <QDebug>
#include <QVector>
#include <QTimer>
#include <QSystemTrayIcon>
#include <QMenu>
#include <QAction>

const int padding = 10;

QVector<EventWidget*> eventWidgetVector;

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    // QSystemTrayIcon *systemIcon = new QSystemTrayIcon(this);
    // systemIcon->setIcon(QIcon(":/ico/logo.ico"));

    // QMenu *menu = new QMenu();
    // QAction *_exit = new QAction("退出程序");
    // menu->addAction(_exit);
    // systemIcon->setContextMenu(menu);

    // QObject::connect(_exit, &QAction::triggered, quit());
    // systemIcon->show();

    init_functions();
    this->resize(screenWidth,screenHeight);

    const int eventWidgetWidth = screenWidth * widthFactor - padding;
    const int eventWidgetLeft = screenWidth * leftFactor;
    const int eventWidgetTop = screenHeight * topFactor;
    const int eventWidgetHeight = screenHeight * itemHeightFactor;

    int eventId = 0;

    for(auto _event : eventVector){
        EventWidget *eventWidget = new EventWidget(this);

        eventWidget->setGeometry(eventWidgetLeft,eventWidgetTop+(eventWidgetHeight+padding)*eventId+padding,eventWidgetWidth,eventWidgetHeight);

        eventWidget->setEventDate(_event.eventDate);
        eventWidget->setEventName(_event.eventName);
        eventWidget->setEvent(_event);

        eventWidget->updateEventCountdown();
        eventWidgetVector.append(eventWidget);
        eventId++;
    }

    QTimer *timer = new QTimer();
    connect(timer, &QTimer::timeout, [=]() {
       for(auto event : eventWidgetVector){
           event->updateEventCountdown();
       }
    });

    timer->start(60000);


}

Widget::~Widget()
{
    delete ui;
}

