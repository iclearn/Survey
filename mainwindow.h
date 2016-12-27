#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QToolButton>
#include <QString>
#include <QPlainTextEdit>
#include <QtWidgets>


namespace Ui {
class MainWindow;
}

#ifndef BUTTON_H
#define BUTTON_H

#include <QToolButton>

//! [0]
class Button : public QToolButton
{
    Q_OBJECT

public:
    explicit Button(const QString &text, QWidget *parent = 0);

    QSize sizeHint() const Q_DECL_OVERRIDE;
};
//! [0]

#endif


static int ans[25];
static int i;
class MainWindow : public QMainWindow
{
    Q_OBJECT
    QWidget *centralWidget;
        QGridLayout* mainLayout;
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    QPlainTextEdit *text = new QPlainTextEdit;
    // declare varibles
    int achievement, affiliation, aggression, extension, dependence;
    QString ques[25];

private slots:
    void digitClicked();
    void nextClicked();
    void finishClicked();
private:
    Ui::MainWindow *ui;
    Button *createButton(const QString &text, const char *member);

};


#endif // MAINWINDOW_H
