#include "QtWidgetsApplication.h"

QtWidgetsApplication::QtWidgetsApplication(QWidget* parent)
    : QWidget(parent)
{
    ui.setupUi(this);
    //���������ڱ���
    setWindowTitle(QStringLiteral("�򵥼�����"));
    //�����ı���ʾ��������С
    ui.result->setFontPointSize(28);
    //�����ְ�ť�ͺ�����
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
    //���������ť�ͺ�����
    connect(ui.action_Button_plus, SIGNAL(clicked()), this, SLOT(on_action_Button_clicked()));
    connect(ui.action_Button_minus, SIGNAL(clicked()), this, SLOT(on_action_Button_clicked()));
    connect(ui.action_Button_multiply, SIGNAL(clicked()), this, SLOT(on_action_Button_clicked()));
    connect(ui.action_Button_divide, SIGNAL(clicked()), this, SLOT(on_action_Button_clicked()));
}

//���ó�Ա����
void QtWidgetsApplication::setnum1(int num) {
    num1 = num;
}
void QtWidgetsApplication::setnum2(int num) {
    num2 = num;
}
void QtWidgetsApplication::setflag(int f) {
    flag = f;
}

//���㺯��
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

//��ʼ������
void QtWidgetsApplication::on_action_Button_c_clicked() {
    ui.result->clear();
    setnum1(0);
    setnum2(0);
    setflag(0);
}

//���ְ�ť����
void QtWidgetsApplication::on_number_Button_clicked() {
    QPushButton* btn = qobject_cast<QPushButton*>(sender()); //�õ���ǰ�����İ�ť
    QString number = btn->text(); //��ȡ��ť�ؼ����ı���ֵ
    QString ss = ui.result->toPlainText();
    ui.result->clear();
    ui.result->append(ss + number);
}

//�������ť����
void QtWidgetsApplication::on_action_Button_clicked() {
    int number = ui.result->toPlainText().toInt();
    setnum1(number);
    QPushButton* btn = qobject_cast<QPushButton*>(sender()); //�õ���ǰ�����İ�ť
    QString action = btn->text();
    ui.result->clear();
    if (action == "+") setflag(1);
    else if (action == "-") setflag(2);
    else if (action == "*") setflag(3);
    else setflag(4);
}

//���ڰ�ť����
void QtWidgetsApplication::on_action_Button_equal_clicked() {
    int number = ui.result->toPlainText().toInt();
    setnum2(number);
    int res = calculate();
    ui.result->clear();
    ui.result->append(QString::number(res));
}