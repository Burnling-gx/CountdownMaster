#include "eventwidget.h"

#include <QDate>
#include <QDebug>
#include <QLabel>
#include <QFont>
#include <utility>

const int padding = 10;
const double factor_04 = 0.4;
const double factor_06 = 0.6;

EventWidget::EventWidget(QWidget *parent) : QWidget(parent)
{

    this->eventWidget = new QWidget(this);
    this->eventWidget->setObjectName("eventContainer");

    this->label_eventName = new QLabel(eventWidget);
    this->label_eventCountdown = new QLabel(eventWidget);

    this->label_eventName->setText("None");
    this->label_eventCountdown->setText("NaN");

}

void EventWidget::setEventDate(QString _eventDate){
    this->eventDate = std::move(_eventDate);
}

void EventWidget::setEventName(QString _eventName){
    this->eventName = std::move(_eventName);
}

void EventWidget::setEvent(_Event _event){
    this->event = _event;
    this->eventDate = _event.eventDate;
    this->eventName = _event.eventName;

    QString _ = "eventContainer";
    QString __ = QString::number(this->event.eventId);

    this->setObjectName(_+__);
    this->eventWidget->setProperty("special",true);
}

void EventWidget::updateEventCountdown(){
    QDate nowDate = QDate::currentDate();
    QDate targetDate = QDate::fromString(this->eventDate,"yyyy-MM-dd");

    this->countdown = nowDate.daysTo(targetDate);

    qDebug() << this->eventName << nowDate << targetDate << this->countdown;

    this->label_eventName->setText(this->eventName);
    this->label_eventCountdown->setText(QString::number(this->countdown));

    this->label_eventName->setAlignment(Qt::Alignment(Qt::AlignmentFlag::AlignHCenter | Qt::AlignmentFlag::AlignVCenter));
    this->label_eventCountdown->setAlignment(Qt::Alignment(Qt::AlignmentFlag::AlignHCenter | Qt::AlignmentFlag::AlignVCenter));

    QRect t = this->geometry();
    this->eventWidget->setGeometry(0,0,t.width(),t.height());

    this->label_eventName->setGeometry(padding,padding,t.width()-(padding<<1),int(t.height()*factor_04)-padding);
    this->label_eventCountdown->setGeometry(padding,int(t.height()*factor_04),t.width()-(padding << 1),int(t.height()*factor_06)-padding);

    this->label_eventName->setFont(this->event.font_eventName);
    this->label_eventCountdown->setFont(this->event.font_eventCountdown);

    QPalette pt_eventName = palette();
    QPalette pt_eventCountdown = palette();

    pt_eventName.setColor(QPalette::WindowText,this->event.color_eventName);
    pt_eventCountdown.setColor(QPalette::WindowText,this->event.color_eventCountdown);

    this->label_eventName->setPalette(pt_eventName);
    this->label_eventCountdown->setPalette(pt_eventCountdown);

    QString stylesheet = QString("QWidget[special=\"true\"]{background-color:%1; border: %2; border-radius: 10px;}").arg(event.backgroundColor.name(QColor::HexArgb)).arg(event.widget_border);
    qDebug() << stylesheet;

    this->eventWidget->setStyleSheet(stylesheet);


}
