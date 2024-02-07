#include "widget.h"
#include "ui_widget.h"
#include "globaldata.h"

#include <QDebug>
#include <QFileDialog>
#include <QString>
#include <QUrl>
#include <QDateEdit>

#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>
#include <QFile>
#include <QJsonParseError>
#include <QJsonArray>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    init_functions();

    int eventWidgetWidth = 100 * widthFactor;
    int eventWidgetLeft = 100 * leftFactor;
    int eventWidgetTop = 100 * topFactor;
    int eventWidgetHeight = 100 * itemHeightFactor;

    ui->slider_width->setValue(eventWidgetWidth);
    ui->slider_left->setValue(eventWidgetLeft);
    ui->slider_top->setValue(eventWidgetTop);
    ui->slider_height->setValue(eventWidgetHeight);

    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    int eventId = 0;

    for(auto _event : eventVector){
        ui->tableWidget->insertRow(eventId);

        QTableWidgetItem *_item_eventName = new QTableWidgetItem(_event.eventName);

        QDateEdit *dateEdit = new QDateEdit(ui->tableWidget);

        dateEdit->setDate(QDate::fromString(_event.eventDate,"yyyy-MM-dd"));

        ui->tableWidget->setItem(eventId,0,_item_eventName);
        ui->tableWidget->setCellWidget(eventId,1,dateEdit);

        eventId++;
    }

}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_save_clicked()
{
    QJsonObject _window;
    QJsonArray _events;

    QJsonArray events;

    _window.insert("width",ui->slider_width->value() / 100.0);
    _window.insert("itemHeight",ui->slider_height->value() / 100.0);
    _window.insert("top",ui->slider_top->value() / 100.0);
    _window.insert("left",ui->slider_left->value() / 100.0);

    int eventNum = ui->tableWidget->rowCount();

    for(int rowNum = 0;rowNum<eventNum;rowNum++){
        QJsonObject event;
        QTableWidget *tb = ui->tableWidget;

        QString eventName = tb->item(rowNum,0)->text();
        QString eventDate = qobject_cast<QDateEdit*>(tb->cellWidget(rowNum,1))->date().toString("yyyy-MM-dd");
        event.insert("eventName",eventName);
        event.insert("eventDate",eventDate);

        _events.append(event);
    }

    QJsonObject rootObj;

    rootObj.insert("window",_window);
    rootObj.insert("events",_events);

    QJsonDocument doc;

    doc.setObject(rootObj);

    saveJsonFile(doc);

}

void Widget::on_pushButton_new_clicked()
{
    int eventNum = ui->tableWidget->rowCount();
    ui->tableWidget->insertRow(eventNum);

    QTableWidgetItem *_item_eventName = new QTableWidgetItem("事件名称");

    QDateEdit *dateEdit = new QDateEdit(ui->tableWidget);

    dateEdit->setDate(QDate::currentDate());

    ui->tableWidget->setItem(eventNum,0,_item_eventName);
    ui->tableWidget->setCellWidget(eventNum,1,dateEdit);
}

void Widget::on_pushButton_del_clicked()
{
    int nowRow = ui->tableWidget->currentRow();
    ui->tableWidget->removeRow(nowRow);
}


