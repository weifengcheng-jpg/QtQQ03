#include "CCMainWindow.h"
#include "SkinWindow.h"

#include <QProxyStyle>
#include <QPainter>


class CustomProxyStyle :public QProxyStyle
{
public:
	virtual void drawPrimitive(PrimitiveElement element, const QStyleOption* option,
		QPainter* painter, const QWidget* widget = nullptr) const
	{
		if (element == PE_FrameFocusRect)
		{
			return;
		}
		else
		{
			QProxyStyle::drawPrimitive(element, option, painter, widget);
		}
	}
};

CCMainWindow::CCMainWindow(QWidget *parent)
	: BasicWindow(parent)
{
	ui.setupUi(this);
	setWindowFlags(windowFlags() | Qt::Tool);
	loadStyleSheet("CCMainWindow");
	initControl();
}

CCMainWindow::~CCMainWindow()
{
}

void CCMainWindow::initControl()
{
	//����ȡ����ʱ�����Ʊ߿�
	ui.treeWidget->setStyle(new CustomProxyStyle);
	setLevelPixmap(0);
	setHeadPixmap(":/Resources/MainWindow/girl.png");
	setStatusMenuIcon(":/Resources/MainWindow/StatusSucceeded.png");

	QHBoxLayout *appupLayout = new QHBoxLayout;
	appupLayout->setContentsMargins(0, 0, 0, 0);
	appupLayout->addWidget(addOtherAppExtension(":/Resources/MainWindow/app/app_7.png", "app_7"));
	appupLayout->addWidget(addOtherAppExtension(":/Resources/MainWindow/app/app_2.png", "app_2"));
	appupLayout->addWidget(addOtherAppExtension(":/Resources/MainWindow/app/app_3.png", "app_3"));
	appupLayout->addWidget(addOtherAppExtension(":/Resources/MainWindow/app/app_4.png", "app_4"));
	appupLayout->addWidget(addOtherAppExtension(":/Resources/MainWindow/app/app_5.png", "app_5"));
	appupLayout->addWidget(addOtherAppExtension(":/Resources/MainWindow/app/app_6.png", "app_6"));
	appupLayout->addWidget(addOtherAppExtension(":/Resources/MainWindow/app/skin.png", "app_skin"));
	appupLayout->addStretch();
	appupLayout->setSpacing(2);
	ui.appWidget->setLayout(appupLayout);

	ui.bottomLayout_up->addWidget(addOtherAppExtension(":/Resources/MainWindow/app/app_10.png", "app_10"));
	ui.bottomLayout_up->addWidget(addOtherAppExtension(":/Resources/MainWindow/app/app_8.png", "app_8"));
	ui.bottomLayout_up->addWidget(addOtherAppExtension(":/Resources/MainWindow/app/app_11.png", "app_11"));
	ui.bottomLayout_up->addWidget(addOtherAppExtension(":/Resources/MainWindow/app/app_9.png", "app_9"));
	ui.bottomLayout_up->addStretch();
}

void CCMainWindow::setUserName(const QString & username)
{
}

void CCMainWindow::setLevelPixmap(int level)
{
	QPixmap levelPixmap(ui.levelBtn->size());
	levelPixmap.fill(Qt::transparent);

	QPainter painter(&levelPixmap);
	painter.drawPixmap(0, 4, QPixmap(":/Resources/MainWindow/lv.png"));

	int unitNum = level % 10;//��λ��
	int tenNum = level / 10; //ʮλ��

	//ʮλ,��ȡͼƬ�еĲ��ֽ��л���
	//drawPixmap(���Ƶ�x�����Ƶ�y,ͼƬ��ͼƬ���Ͻ�x,ͼƬ���Ͻ�y,�����Ŀ�ȣ������ĸ߶�)
	painter.drawPixmap(10, 4, QPixmap(":/Resources/MainWindow/levelvalue.png"), tenNum * 6, 0, 6, 7);

	//��λ
	painter.drawPixmap(16, 4, QPixmap(":/Resources/MainWindow/levelvalue.png"), unitNum * 6, 0, 6, 7);

	ui.levelBtn->setIcon(levelPixmap);
	ui.levelBtn->setIconSize(ui.levelBtn->size());
}

void CCMainWindow::setHeadPixmap(const QString & headPath)
{
	QPixmap pix;
	pix.load(":/Resources/MainWindow/head_mask.png");
	ui.headLabel->setPixmap(getRoundImage(QPixmap(headPath), pix, ui.headLabel->size()));
}

void CCMainWindow::setStatusMenuIcon(const QString & statusPath)
{
	QPixmap statusBtnPixmap(ui.stausBtn->size());
	statusBtnPixmap.fill(Qt::transparent);

	QPainter painter(&statusBtnPixmap);
	painter.drawPixmap(4, 4, QPixmap(statusPath));

	ui.stausBtn->setIcon(statusBtnPixmap);
	ui.stausBtn->setIconSize(ui.stausBtn->size());
}

QWidget * CCMainWindow::addOtherAppExtension(const QString & appPath, const QString & appName)
{
	QPushButton* btn = new QPushButton(this);
	btn->setFixedSize(20, 20);

	QPixmap pixmap(btn->size());
	pixmap.fill(Qt::transparent);

	QPainter painter(&pixmap);
	QPixmap appPixmap(appPath);
	painter.drawPixmap( (btn->width() - appPixmap.width()) / 2,
		(btn->height() - appPixmap.height()) / 2, appPixmap);
	btn->setIcon(pixmap);
	btn->setIconSize(btn->size());
	btn->setObjectName(appName);
	btn->setProperty("hasborder", true);

	connect(btn, &QPushButton::clicked, this, &CCMainWindow::onAppIconClicked);
	return btn;
}

void CCMainWindow::onAppIconClicked()
{
	//�ж��źŷ����ߵĶ������Ƿ���app_skin
	if (sender()->objectName() == "app_skin")
	{
		SkinWindow* skinWindow = new SkinWindow;
		skinWindow->show();
	}
}