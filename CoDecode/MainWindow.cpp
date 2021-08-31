#include "MainWindow.h"
#include "ui_MainWindow.h"

#include "WidgetCaesarCypher.h"
#include "WidgetVignereCypher.h"

#include <iostream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{


    ui->setupUi(this);
    ui->cB_TypeOfCyphers->addItem("Caesar");
    ui->cB_TypeOfCyphers->addItem("Vignere");

    connect(ui->pb_encrypt,&QPushButton::clicked,this,&MainWindow::encrypt);
    connect(ui->pb_decrypt,&QPushButton::clicked,this,&MainWindow::decrypt);

    widgetCaesarCypher = new WidgetCaesarCypher(this);
    widgetVignereCypher = new WidgetVignereCypher(this);
    ui->stackedWidget->addWidget(widgetCaesarCypher);
    ui->stackedWidget->addWidget(widgetVignereCypher);

//    connect(ui->cB_TypeOfCyphers, QOverload<int>::of(&QComboBox::currentIndexChanged),
//                ui->stackedWidget, &QStackedWidget::setCurrentIndex);
    connect(ui->cB_TypeOfCyphers, QOverload<int>::of(&QComboBox::currentIndexChanged),
                this, &MainWindow::setCypherConfigurationWidget);

}

MainWindow::~MainWindow()
{
    delete ui;
}

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


void MainWindow::setCypherConfigurationWidget(int index)
{
    switch(index){
    case 0: //Caesar
        std::cout<<"Set Caesar Cypher"<<std::endl;
        ui->stackedWidget->setCurrentWidget(widgetCaesarCypher);
        break;
    case 1: //Vignere
        std::cout<<"Set Vignere Cypher"<<std::endl;
        ui->stackedWidget->setCurrentWidget(widgetVignereCypher);
        break;
    default:
        break;
    }

}
