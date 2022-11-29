#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_Ok_clicked()
{
    close();
}

void MainWindow::on_Boursorama_clicked()
{
    QSqlQuery qry;
    qry.prepare( "SELECT firstname, lastname FROM info" );
    if( !qry.exec() )
      qDebug() << qry.lastError();
    else
    {
      qDebug( "Selected!" );

      QSqlRecord rec = qry.record();

      int cols = rec.count();

      for( int c=0; c<cols; c++ )
        qDebug() << QString( "Column %1: %2" ).arg( c ).arg( rec.fieldName(c) );

      for( int r=0; qry.next(); r++ )
        for( int c=0; c<cols; c++ )
          qDebug() << QString( "Row %1, %2: %3" ).arg( r ).arg( rec.fieldName(c) ).arg( qry.value(c).toString() );
    }
}


void MainWindow::on_actionOuvrir_un_Compte_triggered()
{
    QWidget *wdg = new QWidget;
    wdg->show();
}
