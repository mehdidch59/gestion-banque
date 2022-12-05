#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QtSql/QtSql>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlError>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();

private slots:
    void on_Annuler_clicked();

    void on_Ok_clicked();

private:
    Ui::Dialog *ui;
};

#endif // DIALOG_H