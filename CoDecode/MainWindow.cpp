#include "MainWindow.h"
#include "ui_MainWindow.h"

#include "CipherCaesar.h"

#include "WidgetCaesarCypher.h"
#include "WidgetVignereCypher.h"

#include <iostream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{


    ui->setupUi(this);
    //Type Of Ciphers COMBOBOX
    ui->cB_TypeOfCiphers->addItem("Caesar");
    ui->cB_TypeOfCiphers->addItem("Vignere");


    //Buttons >> e <<
    connect(ui->pb_encrypt,&QPushButton::clicked,this,&MainWindow::encrypt);
    connect(ui->pb_decrypt,&QPushButton::clicked,this,&MainWindow::decrypt);

    //Cipher Configuration widgets for Caesar and Vignere
    widgetCaesarCypher = new WidgetCaesarCypher(this);
    widgetVignereCypher = new WidgetVignereCypher(this);

    ui->stackedWidget->addWidget(widgetCaesarCypher);
    ui->stackedWidget->addWidget(widgetVignereCypher);

    ui->stackedWidget->setCurrentWidget(widgetCaesarCypher);

    //Conecta o comboBox TypeOfCipher com os widgets para os Cipher
    connect(ui->cB_TypeOfCiphers, QOverload<int>::of(&QComboBox::currentIndexChanged),
                this, &MainWindow::setCypherConfigurationWidget);

    CipherCaesar cipher(1);
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
