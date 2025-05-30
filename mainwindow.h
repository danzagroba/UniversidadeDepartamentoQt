#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "Universidade.h"
#include "Departamento.h"
#include <QMainWindow>
#include <QListWidgetItem>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void adicionarUniversidade(const char* n);


private:
    Ui::MainWindow *ui;
    std::vector<Universidade*> univ;
    int cont;

    void dialogoUniversidade();
    void atualizarListaUniversidade();

    void SegundaLista(QListWidgetItem *item);
    std::vector<Universidade*>::iterator localizarUniversidade(const std::string& nome);

};
#endif // MAINWINDOW_H
