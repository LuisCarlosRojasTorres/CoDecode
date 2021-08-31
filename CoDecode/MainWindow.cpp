#include "MainWindow.h"
#include "ui_MainWindow.h"

#include <iostream>

void MainWindow::decrypt()
{
    code = ui->txt_Code->toPlainText();

    std::cout << code.toStdString() << std::endl;
}

void MainWindow::encrypt()
{
    message = ui->txt_Message->toPlainText();
    std::cout << message.toStdString() << std::endl;
}



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->cB_TypeOfCyphers->addItem("Caesar");
    ui->cB_TypeOfCyphers->addItem("Vignere");

    connect(ui->pb_encrypt,&QPushButton::clicked,this,&MainWindow::encrypt);
    connect(ui->pb_decrypt,&QPushButton::clicked,this,&MainWindow::decrypt);
}

MainWindow::~MainWindow()
{
    delete ui;
}

