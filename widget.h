#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QGroupBox>
#include <QLineEdit>
#include <QPushButton>
#include <vector>
namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

    QGroupBox* createOutputGroup();
    QGroupBox* createIntputGroup();
    QLayout* createOperatorGroup();
    QLayout* createNumberGroup();

public slots:
    void OnClicked0();
    void OnClicked1();
    void OnClicked2();
    void OnClicked5_0();
    void OnClicked6_0();

private:
    //输出框
    QLineEdit *output = new QLineEdit(QString("0"));

    //number buttons
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

    //operator buttons
    QPushButton *button0_o = new QPushButton(tr("/"));
    QPushButton *button1_o = new QPushButton(tr("c"));
    QPushButton *button2_o = new QPushButton(tr("×"));
    QPushButton *button3_o = new QPushButton(tr("÷"));

    QPushButton *button4_o = new QPushButton(tr("-"));
    QPushButton *button5_o = new QPushButton(tr("+"));
    QPushButton *button6_o = new QPushButton(tr("="));
    QString content;
    QString result;
    Ui::Widget *ui;
};

#endif // WIDGET_H
