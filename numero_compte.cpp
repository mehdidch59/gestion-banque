#include "numero_compte.h"
#include "ui_numero_compte.h"

Numero_Compte::Numero_Compte(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Numero_Compte)
{
    ui->setupUi(this);

    QPixmap bkgnd(":/Images/background.jpg");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Window, bkgnd);
    this->setPalette(palette);
}

Numero_Compte::~Numero_Compte()
{
    delete ui;
}

void Numero_Compte::on_Annuler_clicked()
{
    close();
}


void Numero_Compte::on_Ok_clicked()
{
    QString email = ui->email->text();
    QString password = ui->password->text();

    QTcpSocket socket;
    socket.connectToHost("127.0.0.1", 3306);

    if(socket.waitForConnected()){
        if(ui->Banque->currentText() == "Boursorama"){
            QSqlDatabase BB = QSqlDatabase::database("bb");
            QSqlQuery *qry = new QSqlQuery(BB);

            QSqlTableModel *model = new QSqlTableModel(this, BB);
            model->setTable("info");
            model->setEditStrategy(QSqlTableModel::OnManualSubmit);
            model->select();

            qry->prepare( "SELECT account_number FROM info WHERE email = ? AND password = ?" );
            qry->addBindValue(email);
            qry->addBindValue(password);
            qry->exec();

            ui->tableView->setModel(model);

            ui->tableView->setColumnHidden(0,true);
            ui->tableView->setColumnHidden(1,true);
            ui->tableView->setColumnHidden(2,true);
            ui->tableView->setColumnHidden(3,true);
            ui->tableView->setColumnHidden(4,true);
            ui->tableView->setColumnHidden(5,true);
            ui->tableView->setColumnHidden(6,true);
            ui->tableView->setColumnHidden(8,true);

            if(qry->lastError().type() == QSqlError::NoError){
                qDebug() << "Data was successfully found into the DB";
            }

            qDebug() << "Salut mon Bou";
        }

        if(ui->Banque->currentText() == "Revolut"){
            QSqlDatabase RV = QSqlDatabase::database("rv");
            QSqlQuery *qry = new QSqlQuery(RV);

            QSqlTableModel *model = new QSqlTableModel(this, RV);
            model->setTable("info");
            model->setEditStrategy(QSqlTableModel::OnManualSubmit);
            model->select();

            qry->prepare( "SELECT account_number FROM info WHERE email = ? AND password = ?" );
            qry->addBindValue(email);
            qry->addBindValue(password);
            qry->exec();

            ui->tableView->setModel(model);

            ui->tableView->setColumnHidden(0,true);
            ui->tableView->setColumnHidden(3,true);
            ui->tableView->setColumnHidden(4,true);
            ui->tableView->setColumnHidden(5,true);
            ui->tableView->setColumnHidden(6,true);
            ui->tableView->setColumnHidden(8,true);

            if(qry->lastError().type() == QSqlError::NoError){
                qDebug() << "Data was successfully found into the DB";
            }

            qDebug() << "Salut mon reuv";
        }

        if(ui->Banque->currentText() == "N26"){
            QSqlDatabase N26 = QSqlDatabase::database("n26");
            QSqlQuery *qry = new QSqlQuery(N26);

            QSqlTableModel *model = new QSqlTableModel(this, N26);
            model->setTable("info");
            model->setEditStrategy(QSqlTableModel::OnManualSubmit);
            model->select();

            qry->prepare( "SELECT account_number FROM info WHERE email = ? AND password = ?" );
            qry->addBindValue(email);
            qry->addBindValue(password);
            qry->exec();

            ui->tableView->setModel(model);

            ui->tableView->setColumnHidden(0,true);
            ui->tableView->setColumnHidden(3,true);
            ui->tableView->setColumnHidden(4,true);
            ui->tableView->setColumnHidden(5,true);
            ui->tableView->setColumnHidden(6,true);
            ui->tableView->setColumnHidden(8,true);

            if(qry->lastError().type() == QSqlError::NoError){
                qDebug() << "Data was successfully found into the DB";
            }

            qDebug() << "Salut mon Nigger";
        }

        socket.close();
    }

    else
    {
        qDebug() << "Could not connect to the MySQL server";
    }
}

