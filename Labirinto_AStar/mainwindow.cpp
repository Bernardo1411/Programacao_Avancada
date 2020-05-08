#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "labirinto.h"

#include <QFileDialog>
#include <QMessageBox>
#include <chrono>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    status = new QLabel("");
    statusBar()->addWidget(status);

    ui->tableWidget->setStyleSheet("QHeaderView::section {background-color:lightgray}");

    ui->radioButton->setChecked(true);

    redefinir_tabela();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_tableWidget_cellDoubleClicked(int row, int column)
{
    if (labirinto.celulaLivre(Coord(row, column))) {
        if (ui->radioButton->isChecked()) {
            labirinto.setOrigem(Coord(row, column));
            ui->radioButton_2->setChecked(true);
        }
        else if (ui->radioButton_2->isChecked()) {
            labirinto.setDestino(Coord(row, column));
            ui->radioButton->setChecked(true);
        }
        redefinir_tabela();
        status->setText("");
    }
    else {
        return;
    }
}

void MainWindow::on_actionLer_triggered()
{
    QString filename = QFileDialog::getOpenFileName();
    if (!labirinto.ler(filename.toStdString())) {
        QMessageBox erro;
        erro.setText("erro na leitura do arquivo " + filename);
        erro.exec();
    }
    else {
        redefinir_tabela();
    }
}

void MainWindow::on_actionSalvar_triggered()
{
    if (!labirinto.empty()) {
        QString filename = QFileDialog::getOpenFileName();
        if (!labirinto.salvar(filename.toStdString())) {
            QMessageBox erro;
            erro.setText("erro na escrita do arquivo " + filename);
            erro.exec();
        }
    }
    else {
        QMessageBox erro;
        erro.setText("erro: mapa vazio");
        erro.exec();
    }
}

void MainWindow::on_actionGerar_triggered()
{
    if (!labirinto.gerar()) {
        QMessageBox erro;
        erro.setText("erro na geracao do mapa");
        erro.exec();
    }
    else {
        redefinir_tabela();
    }
}

void MainWindow::on_actionSair_triggered()
{
    QCoreApplication::quit();
}

void MainWindow::on_actionCalcular_triggered()
{
    if (labirinto.empty()) {
        QMessageBox erro;
        erro.setText("erro: mapa vazio");
        erro.exec();
    }
    else if (!labirinto.origDestDefinidos()){
        QMessageBox erro;
        erro.setText("erro: origem e destino nao definidos");
        erro.exec();
    }
    else {
        int NN;
        int NA;
        int NF;

        chrono::steady_clock::time_point t0 = chrono::steady_clock::now();

        double comprimento = labirinto.calculaCaminho(NN, NA, NF);

        chrono::steady_clock::time_point t1 = chrono::steady_clock::now();
        chrono::duration<double> dt = chrono::duration_cast<chrono::duration<double>>(t1 - t0);
        double dt_ms = 1000 * dt.count();

        if (comprimento > 0.0) {
            redefinir_tabela();
            status->setText(QString::number(comprimento));
            QMessageBox resultado;
            resultado.setText("caminho encontrado!\nnumero de nos em aberto: "
                              + QString::number(NA)
                              + "\nnumero de nos em fechado: "
                              + QString::number(NF)
                              + "\ntempo de execucao: "
                              + QString::number(dt_ms));
            resultado.exec();
        }
        else {
            QMessageBox resultado;
            resultado.setText("caminho nao encontrado!\nnumero de nos em aberto: "
                              + QString::number(NA)
                              + "\nnumero de nos em fechado: "
                              + QString::number(NF)
                              + "\ntempo de execucao: "
                              + QString::number(dt_ms));
            resultado.exec();
        }
    }
}

void MainWindow::on_actionLimpar_triggered()
{
    labirinto.limpaCaminho();
    redefinir_tabela();
    status->setText("");
}

void MainWindow::redefinir_tabela() {
    ui->tableWidget->clear();
    ui->tableWidget->setRowCount(labirinto.getNumLin());
    ui->tableWidget->setColumnCount(labirinto.getNumCol());
    for (int i=0; i<ui->tableWidget->rowCount(); i++) {
        for (int j=0; j<ui->tableWidget->columnCount(); j++) {
            QLabel* prov = new QLabel("");
            prov->setAlignment(Qt::AlignCenter);
            ui->tableWidget->setCellWidget(i, j, prov);

            if (labirinto.at(i, j) == EstadoCel::LIVRE) {
                ui->tableWidget->cellWidget(i, j)->setStyleSheet("background: white");
                prov->setText("");
            }

            else if (labirinto.at(i, j) == EstadoCel::OBSTACULO) {
                ui->tableWidget->cellWidget(i, j)->setStyleSheet("background: black");
                prov->setText("");
            }

            if (labirinto.at(i, j) == EstadoCel::CAMINHO) {
                ui->tableWidget->cellWidget(i, j)->setStyleSheet("background: white");
                prov->setText("X");
            }

            else if (labirinto.at(i, j) == EstadoCel::ORIGEM) {
                ui->tableWidget->cellWidget(i, j)->setStyleSheet("background: yellow");
                prov->setText("O");
            }

            else if (labirinto.at(i, j) == EstadoCel::DESTINO) {
                ui->tableWidget->cellWidget(i, j)->setStyleSheet("background: green");
                prov->setText("D");
            }
        }
    }
    status->setText("");
}
