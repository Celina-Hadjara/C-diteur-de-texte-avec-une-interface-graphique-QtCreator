#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include <QLineEdit>
#include <QTextEdit>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushQuitter_clicked();

    void on_pushOuvrir_clicked();

    void on_pushNouveau_clicked();

    void on_pushEnregistrer_clicked();

private:
    Ui::MainWindow *ui;
    const QString FilesRootPath = "C:/home/hadjara-celina/Bureau/ProjetPOO/Editeur/EditeurBasique/";
    bool check=false;
    QString Clc;
     QString filename;
    void EFFACER(QLineEdit *p);
    void NOUVEAU(QTextEdit *t);
    QString LIRE(QLineEdit *);
    QString LIRE(QTextEdit *);
    void ECRIRE(QTextEdit *zt,double valeur);
    void ECRIRE(QTextEdit *zt,QString chaine);
    void ECRIRE(QLineEdit *zt,double valeur);
    void ECRIRE(QLineEdit *zt,QString chaine);

};
#endif // MAINWINDOW_H
