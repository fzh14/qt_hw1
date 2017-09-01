#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->frame->hide();
    setWindowTitle("Sudo_FZH");
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
    for(int i=0;i<10;i++){
        for(int j=0;j<3;j++)
            ui->widget->logic->undo[i][j]=-1;
    }
    ui->widget->grid_num=0;
    ui->widget->chooseGrid=false;
    ui->widget->chooseNum=false;
    ui->widget->repaint();
}

void MainWindow::on_num1_clicked()
{
    int x = ui->widget->grid_x/60;
    int y = ui->widget->grid_y/60;
    if(ui->widget->chooseGrid == true){
        int p_value = ui->widget->logic->matrix[y][x];
        int t[3]={y,x,p_value};
        ui->widget->logic->addlog(t);
        ui->widget->logic->matrix[y][x] = 1;
        ui->widget->grid_num = 1;
        ui->widget->chooseNum = true;
        ui->widget->selectNum();
    }
    else if(ui->widget->logic->initial[y][x]==0){
        int p_value = ui->widget->logic->matrix[y][x];
        int t[3]={y,x,p_value};
        ui->widget->logic->addlog(t);
        ui->widget->logic->matrix[y][x] = 1;
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
    if(ui->widget->chooseGrid == true){
        int p_value = ui->widget->logic->matrix[y][x];
        int t[3]={y,x,p_value};
        ui->widget->logic->addlog(t);
        ui->widget->logic->matrix[y][x] = 2;
        ui->widget->grid_num = 2;
        ui->widget->chooseNum = true;
        ui->widget->selectNum();
    }
    else if(ui->widget->logic->initial[y][x]==0){
        int p_value = ui->widget->logic->matrix[y][x];
        int t[3]={y,x,p_value};
        ui->widget->logic->addlog(t);
        ui->widget->logic->matrix[y][x] = 2;
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
    if(ui->widget->chooseGrid == true){
        int p_value = ui->widget->logic->matrix[y][x];
        int t[3]={y,x,p_value};
        ui->widget->logic->addlog(t);
        ui->widget->logic->matrix[y][x] = 3;
        ui->widget->grid_num = 3;
        ui->widget->chooseNum = true;
        ui->widget->selectNum();
    }
    else if(ui->widget->logic->initial[y][x]==0){
        int p_value = ui->widget->logic->matrix[y][x];
        int t[3]={y,x,p_value};
        ui->widget->logic->addlog(t);
        ui->widget->logic->matrix[y][x] = 3;
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
    if(ui->widget->chooseGrid == true){
        int p_value = ui->widget->logic->matrix[y][x];
        int t[3]={y,x,p_value};
        ui->widget->logic->addlog(t);
        ui->widget->logic->matrix[y][x] = 4;
        ui->widget->grid_num = 4;
        ui->widget->chooseNum = true;
        ui->widget->selectNum();
    }
    else if(ui->widget->logic->initial[y][x]==0){
        int p_value = ui->widget->logic->matrix[y][x];
        int t[3]={y,x,p_value};
        ui->widget->logic->addlog(t);
        ui->widget->logic->matrix[y][x] = 4;
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
    if(ui->widget->chooseGrid == true){
        int p_value = ui->widget->logic->matrix[y][x];
        int t[3]={y,x,p_value};
        ui->widget->logic->addlog(t);
        ui->widget->logic->matrix[y][x] = 5;
        ui->widget->grid_num = 5;
        ui->widget->chooseNum = true;
        ui->widget->selectNum();
    }
    else if(ui->widget->logic->initial[y][x]==0){
        int p_value = ui->widget->logic->matrix[y][x];
        int t[3]={y,x,p_value};
        ui->widget->logic->addlog(t);
        ui->widget->logic->matrix[y][x] = 5;
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
    if(ui->widget->chooseGrid == true){
        int p_value = ui->widget->logic->matrix[y][x];
        int t[3]={y,x,p_value};
        ui->widget->logic->addlog(t);
        ui->widget->logic->matrix[y][x] = 6;
        ui->widget->grid_num = 6;
        ui->widget->chooseNum = true;
        ui->widget->selectNum();
    }
    else if(ui->widget->logic->initial[y][x]==0){
        int p_value = ui->widget->logic->matrix[y][x];
        int t[3]={y,x,p_value};
        ui->widget->logic->addlog(t);
        ui->widget->logic->matrix[y][x] = 6;
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
    if(ui->widget->chooseGrid == true){
        int p_value = ui->widget->logic->matrix[y][x];
        int t[3]={y,x,p_value};
        ui->widget->logic->addlog(t);
        ui->widget->logic->matrix[y][x] = 7;
        ui->widget->grid_num = 7;
        ui->widget->chooseNum = true;
        ui->widget->selectNum();
    }
    else if(ui->widget->logic->initial[y][x]==0){
        int p_value = ui->widget->logic->matrix[y][x];
        int t[3]={y,x,p_value};
        ui->widget->logic->addlog(t);
        ui->widget->logic->matrix[y][x] = 7;
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
    if(ui->widget->chooseGrid == true){
        int p_value = ui->widget->logic->matrix[y][x];
        int t[3]={y,x,p_value};
        ui->widget->logic->addlog(t);
        ui->widget->logic->matrix[y][x] = 8;
        ui->widget->grid_num = 8;
        ui->widget->chooseNum = true;
        ui->widget->selectNum();
    }
    else if(ui->widget->logic->initial[y][x]==0){
        int p_value = ui->widget->logic->matrix[y][x];
        int t[3]={y,x,p_value};
        ui->widget->logic->addlog(t);
        ui->widget->logic->matrix[y][x] = 8;
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
    if(ui->widget->chooseGrid == true){
        int p_value = ui->widget->logic->matrix[y][x];
        int t[3]={y,x,p_value};
        ui->widget->logic->addlog(t);
        ui->widget->logic->matrix[y][x] = 9;
        ui->widget->grid_num = 9;
        ui->widget->chooseNum = true;
        ui->widget->selectNum();
    }
    else if(ui->widget->logic->initial[y][x]==0){
        int p_value = ui->widget->logic->matrix[y][x];
        int t[3]={y,x,p_value};
        ui->widget->logic->addlog(t);
        ui->widget->logic->matrix[y][x] = 9;
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
    if(x>=0 && y>=0){
        int k = ui->widget->logic->initial[y][x];
        if(k==0){
            int p_value = ui->widget->logic->matrix[y][x];
            int t[3]={y,x,p_value};
            ui->widget->logic->addlog(t);
            ui->widget->logic->matrix[y][x]=-1;
        }
        else
            qDebug()<<"can't delete";
    }
    ui->widget->repaint();
}

void MainWindow::on_stage1_clicked()
{
    TimeRecord->setHMS(0,0,0); //时间设为0
    ui->Timer->display(TimeRecord->toString("hh:mm:ss")); //显示00:00:00
    timer->start(1000);
    isStart = true;
    ui->frame->show();
    ui->frame_2->hide();
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
    ui->widget->logic->setStage(2);
}

void MainWindow::on_undo_clicked()
{
    int temp[3];
    for(int i=0;i<3;i++)
        temp[i]=ui->widget->logic->undo[0][i];

    if(temp[0]!=-1 && temp[1]!=-1){
        for(int i=0;i<9;i++){
            for(int j=0;j<3;j++)
                ui->widget->logic->undo[i][j]=ui->widget->logic->undo[i+1][j];
        }
        for(int i=8;i>0;i--){
            for(int j=0;j<3;j++){
                ui->widget->logic->predo[i][j]=ui->widget->logic->predo[i-1][j];
            }
        }
        ui->widget->logic->predo[0][0]=temp[0];
        ui->widget->logic->predo[0][1]=temp[1];
        ui->widget->logic->predo[0][2]=ui->widget->logic->matrix[temp[0]][temp[1]];

        ui->widget->logic->matrix[temp[0]][temp[1]] = temp[2];
        ui->widget->repaint();
    }
    else{
        qDebug()<<"can't undo! no log!";
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
    int temp[3];
    for(int i=0;i<3;i++)
        temp[i]=ui->widget->logic->predo[0][i];

    if(temp[0]!=-1 && temp[1]!=-1){
        for(int i=0;i<9;i++){
            for(int j=0;j<3;j++)
                ui->widget->logic->predo[i][j]=ui->widget->logic->predo[i+1][j];
        }
        for(int i=8;i>0;i--){
            for(int j=0;j<3;j++){
                ui->widget->logic->undo[i][j]=ui->widget->logic->undo[i-1][j];
            }
        }
        ui->widget->logic->undo[0][0]=temp[0];
        ui->widget->logic->undo[0][1]=temp[1];
        ui->widget->logic->undo[0][2]=ui->widget->logic->matrix[temp[0]][temp[1]];

        ui->widget->logic->matrix[temp[0]][temp[1]] = temp[2];
        ui->widget->repaint();
    }
    else{
        qDebug()<<"can't cancel undo!";
    }
}
