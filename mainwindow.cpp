#include "mainwindow.h"
#include "ui_mainwindow.h"

double num_first; // функция расмотрена ниже, она нужна для прописывание первый цифры в калькулятор
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

   connect(ui-> p0, SIGNAL(clicked()),this,SLOT(digits_numbers()));// все ниже кноки были созданы вручную, вторым способом
   //( нажимаем на кнопку  срабатывает сигнал слота функции прописанной ниже)
     connect(ui-> p1, SIGNAL(clicked()),this,SLOT(digits_numbers()));// так как в процессе создание проекта
       connect(ui-> p2, SIGNAL(clicked()),this,SLOT(digits_numbers()));// выяснилось что название кноки нельзя придумать меньше двух символовов
         connect(ui-> p3, SIGNAL(clicked()),this,SLOT(digits_numbers()));// под кноки 0-9 были придуманы название p0-p9
           connect(ui-> p4, SIGNAL(clicked()),this,SLOT(digits_numbers()));
             connect(ui-> p5, SIGNAL(clicked()),this,SLOT(digits_numbers()));
               connect(ui-> p6, SIGNAL(clicked()),this,SLOT(digits_numbers()));
                 connect(ui-> p7, SIGNAL(clicked()),this,SLOT(digits_numbers()));
                   connect(ui-> p8, SIGNAL(clicked()),this,SLOT(digits_numbers()));
                     connect(ui-> p9, SIGNAL(clicked()),this,SLOT(digits_numbers()));
                      connect(ui-> plusorminus, SIGNAL(clicked()),this,SLOT(operations()));
                       connect(ui-> prosent, SIGNAL(clicked()),this,SLOT(operations()));
                         connect(ui-> dive, SIGNAL(clicked()),this,SLOT(math_operation()));
                           connect(ui-> multiply, SIGNAL(clicked()),this,SLOT(math_operation()));
                             connect(ui-> minus, SIGNAL(clicked()),this,SLOT(math_operation()));
                               connect(ui-> plus, SIGNAL(clicked()),this,SLOT(math_operation()));

                               ui->dive->setCheckable(true); // команды  для действий /, *, +, - срабабатывает сигнал истина после него пользователь
                               ui->multiply->setCheckable(true); //  вводит второе число
                                 ui->minus->setCheckable(true);
                                  ui->plus->setCheckable(true);


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow :: digits_numbers() // нажатие кнопок 0-9
// данное вызывании функции было созданно вторым спосом, взято сразу же 10 кнопок
// не надо прописывать
// 10 раз одно  и то же
{
QPushButton *button = (QPushButton *)sender(); // задаем функцию

double all_numbers; // все кнопки
QString new_label; // создается строка в панеле label
all_numbers = (ui->result->text()+ button->text()).toDouble(); // прописывает текст в даннм случаем число (todouble прописывается больше двух цифр)
new_label = QString ::number(all_numbers, 'g', 15); // не больше 15 символов
ui-> result->setText(new_label); // в панель лабель под имени result появляется число
}

void MainWindow::on_dot_clicked() // нажатие точки // данное вызывание функции было созданно первым способом // действие только одной кнопки
{
    if(!(ui->result->text().contains('.'))) // задаем текст если в панеле result нету точки
         ui-> result->setText(ui-> result->text() + "."); // то пишем точку
}

void MainWindow :: operations() //  нажатие кнопок % и +/- // функциявызвана вручную// сразу же две операции
// для точо применить операцию если, иначе если
{
QPushButton *button = (QPushButton *)sender();

double all_numbers;
QString new_label;

if (button->text() == "+/-") // если при нажатии кнопки с надписью +/-
   {
   all_numbers = (ui->result->text()).toDouble(); // введено  все // нажатие может срабатовать несколь раз// действие будет чередоваться
   all_numbers = all_numbers *-1; // чтобы получить отрицательное число умножим его на -1
   new_label = QString ::number(all_numbers, 'g', 15); // данный символ входит в диапозон 15 символов
   ui-> result->setText(new_label); // прописывает в поле labrl названо result
   } else if (button->text() == "%") //если же при нажатии кнопки с надписью "%"
{
all_numbers = (ui->result->text()).toDouble();
all_numbers = all_numbers *0.01; // для точо получить число в процентах умножим его на  *0.01
new_label = QString ::number(all_numbers, 'g', 15);
ui-> result->setText(new_label);
}
}

void MainWindow::math_operation() // нажатие сразу 4 кнопок + , - , * , / // функция вызванна вручную
{
QPushButton *button = (QPushButton *)sender();
num_first = ui->result->text().toDouble();
ui->result->setText(""); // после того когда было нажато действие пользователь видит пустое поле result
button->setChecked(true); // действие истино выполняется
}


void MainWindow::on_AC_clicked() // нажатие действия стереть все действия// функция вызввана автоматически
{
ui->plus->setChecked(false); // так как кнопка была нажата действие ложно // действие не выполняется
ui->minus->setChecked(false);
ui->dive->setChecked(false);
ui->multiply->setChecked(false);

ui->result->setText("0");
}

void MainWindow::on_exactly_clicked() // данна операция вызвана автоматические // выполняет сразу несколько действий, поэтому здесь этот способ
//делать проще и правильнее
// выполнения действиями над числамми
// выполнение результата после нажатие равно
{
    double labelNumber, num_second; // задаем две переменные // строку куда все вводим // вторео число
    QString new_label; // переменная новое поле для ввода второго числа

    num_second = ui->result->text().toDouble(); // ввод в полe result поле цифр // ввод более одного символа

    if  (ui->plus->isChecked()){ // выполняется нажатие кнопки +
        labelNumber = num_first + num_second; // результат = 1 число + 2
        new_label = QString ::number(labelNumber, 'g', 15);
        ui-> result->setText(new_label);
        ui->plus->setChecked(false); //при нажатие = действие второй раз не срабатывает и появляется результат операции

      }  else if(ui-> minus->isChecked()){ // выполняется нажатие кнопки -

        labelNumber = num_first - num_second;  // результат = 1 число - 2
        new_label = QString ::number(labelNumber, 'g', 15);
        ui-> result->setText(new_label);
        ui->minus->setChecked(false);


// следущие действие деление// делить на ноль нельзя // деление делаем проверку
    } else if(ui-> dive->isChecked()){ // если нажата кнопка /
        if (num_second == 0){ // то ей присвается 0 ( то есть если после кнопки было введено ноль
            ui->result->setText("делить на ноль нельзя"); // то после нажатие на ноль появляется результат ошибки - делить на ноль нельзя
        }else{ // иначе
        labelNumber = num_first / num_second;  //результат = 1 число / 2
        new_label = QString ::number(labelNumber, 'g', 15);
        ui-> result->setText(new_label);
        }
        ui->dive->setChecked(false);

      } else if(ui->multiply->isChecked()){// выполняется нажатие кнопки *

        labelNumber = num_first * num_second;  // результат = 1 число * 2
        new_label = QString ::number(labelNumber, 'g', 15);
        ui-> result->setText(new_label);
        ui->multiply->setChecked(false);

    }
}


void MainWindow::on_action_triggered() // операция было создана автоматически // действие проходит в панели инструментов
{
    QApplication :: quit(); // выполняет закрытие файла
}
