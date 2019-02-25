#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
private slots:
    void digits_numbers();  // здесь видно следующее: вызов функции digits_number, пользователь название ее придумал сам
    void on_dot_clicked();
    void operations();
    void on_AC_clicked(); // также мы здесь видим и первый способ- при нажатие кнопки АС срабовает действие прописаное в коде
    void on_exactly_clicked();
    void math_operation();

    void on_action_triggered();

};

#endif // MAINWINDOW_H
