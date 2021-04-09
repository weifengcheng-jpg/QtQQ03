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
	void initTimer();	//��ʼ����ʱ��
	void initControl();
	void setUserName(const QString& username);	//�����û���
	void setLevelPixmap(int level);				//���ö���
	void setHeadPixmap(const QString& headPath);//����ͷ��
	void setStatusMenuIcon(const QString& statusPath);//����״̬
	//���Ӧ�ò���(appͼƬ·����app����������)
	QWidget* addOtherAppExtension(const QString& appPath, const QString& appName);

private:
	void resizeEvent(QResizeEvent* event);
private slots:

	void onAppIconClicked();
private:
	Ui::CCMainWindowClass ui;
};
