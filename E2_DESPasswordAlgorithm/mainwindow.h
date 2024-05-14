#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_B1_clicked();

    void on_B2_clicked();

    void on_B3_clicked();

    void on_B4_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
