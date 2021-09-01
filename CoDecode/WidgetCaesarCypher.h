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

    int getCurrentIndex();

public slots:
    void setCurrentIndex(int currentIndex);

signals:
    void valueChanged(int currentIndex);

private:
    Ui::WidgetCaesarCypher *ui;
    int currentIndex;

};

#endif // WIDGETCAESARCYPHER_H
