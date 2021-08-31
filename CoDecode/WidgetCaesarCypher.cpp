#include "WidgetCaesarCypher.h"
#include "ui_WidgetCaesarCypher.h"

WidgetCaesarCypher::WidgetCaesarCypher(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WidgetCaesarCypher)
{
    ui->setupUi(this);

    QStringList keys{"0","1","2","3","4","5","6","7","8","9","10","11","12","13",
                     "14","15","16","17","18","19","20","21","22","23","24","25"};

    ui->cB_key->addItems(keys);

}

WidgetCaesarCypher::~WidgetCaesarCypher()
{
    delete ui;
}
