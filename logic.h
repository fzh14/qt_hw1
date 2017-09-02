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
        for(int i=0;i<9;i++)
            for(int j=0;j<9;j++)
                for(int k=0;k<10;k++){
                    grid_num[i][j][k]=0;
                }
        vector.clear();
        undo_vector.clear();
    }

    void setStage(int);
    int matrix[9][9];
    int initial[9][9];//initial has value=1, blank=0
    int label[9][9];
    bool check();

    //operation log vector
    QVector<int*> vector;
    QVector<int*> undo_vector;
    //void update_value();
    int grid_num[9][9][10];
    void grid_clear(){
        for(int i=0;i<9;i++)
            for(int j=0;j<9;j++){
                if(initial[i][j]==0){
                    matrix[i][j]=-1;
                }
                for(int k=0;k<10;k++)
                    grid_num[i][j][k] = 0;
            }
    }
};

#endif // LOGIC_H
