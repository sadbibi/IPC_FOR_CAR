#ifndef INSTRUCT_H
#define INSTRUCT_H

#include <QWidget>

namespace Ui {
class Instruct;
}

class Instruct : public QWidget
{
    Q_OBJECT

public:
    explicit Instruct(QWidget *parent = 0);
    ~Instruct();

private:
    Ui::Instruct *ui;
    QByteArray data;

private slots:


    void on_btn_read_clicked();
    void on_btn_write_name_clicked();

    void on_btn_load_clicked();

    void on_btn_write_mode_clicked();

    void on_btn_write_baud_clicked();

    void on_btn_write_size_clicked();

    void on_btn_write_code_clicked();

    void on_btn_write_address_clicked();

    void on_btn_write_com_clicked();

    void rec_time_count();

public slots:
     void Receive_data(QByteArray temp);

signals:
    void Send_instruction(QByteArray data);

};

#endif // INSTRUCT_H
