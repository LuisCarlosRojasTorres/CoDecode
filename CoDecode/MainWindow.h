#ifndef MAINWINDOW_H
#define MAINWINDOW_H

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
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QWidget *widgetCaesarCypher;
    QWidget *widgetVignereCypher;


    QString message,code;
};
#endif // MAINWINDOW_H
