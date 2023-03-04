#ifndef STUDENTDIALOG_H
#define STUDENTDIALOG_H

#include <QDialog>


#include <QSqlDatabase> // 创建数据库
#include <QSqlQuery>    // 用于DML（数据操作）DLL（数据定义语言）
#include <QSqlQueryModel>
#include <QSqlError>
#include <QDebug>
#include <QMessageBox>


QT_BEGIN_NAMESPACE
namespace Ui { class StudentDialog; }
QT_END_NAMESPACE

class StudentDialog : public QDialog
{
    Q_OBJECT

public:
    StudentDialog(QWidget *parent = nullptr);
    ~StudentDialog();

private slots:
    void on_pushButtonSort_clicked();

    void on_pushButton_INSERT_clicked();

    void on_pushButton_DELETE_clicked();

    void on_pushButton_UPDATE_clicked();

    void on_pushButton_SEARCH_clicked();


    void on_comboBoxOrder_activated(int index);

    void on_comboBoxBy_activated(int index);

    void on_pushButtonQueryAll_clicked();

private: // 自定义函数
    void CreateDatabaseFunc();
    void CreateTableFunc();
    void QueryTableFunc();
    QSqlDatabase sqldb;
    QSqlQueryModel sqlmodel; // 存储结果集
    Qt::SortOrder m_sortOrder; // 排序顺序
    QString m_sortBy;          // 排序依据



private:
    Ui::StudentDialog *ui;
};
#endif // STUDENTDIALOG_H
