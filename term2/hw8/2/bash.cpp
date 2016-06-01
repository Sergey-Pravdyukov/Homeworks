#include "bash.h"
#include "ui_bash.h"

#include <QGridLayout>
#include <QTextEdit>
#include <QLayout>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QWebElement>
#include <QWebFrame>
#include <QWebPage>
#include <QFont>
#include <QNetworkAccessManager>
#include <QNetworkRequest>

Bash::Bash(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Bash),
    index(0)
{
    view = new QWebView();
    view->load(QUrl("http://bash.im/"));
    connect(view, SIGNAL(loadFinished(bool)), this, SLOT(load()));
    ui->setupUi(this);
    QFont font;
    font.setPixelSize(15);
    bayanButton = new QPushButton;
    bayanButton->setFont(font);
    bayanButton->setText("[:|||:]");
    connect(bayanButton, &QPushButton::clicked, this, &Bash::bayanClicked);
    plusButton = new QPushButton;
    plusButton->setFont(font);
    plusButton->setText("+");
    connect(plusButton, &QPushButton::clicked, this, &Bash::plusClicked);
    minusButton = new QPushButton;
    minusButton->setFont(font);
    minusButton->setText("-");
    connect(minusButton, &QPushButton::clicked, this, &Bash::minusClicked);
    nextButton = new QPushButton;
    nextButton->setFont(font);
    nextButton->setText("next");
    connect(nextButton, &QPushButton::clicked, this, &Bash::nextClicked);
    prevButton = new QPushButton;
    prevButton->setFont(font);
    prevButton->setText("previous");
    connect(prevButton, &QPushButton::clicked, this, &Bash::prevClicked);
    rating = new QLabel;
    rating->setFont(font);
    rating->setText("rating: ----");
    quote = new QTextEdit;
    quote->setFont(font);
    quote->setEnabled(false);
    generate(0);
    quote->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    makeDisabled();
    QGridLayout *buttons = new QGridLayout;
    buttons->addWidget(prevButton, 0, 0);
    buttons->addWidget(nextButton, 0, 1);
    buttons->addWidget(rating, 0, 2);
    buttons->addWidget(plusButton, 1, 0);
    buttons->addWidget(bayanButton, 1, 1);
    buttons->addWidget(minusButton, 1, 2);
    ui->gridLayout->addLayout(buttons, 0, 0, 1, 1);
    ui->gridLayout->addWidget(quote);
}

void Bash::makeEnabled()
{
    prevButton->setEnabled(true);
    nextButton->setEnabled(true);
    rating->setEnabled(true);
    bayanButton->setEnabled(true);
    plusButton->setEnabled(true);
    minusButton->setEnabled(true);
}

void Bash::makeDisabled()
{
    prevButton->setEnabled(false);
    nextButton->setEnabled(false);
    rating->setEnabled(false);
    bayanButton->setEnabled(false);
    plusButton->setEnabled(false);
    minusButton->setEnabled(false);
}

void Bash::load()
{
    qDebug() << "load started\n";
    QWebElementCollection elements = view->page()->mainFrame()->findAllElements("div[class=quote]");
    int count = 0;
    foreach (QWebElement const &element, elements)
    {
        if (element.findFirst("div[class=text]").toPlainText() == "")
            continue;
        quotes[count] = element.findFirst("div[class=text]").toPlainText();
        ratings[count] = element.findFirst("span[class=rating-o]").toPlainText();
        plusLinks[count] = element.findFirst("a[class=up]").attribute("href");
        minusLinks[count] = element.findFirst("a[class=down]").attribute("href");
        bayanLinks[count++] = element.findFirst("a[class=bayan]").attribute("href");

        if (count == size)
            break;
    }
    makeEnabled();
    generate(0);
}

void Bash::generate(int index)
{
    quote->setText(quotes[index]);
    rating->setText("rating: " + ratings[index]);
}

void Bash::prevClicked()
{
    index = (index - 1 + size) % size;
    generate(index);
}

void Bash::nextClicked()
{
    index = (index + 1) % size;
    generate(index);
}

void Bash::plusClicked()
{
    QNetworkAccessManager manager;
    manager.get(QNetworkRequest(QUrl("bash.im" + plusLinks[index])));
}

void Bash::minusClicked()
{
    QNetworkAccessManager manager;
    manager.get(QNetworkRequest(QUrl("bash.im" + minusLinks[index])));
}

void Bash::bayanClicked()
{
    QNetworkAccessManager manager;
    manager.get(QNetworkRequest(QUrl("bash.im" + bayanLinks[index])));
}

Bash::~Bash()
{
    delete ui;
    delete view;
}
