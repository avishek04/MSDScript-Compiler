#include <QApplication>
#include <mainwidget.h>

int main(int argc, char **argv) {
    QApplication app(argc, argv);
    mainwidget* widget = new mainwidget();

    widget->show();

    return app.exec();
}
