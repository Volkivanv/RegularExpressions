#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QRegularExpression>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);

    connect(ui->lineEdit,&QLineEdit::textEdited,[this](QString currentText){
        QRegularExpression exp("^\\+[1-9](\\d{10})$");

        if(exp.match(currentText).hasMatch()){
            setOkLabel();
        } else {
            setNonOkLabel();
        }
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setOkLabel()
{
    ui->label->setText("OK");
    ui->label->setStyleSheet("QLabel {color : green;}");
}

void MainWindow::setNonOkLabel()
{
    ui->label->setText("Not OK");
    ui->label->setStyleSheet("QLabel {color : red;}");
}

