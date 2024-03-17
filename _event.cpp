#include "_event.h"

void _Event::initializeDefaults() {
    this->color_eventName.setRgb(0, 0, 0);
    this->color_eventCountdown.setRgb(0, 0, 0);

    this->backgroundColor.setRgb(255, 255, 255, 32);

    this->font_eventName.setFamily("微软雅黑");
    this->font_eventCountdown.setFamily("微软雅黑");

    this->font_eventName.setPointSize(25);
    this->font_eventCountdown.setPointSize(30);

    this->font_eventName.setBold(true);
    this->font_eventCountdown.setBold(true);

    this->widget_border = "2px solid black";

    // this->shadow_enabled = false;

    this->otherStylesheet = "";
}

void setColorFromJson(QColor& color, const QJsonObject& jsonObject, const QString& key) {
    if (jsonObject.contains(key)) {
        color = QColor::fromString(jsonObject.value(key).toString());
    }
}

void setFontFamilyFromJson(QFont& font, const QJsonObject& jsonObject, const QString& key) {
    if (jsonObject.contains(key)) {
        font.setFamily(jsonObject.value(key).toString());
    }
}

void setFontSizeFromJson(QFont& font, const QJsonObject& jsonObject, const QString& key) {
    if (jsonObject.contains(key)) {
        font.setPointSize(jsonObject.value(key).toInt());
    }
}

void setFontBoldFromJson(QFont& font, const QJsonObject& jsonObject, const QString& key) {
    if (jsonObject.contains(key)) {
        font.setBold(jsonObject.value(key).toBool());
    }
}

void _Event::parseJsonObject(const QJsonObject& jsonObject) {
    eventName = jsonObject.value("eventName").toString();
    eventDate = jsonObject.value("eventDate").toString();

    setColorFromJson(color_eventName, jsonObject, "color_eventName");
    setColorFromJson(color_eventCountdown, jsonObject, "color_eventCountdown");
    setColorFromJson(backgroundColor, jsonObject, "color_background");

    setFontFamilyFromJson(font_eventName, jsonObject, "fontFamily_eventName");
    setFontFamilyFromJson(font_eventCountdown, jsonObject, "fontFamily_eventCountdown");

    setFontSizeFromJson(font_eventName, jsonObject, "fontSize_eventName");
    setFontSizeFromJson(font_eventCountdown, jsonObject, "fontSize_eventCountdown");

    setFontBoldFromJson(font_eventName, jsonObject, "bold_eventName");
    setFontBoldFromJson(font_eventCountdown, jsonObject, "bold_eventCountdown");


    widget_border = jsonObject.value("border").toString();
    if(!widget_border.size()) widget_border = "2px solid black";

    if (jsonObject.contains("other_stylesheet")){
        otherStylesheet = jsonObject.value("other_stylesheet").toString();
    }

    // if (jsonObject.contains("shadow")) {
    //     QJsonObject shadowJsonObject = jsonObject.value("shadow").toObject();

    //     shadow_enabled = true;

    //     shadow_offset_x = shadowJsonObject.value("offset_x").toInt();
    //     shadow_offset_y = shadowJsonObject.value("offset_y").toInt();
    //     shadow_blur_radius = shadowJsonObject.value("blur_radius").toInt();
    //     shadow_color = QColor::fromString(shadowJsonObject.value("color").toString());

    // }
}

_Event::_Event() = default;

_Event::_Event(const QJsonObject& eventJsonObj, int eventId) : eventId(eventId) {
    initializeDefaults();
    parseJsonObject(eventJsonObj);
}
