#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include <QtWidgets>

class mainwidget : public QWidget
{
    Q_OBJECT

    QLabel* exprLabel;
    QTextEdit* expression;

    QGroupBox* opBox;
    QButtonGroup* opBtnGrp;
    QVBoxLayout* radioBoxLayout;

    QRadioButton* interp;
    QRadioButton* prettyPrint;

    QPushButton* submitBtn;

    QLabel* resultLabel;
    QTextEdit* resultArea;
    QPushButton* resetBtn;

    QVBoxLayout* mainVLayout;
    QGridLayout* mainGLayout;

public:
    explicit mainwidget(QWidget *parent = nullptr);
    void setVerticalLayout();
    void setGridLayout();

signals:

public slots:
    void fill_summary();
    void reset();

};

#endif // MAINWIDGET_H
