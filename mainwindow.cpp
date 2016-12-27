#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPlainTextEdit>
#include <QString>
#include <QtWidgets>


Button::Button(const QString &text, QWidget *parent)
    : QToolButton(parent)
{
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
    setText(text);
}
//! [0]

//! [1]
QSize Button::sizeHint() const
//! [1] //! [2]
{
    QSize size = QToolButton::sizeHint();
    size.rheight() += 20;
    size.rwidth() = qMax(size.width(), size.height());
    return size;
}
//! [2]


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)

{
    // variables initialised
    ques[0] = QString("I get my own (usually very high) standards and accomplish such standards and goals.");
    ques[1] = QString("I am a go-getter. I love being with people.");
    ques[2] = QString("If I do not like anybody, I will tease him or her whenever I get an opportunity.");
    ques[3] = QString("I do what society expects of me, and behave as a normal person.");
    ques[4] = QString("I love competing with others and I come out a winner.");
    ques[5] = QString("I have/love to join various clubs and groups.");
    ques[6] = QString("I have fought for my rights.");
    ques[7] = QString("If I find someone in trouble, I offer my help even if I have to go out of the way.");
    ques[8] = QString("I will do everything possible to keep my relations/peers happy.");
    ques[9] = QString("I do not mind criticism and would not leave a job if it may invite criticism.");
    ques[10] = QString("I take up difficult work and task to prove my worth.");
    ques[11] = QString("I love to be invited to others places and I do invite others to my   home.");
    ques[12] = QString("I sometimes disagree and argue with my peers and Govt. officials.");
    ques[13] = QString("I will personally take care of those who depend upon me.");
    ques[14] = QString("I love to make my own rules.");
    ques[15] = QString("I do think differently to excel; perform better than others.");
    ques[16] = QString("I have a lot of friends.");
    ques[17] = QString("I love to deflate the egos of egoistic people.");
    ques[18] = QString("I would love to lay my life for my nation if needed.    ");
    ques[19] = QString("I do not take big decisions myself to avoid the problems later. I prefer to consult all others.");
    ques[20] = QString("I am good at consoling others when they are in grief.");
    ques[21] = QString("I play within the rules & attain goals I set for myself.");
    ques[22] = QString("If I do not know anybody at a social gathering. I do not feel comfortable.");
    ques[23] = QString("I can make sacrifices to keep others happy");
    ques[24] = QString("I base my decisions on others opinions.");

    // question

    text->setReadOnly(true);
    text->setPlainText(ques[0]);

    // instructions
    QString str2 = QString("0: Never  1: Rarely 2: Sometimes 3: Occassionaly 4: Frequently");

    QPlainTextEdit *text2 = new QPlainTextEdit;
    text2->setReadOnly(true);
    text2->setPlainText(str2);

    // buttons
    Button * digitButtons[5];
    for (int i = 0; i < 5; i++)
    {
        digitButtons[i] = createButton(QString::number(i), SLOT(digitClicked()));
    }

    Button *nextButton = createButton(tr("Next"), SLOT(nextClicked()));
    Button *finishButton = createButton(tr("finish"), SLOT(finishClicked()));

    // adding widgets to layout

    centralWidget = new QWidget(this);
        this->setCentralWidget( centralWidget );
        mainLayout = new QGridLayout( centralWidget );


    mainLayout->setSizeConstraint(QLayout::SetFixedSize);
    mainLayout->addWidget(text, 0, 0, 5, 10);
    mainLayout->addWidget(text2, 4, 0, 2, 10);

    for (int i = 0; i < 5; i++)
    {
          mainLayout->addWidget(digitButtons[i], 6, i*2, 2, 2);
    }
    mainLayout->addWidget(nextButton, 8, 0, 2, 5);
    mainLayout->addWidget(finishButton, 8, 5, 2, 5);
    setLayout(mainLayout);


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::digitClicked()
{
    Button *clickedButton = qobject_cast<Button *>(sender());
    int digitValue = clickedButton->text().toInt();
    ans[i] += digitValue;
}

void MainWindow::nextClicked()
{
    i++;
    if (i >= 25)
    {
        achievement = ans[0] + ans[4] + ans[10] + ans[15] + ans[21];
        affiliation = ans[1] + ans[5] + ans[11] + ans[16] + ans[22];
        aggression = ans[2] + ans[6] + ans[9] + ans[12] + ans[17];
        extension = ans[7] + ans[13] + ans[18] + ans[20] + ans[23];
        dependence = ans[3] + ans[8] - ans[14] + ans[19] + ans[24];

        QString result = QString("The results are: Achievement Motivation = %1 \nAffiliation Motivation = %2\n Aggression Motivation = %3\n Extension motivation = %4\nDependence Motivation = %5").
                arg(achievement).arg(affiliation).arg(aggression).arg(extension).arg(dependence);
        QMessageBox msgBox1;
        msgBox1.setText(result);
        msgBox1.setWindowTitle("Results");
        msgBox1.exec();
    }
    else
    {
        text->setPlainText(ques[i]);
    }

}

void MainWindow::finishClicked()
{
    MainWindow::close();
}


Button *MainWindow::createButton(const QString &text, const char *member)
{
    Button *button = new Button(text);
    connect(button, SIGNAL(clicked()), this, member);
    return button;
}

