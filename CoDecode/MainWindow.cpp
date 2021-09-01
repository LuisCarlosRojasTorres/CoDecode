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
    setWindowTitle("CoDeco - RedTower2021");
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

    cipherCaesar = new CipherCaesar();
    //Conecta o comboBox TypeOfCipher com os widgets para os Cipher
    connect(ui->cB_TypeOfCiphers, QOverload<int>::of(&QComboBox::currentIndexChanged),
                this, &MainWindow::setCypherConfigurationWidget);

    connect(widgetCaesarCypher, &WidgetCaesarCypher::valueChanged,
                this, &MainWindow::setCaesarCipher);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::decrypt()
{
    code = ui->txt_Code->toPlainText();
    message = cipherCaesar->decrypt(code);
    ui->txt_Message->setPlainText(message);
}

void MainWindow::encrypt()
{
    message = ui->txt_Message->toPlainText();
    code = cipherCaesar->encrypt(message);
    ui->txt_Code->setPlainText(code);
}


void MainWindow::setCypherConfigurationWidget(int index)
{
    switch(index){
    case 0: //Caesar
        std::cout<<"Set Caesar Cypher"<<std::endl;
        ui->stackedWidget->setCurrentWidget(widgetCaesarCypher);
        typeOfCipher = TypeOfCipher::Caesar;
        break;
    case 1: //Vignere
        std::cout<<"Set Vignere Cypher"<<std::endl;
        ui->stackedWidget->setCurrentWidget(widgetVignereCypher);
        typeOfCipher = TypeOfCipher::Vignere;
        break;
    default:
        break;
    }

}

void MainWindow::setCaesarCipher(int shift)
{
/*
    When the shift is changed CODECO will encrypt or decrypt based on
    which plainTextEdit is empty. In case that both plainTextEdit are not empty
    the program will encrypt by default.
*/
    cipherCaesar->setShift(shift);
    std::cout << "MainWindow::setCaesarCipher" << std::endl;

    bool codeIsEmpty = ui->txt_Code->toPlainText().isEmpty();
    bool messageIsEmpty = ui->txt_Message->toPlainText().isEmpty();

    if( (!codeIsEmpty && !messageIsEmpty)){
        encrypt();
    }
    else if(codeIsEmpty){
        encrypt();
    }
    else if(messageIsEmpty){
        decrypt();
    }
}
