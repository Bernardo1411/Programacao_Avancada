#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include "labirinto.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_tableWidget_cellDoubleClicked(int row, int column);

    void on_actionLer_triggered();

    void on_actionSalvar_triggered();

    void on_actionGerar_triggered();

    void on_actionSair_triggered();

    void on_actionCalcular_triggered();

    void on_actionLimpar_triggered();

private:
    Ui::MainWindow *ui;

    Labirinto labirinto;

    QLabel* status;

    void redefinir_tabela();
};

#endif // MAINWINDOW_H
