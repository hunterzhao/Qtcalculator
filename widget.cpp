#include <QGridLayout>
#include <QLineEdit>
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
    QVBoxLayout *vbox = new QVBoxLayout;
    output->setReadOnly(true);
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
   QGridLayout *box = new QGridLayout;
   box->addWidget(buttonMC,0,0);box->addWidget(button7,0,1);
   box->addWidget(button8,0,2);box->addWidget(button9,0,3);

   box->addWidget(buttonMR,1,0);box->addWidget(button4,1,1);
   box->addWidget(button5,1,2);box->addWidget(button6,1,3);

   box->addWidget(buttonMS,2,0);box->addWidget(button1,2,1);
   box->addWidget(button2,2,2);box->addWidget(button3,2,3);

   box->addWidget(buttonMT,3,0);box->addWidget(button0,3,1);
   box->addWidget(buttondot,3,2);box->addWidget(buttonNull,3,3);

   connect(button0, SIGNAL(clicked()), this, SLOT(OnClicked0()));
   connect(button1, SIGNAL(clicked()), this, SLOT(OnClicked1()));
   connect(button2, SIGNAL(clicked()), this, SLOT(OnClicked2()));
   return box;
}

QLayout* Widget::createOperatorGroup() {
   QGridLayout *grid = new QGridLayout;
   QGridLayout *box1 = new QGridLayout;
   box1->addWidget(button0_o,0,0);
   box1->addWidget(button1_o,0,1);
   box1->addWidget(button2_o,1,0);
   box1->addWidget(button3_o,1,1);
   box1->addWidget(button4_o,2,0);
   box1->addWidget(button5_o,2,1);
   QGridLayout *box2 = new QGridLayout;
   box2->addWidget(button6_o,0,0);
   grid->addLayout(box1,0,0);
   grid->addLayout(box2,1,0);

   connect(button5_o, SIGNAL(clicked()), this, SLOT(OnClicked5_0()));
   connect(button6_o, SIGNAL(clicked()), this, SLOT(OnClicked6_0()));
   return grid;
}

void Widget::OnClicked0() {
   content.append('0');
   output->setText(content);
}

void Widget::OnClicked1() {
    content.append('1');
    output->setText(content);
}

void Widget::OnClicked2() {
    content.append('2');
    output->setText(content);
}

void Widget::OnClicked5_0() {
    content.append('+');
    output->setText(content);
}

void Widget::OnClicked6_0() {
    for(int i=0;i<content.size();i++) {

    }
    result="3";
    output->setText(result);
}
