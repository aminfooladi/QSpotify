#ifndef SONGWINDOW_H
#define SONGWINDOW_H
#include "database.h"
#include "apppagge.h"

#include <QMediaPlayer>
#include <QAudioOutput>
#include <QMainWindow>

namespace Ui {
class SongWindow;
}

class SongWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit SongWindow(QWidget *parent = nullptr);
    ~SongWindow();
    void setDatabase(Database* database) ;
    void setPtrToPage(AppPage* page) ;
    void setSongId(int songID) ;
    void setPageInfo() ;

private:
    Ui::SongWindow *ui;
    Database * database ;
    AppPage * page ;
    int songID ;
    QMediaPlayer* mediaPlayer ;
    QAudioOutput * audioOutput;
};

#endif // SONGWINDOW_H
