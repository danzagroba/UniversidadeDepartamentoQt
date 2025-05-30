#include "adduniv.h"
#include "./ui_adduniv.h"

AddUniv::AddUniv(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddUniv)
{
    ui->setupUi(this);
}

AddUniv::~AddUniv()
{
    delete ui;
}
