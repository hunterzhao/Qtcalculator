#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QGroupBox>
#include <QLineEdit>
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
private:
    QGroupBox *output;
    QGroupBox *buttons;
    Ui::Widget *ui;
};

#endif // WIDGET_H





















