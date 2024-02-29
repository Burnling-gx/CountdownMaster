#include "widget.h"
#include "configeditordialog.h"

#include <QApplication>
#include <QWindow>
#include <QGuiApplication>
#include <QScreen>
#include <QDebug>
#include <QSystemTrayIcon>
#include <QMenu>
#include <QAction>
#include <QFile>
#include <QProcess>

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

    QAction *openConfigurator = new QAction("打开设置",&a);
    QObject::connect(openConfigurator, &QAction::triggered, [&]() {
        ConfigEditorDialog dialog;
        dialog.exec();
    });
    trayIconMenu->addAction(openConfigurator);

    trayIconMenu->addSeparator();

    QAction *restart = new QAction("重启程序",&a);
    QObject::connect(restart, &QAction::triggered, [&]() {
        w.restart();
    });
    trayIconMenu->addAction(restart);

    QAction *exitAction = new QAction("退出程序", &a);
    QObject::connect(exitAction, &QAction::triggered, &a, &QApplication::quit);
    trayIconMenu->addAction(exitAction);


    trayIcon->setContextMenu(trayIconMenu);

    trayIcon->show();

    a.setQuitOnLastWindowClosed(false);

    int code = a.exec();

    if(code == 312){
        QProcess::startDetached(qApp->applicationFilePath());
        return 0;
    }

    return code;
}
