#ifndef LOGIC_H
#define LOGIC_H
#include <QVector>

class Logic
{
public:
    Logic();

    void regulation(int m[9][9]){
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                label[i][j]=0;
                matrix[j][i] = m[j][i];
                if (matrix[j][i] == -1){
                    initial[j][i] = 0;
                }
                else{
                    initial[j][i] = 1;
                }
            }
        }
    }

    void setStage(int);
    int matrix[9][9];
    int initial[9][9];
    int label[9][9];
    bool check();

    //[step][y,x,ex-value]
    int undo[10][3];
    void addlog(int* t){
        for(int i=8;i>0;i--){
            for(int j=0;j<3;j++){
                undo[i][j]=undo[i-1][j];
            }
        }
        undo[0][0]=t[0];
        undo[0][1]=t[1];
        undo[0][2]=t[2];
        for(int i=0;i<10;i++){
            for(int j=0;j<3;j++){
                predo[i][j]=-1;
            }
        }
    }
    //[step][y,x,value]
    int predo[10][3];
    QVector<int*> vector;
};

#endif // LOGIC_H
