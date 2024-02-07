#include "widget.h"

#include <QApplication>
#include <QWindow>
#include <QGuiApplication>
#include <QScreen>
#include <QDebug>
#include <QSystemTrayIcon>
#include <QMenu>
#include <QAction>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;

    w.setWindowFlags(Qt::FramelessWindowHint | Qt::WindowTransparentForInput | Qt::WindowStaysOnBottomHint | Qt::Tool); //
    w.setAttribute(Qt::WA_TranslucentBackground);
    w.show();

    // 创建系统托盘图标
    QSystemTrayIcon *trayIcon = new QSystemTrayIcon;
    trayIcon->setIcon(QIcon(":/ico/logo.ico"));

    // 创建托盘图标菜单
    QMenu *trayIconMenu = new QMenu;
    QAction *exitAction = new QAction("退出程序", &a);
    QObject::connect(exitAction, &QAction::triggered, &a, &QApplication::quit);
    trayIconMenu->addAction(exitAction);

    // 将菜单设置给托盘图标
    trayIcon->setContextMenu(trayIconMenu);

    // 显示系统托盘图标
    trayIcon->show();

    return a.exec();
}
