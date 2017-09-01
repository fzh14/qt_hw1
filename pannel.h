#ifndef PANNEL_H
#define PANNEL_H

#include <QWidget>
#include <QKeyEvent>
#include "logic.h"

class pannel:public QWidget
{
    Q_OBJECT

public:
    explicit pannel(QWidget *parent=0);

    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent *ev);

    //void mouseReleaseEvent(QMouseEvent *ev);
    //void mouseMoveEvent(QMouseEvent *ev);

    void selectGrid(){
        chooseNum = false;
        repaint();
    }
    void selectNum(){
        chooseGrid = false;
        repaint();
    }
    Logic *logic;
    bool chooseGrid;
    bool chooseNum;
    int grid_x;
    int grid_y;
    int grid_num;
};

#endif // PANNEL_H
