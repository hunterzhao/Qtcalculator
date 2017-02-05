#include <QGridLayout>
#include <QLineEdit>
#include <QPushButton>
#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    QGridLayout *grid = new QGridLayout;
    grid->addWidget(createOutputGroup(), 0, 0);
    grid->addWidget(createIntputGroup(), 1, 0);
    setLayout(grid);

    setWindowTitle(tr("计算器"));
    resize(480, 300);
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

QGroupBox* Widget::createOutputGroup() {
    QGroupBox *groupBox = new QGroupBox(tr("输出"));
    QLineEdit *output = new QLineEdit(QString("0"));
    QVBoxLayout *vbox = new QVBoxLayout;
    vbox->addWidget(output,0,0);
    groupBox->setLayout(vbox);
    return groupBox;
}

QGroupBox* Widget::createIntputGroup() {
    QGroupBox *groupBox = new QGroupBox(tr("keyBroad"));
    QHBoxLayout* hLayout = new QHBoxLayout();
    hLayout->addLayout(createNumberGroup());
    QSpacerItem* hSpacer1 = new QSpacerItem(50, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);
    hLayout->addSpacerItem(hSpacer1);
    hLayout->addLayout(createOperatorGroup());
    groupBox->setLayout(hLayout);
    return groupBox;
}

QLayout* Widget::createNumberGroup() {
   QPushButton *buttonMC = new QPushButton(tr("MC"));
   QPushButton *buttonMR = new QPushButton(tr("MR"));
   QPushButton *buttonMS = new QPushButton(tr("MS"));
   QPushButton *buttonMT = new QPushButton(tr("MT"));

   QPushButton *button0 = new QPushButton(tr("0"));
   QPushButton *button1 = new QPushButton(tr("1"));
   QPushButton *button2 = new QPushButton(tr("2"));
   QPushButton *button3 = new QPushButton(tr("3"));

   QPushButton *button4 = new QPushButton(tr("4"));
   QPushButton *button5 = new QPushButton(tr("5"));
   QPushButton *button6 = new QPushButton(tr("6"));
   QPushButton *button7 = new QPushButton(tr("7"));
   QPushButton *button8 = new QPushButton(tr("8"));
   QPushButton *button9 = new QPushButton(tr("9"));
   QPushButton *buttondot = new QPushButton(tr("."));
   QPushButton *buttonNull = new QPushButton(tr(" "));
   QGridLayout *box = new QGridLayout;
   box->addWidget(buttonMC,0,0);box->addWidget(button7,0,1);
   box->addWidget(button8,0,2);box->addWidget(button9,0,3);

   box->addWidget(buttonMR,1,0);box->addWidget(button4,1,1);
   box->addWidget(button5,1,2);box->addWidget(button6,1,3);

   box->addWidget(buttonMS,2,0);box->addWidget(button1,2,1);
   box->addWidget(button2,2,2);box->addWidget(button3,2,3);

   box->addWidget(buttonMT,3,0);box->addWidget(button0,3,1);
   box->addWidget(buttondot,3,2);box->addWidget(buttonNull,3,3);
   return box;
}

QLayout* Widget::createOperatorGroup() {
   QGridLayout *grid = new QGridLayout;
   QPushButton *button0 = new QPushButton(tr("/"));
   QPushButton *button1 = new QPushButton(tr("c"));
   QPushButton *button2 = new QPushButton(tr("×"));
   QPushButton *button3 = new QPushButton(tr("÷"));

   QPushButton *button4 = new QPushButton(tr("-"));
   QPushButton *button5 = new QPushButton(tr("+"));
   QPushButton *button6 = new QPushButton(tr("="));
   QGridLayout *box1 = new QGridLayout;
   box1->addWidget(button0,0,0);
   box1->addWidget(button1,0,1);
   box1->addWidget(button2,1,0);
   box1->addWidget(button3,1,1);
   box1->addWidget(button4,2,0);
   box1->addWidget(button5,2,1);
   QGridLayout *box2 = new QGridLayout;
   box2->addWidget(button6,0,0);
   grid->addLayout(box1,0,0);
   grid->addLayout(box2,1,0);
   return grid;
}
