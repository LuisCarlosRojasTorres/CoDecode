#include "WidgetVignereCypher.h"
#include "ui_WidgetVignereCypher.h"

WidgetVignereCypher::WidgetVignereCypher(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WidgetVignereCypher)
{
    ui->setupUi(this);
}

WidgetVignereCypher::~WidgetVignereCypher()
{
    delete ui;
}
