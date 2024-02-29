#ifndef CONFIGEDITORDIALOG_H
#define CONFIGEDITORDIALOG_H

#include <QDialog>

namespace Ui {
class ConfigEditorDialog;
}

class ConfigEditorDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ConfigEditorDialog(QWidget *parent = nullptr);
    ~ConfigEditorDialog();

private slots:
    void on_pushButton_new_clicked();

    void on_pushButton_del_clicked();

    void on_pushButton_save_clicked();

private:
    Ui::ConfigEditorDialog *ui;
};

#endif // CONFIGEDITORDIALOG_H
