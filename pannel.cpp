#include "pannel.h"
#include <QApplication>
#include <QPainter>
#include <QString>
#include <QtDebug>
#include <QtWidgets/qframe.h>
#include <string>


pannel::pannel(QWidget *parent):QWidget(parent),logic(new Logic())
{
    pannel::chooseGrid = false;
    pannel::chooseNum = false;
    pannel::grid_x = -60;
    pannel::grid_y = -60;
    pannel::grid_num = 0;
}

void pannel::paintEvent(QPaintEvent *event)
{
    QPainter p(this);
    logic->grid_clear();
    if (chooseNum == true){
        qDebug()<<"GridNum:"<<grid_num;
        p.setPen(Qt::white);
        p.setBrush(Qt::yellow);
        for(int i=0;i<9;i++)
            for(int j=0;j<9;j++){
                if(grid_num == logic->matrix[j][i]){
                p.drawRect(i*60+10,j*60+10,40,40);
                }
            }
    }

        p.setPen(Qt::black);
        QPen pen=p.pen();
        pen.setWidth(4);
        p.setPen(pen);
        p.drawLine(2,0,2,540);
        p.drawLine(182,0,182,540);
        p.drawLine(362,0,362,540);
        p.drawLine(538,0,538,540);
        p.drawLine(0,2,540,2);
        p.drawLine(0,182,540,182);
        p.drawLine(0,362,540,362);
        p.drawLine(0,538,540,538);
        pen.setWidth(2);
        p.setPen(pen);
        for(int i=0;i<=540;i=i+60){
            p.drawLine(i,0,i,540);
            p.drawLine(0,i,540,i);
        }
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if (logic->matrix[i][j] !=-1){
                    QFont font("Helvetica");
                    font.setPixelSize(40);
                    p.setFont(font);
                    if(logic->initial[i][j]==1){
                        p.setPen(Qt::black);
                        QString s = QString::number(logic->matrix[i][j]);
                        p.drawText(j*60+20,i*60+20,60,60,0,s);
                    }
                    else{
                        p.setPen(Qt::darkGray);
                    }
                    /*QString s = QString::number(logic->matrix[i][j]);
                    p.drawText(j*60+20,i*60+20,60,60,0,s);*/
                }
                if(logic->label[i][j] != 0){
                    p.setPen(Qt::red);
                    p.setBrush(Qt::red);
                    p.drawEllipse(j*60+51,i*60+5,6,6);
                }
            }
        }
        for(int i=0;i<logic->vector.length();i++){
            int temp_y = logic->vector.at(i)[0];
            int temp_x = logic->vector.at(i)[1];
            int temp_value = logic->vector.at(i)[2];
            if(temp_value == -2){
                for(int p=0;p<10;p++){
                    logic->grid_num[temp_y][temp_x][p]=0;
                }
            }
            else{
                logic->grid_num[temp_y][temp_x][temp_value] = 1;
            }
        }
        for(int i=0;i<9;i++)
            for(int j=0;j<9;j++){
                if(logic->initial[i][j]==0){
                    int count = 0;
                    for(int k=0;k<10;k++){
                        count += logic->grid_num[i][j][k];
                    }
                    if(count == 1){
                        for(int k=0;k<10;k++){
                            if(logic->grid_num[i][j][k]==1){
                                if(k==grid_num && chooseNum==true){
                                p.setPen(Qt::white);
                                p.setBrush(Qt::yellow);
                                p.drawRect(j*60+10,i*60+10,40,40);
                                }
                                QFont font("Helvetica");
                                font.setPixelSize(40);
                                p.setFont(font);
                                p.setPen(Qt::darkGray);
                                QString s = QString::number(k);
                                p.drawText(j*60+20,i*60+20,60,60,0,s);
                                logic->matrix[i][j]=k;
                            }
                        }
                    }
                    else if(count >1){
                        logic->matrix[i][j]=-1;
                        QFont font("Helvetica");
                        font.setPixelSize(15);
                        p.setFont(font);
                        p.setPen(Qt::darkGray);
                        for(int k=0;k<10;k++){
                            if(logic->grid_num[i][j][k]==1){
                                QString s = QString::number(k);
                                p.drawText(j*60+(0.5+((k-1)%3))*18,i*60+18*(0.5+((k-1)/3)),18,18,0,s);
                            }
                        }
                    }
                }
            }

        if (chooseGrid == true){
            int num_x = (int)grid_x/60;
            int num_y = (int)grid_y/60;
            p.setPen(Qt::blue);
            QPen pen=p.pen();
            pen.setWidth(5);
            p.setPen(pen);
            p.drawLine(num_x*60,0,num_x*60,540);
            p.drawLine(num_x*60+60,0,num_x*60+60,540);
            p.drawLine(0,num_y*60,540,num_y*60);
            p.drawLine(0,num_y*60+60,540,num_y*60+60);
        }

        if(logic->check()==true){
            QFont font("Helvetica");
            font.setPixelSize(100);
            p.setFont(font);
            p.setPen(Qt::red);
            p.drawText(150,200,200,200,0,"YES");
            QApplication::beep();
        }
        //p.setBrush(Qt::black);
        //p.drawEllipse(0, 0, extent, extent);
        QWidget::paintEvent(event);
}

void pannel::mousePressEvent(QMouseEvent *ev){
    qDebug()<<"mouse"<<ev->x()<<"&&"<<ev->y();
    grid_x = (int)ev->x();
    grid_y = (int)ev->y();
    int num_x = (int)grid_x/60;
    int num_y = (int)grid_y/60;
    if(logic->matrix[num_y][num_x] != -1){
        chooseNum = true;
        grid_num = logic->matrix[num_y][num_x];
        selectNum();
    }
    else{
    chooseGrid = true;
    selectGrid();
    }
}
