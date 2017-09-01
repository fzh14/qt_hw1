#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDateTime>
#include <QTimer>
#include <QTime>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void updateTime();
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_num1_clicked();

    void on_num2_clicked();

    void on_num3_clicked();

    void on_num4_clicked();

    void on_num5_clicked();

    void on_num6_clicked();

    void on_num7_clicked();

    void on_num8_clicked();

    void on_num9_clicked();

    void on_button_lab_clicked();

    void on_button_del_clicked();

    void on_stage1_clicked();

    void on_stage2_clicked();

    void on_undo_clicked();

    void on_stage3_clicked();

    void on_stage4_clicked();

    void on_stage6_clicked();

    void on_stage5_clicked();

    void on_stage7_clicked();

    void on_stage8_clicked();

    void on_stage9_clicked();

    void on_nextdo_clicked();

private:
    Ui::MainWindow *ui;
    QTimer * timer;      //定时器 每秒更新时间
    QTime * TimeRecord;  //记录时间
    bool isStart;        //记录是否已经开始计时
};

#endif // MAINWINDOW_H
