#include "studentdialog.h"
#include "ui_studentdialog.h"
#include <QTimer>

StudentDialog::StudentDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::StudentDialog)
{
    ui->setupUi(this);


    // 排序顺序和排序依据属性初始化
    m_sortOrder = Qt::AscendingOrder;
    m_sortBy = "id";


    // 调用函数并创建打开数据库
    CreateDatabaseFunc();

    // 调用函数创建数据表
    CreateTableFunc();

    // 执行查询
    QSqlQueryModel *model = new QSqlQueryModel(this);
    model->setQuery("SELECT id, name, score FROM student");

    // 设置到 QTableView 中
    ui->tableView->setModel(model);
}


StudentDialog::~StudentDialog()
{
    delete ui;
}

void StudentDialog::CreateDatabaseFunc()
{
    // 1.添加数据库驱动
    sqldb = QSqlDatabase::addDatabase("QSQLITE");
    // 2. 设置数据库名称
    sqldb.setDatabaseName("studentmis.db");
    // 3.打开数据库是否成功
    if(sqldb.open()==true)
    {
        return;
        QMessageBox::information(0,"提示","数据库加载成功！",QMessageBox::Ok);
    }
    else
    {
        QMessageBox::critical(0,"提示","数据库打开失败，请重新检查！",QMessageBox::Ok);
    }
}

void StudentDialog::CreateTableFunc()
{
    QSqlQuery query;
    QString str = QString("CREATE TABLE IF NOT EXISTS student ("
                          "id INT PRIMARY KEY NOT NULL,"
                          "name TEXT NOT NULL,"
                          "score REAL NOT NULL)");
    bool query1 = query.exec("SELECT name FROM sqlite_master WHERE type='table' AND name='student'");
    bool query_result = query.next();
    if (query1 && query_result)
    {
        return;
        // 数据表已经存在，无需创建
        QMessageBox::information(this, "提示", "数据表已经存在！");
    }
    else
    {
        // 数据表不存在，创建数据表
        if (query.exec(str))
        {
            QMessageBox::information(this, "成功", "数据表创建成功！");
        }
        else
        {
            QMessageBox::critical(this, "失败", "数据表创建失败: " + query.lastError().text());
        }
    }
}



void StudentDialog::QueryTableFunc()
{
    if (!sqldb.isOpen()) {
        QMessageBox::critical(this, "错误", "数据库未打开！");
        return;
    }

    // 构造查询语句
    QString sql = "SELECT * FROM student";

    // 查询操作
    QSqlQuery query;
    if (!query.exec(sql)) {
        QMessageBox::critical(this, "错误", "查询失败：" + query.lastError().text());
        return;
    }

    // 显示结果到表格中
    QSqlQueryModel *model = new QSqlQueryModel(ui->tableView);
    model->setQuery(query);
    ui->tableView->setModel(model);
}


void StudentDialog::on_pushButton_INSERT_clicked()
{
    QSqlQuery query;
    query.prepare("INSERT INTO student (id, name, score) VALUES (:id, :name, :score)");

    int id = ui->lineEdit_ID->text().toInt();
    if (id == 0)
    {
        QMessageBox::critical(this, "错误", "学生的学号不能为0！");
        return;
    }
    query.bindValue(":id", id);

    QString name = ui->lineEdit_NAME->text();
    if (name.isEmpty())
    {
        QMessageBox::critical(this, "错误", "姓名不能为空！");
        return;
    }
    query.bindValue(":name", name);

    double score = ui->lineEdit_SCORE->text().toDouble();
    if (score < 0 || score > 100)
    {
        QMessageBox::critical(this, "错误", "分数范围必须在0-100之间！");
        return;
    }
    query.bindValue(":score", score);

    if (!query.exec())
    {
        QMessageBox::critical(this, "错误", "数据插入失败: " + query.lastError().text());
        return;
    }
    else
    {
        QMessageBox::information(this, "成功", "数据插入成功！");
    }
}



void StudentDialog::on_pushButton_DELETE_clicked()
{
    QSqlQuery query;
    int id = ui->lineEdit_ID->text().toInt();
    if (id == 0)
    {
        QMessageBox::critical(this, "错误", "学生的学号不能为0！");
        return;
    }
    QString str = "DELETE FROM student WHERE id=:id";
    query.prepare(str);
    query.bindValue(":id", id);
    if (query.exec())
    {
        QMessageBox::information(this, "成功", "数据删除成功！");
    }
    else
    {
        QMessageBox::critical(this, "错误", "数据删除失败: " + query.lastError().text());
    }
}



void StudentDialog::on_pushButton_UPDATE_clicked()
{
    QSqlQuery query;
    int id = ui->lineEdit_ID->text().toInt();
    if (id == 0)
    {
        QMessageBox::critical(this, "错误", "学生的学号不能为0！");
        return;
    }
    QString name = ui->lineEdit_NAME->text();
    if (name.isEmpty())
    {
        QMessageBox::critical(this, "错误", "姓名不能为空！");
        return;
    }
    double score = ui->lineEdit_SCORE->text().toDouble();
    if (score < 0 || score > 100)
    {
        QMessageBox::critical(this, "错误", "分数范围必须在0-100之间！");
        return;
    }
    QString str = "UPDATE student SET name=:name,score=:score WHERE id=:id";
    query.prepare(str);
    query.bindValue(":name", name);
    query.bindValue(":score", score);
    query.bindValue(":id", id);
    if (query.exec())
    {
        QMessageBox::information(this, "成功", "数据更新成功！");
    }
    else
    {
        QMessageBox::critical(this, "错误", "数据更新失败: " + query.lastError().text());
    }
}




void StudentDialog::on_pushButton_SEARCH_clicked()
{
    QSqlQuery query;
    int id = ui->lineEdit_ID->text().toInt();
    if (id == 0)
    {
        QMessageBox::critical(this, "错误", "学生的学号不能为0！");
        return;
    }
    QString str = QString("SELECT * FROM student WHERE id=%1").arg(id);
    if (query.exec(str))
    {
        if (query.next())
        {
            ui->lineEdit_NAME->setText(query.value(1).toString());
            ui->lineEdit_SCORE->setText(query.value(2).toString());

            // 将查询结果显示在 tableView 控件中
            QSqlQueryModel *model = new QSqlQueryModel();
            model->setQuery(str);
            ui->tableView->setModel(model);
        }
        else
        {
            QMessageBox::information(this, "提示", "没有找到该学生！");
        }
    }
    else
    {
        QMessageBox::critical(this, "错误", "数据查询失败: " + query.lastError().text());
    }
}






void StudentDialog::on_comboBoxBy_activated(int index)
{
    switch (index) {
    case 0:
        m_sortBy = "id";
        break;
    case 1:
        m_sortBy = "score";
        break;
    case 2:
        m_sortBy = "name";
        break;
    }
}

void StudentDialog::on_comboBoxOrder_activated(int index)
{
    if (index == 0) {
        m_sortOrder = Qt::AscendingOrder;
    } else {
        m_sortOrder = Qt::DescendingOrder;
    }
}

void StudentDialog::on_pushButtonSort_clicked()
{
    QSqlQueryModel *model = new QSqlQueryModel(this);
    QString query = QString("SELECT id, name, score FROM student ORDER BY %1 %2").arg(m_sortBy).arg(m_sortOrder == Qt::AscendingOrder ? "ASC" : "DESC");
    model->setQuery(query);
    ui->tableView->setModel(model);
}

// 查询全部按钮
void StudentDialog::on_pushButtonQueryAll_clicked()
{
    QSqlQueryModel *model = new QSqlQueryModel(this);
    model->setQuery("SELECT id, name, score FROM student");
    ui->tableView->setModel(model);
}


