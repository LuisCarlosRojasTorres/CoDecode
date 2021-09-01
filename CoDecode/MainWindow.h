#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "CipherCaesar.h"
#include <QMainWindow>

class WidgetCaesarCypher;
class WidgetVignereCypher;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
public slots:
    void encrypt();
    void decrypt();
    void setCypherConfigurationWidget(int index);

    void setCaesarCipher(int shift);

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    WidgetCaesarCypher *widgetCaesarCypher;
    WidgetVignereCypher *widgetVignereCypher;

    QString message,code;

    CipherCaesar *cipher;
};
#endif // MAINWINDOW_H
