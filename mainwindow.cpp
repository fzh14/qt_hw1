#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtDebug>
#include <QVector>
#include <QPixmap>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->frame->hide();
    setWindowTitle("Sudo_FZH");
    QPixmap pix=QPixmap("/Users/ivanfzh/Desktop/qt_summer/week1/hw1/title.png");
    ui->title_label->setPixmap(pix);
    ui->title_label->show();
    isStart = false;     //初始为还未计时
    timer = new QTimer;  //初始化定时器
    TimeRecord = new QTime(0, 0, 0); //初始化时间
    ui->Timer->setDigitCount(8);
    ui->Timer->setSegmentStyle(QLCDNumber::Flat);
    ui->Timer->display(TimeRecord->toString("hh:mm:ss"));
    connect(timer,SIGNAL(timeout()),this,SLOT(updateTime()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateTime()
{
    *TimeRecord = TimeRecord->addSecs(1);
    ui->Timer->display(TimeRecord->toString("hh:mm:ss"));
}
//start/pause button
void MainWindow::on_pushButton_2_clicked()
{
    if(!isStart) //尚未开始 开始计时
    {
        timer->start(1000);
        ui->pushButton_2->setText("pause");
        ui->widget->show();
    }
    else //已经开始，暂停
    {
        timer->stop();
        ui->pushButton_2->setText("start");
        ui->widget->hide();
    }
    isStart = !isStart;
}
//replay button
void MainWindow::on_pushButton_clicked()
{
    //timer->stop();    //计时器停止
    TimeRecord->setHMS(0,0,0); //时间设为0
    ui->Timer->display(TimeRecord->toString("hh:mm:ss")); //显示00:00:00
    //isStart = false;
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            ui->widget->logic->label[i][j]=0;
            if (ui->widget->logic->initial[i][j]==0){
                ui->widget->logic->matrix[i][j]=-1;
            }
        }
    }
    ui->widget->logic->vector.clear();
    ui->widget->logic->undo_vector.clear();
    ui->widget->grid_num=0;
    ui->widget->chooseGrid=false;
    ui->widget->chooseNum=false;
    ui->widget->repaint();
}

void MainWindow::on_num1_clicked()
{
    int x = ui->widget->grid_x/60;
    int y = ui->widget->grid_y/60;
    if(ui->widget->logic->initial[y][x]==0){
        int *t = new int[3];
        t[0]=y;t[1]=x;t[2]=1;
        ui->widget->logic->vector.append(t);
        ui->widget->logic->undo_vector.clear();
        ui->widget->grid_num = 1;
        ui->widget->chooseNum = true;
        ui->widget->selectNum();
    }
    else{
        qDebug()<<"can't fill";
    }
}

void MainWindow::on_num2_clicked()
{
    int x = ui->widget->grid_x/60;
    int y = ui->widget->grid_y/60;
    if(ui->widget->logic->initial[y][x]==0){
        int *t = new int[3];
        t[0]=y;t[1]=x;t[2]=2;
        ui->widget->logic->vector.append(t);
        ui->widget->logic->undo_vector.clear();
        ui->widget->grid_num = 2;
        ui->widget->chooseNum = true;
        ui->widget->selectNum();
    }
    else{
        qDebug()<<"can't fill";
    }
}

void MainWindow::on_num3_clicked()
{
    int x = ui->widget->grid_x/60;
    int y = ui->widget->grid_y/60;
    if(ui->widget->logic->initial[y][x]==0){
        int *t = new int[3];
        t[0]=y;t[1]=x;t[2]=3;
        ui->widget->logic->vector.append(t);
        ui->widget->logic->undo_vector.clear();
        ui->widget->grid_num = 3;
        ui->widget->chooseNum = true;
        ui->widget->selectNum();
    }
    else{
        qDebug()<<"can't fill";
    }
}

void MainWindow::on_num4_clicked()
{
    int x = ui->widget->grid_x/60;
    int y = ui->widget->grid_y/60;
    if(ui->widget->logic->initial[y][x]==0){
        int *t = new int[3];
        t[0]=y;t[1]=x;t[2]=4;
        ui->widget->logic->vector.append(t);
        ui->widget->logic->undo_vector.clear();
        ui->widget->grid_num = 4;
        ui->widget->chooseNum = true;
        ui->widget->selectNum();
    }
    else{
        qDebug()<<"can't fill";
    }
}

void MainWindow::on_num5_clicked()
{
    int x = ui->widget->grid_x/60;
    int y = ui->widget->grid_y/60;
    if(ui->widget->logic->initial[y][x]==0){
        int *t = new int[3];
        t[0]=y;t[1]=x;t[2]=5;
        ui->widget->logic->vector.append(t);
        ui->widget->logic->undo_vector.clear();
        ui->widget->grid_num = 5;
        ui->widget->chooseNum = true;
        ui->widget->selectNum();
    }
    else{
        qDebug()<<"can't fill";
    }
}

void MainWindow::on_num6_clicked()
{
    int x = ui->widget->grid_x/60;
    int y = ui->widget->grid_y/60;
    if(ui->widget->logic->initial[y][x]==0){
        int *t = new int[3];
        t[0]=y;t[1]=x;t[2]=6;
        ui->widget->logic->vector.append(t);
        ui->widget->logic->undo_vector.clear();
        ui->widget->grid_num = 6;
        ui->widget->chooseNum = true;
        ui->widget->selectNum();
    }
    else{
        qDebug()<<"can't fill";
    }
}

void MainWindow::on_num7_clicked()
{
    int x = ui->widget->grid_x/60;
    int y = ui->widget->grid_y/60;
    if(ui->widget->logic->initial[y][x]==0){
        int *t = new int[3];
        t[0]=y;t[1]=x;t[2]=7;
        ui->widget->logic->vector.append(t);
        ui->widget->logic->undo_vector.clear();
        ui->widget->grid_num = 7;
        ui->widget->chooseNum = true;
        ui->widget->selectNum();
    }
    else{
        qDebug()<<"can't fill";
    }
}

void MainWindow::on_num8_clicked()
{
    int x = ui->widget->grid_x/60;
    int y = ui->widget->grid_y/60;
    if(ui->widget->logic->initial[y][x]==0){
        int *t = new int[3];
        t[0]=y;t[1]=x;t[2]=8;
        ui->widget->logic->vector.append(t);
        ui->widget->logic->undo_vector.clear();
        ui->widget->grid_num = 8;
        ui->widget->chooseNum = true;
        ui->widget->selectNum();
    }
    else{
        qDebug()<<"can't fill";
    }
}

void MainWindow::on_num9_clicked()
{
    int x = ui->widget->grid_x/60;
    int y = ui->widget->grid_y/60;
    if(ui->widget->logic->initial[y][x]==0){
        int *t = new int[3];
        t[0]=y;t[1]=x;t[2]=9;
        ui->widget->logic->vector.append(t);
        ui->widget->logic->undo_vector.clear();
        ui->widget->grid_num = 9;
        ui->widget->chooseNum = true;
        ui->widget->selectNum();
    }
    else{
        qDebug()<<"can't fill";
    }
}

void MainWindow::on_button_lab_clicked()
{
    int x = ui->widget->grid_x/60;
    int y = ui->widget->grid_y/60;
    if(x>=0 && y>=0){
        int k = ui->widget->logic->label[y][x];
        if(k==0)
            ui->widget->logic->label[y][x]=1;
        else
            ui->widget->logic->label[y][x]=0;
    }
    ui->widget->repaint();
}

void MainWindow::on_button_del_clicked()
{
    int x = ui->widget->grid_x/60;
    int y = ui->widget->grid_y/60;

    if(ui->widget->logic->initial[y][x]==0){
        int *t = new int[3];
        t[0]=y;t[1]=x;t[2]=-2;
        ui->widget->logic->vector.append(t);
        ui->widget->logic->undo_vector.clear();
        ui->widget->chooseNum = false;
        ui->widget->selectNum();
    }
    //ui->widget->repaint();
}

void MainWindow::on_stage1_clicked()
{
    TimeRecord->setHMS(0,0,0); //时间设为0
    ui->Timer->display(TimeRecord->toString("hh:mm:ss")); //显示00:00:00
    timer->start(1000);
    isStart = true;
    ui->frame->show();
    ui->frame_2->hide();
    ui->widget->chooseGrid=false;
    ui->widget->chooseNum=false;
    ui->widget->logic->setStage(1);
}


void MainWindow::on_stage2_clicked()
{
    TimeRecord->setHMS(0,0,0); //时间设为0
    ui->Timer->display(TimeRecord->toString("hh:mm:ss")); //显示00:00:00
    timer->start(1000);
    isStart = true;
    ui->frame->show();
    ui->frame_2->hide();
    ui->widget->chooseGrid=false;
    ui->widget->chooseNum=false;
    ui->widget->logic->setStage(2);
}

void MainWindow::on_undo_clicked()
{
    if(ui->widget->logic->vector.length()-1>0){
        int *t = new int[3];
        t[0]=ui->widget->logic->vector.last()[0];
        t[1]=ui->widget->logic->vector.last()[1];
        t[2]=ui->widget->logic->vector.last()[2];
        ui->widget->logic->vector.remove(ui->widget->logic->vector.length()-1);
        ui->widget->logic->undo_vector.append(t);
        ui->widget->chooseGrid=false;
        ui->widget->chooseNum=false;
        qDebug()<<ui->widget->logic->vector.last()[0]<<" "<<ui->widget->logic->vector.last()[1]<<" "<<ui->widget->logic->vector.last()[2];
        ui->widget->repaint();
    }
    else{
        qDebug()<<"can't undo";
        QApplication::beep();
    }
}

void MainWindow::on_stage3_clicked()
{
    TimeRecord->setHMS(0,0,0); //时间设为0
    ui->Timer->display(TimeRecord->toString("hh:mm:ss")); //显示00:00:00
    timer->start(1000);
    isStart = true;
    ui->frame->show();
    ui->frame_2->hide();
    ui->widget->chooseGrid=false;
    ui->widget->chooseNum=false;
    ui->widget->logic->setStage(3);
}

void MainWindow::on_stage4_clicked()
{
    TimeRecord->setHMS(0,0,0); //时间设为0
    ui->Timer->display(TimeRecord->toString("hh:mm:ss")); //显示00:00:00
    timer->start(1000);
    isStart = true;
    ui->frame->show();
    ui->frame_2->hide();
    ui->widget->logic->setStage(4);
}

void MainWindow::on_stage6_clicked()
{
    TimeRecord->setHMS(0,0,0); //时间设为0
    ui->Timer->display(TimeRecord->toString("hh:mm:ss")); //显示00:00:00
    timer->start(1000);
    isStart = true;
    ui->frame->show();
    ui->frame_2->hide();
    ui->widget->logic->setStage(6);
}

void MainWindow::on_stage5_clicked()
{
    TimeRecord->setHMS(0,0,0); //时间设为0
    ui->Timer->display(TimeRecord->toString("hh:mm:ss")); //显示00:00:00
    timer->start(1000);
    isStart = true;
    ui->frame->show();
    ui->frame_2->hide();
    ui->widget->logic->setStage(5);
}

void MainWindow::on_stage7_clicked()
{
    TimeRecord->setHMS(0,0,0); //时间设为0
    ui->Timer->display(TimeRecord->toString("hh:mm:ss")); //显示00:00:00
    timer->start(1000);
    isStart = true;
    ui->frame->show();
    ui->frame_2->hide();
    ui->widget->logic->setStage(7);
}

void MainWindow::on_stage8_clicked()
{
    TimeRecord->setHMS(0,0,0); //时间设为0
    ui->Timer->display(TimeRecord->toString("hh:mm:ss")); //显示00:00:00
    timer->start(1000);
    isStart = true;
    ui->frame->show();
    ui->frame_2->hide();
    ui->widget->logic->setStage(8);
}

void MainWindow::on_stage9_clicked()
{
    TimeRecord->setHMS(0,0,0); //时间设为0
    ui->Timer->display(TimeRecord->toString("hh:mm:ss")); //显示00:00:00
    timer->start(1000);
    isStart = true;
    ui->frame->show();
    ui->frame_2->hide();
    ui->widget->logic->setStage(9);
}

void MainWindow::on_nextdo_clicked()
{
    if(ui->widget->logic->undo_vector.length()>0){
    int *t = new int[3];
    t[0]=ui->widget->logic->undo_vector.last()[0];
    t[1]=ui->widget->logic->undo_vector.last()[1];
    t[2]=ui->widget->logic->undo_vector.last()[2];
    ui->widget->logic->undo_vector.remove(ui->widget->logic->undo_vector.length()-1);
    ui->widget->logic->vector.append(t);
    ui->widget->chooseGrid=false;
    ui->widget->chooseNum=false;
    ui->widget->repaint();
    }
    else{
        qDebug()<<"can't cancel undo";
        QApplication::beep();
    }
}
