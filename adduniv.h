#ifndef ADDUNIV_H
#define ADDUNIV_H

#include <QDialog>

namespace Ui {
class AddUniv;
}

class AddUniv : public QDialog
{
    Q_OBJECT

public:
    explicit AddUniv(QWidget *parent = nullptr);
    ~AddUniv();

private:
    Ui::AddUniv *ui;
};

#endif // ADDUNIV_H
