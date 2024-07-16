#include "mainwidget.h"
#include <sstream>
#include <fstream>
#include "pointer.hpp"
#include "Expr.hpp"
#include "parse.hpp"
#include "EmptyEnv.hpp"

mainwidget::mainwidget(QWidget *parent)
    : QWidget{parent}
{
    mainVLayout = new QVBoxLayout();
    mainGLayout = new QGridLayout();

    setGridLayout();
    setVerticalLayout();


        connect(submitBtn, &QPushButton::clicked, this, &mainwidget::fill_summary);
        connect(resetBtn, &QPushButton::clicked, this, &mainwidget::reset);
}

void mainwidget::setGridLayout() {
    exprLabel = new QLabel("Expression:");
    expression = new QTextEdit();

    opBtnGrp = new QButtonGroup();
    opBox = new QGroupBox();
    radioBoxLayout = new QVBoxLayout();

    interp = new QRadioButton("Interp");
    prettyPrint = new QRadioButton("Pretty Print");
    opBtnGrp -> addButton(interp, 0);
    opBtnGrp -> addButton(prettyPrint, 1);

    radioBoxLayout -> addWidget(interp);
    radioBoxLayout -> addWidget(prettyPrint);

    opBox -> setLayout(radioBoxLayout);

    submitBtn = new QPushButton("Submit");

    resultLabel = new QLabel("Result:");
    resultArea = new QTextEdit();

    resetBtn = new QPushButton("Reset");

    mainGLayout -> addWidget(exprLabel, 0, 0);
    mainGLayout -> addWidget(expression, 0, 1);

    mainGLayout -> addWidget(opBox, 2, 1);

    mainGLayout -> addWidget(submitBtn, 3, 1);
    mainGLayout -> addWidget(resultLabel, 4, 0);
    mainGLayout -> addWidget(resultArea, 4, 1);
    mainGLayout -> addWidget(resetBtn, 5, 1);
}

void mainwidget::setVerticalLayout() {
    mainVLayout -> addItem(mainGLayout);
    setLayout(mainVLayout);
}

void mainwidget::fill_summary() {
    std::string input = expression -> toPlainText().toUtf8().constData();
    std::string fileName;

    std::istringstream ssTemp(input);
    std::string word;
    bool isFile = false;
    bool isNext = false;

    while(getline(ssTemp, word, ' ')) {
        if (isFile && isNext) {
            fileName = word;
            break;
        }
        if (word == "f" || "F") {
            isFile = true;
        }
        if (word == "=") {
            isNext = true;
        }
    }

    std::ifstream myfile(fileName);
    if (fileName.length() > 0) {
        if (myfile.is_open())
        {
            word = "";
            input = "";
            while (getline(myfile, word))
            {
                input += word + " ";
            }
            myfile.close();
        }
    }

    std::stringstream ss(input);
    std::string operation;
    std::string result;

    if (opBtnGrp -> checkedButton()) {
        if (opBtnGrp -> checkedId() == 0) operation = "interp";
        else operation = "pretty";
    }

    if (operation == "interp") {
        PTR(Expr) expr = parse_expr(ss);
        result = expr -> interp(NEW(EmptyEnv) ()) -> to_string();
    }
    else {
        PTR(Expr) expr = parse_expr(ss);
        result = expr -> to_prettyString();
    }

    resultArea -> setText(QString::fromStdString(result));
}

void mainwidget::reset() {
        expression -> clear();

        if (opBtnGrp -> checkedButton() != 0) {
            opBtnGrp -> setExclusive(false);
            opBtnGrp -> checkedButton() -> setChecked(false);
            opBtnGrp -> setExclusive(true);
        }

        resultArea -> clear();
}
