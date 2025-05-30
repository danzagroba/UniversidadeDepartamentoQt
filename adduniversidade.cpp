#include "adduniversidade.h"
#include "ui_adduniversidade.h"

AddUniversidade::AddUniversidade(MainWindow *mw):
    ui(new Ui::AddUniversidade)
    , MW(mw)
{
    ui->setupUi(this);

    connect(ui->pushButton, &QPushButton::clicked, this, &AddUniversidade::MandarUniversidade);
}

AddUniversidade::~AddUniversidade()
{
    delete ui;
}

void AddUniversidade::MandarUniversidade()
{
    if(ui->textEdit->toPlainText().toStdString().empty() == false)
    {
        MW->adicionarUniversidade(ui->textEdit->toPlainText().toStdString().c_str());
    }
    this->close();
}


