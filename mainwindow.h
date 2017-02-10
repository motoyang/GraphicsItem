#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void initScene();

private slots:

    void on_actionNew_triggered();

    void on_actionClear_triggered();

    void on_actionAddEllipse_triggered();

    void on_actionAddText_triggered();

    void on_actionAddRect_triggered();

    void on_actionAddPolygon_triggered();

    void on_actionAddAlpha_triggered();

    void on_actionAddFlash_triggered();

    void on_actionAddAnim_triggered();

private:
    Ui::MainWindow *ui;

    QGraphicsScene *scene;
};

#endif // MAINWINDOW_H
