#include "QtWidgetsApplication.h"

QtWidgetsApplication::QtWidgetsApplication(QWidget* parent)
    : QWidget(parent)
{
    ui.setupUi(this);
    //设置主窗口标题
    setWindowTitle(QStringLiteral("简单计算器"));
    //设置文本显示框的字体大小
    ui.result->setFontPointSize(28);
    //将数字按钮和函数绑定
    connect(ui.number_Button_1, SIGNAL(clicked()), this, SLOT(on_number_Button_clicked()));
    connect(ui.number_Button_2, SIGNAL(clicked()), this, SLOT(on_number_Button_clicked()));
    connect(ui.number_Button_3, SIGNAL(clicked()), this, SLOT(on_number_Button_clicked()));
    connect(ui.number_Button_4, SIGNAL(clicked()), this, SLOT(on_number_Button_clicked()));
    connect(ui.number_Button_5, SIGNAL(clicked()), this, SLOT(on_number_Button_clicked()));
    connect(ui.number_Button_6, SIGNAL(clicked()), this, SLOT(on_number_Button_clicked()));
    connect(ui.number_Button_7, SIGNAL(clicked()), this, SLOT(on_number_Button_clicked()));
    connect(ui.number_Button_8, SIGNAL(clicked()), this, SLOT(on_number_Button_clicked()));
    connect(ui.number_Button_9, SIGNAL(clicked()), this, SLOT(on_number_Button_clicked()));
    connect(ui.number_Button_0, SIGNAL(clicked()), this, SLOT(on_number_Button_clicked()));
    //将运算符按钮和函数绑定
    connect(ui.action_Button_plus, SIGNAL(clicked()), this, SLOT(on_action_Button_clicked()));
    connect(ui.action_Button_minus, SIGNAL(clicked()), this, SLOT(on_action_Button_clicked()));
    connect(ui.action_Button_multiply, SIGNAL(clicked()), this, SLOT(on_action_Button_clicked()));
    connect(ui.action_Button_divide, SIGNAL(clicked()), this, SLOT(on_action_Button_clicked()));
}

//设置成员变量
void QtWidgetsApplication::setnum1(int num) {
    num1 = num;
}
void QtWidgetsApplication::setnum2(int num) {
    num2 = num;
}
void QtWidgetsApplication::setflag(int f) {
    flag = f;
}

//计算函数
int QtWidgetsApplication::calculate() {
    int result = 0;
    if (flag == 1) result = num1 + num2;
    else if (flag == 2) result = num1 - num2;
    else if (flag == 3) result = num1 * num2;
    else if (flag == 4) {
        if (num2 == 0) return -1;
        else result = num1 / num2;
    }
    else {
        result = 0;
    }
    return result;
}

//初始化函数
void QtWidgetsApplication::on_action_Button_c_clicked() {
    ui.result->clear();
    setnum1(0);
    setnum2(0);
    setflag(0);
}

//数字按钮函数
void QtWidgetsApplication::on_number_Button_clicked() {
    QPushButton* btn = qobject_cast<QPushButton*>(sender()); //得到当前操作的按钮
    QString number = btn->text(); //获取按钮控件上文本的值
    QString ss = ui.result->toPlainText();
    ui.result->clear();
    ui.result->append(ss + number);
}

//运算符按钮函数
void QtWidgetsApplication::on_action_Button_clicked() {
    int number = ui.result->toPlainText().toInt();
    setnum1(number);
    QPushButton* btn = qobject_cast<QPushButton*>(sender()); //得到当前操作的按钮
    QString action = btn->text();
    ui.result->clear();
    if (action == "+") setflag(1);
    else if (action == "-") setflag(2);
    else if (action == "*") setflag(3);
    else setflag(4);
}

//等于按钮函数
void QtWidgetsApplication::on_action_Button_equal_clicked() {
    int number = ui.result->toPlainText().toInt();
    setnum2(number);
    int res = calculate();
    ui.result->clear();
    ui.result->append(QString::number(res));
}