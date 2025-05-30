#ifndef ADDUNIVERSIDADE_H
#define ADDUNIVERSIDADE_H
#include "mainwindow.h"
#include <QDialog>

namespace Ui {
class AddUniversidade;
}

class AddUniversidade : public QDialog
{
    Q_OBJECT

public:
    AddUniversidade(MainWindow *mw);
    ~AddUniversidade();

private:
    Ui::AddUniversidade *ui;
    MainWindow *MW;
    void MandarUniversidade();
};

#endif // ADDUNIVERSIDADE_H
