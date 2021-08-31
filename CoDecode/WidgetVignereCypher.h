#ifndef WIDGETVIGNERECYPHER_H
#define WIDGETVIGNERECYPHER_H

#include <QWidget>

namespace Ui {
class WidgetVignereCypher;
}

class WidgetVignereCypher : public QWidget
{
    Q_OBJECT

public:
    explicit WidgetVignereCypher(QWidget *parent = nullptr);
    ~WidgetVignereCypher();

private:
    Ui::WidgetVignereCypher *ui;
};

#endif // WIDGETVIGNERECYPHER_H
