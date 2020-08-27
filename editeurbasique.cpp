#include "editeurbasique.h"
#include "ui_editeurbasique.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushQuitter_clicked()
{
    this->close();
}

void MainWindow::on_pushOuvrir_clicked()
{
    filename=QFileDialog::getOpenFileName(this,tr("Ouvrir un fichier texte"),FilesRootPath,tr("Fichiers Textes (*.txt)"));
    QFile file(filename);
    if (!file.open(QIODevice::ReadOnly| QIODevice::Text))
        return;
    QTextStream in(&file);
    ECRIRE(ui->Titre,in.readLine());
    ECRIRE(ui->texte,in.readLine());
    ECRIRE(ui->Auteur,in.readLine());
    file.close();

}

void MainWindow::ECRIRE(QLineEdit *zt, double valeur)
{
    zt->setText(QString::number(valeur));
}

void MainWindow::ECRIRE(QLineEdit *zt, QString chaine)
{
    zt->setText(chaine);
}

void MainWindow::ECRIRE(QTextEdit *zt, double valeur)
{
    zt->setText(QString::number(valeur));
}

void MainWindow::ECRIRE(QTextEdit *zt, QString chaine)
{
    zt->setText(chaine);
}
void MainWindow::on_pushNouveau_clicked()
{
    check =true;
    EFFACER(ui->Titre);
    EFFACER(ui->Auteur);
    NOUVEAU(ui->texte);
    filename=QFileDialog::getSaveFileName(this,tr("Exporter dans un fichier texte"),FilesRootPath,tr("Fichiers Textes (*.txt)"));
    QFile file(filename);
    if (!file.open(QIODevice::WriteOnly| QIODevice::Text))
        return;
    QTextStream out(&file);

    out << LIRE(ui->Titre) << endl;
    out << LIRE(ui->texte) << endl;
    out << LIRE(ui->Auteur) << endl;
    Clc=filename;
    file.close();

}
void MainWindow::EFFACER(QLineEdit *p)
{
    p->clear();
}

void MainWindow::NOUVEAU(QTextEdit *t)
{
    t->clear();
}
QString MainWindow::LIRE(QLineEdit *zt)
{
   return zt->text();
}
QString MainWindow::LIRE(QTextEdit *zt)
{
   return zt->toPlainText();
}



void MainWindow::on_pushEnregistrer_clicked()
{
    if(check){
        filename =Clc;
    }else{
        filename = QFileDialog::getSaveFileName(this,tr("Exporter dans un fichier texte"),FilesRootPath,tr("Fichiers Textes (*.txt)"));
    }
    QFile file(filename);
    if (!file.open(QIODevice::WriteOnly| QIODevice::Text))
        return;
    QTextStream out(&file);

    out << LIRE(ui->Titre) << endl;
    out << LIRE(ui->texte) << endl;
    out << LIRE(ui->Auteur) << endl;
    file.close();


}
