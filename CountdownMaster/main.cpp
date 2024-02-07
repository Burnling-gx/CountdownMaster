#include "widget.h"

#include <QApplication>
#include <QWindow>
#include <QGuiApplication>
#include <QScreen>
#include <QDebug>
#include <QSystemTrayIcon>
#include <QMenu>
#include <QAction>
#include <QFile>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;

    w.setWindowFlags(Qt::FramelessWindowHint | Qt::WindowTransparentForInput | Qt::WindowStaysOnBottomHint | Qt::Tool); //
    w.setAttribute(Qt::WA_TranslucentBackground);
    w.show();

    QSystemTrayIcon *trayIcon = new QSystemTrayIcon;
    trayIcon->setIcon(QIcon(":/ico/logo.ico"));

    QMenu *trayIconMenu = new QMenu;
    QAction *exitAction = new QAction("退出程序", &a);
    QObject::connect(exitAction, &QAction::triggered, &a, &QApplication::quit);
    trayIconMenu->addAction(exitAction);

    trayIcon->setContextMenu(trayIconMenu);

    trayIcon->show();

    return a.exec();
}
