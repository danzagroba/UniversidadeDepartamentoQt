#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "adduniversidade.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    ,cont(1)
{
    ui->setupUi(this);
    connect(ui->IniciarButton, &QPushButton::clicked, this, &MainWindow::atualizarListaUniversidade);
    connect(ui->AdicionarButton, &QPushButton::clicked, this, &MainWindow::dialogoUniversidade);
    connect(ui->listWidget, &QListWidget::itemClicked, this, &MainWindow::SegundaLista);

    Universidade* u = new Universidade(cont++,"UTFPR");
    Departamento* d = new Departamento(1,"Eletronica UTFPR");
    u->setDepartamento(d);
    d = new Departamento(2,"Matematica UTFPR");
    u->setDepartamento(d);
    d = new Departamento(3,"Fisica UTFPR");
    u->setDepartamento(d);
    univ.push_back(u);

    u = new Universidade(cont++,"Princeton");
    d = new Departamento(1,"Matematica Princeton");
    u->setDepartamento(d);
    d = new Departamento(2,"Fisica Princeton");
    u->setDepartamento(d);
    univ.push_back(u);

    u = new Universidade(cont++,"Cambridge");
    d = new Departamento(1,"Matematica Cambridge");
    u->setDepartamento(d);
    d = new Departamento(2,"Fisica Cambridge");
    u->setDepartamento(d);
    univ.push_back(u);
}

MainWindow::~MainWindow()
{
    delete ui;
    for(vector<Universidade*>::iterator it = univ.begin(); it != univ.end();)
    {
        delete *it;
        it = univ.erase(it);
    }
}


void MainWindow::atualizarListaUniversidade()
{
    ui->listWidget->clear();
    for(vector<Universidade*>::iterator it = univ.begin(); it != univ.end(); it++)
    {
        QString aux = QString::fromStdString((*it)->getNome());
        ui->listWidget->addItem(aux);
    }
}

void MainWindow::dialogoUniversidade()
{
    AddUniversidade *au = new AddUniversidade(this);
    au->exec();
}

void MainWindow::adicionarUniversidade(const char* n)
{
    Universidade* u = new Universidade(cont++,n);
    univ.push_back(u);
}

void MainWindow::SegundaLista(QListWidgetItem *item)
{
    ui->listWidget_2->clear();
    string nome = item->text().toStdString();
    std::vector<Universidade*>::iterator IteradorUniv = localizarUniversidade(nome);
    if(IteradorUniv == univ.end())
    {
        return;
    }
    std::vector<Departamento*>::iterator IteradorDept = (*IteradorUniv)->getDepartamentosBegin();
    while (IteradorDept!= (*IteradorUniv)->getDepartamentosEnd())
    {
        QString aux = QString::fromStdString((*IteradorDept)->getNome());

        ui->listWidget_2->addItem(aux);
        IteradorDept++;
    }
}

std::vector<Universidade*>::iterator MainWindow::localizarUniversidade(const std::string& nome)
{
    for (std::vector<Universidade*>::iterator it = univ.begin(); it != univ.end(); it++) {
        if ((*it)->getNome() == nome) {
            return it;
        }
    }
    return univ.end();
}
