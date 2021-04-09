#pragma once

#include "basicwindow.h"
#include "ui_CCMainWindow.h"

class CCMainWindow : public BasicWindow
{
	Q_OBJECT

public:
	CCMainWindow(QWidget *parent = Q_NULLPTR);
	~CCMainWindow();

public:
	void initTimer();	//初始化计时器
	void initControl();
	void setUserName(const QString& username);	//设置用户名
	void setLevelPixmap(int level);				//设置顶级
	void setHeadPixmap(const QString& headPath);//设置头像
	void setStatusMenuIcon(const QString& statusPath);//设置状态
	//添加应用部件(app图片路径，app部件对象名)
	QWidget* addOtherAppExtension(const QString& appPath, const QString& appName);

private:
	void resizeEvent(QResizeEvent* event);
private slots:

	void onAppIconClicked();
private:
	Ui::CCMainWindowClass ui;
};
