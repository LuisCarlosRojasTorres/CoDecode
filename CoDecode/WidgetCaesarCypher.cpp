#include "WidgetCaesarCypher.h"
#include "ui_WidgetCaesarCypher.h"

WidgetCaesarCypher::WidgetCaesarCypher(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WidgetCaesarCypher)
{
    ui->setupUi(this);
}

WidgetCaesarCypher::~WidgetCaesarCypher()
{
    delete ui;
}
