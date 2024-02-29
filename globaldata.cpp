#include "globaldata.h"
#include <QGuiApplication>
#include <QScreen>
#include <QDebug>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>
#include <QFile>
#include <QJsonParseError>
#include <QJsonArray>
#include <QVector>
#include "_event.h"

int screenWidth;
int screenHeight;

double leftFactor;
double topFactor;
double widthFactor;
double heightFactor;
double itemHeightFactor;

QVector<_Event> eventVector;
QVector<EventWidget*> eventWidgetVector;

bool createDefaultJsonFile(QFile &file) {
    if (!file.open(QIODevice::WriteOnly)) {
        return false;
    }

    QJsonObject windowContent;
    windowContent["width"] = 0.12;
    windowContent["left"] = 0.88;
    windowContent["top"] = 0;
    windowContent["itemHeight"] = 0.15;


    QJsonObject event;
    event["eventName"] = "2025";
    event["eventDate"] = "2025-01-01";

    QJsonArray defaultEvent;
    defaultEvent.append(event);

    QJsonObject defaultContent;
    defaultContent["events"] = defaultEvent;
    defaultContent["window"] = windowContent;

    QJsonDocument doc(defaultContent);
    file.write(doc.toJson());
    qDebug() << "Created a new events.json file with default content.";
    file.close();

    return true;
}

void parseEvents(const QJsonObject &rootObject) {

    eventVector.clear();

    QJsonArray eventsArray = rootObject.value("events").toArray();
    int cnt = 0;

    qDebug() << "eventsArray: " << eventsArray;

    for (const auto &event : eventsArray) {
        QJsonObject eventObject = event.toObject();
        eventVector.append(_Event(eventObject, cnt));
        qDebug() << "globaldata.cpp >> eventName & eventDate:" << eventObject.value("eventName").toString() << eventObject.value("eventDate").toString();
        ++cnt;
    }
}

void parseWindowParams(const QJsonObject &rootObject) {
    QJsonObject windowObject = rootObject.value("window").toObject();
    widthFactor = windowObject.value("width").toDouble();
    heightFactor = windowObject.value("height").toDouble();
    leftFactor = windowObject.value("left").toDouble();
    topFactor = windowObject.value("top").toDouble();
    itemHeightFactor = windowObject.value("itemHeight").toDouble();

    qDebug() << "getFactors: " << widthFactor << heightFactor << leftFactor << topFactor << itemHeightFactor;
}

void initJson() {
    QFile jsonFile("./events.json");

    if (!jsonFile.open(QIODevice::ReadOnly)) {
        qDebug() << "Failed to open events.json for reading, trying to create a new one.";
        if (!createDefaultJsonFile(jsonFile)) {
            qDebug() << "Failed to create events.json for writing.";
            return;
        }
        if (!jsonFile.open(QIODevice::ReadOnly)) {
            qDebug() << "Failed to open events.json for reading even after creating a new one.";
            return;
        }
    }

    QByteArray jsonData = jsonFile.readAll();
    jsonFile.close();

    QJsonDocument doc = QJsonDocument::fromJson(jsonData);
    if (doc.isNull()) {
        qDebug() << "Failed to parse JSON data from events.json";
        return;
    }

    QJsonObject rootObject = doc.object();


    parseEvents(rootObject);
    parseWindowParams(rootObject);
}

void initGlobalValue(){
    QScreen *primaryScreen = QGuiApplication::primaryScreen();
    QRect screenGeometry = primaryScreen->availableGeometry();

    qDebug() << "Primary Screen Size:" << screenGeometry.width() << "x" << screenGeometry.height();

    screenWidth = screenGeometry.width();
    screenHeight = screenGeometry.height();
}

void saveJsonFile(QJsonDocument doc){


    QFile jsonFile("events.json");

    if (!jsonFile.open(QIODevice::WriteOnly)) {
        qDebug() << "Failed to create or open events.json for writing.";
        return;
    }

    QTextStream stream(&jsonFile);

    stream << doc.toJson();
    qDebug() << doc.toJson();
    jsonFile.close();

}

void init_functions(){

    initGlobalValue();
    initJson();
}
