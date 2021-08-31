#ifndef WIDGETCAESARCYPHER_H
#define WIDGETCAESARCYPHER_H

#include <QWidget>

namespace Ui {
class WidgetCaesarCypher;
}

class WidgetCaesarCypher : public QWidget
{
    Q_OBJECT

public:
    explicit WidgetCaesarCypher(QWidget *parent = nullptr);
    ~WidgetCaesarCypher();

private:
    Ui::WidgetCaesarCypher *ui;
};

#endif // WIDGETCAESARCYPHER_H
